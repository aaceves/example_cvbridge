#include <ros/ros.h>
#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>

using namespace cv;

int main(int argc, char** argv){
  ros::init(argc, argv, "cam_publisher");
  ros::NodeHandle n;
  image_transport::ImageTransport  it(n);
  image_transport::Publisher pub = it.advertise("camera/image", 1);
  VideoCapture cap(0);
  ros::Rate loop_rate(20);
  while (n.ok()) {
    Mat imageCV;
    cap >> imageCV;
    sensor_msgs::ImagePtr imageROS = cv_bridge::CvImage(
                   std_msgs::Header(), "bgr8", imageCV).toImageMsg();
    pub.publish(imageROS);
    ros::spinOnce();
    loop_rate.sleep();
  }
}
