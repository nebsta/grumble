cmake_minimum_required(VERSION 3.9.1)
set (CMAKE_CXX_STANDARD 17)
project(grumble)
include_directories(include)

find_package(glm REQUIRED)
find_package(fmt REQUIRED)
find_package(Freetype REQUIRED)
find_package(nlohmann_json REQUIRED)

file(GLOB SOURCES "src/**/*.cpp")

add_library(grumble STATIC ${SOURCES})
target_link_libraries(grumble glm::glm)
target_link_libraries(grumble fmt::fmt)
target_link_libraries(grumble ${freetype_LIBRARIES})
target_link_libraries(grumble nlohmann_json::nlohmann_json)

target_include_directories(grumble PRIVATE ${freetype_INCLUDE_DIRS})
target_include_directories(grumble PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
