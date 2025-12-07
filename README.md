# Robotics-Software-Engineer-Go-chase-it

In this project, a simulation of a differential drive mobile robot is implemented in Gazebo and visualized in RVIZ, where the Mobile robot is chasing a white ball.

This project was run on Ubuntu 18.04 and ROS Melodic.

## Project files:

The project contains two main packages:
### The my_robot package content:

1. The Environment the mobile robot will move in at `loma_ws\src\my_robot\worlds\myworld.world`
2. The Mobile robot design at `loma_ws\src\my_robot\urdf\my_robot.xacro`
3. The white ball design at `loma_ws\src\my_robot\myball2\model.sdf`
4. The Lidar meshes file at `loma_ws\src\my_robot\meshes\hokuyo.dae`
5. The world launch file that launches the Gazebo environment, including the mobile robot, and starts RVIZ at `loma_ws\src\my_robot\launch\world.launch` 

### The ball_chaser package content:
1. The package launch file at `loma_ws\src\ball_chaser\launch\ball_chaser.launch`
2. The service server node at `loma_ws\src\ball_chaser\src\drive_bot.cpp`
3. The service client node at `loma_ws\src\ball_chaser\src\process_image.cpp`
4. The service configuration file at `loma_ws\src\ball_chaser\srv\DriveToTarget.srv`

### Steps to run the project:

To run this project, run the following commands in the terminal,
1. Got to the workspace directory: $ cd loma_ws
2. Build the workspace: $ catkin_make
3. Source the setup.bash file: $ source devel/setup.bash
4. Launch the robot inside your world: $ roslaunch my_robot world.launch
![2025-12-05 12-26-43 - frame at 0m19s](https://github.com/user-attachments/assets/b1e7f484-3399-427c-a03e-6cc96e05f46b)
6. Connect Gazebo and RVIZ: See [this video](https://www.youtube.com/watch?v=33L9WSq6ZsE) for the steps.
  
7. In a new terminal, Run `drive_bot` and `process_image`:
 - $ source devel/setup.bash
 - $ roslaunch ball_chaser ball_chaser.launch

8. In a new terminal, visualize the robot’s camera images:
 - $ source devel/setup.bash
 - $ rosrun rqt_image_view rqt_image_view
![2025-12-05 12-26-43 - frame at 1m7s](https://github.com/user-attachments/assets/1ca5e474-23e5-4f5a-ab21-539721ffaf1c)


