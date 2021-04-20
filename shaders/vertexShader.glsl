#version 330 core  

layout (location = 0) in vec3 position;

out vec3 posColor;

uniform mat4 modelMatrix;
uniform mat4 projectionViewMatrix;

void main()  
{  
    gl_Position = projectionViewMatrix * modelMatrix * vec4(position, 1.0f);
    posColor = position;
}