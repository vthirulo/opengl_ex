
include(FetchContent)

FetchContent_Declare(
    SDL
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-3.2.28
    SOURCE_DIR "${CMAKE_SOURCE_DIR}/vendor/SDL"
)

FetchContent_MakeAvailable(SDL)

add_library(vendor_glad STATIC ${CMAKE_SOURCE_DIR}/vendor/glad/src/gl.c)

target_include_directories(vendor_glad PUBLIC ${CMAKE_SOURCE_DIR}/vendor/glad/include)