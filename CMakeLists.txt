cmake_minimum_required(VERSION 3.9.1)
project(grumble)
include_directories(include)

find_package(glm)
file(GLOB SOURCES "src/**/*.cpp")

add_library(grumble STATIC ${SOURCES})
target_link_libraries(grumble glm::glm)
target_include_directories(grumble PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
