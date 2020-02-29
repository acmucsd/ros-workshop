# ACM x Robosub ROS Workshops
This repository contains all the ROS packages for the ROS workshop series, and will hopefully give you a basic idea of how ROS works. 

Slides for Part 1 of this workshop series can be found [here](https://acmurl.com/rosslides).

## What even is ROS? 
ROS stands for Robot Operating System. Is it an operating system? Not really. ROS is what's called a "middleware", meaning that it provides an interface for data transfer between different programs. It allows developers to more effectively compartmentalize different sections of their code that perform different tasks, which, if you're working with a robot that has many different sensors and actuators that performs complex tasks, is incredibly useful. Other people have also written many different packages for ROS, like drivers for certain sensors, autonomous navigation, simulation, etc, that people can leverage for their own robots, which is also very helpful.  

## How does it work? 
Perhaps the most important ROS concept is the node. Nodes are essentially isolated bits of code that run separately from each other. They can pass data between each other by sending messages through topics - channels that data (in a specific format) can be sent through. Nodes can either "publish" data to a topic, or "subscribe" to a topic, and can do both with as many topics as necessary. 

## Setting up our environment
Whether you have ROS directly installed onto your computer or are running a Docker image, the setup for both is the same.

### Intro to Catkin
Catkin is a build tool that we'll be using to compile and run our ROS code. The interesting thing about catkin is that it helps to create CMake files, which create Makefiles, which build our code. The first thing we'll be doing is the following: 

```
cd ~
mkdir -p catkin_ws/src
cd catkin_ws
catkin_make
```

This will initialise our workspace and create all the necessary folders for ROS. If you look at the contents of our catkin workspace, you'll see that we have a "build" folder, a "devel" folder, and a "src" folder. We'll only worry about the contents of the "src" folder today. 

### Grabbing code
Execute the following: 
```
cd src
rm CMakeLists.txt
git clone https://github.com/acmucsd/ros-workshop
```
This will pull the contents of this repository into your src folder. To build all packages at the same time, navigate to the `catkin_ws` folder and run `catkin_make`.

