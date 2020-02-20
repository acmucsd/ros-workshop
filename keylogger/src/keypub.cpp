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

	/* TODO: initialise the node and publisher */

	// here we get the terminal ready to record keyboard input
	tcgetattr(kfd, &cooked);		
	memcpy(&raw, &cooked, sizeof(struct termios));
	raw.c_lflag &= ~(ICANON | ECHO);
	raw.c_cc[VEOL] = 1;
	raw.c_cc[VEOF] = 2;
	tcsetattr(kfd, TCSANOW, &raw);

	puts("Reading keyboard.");
	
	int c = 0;
	// reads the keyboard input and puts the character into c
	read(kfd, &c, 1);

	/* TODO: continuously read keyboard input and publish if we receive something */
	
	quit(0);
	return 0;
}
