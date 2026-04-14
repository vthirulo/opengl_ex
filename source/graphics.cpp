
#include "graphics.hpp"
#include "shader_handler.hpp"

#define BUFFER_OFFSET(offset) ((void *)(offset))

Graphics::Graphics()
{

    const GLfloat vertices[NumVertices][2] = 
    {
        { -0.90, -0.90 },
        {  0.85, -0.90 },
        { -0.90,  0.85 },
        {  0.90, -0.85 },
        {  0.90,  0.90 },
        { -0.85,  0.90 }
    };

    glCreateVertexArrays(NumVAOs, VAOs);
    glCreateBuffers(NumBuffers, Buffers);
    glNamedBufferStorage(
        Buffers[ArrayBuffer],
        sizeof(vertices),
        vertices,
        0
    );

    ShaderHandler shader_H{};

	shader_H.CompileShaders();

    glGenVertexArrays(NumVAOs, VAOs);
    glBindVertexArray(VAOs[Triangles]);
    glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);

    glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(vPosition);
}

void Graphics::Display()
{
    static const float black[] = { 0.0f, 0.0f, 0.0f, 0.0f };

    glClearBufferfv(GL_COLOR, 0, black);

    glBindVertexArray(VAOs[Triangles]);
    glDrawArrays(GL_TRIANGLES, 0, NumVertices);
}