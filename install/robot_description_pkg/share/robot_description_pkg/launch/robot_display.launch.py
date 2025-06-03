import launch
import launch_ros
from launch_ros.actions import Node
from launch import LaunchDescription
from ament_index_python.packages import get_package_share_directory
import launch_ros.parameter_descriptions
from os.path import join
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():

    robot_name_in_model = 'balance_car'
    # 获取名为'robot_description_pkg'的ROS软件包的共享目录路径
    urdf_share_path = get_package_share_directory('robot_description_pkg')

    # 拼接默认URDF模型文件路径（假设包内有urdf/first_robot.urdf文件）
    default_model_path = join(urdf_share_path, 'urdf', 'balance_car.urdf.xacro')

    default_rviz2_config_path = join(urdf_share_path, 'config', 'rviz2_default_config.rviz')

    # 声明一个启动参数（可在命令行覆盖）
    action_declare_arg_model_path = launch.actions.DeclareLaunchArgument(
        name='model',                          # 参数名称
        default_value=str(default_model_path), # 默认使用上述路径
        description='URDF的绝对路径',           # 参数描述
    )

    # 构建机器人描述参数（核心部分）
    robot_description = launch_ros.parameter_descriptions.ParameterValue(
        # 使用命令替换：执行 cat 命令读取模型文件内容
        launch.substitutions.Command(
            ['xacro ', launch.substitutions.LaunchConfiguration('model')] # 通过启动参数获取文件路径，注意'cat '的cat后面要有空格
        ),
        value_type=str  # 指定参数类型为字符串
    )

    # 配置robot_state_publisher节点
    action_robot_state_publisher_node = Node(
        package='robot_state_publisher',   # 节点所属包
        executable='robot_state_publisher', # 可执行文件名称
        parameters=[{
            # 将生成的URDF内容传递给robot_description参数
            'robot_description': robot_description
        }]
    )
    # action_joint_state_publisher_node = Node(
    #     package='joint_state_publisher',
    #     executable='joint_state_publisher',
    # )
    
    action_rviz2_node = Node(
        package='rviz2',
        executable='rviz2',
        arguments=['-d',default_rviz2_config_path]
    )

    # 通过 IncludeLaunchDescription 包含另外一个 launch 文件
    launch_gazebo = launch.actions.IncludeLaunchDescription(
        PythonLaunchDescriptionSource([get_package_share_directory(
            'gazebo_ros'), '/launch', '/gazebo.launch.py']),
      	# 传递参数
        launch_arguments=[('verbose','true')]
    )
    # 请求 Gazebo 加载机器人
    spawn_entity_node = launch_ros.actions.Node(
        package='gazebo_ros',
        executable='spawn_entity.py',
        arguments=['-topic', '/robot_description',
                   '-entity', robot_name_in_model, ])
    
    # 加载并激活 myrobot_joint_state_broadcaster 控制器
    load_joint_state_controller = launch_ros.actions.Node(
        package='controller_manager',
        executable='spawner',
        arguments=['robot_joint_state_broadcaster'],

    )

    load_lqr_effort_controller = launch_ros.actions.Node(
        package='controller_manager',
        executable='spawner',
        arguments=['lqr_effort_controller'],

    )
    
    return LaunchDescription([
        action_declare_arg_model_path,
        action_robot_state_publisher_node,
        # action_joint_state_publisher_node,
        # action_rviz2_node,
        launch_gazebo,
        spawn_entity_node,
         # 事件动作，当加载机器人结束后执行    
        launch.actions.RegisterEventHandler(
            event_handler=launch.event_handlers.OnProcessExit(
                target_action=spawn_entity_node,
                on_exit=[load_joint_state_controller],)
            ),
         # 事件动作，当加载机器人结束后执行    
        launch.actions.RegisterEventHandler(
            event_handler=launch.event_handlers.OnProcessExit(
                target_action=load_joint_state_controller,
                on_exit=[load_lqr_effort_controller],)
            ),
    ])
    