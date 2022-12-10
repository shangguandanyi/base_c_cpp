add_library(first SHARED first.cpp)
# add_library(second SHARED third/second.cpp)
# target_link_libraries(second first)
add_executable(main main.cpp)
target_link_libraries(main first dl)

set(third ${PROJECT_SOURCE_DIR}/third)

# configure_file (
#   "${CMAKE_CURRENT_SOURCE_DIR}/third/config.h.in"
#   "${CMAKE_CURRENT_SOURCE_DIR}/third/config.h"
# )

# link_directories(${third})
# file(GLOB so_files ${third}/*.so)
# target_link_libraries(main ${so_files})

add_subdirectory(third)