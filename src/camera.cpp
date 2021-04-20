#include "camera.h"

Camera::Camera(int viewportX, int viewportY, int windowWidth, int windowHeight) : m_viewportX(viewportX), m_viewportY(viewportY), m_windowWidth(windowWidth), m_windowHeight(windowHeight)
{
	m_cameraPosition = glm::vec3(0.0f, 0.0f, 3.0f);
	m_cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	m_fov = glm::radians(45.0f);
	m_aspect = (float)windowWidth / (float)windowHeight;
	m_nearClip = 0.1f;
	m_farClip = 100.0f;

	m_yaw = -90.0f;
	m_pitch = 0.0f;
}

void Camera::update()
{
	m_projectionMatrix = glm::perspective(m_fov, m_aspect, m_nearClip, m_farClip);

	m_cameraDirection.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
	m_cameraDirection.y = sin(glm::radians(m_pitch));
	m_cameraDirection.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
	m_cameraDirection = glm::normalize(m_cameraDirection);

	m_viewMatrix = glm::lookAt(m_cameraPosition, m_cameraPosition + m_cameraDirection, m_cameraUp);
}