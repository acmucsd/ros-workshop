cmake_minimum_required(VERSION 2.8.3)
project(keylogger)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  genmsg
)

generate_messages(
   DEPENDENCIES
   std_msgs
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(keypub src/keypub.cpp)
target_link_libraries(keypub ${catkin_LIBRARIES})

# TODO: do the same for keysub 
