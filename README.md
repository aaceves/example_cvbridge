# example_cvbridge ROS_package

## Descripción general
Tutorial básico del uso de Image Transport y CvBridge para enviar imágenes obtenidas con OpenCV a traves de un tópico de ROS.

## Pre-requisitos
Se considera que la computadora del usuario ya tiene correctamente instalado ROS, GIT y que ya tiene la carpeta de `catkin_ws` correctamente inicializada.   
Para asegurarse que se tiene un dispositivo de video, ejecutar en una Terminal:
```
cheese
```
Deberá de ver la imagen de la cámara. En caso contrario significa que no tiene una cámara de video correctamente instalada.    
Para asegurarse que se tiene correctamente instalado OpenCV, ejecutar la siguiente instrucción en una Terminal:
```
pkg-config –-modversion opencv
```
Debe responder con la versión de OpenCV. En caso que no tenga instalado OpenCV, ejecutar:
```
sudo apt-get install ros-kinetic-vision-opencv libopencv-dev python-opencv
```

## Proceso de instalación
En una Terminal ejecutar las siguientes instrucciones:
```
cd ~/catkin_ws/src
git clone https://github.com/aaceves/example_cvbridge.git
cd ~/catkin_ws
catkin build
source devel/setup.bash
```
El proceso de compilación debe terminar sin errores.

## Ejemplo de ejecución

En tres Terminales diferentes ejecutar cada una de las siguientes lineas:
```
roscore
rosrun example_cvbridge cam_publisher
rosrun example_cvbridge cam_subscriber
```

## Autores y colaboradores
Este paquete fue preparado por el Dr. Alejandro Aceves-López usando las referencias abajo citadas para que sea más comprensible a los programadores nuevos de ROS.

## Referencias
1. Haowei Zhang, “Configure OpenCV in ROS environment with cv_bridge”, publicado 15 nov 2016, [link](https://www.youtube.com/watch?v=HqNJbx0uAv0)   
2. Patrick Mihelich, and James Bowman, “Vision OpenCV Package”, [link](http://wiki.ros.org/opencv)   
3. Patrick Mihelich, “Image view Package”, consultado en enero 2018, [link](http://wiki.ros.org/image_view)   
4. Patrick Mihelich, and  James Bowman, “Converting between ROS images and OpenCV images in C++”, [link](http://wiki.ros.org/cv_bridge/Tutorials)   
5. Patrick Mihelich, “Image transport tutorials”, consultado en enero 2018, [link](http://wiki.ros.org/image_transport/Tutorials/)   
6. Patrick Mihelich, and James Bowman, “Documentación cv_bridge”, [link](http://docs.ros.org/jade/api/cv_bridge/html/c++/index.html) 
