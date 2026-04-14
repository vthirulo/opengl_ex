#include "shader_handler.hpp"

#include "SDL3/SDL_log.h"
#include "glad/gl.h"

#include <string>
#include <fstream>

ShaderHandler::ShaderHandler() : program{}, vertex_shader{}, fragment_shader{}, shader_content{}
{

}

void ShaderHandler::CompileShaders()
{
	const GLchar* ptr_to_shader_source{};
	
	ptr_to_shader_source = this->get_shader_source("resources/shader.vert");

	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &ptr_to_shader_source, NULL);
	glCompileShader(vertex_shader);

	this->check_compile_status(vertex_shader);

	ptr_to_shader_source = this->get_shader_source("resources/shader.frag");

	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &ptr_to_shader_source, NULL);
	glCompileShader(fragment_shader);

	if (!this->check_compile_status(fragment_shader)) return;

	program = glCreateProgram();
	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);

	glLinkProgram(program);

	glDeleteShader(fragment_shader);
	glDeleteShader(vertex_shader);

	glUseProgram(program);
}

const GLchar* ShaderHandler::get_shader_source(std::string_view filename)
{

	std::ifstream shader_file{ filename.data() };

	if (shader_file.is_open())
	{
		this->shader_content.clear();
		for (std::string line; std::getline(shader_file, line); shader_content.append("\n"))
		{
			shader_content.append(line);
		}
		
		return shader_content.c_str();
	}
	
	SDL_LogError(SDL_LOG_PRIORITY_ERROR, "%s is not found", filename.data());

	return nullptr;
}

GLboolean ShaderHandler::check_compile_status(GLuint& shader)
{
	GLint success{};
	GLint TotalLenght=0;
	
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &TotalLenght);
	std::string logs;
    logs.resize(TotalLenght);
    glGetShaderInfoLog(shader, TotalLenght, NULL, &logs[0] );

	if (success == GL_FALSE) {
		SDL_Log("Compilation Failed");
		SDL_Log("%s", logs.c_str());
		return GL_FALSE;
	}
	else {
		SDL_Log("Shader Compiled Sucessfully");
		return GL_TRUE;
	}
}