
#include "glad/gl.h"

#include <string>

class ShaderHandler
{
public:
	void CompileShaders();

	ShaderHandler();

private:
	const GLchar* get_shader_source(std::string_view filename);
	GLboolean check_compile_status(GLuint& shader);

private:
	GLuint program;
	GLuint vertex_shader, fragment_shader;

	std::string shader_content;
};