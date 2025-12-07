#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    // TODO: Request a service and pass the velocities to it to drive the robot
    ROS_INFO_STREAM("Driving the robot: linear_x = " << lin_x << " angular_z = " << ang_z);

    // Create a service object
    ball_chaser::DriveToTarget srv;
    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;

    // Call the service /ball_chaser/command_robot
    if(!client.call(srv)) {
        ROS_ERROR("Failed to call service command_robot");
    }
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image::ConstPtr& img)
{

    int white_pixel = 255;
    bool ball_found = false;

    // TODO: Loop through each pixel in the image and check if there's a bright white one
    // Then, identify if this pixel falls in the left, mid, or right side of the image
    // Depending on the white ball position, call the drive_bot function and pass velocities to it
    // Request a stop when there's no white ball seen by the camera

    // Image dimensions

    int img_width  = img->width;
    int img_height = img->height;
    int img_step   = img->step;     // total bytes per row
    int channels   = 3;             // RGB = 3 bytes per pixel


    int ball_x_pos = -1; // column index of detected white pixel

    // Loop through the image to find a white pixel
    // Loop through image data to find a white pixel
    for (size_t i = 0; i < img_height * img_step; i += channels) {

        int red   = img->data[i];
        int green = img->data[i + 1];
        int blue  = img->data[i + 2];

        if (red == white_pixel && green == white_pixel && blue == white_pixel) {
            ball_found = true;


            // Compute pixel position in the image
            int pixel_index = i / channels;
            ball_x_pos = pixel_index % img_width;

            break; // stop after finding the first white pixel
        }
    }
    if (ball_found) {
        ROS_WARN("WHITE PIXEL DETECTED!");

        // Divide image into three vertical regions
        int left_boundary   = img_width / 3;
        int right_boundary  = 2 * img_width / 3;

        if (ball_x_pos < left_boundary) {
            // Ball is on the LEFT
            drive_robot(0.0, 0.5);
        }
        else if (ball_x_pos > right_boundary) {
            // Ball is on the RIGHT
            drive_robot(0.0, -0.5);
        }
        else {
            // Ball is in the CENTER
            drive_robot(0.5, 0.0);
        }
    }
    else {
        // No white ball → stop
        ROS_WARN("WHITE PIXEL NOT DETECTED!");
        drive_robot(0.0, 0.0);
    }
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}
