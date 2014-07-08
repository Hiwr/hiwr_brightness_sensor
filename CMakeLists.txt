cmake_minimum_required(VERSION 2.8.3)
project(hiwr_tired)
## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  rospack
  sensor_msgs
  image_transport
  dynamic_reconfigure
  tf
  driver_base
  hyve_msg
  cv_bridge
  nodelet
)

find_package(OpenCV)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

#######################################
## Declare ROS messages and services ##
#######################################

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   std_msgs
# )

# generate_dynamic_reconfigure_options(
#  cfg/UVCCam.cfg
# )


###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  LIBRARIES facetracking
  CATKIN_DEPENDS roscpp rospy std_msgs rospack hyve_msg
  DEPENDS opencv nodelet std_msgs
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS}
  include
)

## Declare a cpp library
# add_library(facetracking
#   src/${PROJECT_NAME}/facetracking.cpp
# )

## Declare a cpp executable
# add_executable(facetracking_node src/facetracking_node.cpp)

## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
# add_dependencies(facetracking_node facetracking_generate_messages_cpp)

## Specify libraries to link a library or executable target against
# target_link_libraries(facetracking_node
#   ${catkin_LIBRARIES}
# )

#############
## Install ##
#############
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables and/or libraries for installation
# install(TARGETS facetracking facetracking_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_facetracking.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)


##PERSONNALIZED
#include_directories(include cfg/cpp ${catkin_INCLUDE_DIRS})

#include_directories(${catkin_INCLUDE_DIRS})


#configure_file(include/toto ${facetracking_DEVEL_PREFIX}/include/tata)


# make sure configure headers are built before any node using them
#link_directories( /opt/ros/groovy/lib )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -std=c++0x -pthread -pg")
#add_executable(grayscale src/grayscale.cpp )
#target_link_libraries(grayscale ${catkin_LIBRARIES} opencv_core opencv_imgproc opencv_objdetect opencv_highgui)

add_library(hiwr_tired src/hiwr_tired.cpp)
target_link_libraries(hiwr_tired ${catkin_LIBRARIES})
#add_dependencies(uvc_cam_node ${PROJECT_NAME}_gencfg)

#add_executable(tracker src/tracker.cpp )
#target_link_libraries(tracker ${catkin_LIBRARIES} opencv_core opencv_imgproc opencv_objdetect opencv_highgui)


