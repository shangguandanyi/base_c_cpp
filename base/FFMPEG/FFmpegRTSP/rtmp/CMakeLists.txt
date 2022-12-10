cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(FFmpeg-RTMP LANGUAGES CXX C)

set(FFMPEG_ROOT /opt/ffmpeg-4.1.3)
include_directories(${FFMPEG_ROOT}/include)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

link_directories(${FFMPEG_ROOT}/lib)
set(link_libs avcodec avformat avutil swscale)

add_executable(ffmpeg-rmsp ffmpeg_rtmp.cpp)
target_link_libraries(ffmpeg-rmsp ${link_libs} ${OpenCV_LIBS})