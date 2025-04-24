cmake_minimum_required(VERSION 3.20)
project(sk8view LANGUAGES C CXX)

set(TARGET_NAME sk8view)

list(APPEND CMAKE_PREFIX_PATH "$ENV{VULKAN_SDK}/cmake")

find_package(Vulkan REQUIRED)
find_package(SDL2 REQUIRED)

# Fetch glm
include(FetchContent)
FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG master
)
FetchContent_MakeAvailable(glm)

add_executable(${TARGET_NAME} 
    src/main.cpp
)

target_link_libraries(${TARGET_NAME} 
Vulkan::Vulkan
glm::glm
SDL2::SDL2
SDL2::SDL2main
)

set_property(TARGET ${TARGET_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${TARGET_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
