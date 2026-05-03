
add_custom_command(TARGET ${CMAKE_PROJECT_NAME} PRE_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different ${CMAKE_SOURCE_DIR}/resources
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE}/resources
	COMMENT "Copying Shaders to the path ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE}"
)

if (NOT WIN32)
add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD VERBATIM
	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_BINARY_DIR}/compile_commands.json
	${CMAKE_SOURCE_DIR}/compile_commands.json 
	COMMENT "Copying compile_commands.json to project's root directory"
)
endif()

# add_dependencies(shader_files ${CMAKE_PROJECT_NAME})
