## ! DO NOT MANUALLY INVOKE THIS setup.py, USE CATKIN INSTEAD

from distutils.core import setup
from catkin_pkg.python_setup import generate_distutils_setup

# fetch values from package.xml
setup_args = generate_distutils_setup(
    packages=['vrep', 'vrepConst', 'vrep_ur5_ros'],
    package_dir={'vrep': 'include/CopellaRobotics/remoteApiBindings/python/python/vrep',
                 'vrepConst': 'include/CopellaRobotics/remoteApiBindings/python/python/vrepConst',
                 'vrep_ur5_ros': 'scripts/vrep_ur5_ros'},
)

setup(**setup_args)
