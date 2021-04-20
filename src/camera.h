#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
public:
	Camera(int viewportX, int viewportY, int windowWidth, int windowHeight);

	void update();

	void getViewport(int& viewportX, int& viewportY, int& windowWidth, int& windowHeight)
	{
		viewportX = m_viewportX;
		viewportY = m_viewportY;
		windowWidth = m_windowWidth;
		windowHeight = m_windowHeight;
	}

	void setViewport(int viewportX, int viewportY, int windowWidth, int windowHeight)
	{
		m_viewportX = viewportX;
		m_viewportY = viewportY;
		m_windowWidth = windowWidth;
		m_windowHeight = windowHeight;

		m_aspect = (float)windowWidth / (float)windowHeight;
	}

	float getFov()
	{
		return m_fov;
	}

	void setFov(float fov)
	{
		m_fov = fov;
	}

	float getAspect()
	{
		return m_aspect;
	}

	void setAspect(float aspect)
	{
		m_aspect = aspect;
	}

	float getNearClip()
	{
		return m_nearClip;
	}

	void setNearClip(float nearClip)
	{
		m_nearClip = nearClip;
	}

	float getFarClip()
	{
		return m_farClip;
	}

	void setFarClip(float farClip)
	{
		m_farClip = farClip;
	}

	float getYaw()
	{
		return m_yaw;
	}

	void setYaw(float yaw)
	{
		m_yaw = yaw;
	}

	float getPitch()
	{
		return m_pitch;
	}

	void setPitch(float pitch)
	{
		m_pitch = pitch;
	}

	void getYawPitch(float& yaw, float& pitch)
	{
		yaw = m_yaw;
		pitch = m_pitch;
	}

	void setYawPitch(float yaw, float pitch)
	{
		setYaw(yaw);
		setPitch(pitch);
	}

	void addYaw(float add)
	{
		m_yaw += add;
	}

	void addPitch(float add)
	{
		m_pitch += add;
	}

	glm::mat4 getProjectionMatrix()
	{
		return m_projectionMatrix;
	}

	glm::mat4 getViewMatrix()
	{
		return m_viewMatrix;
	}

	glm::mat4 getProjectionViewMatrix()
	{
		return m_projectionMatrix * m_viewMatrix;
	}

	glm::vec3 getPosition()
	{
		return m_cameraPosition;
	}

	void setPosition(glm::vec3 cameraPosition)
	{
		m_cameraPosition = cameraPosition;
	}

	glm::vec3 getDirectionVector()
	{
		return m_cameraDirection;
	}

	glm::vec3 getUp()
	{
		return m_cameraUp;
	}

	void setUp(glm::vec3 up)
	{
		m_cameraUp = up;
	}

private:
	glm::mat4 m_viewMatrix;
	glm::mat4 m_projectionMatrix;

	glm::vec3 m_cameraPosition;
	glm::vec3 m_cameraUp;
	glm::vec3 m_cameraDirection;

	int m_viewportX;
	int m_viewportY;
	int m_windowWidth;
	int m_windowHeight;

	float m_fov;
	float m_aspect;
	float m_nearClip;
	float m_farClip;

	float m_yaw;
	float m_pitch;
};