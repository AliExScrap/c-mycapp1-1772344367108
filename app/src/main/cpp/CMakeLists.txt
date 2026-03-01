cmake_minimum_required(VERSION 3.18.1)
project(capp)
add_library(capp SHARED main.c)
target_link_libraries(capp log android)