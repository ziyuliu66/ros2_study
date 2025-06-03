from setuptools import find_packages
from setuptools import setup

setup(
    name='robot_state_pub_interface',
    version='0.0.0',
    packages=find_packages(
        include=('robot_state_pub_interface', 'robot_state_pub_interface.*')),
)
