hiwr\_brightness\_sensor
===============================================

The hiwr\_brightness\_sensor ROS package aims to compute the current brightness with the video camera.

Contributing
----------------------

Contributions via pull request are welcome and may be included under the
same license as below.

Copyright
----------------------

hiwr\_brightness\_sensor, except where otherwise noted, is released under the
[Apache License 2.0](http://www.apache.org/licenses/LICENSE-2.0.html).
See the LICENSE file located in the root directory.

Build
----------------------
It requires [Hiwr_msg package](https://github.com/Hiwr/hiwr_msg) to work properly.

Execution
----------------------

To start hiwr\_brightness\_sensor, do the following (assuming, you
have a working ROS core running and that you have a running camera controller):

   Launch using roslaunch:

   > roslaunch hiwr\_brightness\_sensor brightness\_sensor\_example.launch

   Launch from another launchfile:

   ```
   <include file="$(find hiwr_brightness_sensor)/launch/brightness_sensor_example.launch" />
   ```
Node
----------------------

### Subscribed Topics

- `/hiwr_camera_controller/output_video`
      * Subscribe to camera video stream (cf. video_stream parameter)

### Published Topics

- `/hiwr_brightness_sensor/brightness`
      * Get the tired value

### Parameters

- `video_stream` (std_msgs/String)
     * Define the name of the video output stream
