######################################################################
# Copyright (c) 2017+ The Baidu MapAuto Authors. All Rights Reserved.
# Template of CMakeLists.txt
# @Author: Spark Zheng <zhengyu02@baidu.com>
# @Date: 2018-11-14
# @Version:
######################################################################

cmake_minimum_required(VERSION 3.4.1)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
## env
set(mapauto_path "${CMAKE_CURRENT_SOURCE_DIR}/../../..")
set(WORK_SPACE "${CMAKE_CURRENT_SOURCE_DIR}/../../../..")
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	ADD_DEFINITIONS(-DAR_IOS)
	set(IOS TRUE)
	set(APPLE TRUE)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Android")
	ADD_DEFINITIONS(-DAR_ANDROID)
	set(ANDROID  TRUE)
endif()
if (NOT DEFINED PLATFORM OR NOT PLATFORM)
	set(PLATFORM "ubuntu")
	ADD_DEFINITIONS(-DAR_LINUX)
endif()

# include project cmake files
include(${WORK_SPACE}/com-project/env.cmake)
include(${WORK_SPACE}/com-project/toolchains.cmake)

# include interface env cmake files
include(${WORK_SPACE}/map-engine-interface/mk/interface_env.cmake)

# include common cmake files
include (${mapauto_path}/src/common/common_env.cmake)

# include engine cmake files
include (${mapauto_path}/src/engine/engine_env.cmake)

# compiler parameters

# linker parameters

## arnavi sources

## utest sources

## targets
# basic targets
add_library(
    engine_arnavi
    SHARED
    ${mapauto_common_sources}
    ${engine_arnavi_sources}
)

target_link_libraries(
    engine_arnavi
    ${mapauto_libs}
)

# utest targets
include_directories(
    BEFORE
    ${utest_inc}
)

set(utest_libs
    ${utest_libs}
    ${gflags_lib}
)

# arnavi_utest

## run utest
enable_testing()

# add utests

