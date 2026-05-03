
#pragma once

#include "glad/gl.h"

class Graphics
{
public:
    Graphics();
    void Display();

private:
    GLuint VAO;

    GLuint pVBO, cVBO;
    
    enum attrib : GLuint
    {
        position = 0, color
    };

};