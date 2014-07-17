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

#include "hiwr_tired.h"

using namespace cv;

namespace hiwr_tired{
void HiwrTiredNodelet::onInit() {
    ROS_DEBUG("[Hiwr Tired Nodelet][onInit] Processing tired frame");

    public_nh_ = getNodeHandle();
    private_nh_ = getMTPrivateNodeHandle();
    it_ = new image_transport::ImageTransport(public_nh_);

    if(!private_nh_.getParam("video_stream", video_stream_name_)){
        NODELET_ERROR("[Hiwr Tired Nodelet][onInit] Problem recovering the video stream");
        return;
    }
    im_available_ = false;

    // Publisher
    pub_ = public_nh_.advertise<std_msgs::UInt8>("/hiwr_tired/brightness", 1);

    // Subscriber
    image_sub_ = it_->subscribe(video_stream_name_.c_str(), 1,&HiwrTiredNodelet::callback, this);

    data_received_ = false;
    loop_thread_ = std::thread(&HiwrTiredNodelet::loop , this);

}

void HiwrTiredNodelet::loop(){
    ros::Rate loop_rate(10);
    while(ros::ok()){

        // When receiving data, publishing them on /hiwr_tired/brightness
        if(data_received_){
            frame_ = im_ptr_->image;

            Mat out(Size(1,1) , CV_8UC1) ;
            cv::resize(frame_ , out ,  out.size() );

            msg_UInt8_.data = out.data[0];

            pub_.publish(msg_UInt8_);
            data_received_ = false;
        }

        ros::spinOnce();
        loop_rate.sleep();
    }
}

void HiwrTiredNodelet::callback(const sensor_msgs::ImageConstPtr& msg){
    data_received_ = true;
    im_ptr_ = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::MONO8);

}
PLUGINLIB_DECLARE_CLASS(hiwr_tired, HiwrTiredNodelet, hiwr_tired::HiwrTiredNodelet, nodelet::Nodelet);
}
