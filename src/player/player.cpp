#include "player.h"

Player::Player(Game* game) : m_game(game)
{
	m_position = glm::vec3(0.0f, 0.0f, 0.0f);
	m_yaw = -90.0f;
	m_pitch = 0.0f;
	m_speed = 2.0f;
}

void Player::handleInput(GLFWwindow* window, float deltaTime)
{
	Camera* camera = m_game->getCamera();

	glm::vec3 cameraDirection = camera->getDirectionVector();
	glm::vec3 moveDirection = glm::normalize(glm::vec3(cameraDirection.x, 0.0f, cameraDirection.z));

	float velocity = m_speed * deltaTime;

	if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		move(moveDirection * velocity);

	if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		move(moveDirection * -velocity);

	if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		move(glm::normalize(glm::cross(moveDirection, camera->getUp())) * -velocity);

	if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		move(glm::normalize(glm::cross(moveDirection, camera->getUp())) * velocity);

	if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		moveY(velocity);

	if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		moveY(-velocity);
}

void Player::handleMouse(double x, double y)
{
	if(m_firstMouse)
	{
		m_lastMouseX = x;
		m_lastMouseY = y;
		m_firstMouse = false;
	}

	float xOffset = x - m_lastMouseX;
	float yOffset = m_lastMouseY - y;

	m_lastMouseX = x;
	m_lastMouseY = y;

	float sensitivity = 0.05f;

	addYaw(xOffset * sensitivity);
	addPitch(yOffset * sensitivity);
}