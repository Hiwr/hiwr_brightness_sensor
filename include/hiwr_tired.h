#include <dlfcn.h>
#include <stdio.h>
#include <unistd.h>

#include <signal.h>
#include <cstdio>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <ros/ros.h>
#include <ros/time.h>
#include "std_msgs/UInt8.h"

#include <sensor_msgs/Image.h>
#include <sensor_msgs/CameraInfo.h>
#include <sensor_msgs/fill_image.h>
#include <tf/transform_listener.h>
#include <camera_info_manager/camera_info_manager.h>
#include <dynamic_reconfigure/server.h>

//#include "facetracking/UVCCamConfig.h"

#include <hyve_msg/TouchEvent.h>
#include <hyve_msg/SetState.h>
#include <hyve_msg/GetState.h>

#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <image_transport/image_transport.h>

#include <driver_base/SensorLevels.h>
#include <driver_base/driver.h>

#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>

#include <nodelet/nodelet.h>
#include <pluginlib/class_list_macros.h>

#include "std_msgs/String.h"

//OpenCV
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

//Threads
#include <thread>

#include <list>
namespace hiwr_tired{



class Hiwr_tired_nodelet : public nodelet::Nodelet{
public:
    virtual void onInit();

protected:
    cv_bridge::CvImagePtr im_ptr;
    cv::Mat frame;
    //ros::NodeHandle& public_nh;
    ros::NodeHandle private_nh;
    ros::NodeHandle public_nh;
    bool im_available;
    std_msgs::UInt8 msgUInt8;

private:
    // suscriber for the camera
    std::string video_stream_name;
    image_transport::Subscriber image_sub_;
    image_transport::ImageTransport * it_;
     std::thread loop_thread;
     ros::Publisher pub;

     bool data_received;

     //Main loop
     void loop();
     void callback(const sensor_msgs::ImageConstPtr& msg);

};

PLUGINLIB_DECLARE_CLASS(hiwr_tired, Hiwr_tired_nodelet, hiwr_tired::Hiwr_tired_nodelet, nodelet::Nodelet);
}
