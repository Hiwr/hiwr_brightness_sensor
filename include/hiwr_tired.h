#include <dlfcn.h>
#include <stdio.h>
#include <unistd.h>

#include <ros/ros.h>
#include <ros/time.h>
#include "std_msgs/UInt8.h"

#include <camera_info_manager/camera_info_manager.h>

#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <image_transport/image_transport.h>

#include <nodelet/nodelet.h>

#include "std_msgs/String.h"

//OpenCV
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

//Threads
#include <thread>

#include <list>
#include <pluginlib/class_list_macros.h>

namespace hiwr_tired{

  class HiwrTiredNodelet : public nodelet::Nodelet{
  public:
    virtual void onInit();

  protected:
    cv_bridge::CvImagePtr im_ptr_;
    cv::Mat frame_;
    ros::NodeHandle private_nh_;
    ros::NodeHandle public_nh_;
    bool im_available_;
    std_msgs::UInt8 msg_UInt8_;

  private:
    // suscriber for the camera
    std::string video_stream_name_;
    image_transport::Subscriber image_sub_;
    image_transport::ImageTransport * it_;
    std::thread loop_thread_;
    ros::Publisher pub_;

    bool data_received_;

    //Main loop
    void loop();
    void callback(const sensor_msgs::ImageConstPtr& msg);

  };

  PLUGINLIB_DECLARE_CLASS(hiwr_tired, HiwrTiredNodelet, hiwr_tired::HiwrTiredNodelet, nodelet::Nodelet);
}
