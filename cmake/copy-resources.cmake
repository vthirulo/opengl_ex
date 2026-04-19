
add_custom_target(shader_files ALL
	COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different ${CMAKE_SOURCE_DIR}/resources
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE}/resources
	COMMENT "Copying Shaders to the path ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE}" VERBATIM
)

add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD VERBATIM
	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_BINARY_DIR}/compile_commands.json
	${CMAKE_SOURCE_DIR}/compile_commands.json 
)

add_dependencies(shader_files ${CMAKE_PROJECT_NAME})
