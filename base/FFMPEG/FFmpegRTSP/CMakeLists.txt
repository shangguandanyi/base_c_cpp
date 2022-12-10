cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(FFmpeg-RTSP LANGUAGES CXX C)

set(FFMPEG_ROOT /opt/ffmpeg-4.1.3)
include_directories(${FFMPEG_ROOT}/include)
include_directories(${PROJECT_SOURCE_DIR}/inc)

link_directories(${FFMPEG_ROOT}/lib)
set(link_libs avcodec avformat avutil swscale)

add_executable(ffmpeg-rtsp main.cpp)
target_link_libraries(ffmpeg-rtsp ${link_libs})

set(src_dir ${PROJECT_SOURCE_DIR}/src)
file(GLOB src_codes ${src_dir}/*.c)

find_package(PkgConfig REQUIRED)
pkg_search_module(GST1 REQUIRED gstreamer-1.0)

foreach(src ${src_codes})
	string(REGEX MATCH "[^/]+$" src_file ${src})
	string(REPLACE ".c" "" src_basename ${src_file})
	add_executable(${src_basename} ${src})
	target_include_directories(${src_basename}  PRIVATE ${GST1_INCLUDE_DIRS})
	target_link_libraries(${src_basename} ${link_libs} ${GST1_LIBRARIES})
endforeach()