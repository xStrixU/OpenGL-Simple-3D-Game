#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include "../shader/shader.h"
#include "../camera.h"

class Cube
{
public:
	Cube();

	void render(Camera& camera);

private:
	GLuint m_VAO, m_VBO;
	Shader* m_shader;
	glm::mat4 m_modelMatrix;
};