
#pragma once

#include "glad/gl.h"

class Graphics
{
public:
    Graphics();
    void Display();

private:
    enum VAO_IDs { Triangles, NumVAOs };
    enum Buffer_IDs { ArrayBuffer, NumBuffers };
    enum Attrib_IDs { vPosition = 0 };

    GLuint  VAOs[NumVAOs];
    GLuint  Buffers[NumBuffers];

    const GLuint    NumVertices { 6 };

};