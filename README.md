该项目环境为 ubuntu 22.04 + ROS2 humble

该项目为我为了学习ros2_control与gazebo所写的，因为初学代码水平较低，请大家见谅，也欢迎大家提出修改意见。

食用方法：
  1：新开一个终端，使用命令：source install/setup.bash刷新一下bash
  2: 使用命令：ros2 launch robot_description_pkg robot_display.launch.py
  3: 新开一个终端，使用命令：ros2 run teleop_twist_keyboard teleop_twist_keyboard
  注意：如果出现无法编译的情况，请删除build install log 三个文件夹，再重新编译即可。
  

工程文件里面有一个K_calc.m的matlab代码，运行该代码可以求解控制平衡小车的k增益矩阵

看到这里了，可以给我一个star吗
