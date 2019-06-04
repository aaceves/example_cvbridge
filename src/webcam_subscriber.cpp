#include <ros/ros.h>
#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
void imageCallback(const sensor_msgs::ImageConstPtr& imageROS){
  try {
    cv::imshow("view", cv_bridge::toCvShare(imageROS, "bgr8")->image);
    cv::waitKey(1);
  }
  catch (cv_bridge::Exception& e) {
    ROS_ERROR("Could not convert from '%s' to 'bgr8'.", imageROS->encoding.c_str());
  }
}
int main(int argc, char **argv){
  ros::init(argc, argv, "cam_subscriber");
  ros::NodeHandle n;
  cv::namedWindow("view");
  //cv::startWindowThread();
  image_transport::ImageTransport it(n);
  image_transport::Subscriber sub = it.subscribe("camera/image",1,imageCallback);
  ros::spin();
  cv::destroyWindow("view");
}
