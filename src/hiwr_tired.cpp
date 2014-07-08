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
#include <pluginlib/class_list_macros.h>


using namespace cv;

namespace hiwr_tired{
void Hiwr_tired_nodelet::onInit() {
    ROS_DEBUG("[Hiwr Tired Nodelet][onInit] Processing tired frame");

    public_nh = getNodeHandle();
    private_nh = getMTPrivateNodeHandle();
    it_ = new image_transport::ImageTransport(public_nh);

    if(!private_nh.getParam("video_stream", video_stream_name)){
        NODELET_ERROR("[Hiwr Tired Nodelet][onInit] Problem recovering the video stream");
        return;
    }

    im_available = false;

    pub = public_nh.advertise<std_msgs::UInt8>("/uvc_cam_node/tired", 1);
    image_sub_ = it_->subscribe(video_stream_name.c_str(), 1,&Hiwr_tired_nodelet::callback, this);

    data_received = false;
    loop_thread = std::thread(&Hiwr_tired_nodelet::loop , this);

}

void Hiwr_tired_nodelet::loop(){
    ros::Rate loop_rate(10);
    while(ros::ok()){

        if(data_received){
            frame = im_ptr->image;

            Mat out(Size(1,1) , CV_8UC1) ;
            cv::resize(frame , out ,  out.size() );

            msgUInt8.data = out.data[0];

            pub.publish(msgUInt8);
            data_received = false;
        }

        ros::spinOnce();
        loop_rate.sleep();
    }
}

void Hiwr_tired_nodelet::callback(const sensor_msgs::ImageConstPtr& msg){
    data_received = true;
    im_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::MONO8);

}
PLUGINLIB_DECLARE_CLASS(hiwr_tired, Hiwr_tired_nodelet, hiwr_tired::Hiwr_tired_nodelet, nodelet::Nodelet);

}
