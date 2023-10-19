cmake_minimum_required(VERSION 3.0)

project(capstone_detector LANGUAGES C)

add_library(capstone_detector identify.c quirc.c)

target_link_libraries(capstone_detector)
