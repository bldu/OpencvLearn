cmake_minimum_required(VERSION 3.21)
project (OpencvLearn)

# mandatory for opencv4
set(CMAKE_CXX_STANDARD 11)

IF (WIN32)
    MESSAGE(STATUS "windows")
    set(OpenCV_DIR ${CMAKE_SOURCE_DIR}/thirdparty/opencv/build)
ELSEIF (APPLE)
    MESSAGE(STATUS "Apple systems.")
    set(OpenCV_DIR ${CMAKE_SOURCE_DIR}/thirdparty/opencv/lib/cmake/opencv4)
ELSEIF (UNIX)
    MESSAGE(STATUS "UNIX-like OS's.")
    set(OpenCV_DIR ${CMAKE_SOURCE_DIR}/thirdparty/opencv/lib/cmake/opencv4)
ENDIF ()

find_package(OpenCV 4.11.0 REQUIRED)
# message(STATUS "OpenCV_LIBS:  ${OpenCV_LIBS}")
# message(STATUS "OpenCV_INCLUDE_DIRS:  ${OpenCV_INCLUDE_DIRS}")


ADD_SUBDIRECTORY(learn_examples)
