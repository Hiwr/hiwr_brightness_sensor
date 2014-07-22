/*********************************************************************
*
*
* Copyright 2014 Worldline
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
***********************************************************************/

//Common
#include <dlfcn.h>
#include <stdio.h>
#include <unistd.h>

// ROS
#include <ros/ros.h>
#include <ros/time.h>
#include <cv_bridge/cv_bridge.h>

// Messages
#include <sensor_msgs/image_encodings.h>
#include "std_msgs/UInt8.h"
#include "std_msgs/String.h"

// Nodelet
#include <nodelet/nodelet.h>

#include <image_transport/image_transport.h>
#include <camera_info_manager/camera_info_manager.h>

//OpenCV
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

//Threads
#include <thread>

#include <list>

#include <pluginlib/class_list_macros.h>

namespace hiwr_brightness_sensor{

  class HiwrBrightnessSensor : public nodelet::Nodelet{
  public:
    virtual void onInit();

  protected:
    cv_bridge::CvImagePtr im_ptr_;
    cv::Mat frame_;

    // Node handler
    ros::NodeHandle private_nh_;
    ros::NodeHandle public_nh_;

    // Messages
    std_msgs::UInt8 msg_UInt8_;

    bool im_available_;

  private:
    // Suscriber for the camera
    std::string video_stream_name_;

    // Img transport
    image_transport::Subscriber image_sub_;
    image_transport::ImageTransport * it_;

    // Thread
    std::thread loop_thread_;

    // Publisher
    ros::Publisher pub_;

    bool data_received_;

    void loop();
    void callback(const sensor_msgs::ImageConstPtr& msg);

  };

  PLUGINLIB_DECLARE_CLASS(hiwr_brightness_sensor, HiwrBrightnessSensor, hiwr_brightness_sensor::HiwrBrightnessSensor, nodelet::Nodelet);
}
