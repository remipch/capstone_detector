cmake_minimum_required(VERSION 3.0)

project(capstone_detector LANGUAGES C)

add_library(capstone_detector identify.c quirc.c)

include_directories(.)

target_link_libraries(capstone_detector m)

add_executable(capstone_detector_test test/capstone_detector_test.c)

target_link_libraries(capstone_detector_test capstone_detector)
