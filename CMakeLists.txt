cmake_minimum_required(VERSION 2.8.3)
project(example_cvbridge)
find_package(OpenCV)
find_package(catkin REQUIRED COMPONENTS roscpp
   cv_bridge image_transport sensor_msgs std_msgs)

catkin_package(LIBRARIES OpenCV
   CATKIN_DEPENDS roscpp 
   cv_bridge image_transport sensor_msgs std_msgs)

include_directories(${OpenCV_INCLUDE_DIRS}
                    ${catkin_INCLUDE_DIRS})
add_executable(cam_publisher src/webcam_publisher.cpp)
target_link_libraries(cam_publisher ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})

add_executable(cam_subscriber src/webcam_subscriber.cpp)
target_link_libraries(cam_subscriber ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
