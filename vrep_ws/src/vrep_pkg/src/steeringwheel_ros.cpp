//
// Created by chrisliu on 2019/9/25.
//

#include "ros/ros.h"
#include <iostream>
#include <algorithm>
#include "steeringwheel.h"
#include <std_msgs/Float32.h>
#include <geometry_msgs/Twist.h>

using namespace std;

ros::Publisher S0;
ros::Publisher M0;
ros::Publisher S1;
ros::Publisher M1;
ros::Publisher S2;
ros::Publisher M2;
ros::Publisher S3;
ros::Publisher M3;



void keyboard_callback(const geometry_msgs::Twist::ConstPtr &keyboard)
{
    float vel=sqrt(pow(keyboard->linear.x,2)+pow(keyboard->linear.y,2));
    float angular = atan2(keyboard->linear.y,keyboard->linear.x)+PI/2;

    fwc(vel,angular,keyboard->angular.z);
    std_msgs::Float32 speed[4],steer[4];
    for(int i=0;i<4;i++)
    {

        speed[i].data = wheel.w_vol[i];
        steer[i].data = wheel.w_angle[i];
    }

    M0.publish(speed[0]);
    S0.publish(steer[0]);
    M1.publish(speed[1]);
    S1.publish(steer[1]);
    M2.publish(speed[2]);
    S2.publish(steer[2]);
    M3.publish(speed[3]);
    S3.publish(steer[3]);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "SteeringWheel");//初始化ROS节点
    ros::NodeHandle n;

    ros::Subscriber sub_keyboard = n.subscribe("/cmd_vel",1,keyboard_callback);

    S0 = n.advertise<std_msgs::Float32>("/FrontRight_SteerMotor", 1);
    M0 = n.advertise<std_msgs::Float32>("/FrontRight_MoveMotor", 1);
    S1 = n.advertise<std_msgs::Float32>("/BackRight_SteerMotor", 1);
    M1 = n.advertise<std_msgs::Float32>("/BackRight_MoveMotor", 1);
    S2 = n.advertise<std_msgs::Float32>("/BackLeft_SteerMotor", 1);
    M2 = n.advertise<std_msgs::Float32>("/BackLeft_MoveMotor", 1);
    S3 = n.advertise<std_msgs::Float32>("/FrontLeft_SteerMotor", 1);
    M3 = n.advertise<std_msgs::Float32>("/FrontLeft_MoveMotor", 1);


    while (ros::ok()) {
        ros::spinOnce();
    }
    return 0;
}
