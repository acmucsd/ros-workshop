#include <ros/ros.h>
#include <std_msgs/Char.h>
#include <termios.h>

int kfd = 0; 
struct termios cooked, raw;

void quit(int sig) {
	tcsetattr(kfd, TCSANOW, &cooked);
	ros::shutdown();
	exit(0);
}

int main(int argc, char** argv) {
	ros::init(argc, argv, "keypub");
	ros::NodeHandle n;

	ros::Publisher key_pub = n.advertise<std_msgs::Char>("keys",1000);
	ros::Rate loop_rate(10);

	// here we get the terminal ready to record keyboard input
	tcgetattr(kfd, &cooked);		
	memcpy(&raw, &cooked, sizeof(struct termios));
	raw.c_lflag &= ~(ICANON | ECHO);
	raw.c_cc[VEOL] = 1;
	raw.c_cc[VEOF] = 2;
	tcsetattr(kfd, TCSANOW, &raw);

	puts("Reading keyboard.");
	
	int c;
	while(ros::ok()) {
		c = 0;
		if (read(kfd, &c, 1) < 0) {
			perror("read():");
			exit(-1);
		}
		if (c) {	
			std_msgs::Char c_msg;
			c_msg.data = c;
			key_pub.publish(c_msg);
		}
		
	}
	quit(0);
	return 0;
}
