
#include "graphics.hpp"
#include "shader_handler.hpp"

#define BUFFER_OFFSET(offset) ((void *)(offset))

Graphics::Graphics()
{
	const GLfloat vertices[] = {
		-0.5f, -0.5, 0.0f,
		0.0f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f
	};

	const GLfloat colors[] = {
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f
	};

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &pVBO);
	glBindBuffer(GL_ARRAY_BUFFER, pVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(attrib::position, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	

	glGenBuffers(1, &cVBO);
	glBindBuffer(GL_ARRAY_BUFFER, cVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

	glVertexAttribPointer(attrib::color, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glEnableVertexAttribArray(attrib::position);
	glEnableVertexAttribArray(attrib::color);

	ShaderHandler s_handler{};

	s_handler.CompileShaders();
}

void Graphics::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBindVertexArray(this->VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}