cmake_minimum_required(VERSION 2.8.3)
project(hiwr_brightness_sensor)
## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  image_transport
  cv_bridge
  nodelet
)

find_package(OpenCV)

catkin_package(
  CATKIN_DEPENDS roscpp rospy std_msgs
  DEPENDS opencv nodelet std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  include
)


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -std=c++0x -pthread -pg")

add_library(hiwr_brightness_sensor src/hiwr_brightness_sensor.cpp)
target_link_libraries(hiwr_brightness_sensor ${catkin_LIBRARIES})

