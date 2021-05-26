#version 330

in vec4 vCol;
in vec2 texCoord;

out vec4 colour;

// Since we're dealing with just one texture unit (GL_TEXTURE0), we don't have to define the sampler explicitly 
uniform sampler2D theTexture;

void main()
{
	// Multiplying the color vector will just blend the color with the texture image
	colour = texture(theTexture, texCoord) * vCol;
}