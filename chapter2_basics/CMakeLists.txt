cmake_minimum_required( VERSION 3.0)
cmake_policy(SET CMP0012 NEW)
PROJECT(proj1)

set (OpenCV_DIR /home/alka/opencv_install/build_opencv)
FIND_PACKAGE(OpenCV 4.5.5 REQUIRED)
MESSAGE("OpenCV version : ${OpenCV_VERSION}")

include_directories( ${OpenCV_INCLUDE_DIRS} )
link_directories( ${OpenCV_LIB_DIR} )

ADD_EXECUTABLE(app1 main1.cpp)
ADD_EXECUTABLE(app2 main2.cpp)
ADD_EXECUTABLE(app3 main3.cpp)
ADD_EXECUTABLE(app4 main4.cpp)
ADD_EXECUTABLE(app5 main5.cpp)
ADD_EXECUTABLE(app6 main6.cpp)

TARGET_LINK_LIBRARIES(app1 ${OpenCV_LIBS})
TARGET_LINK_LIBRARIES(app2 ${OpenCV_LIBS})
TARGET_LINK_LIBRARIES(app3 ${OpenCV_LIBS})
TARGET_LINK_LIBRARIES(app4 ${OpenCV_LIBS})
TARGET_LINK_LIBRARIES(app5 ${OpenCV_LIBS})
TARGET_LINK_LIBRARIES(app6 ${OpenCV_LIBS})
