# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

set(SRC_DIR src/main/cpp)

#include_directories(${SRC_DIR})

file(GLOB_RECURSE CPP_SRCS "${SRC_DIR}/*.cpp")  #指定当前目录下的所有.cpp文件（包括子目录）

add_library( # Sets the name of the library.
             GLES

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             #${SRC_DIR}/Android/JniWarpper.cpp
             ${CPP_SRCS}
             )

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

target_link_libraries( # Specifies the mTarget library.
                       GLES

                       # Links the mTarget library to the log library
                       # included in the NDK.
                       ${log-lib}
                       GLESv2
                       )