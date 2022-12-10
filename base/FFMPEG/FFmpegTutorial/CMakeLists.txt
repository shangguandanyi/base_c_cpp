cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(hello-world-01 LANGUAGES CXX)

set(FFMPEG_ROOT /opt/ffmpeg-3.4.11)
include_directories(${FFMPEG_ROOT}/include)
include_directories(${PROJECT_SOURCE_DIR}/inc)

link_directories(${FFMPEG_ROOT}/lib)
set(link_libs avcodec avformat avutil swscale)

set(src_dir ${PROJECT_SOURCE_DIR}/src)
file(GLOB src_codes ${src_dir}/*.cpp)

set(demo_dir ${PROJECT_SOURCE_DIR}/demo)
file(GLOB demo_codes ${demo_dir}/*.cpp)

foreach(demo ${demo_codes})
	string(REGEX MATCH "[^/]+$" demo_file ${demo})
	string(REPLACE ".cpp" "" demo_basename ${demo_file})
	add_executable(${demo_basename} ${demo} ${src_codes})
	target_link_libraries(${demo_basename} ${link_libs})
endforeach()