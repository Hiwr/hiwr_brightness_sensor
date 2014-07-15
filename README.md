hiwr\_tired
===============================================

When putting hiwr in the black, hiwr is becoming tired and sleepy. After a second, hiwr will be asleep until the thing in front of its camera is off.

Contributing
----------------------

Contributions via pull request are welcome and may be included under the
same license as below.

Copyright
----------------------

hiwr\_tired, except where otherwise noted, is released under the
[Apache License 2.0](http://www.apache.org/licenses/LICENSE-2.0.html).
See the LICENSE file located in the root directory.

Build
----------------------
build instructions

Execution
----------------------

To start hiwr\_tired, do the following (assuming, you
have a working ROS core running and that you have a running camera controller):

   Launch using roslaunch:

   > roslaunch hiwr\_tired tired\_example.launch

   Launch from another launchfile:

   ```
   <include file="$(find hiwr_tired)/launch/tired_example.launch" />
   ```
Node
----------------------

### Subscribed Topics

- `/hiwr_camera_controller/output_video`
      * Subscribe to camera video stream (cf. video_stream parameter)

### Published Topics

- `/hiwr_tired/brightness`
      * Get the tired value

### Parameters

- `video_stream` (std_msgs/String)
     * Define the name of the video output stream
