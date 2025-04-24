cmake_minimum_required(VERSION 3.20)
project(sk8view LANGUAGES C CXX)

set(TARGET_NAME sk8view)

add_executable(${TARGET_NAME} 
    src/main.cpp
)

set_property(TARGET ${TARGET_NAME} PROPERTY CXX_STANDARD 23)
set_property(TARGET ${TARGET_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)