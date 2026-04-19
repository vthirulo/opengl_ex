cmake_minimum_required(VERSION 3.30)

project(opengl_application LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(${CMAKE_PROJECT_NAME})

include(cmake/dependencies.cmake)
include(cmake/copy-resources.cmake)

target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_20)

add_subdirectory(include)
add_subdirectory(source)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE vendor_glad SDL3::SDL3)
