
target_sources(${CMAKE_PROJECT_NAME}
    PRIVATE
    FILE_SET HEADERS
    BASE_DIRS "${CMAKE_SOURCE_DIR}/include"
    FILES
        "${CMAKE_SOURCE_DIR}/include/window.hpp"
        "${CMAKE_SOURCE_DIR}/include/graphics.hpp"
        "${CMAKE_SOURCE_DIR}/include/shader_handler.hpp"
)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC )
