
#version 450 core

in vec3 color;
out vec4 frag_color;

void main(void) 
{
	frag_color = vec4(color, 0.7f);
}