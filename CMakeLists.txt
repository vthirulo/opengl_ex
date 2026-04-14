cmake_minimum_required(VERSION 3.23)

project(opengl_application LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include(cmake/dependencies.cmake)

add_executable(${CMAKE_PROJECT_NAME})

target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_20)

add_subdirectory(include)
add_subdirectory(source)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE vendor_glad SDL3::SDL3)
