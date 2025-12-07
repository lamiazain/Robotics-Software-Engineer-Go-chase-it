# Robotics-Software-Engineer-Go-chase-it
This project was run on the Ubuntu 18.04 Operating system and using ROS Melodic.


The project contains two main packages:
1. The my_robot package content:
a. The Environment the mobile robot will move in at `loma_ws\src\my_robot\worlds\myworld.world`
b. The Mobile robot design at `loma_ws\src\my_robot\urdf\my_robot.xacro`
c. The white ball design at `loma_ws\src\my_robot\myball2\model.sdf`
d. The Lidar meshes file at `loma_ws\src\my_robot\meshes\hokuyo.dae`
e. The world launch file that launches The Gazebo environment, including the mobile robot and starting RVIZ at `loma_ws\src\my_robot\launch\world.launch` 

2. The ball_chaser package content:
a. The package launch file at `loma_ws\src\ball_chaser\launch\ball_chaser.launch`
b. The service server node at `loma_ws\src\ball_chaser\src\drive_bot.cpp`
c. The service client node at `loma_ws\src\ball_chaser\src\process_image.cpp`
d. The service configuration file at `loma_ws\src\ball_chaser\srv\DriveToTarget.srv`

To run this project run the following commands in terminal,
1. Got o the workspace directory: $ cd loma_ws
2. build the workspace: $ catkin_make
3. Source the setup.bash file: $ source devel/setup.bash
4. Launch the robot inside your world: $ roslaunch my_robot world.launch
5. In a new terminal, Run `drive_bot` and `process_image`:
 $ source devel/setup.bash
 $ roslaunch ball_chaser ball_chaser.launch
7. In a new terminal, visualize the robot’s camera images:
 $ source devel/setup.bash
 $ rosrun rqt_image_view rqt_image_view  

