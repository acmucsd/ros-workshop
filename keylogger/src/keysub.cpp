#include <ros/ros.h>
#include <std_msgs/Char.h>

void keyCallback(const std_msgs::Char::ConstPtr &msg) {
	ROS_INFO("Got key: %c", msg->data);
}

int main(int argc, char** argv) {
	ros::init(argc, argv, "keysub");
	ros::NodeHandle n;

	ros::Subscriber key_sub = n.subscribe("keys", 1000, keyCallback);

	ros::spin();
	return 0;	
}
