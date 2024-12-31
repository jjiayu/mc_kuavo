# Here we find a typical ROS description package, this set the
# JVRC_DESCRIPTION_PATH CMake variable
find_description_package(jvrc_description)
# Generate the robot module C++ code using this value
configure_file(Kuavo4pro.in.cpp
               "${CMAKE_CURRENT_BINARY_DIR}/Kuavo4pro.cpp")

set(module_SRC "${CMAKE_CURRENT_BINARY_DIR}/Kuavo4pro.cpp")

set(module_HDR Kuavo4pro.h)

add_robot(Kuavo4pro "${module_SRC}" "${module_HDR}")
target_include_directories(Kuavo4pro PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
