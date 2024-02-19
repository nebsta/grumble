cmake_minimum_required(VERSION 3.9.1)
set (CMAKE_CXX_STANDARD 11)
project(grumble)
include_directories(include)

find_package(glm REQUIRED)
find_package(fmt REQUIRED)
find_package(Freetype REQUIRED)

file(GLOB SOURCES "src/**/*.cpp")

add_library(grumble STATIC ${SOURCES})

target_link_libraries(grumble glm::glm)
target_link_libraries(grumble fmt::fmt)
target_link_libraries(grumble ${FREETYPE_LIBRARIES})

target_include_directories(grumble PRIVATE ${FREETYPE_INCLUDE_DIRS})
target_include_directories(grumble PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
