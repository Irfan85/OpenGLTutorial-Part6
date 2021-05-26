#version 330

layout (location = 0) in vec3 pos;
// As the first stage of the pipeline, vertex shader will receive the texture but will not do anything to 
// it. Instead it will just pass it on to the fragment shader
layout (location = 1) in vec2 tex;

out vec4 vCol;
out vec2 texCoord;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;

void main()
{
	gl_Position = projection * view * model * vec4(pos, 1.0);
	vCol = vec4(clamp(pos, 0.0f, 1.0f), 1.0f);
	texCoord = tex;
}