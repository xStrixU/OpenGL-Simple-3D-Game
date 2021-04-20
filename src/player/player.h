#pragma once

#include "../game.h"
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

class Game;

class Player
{
public:
	Player(Game* game);

	void handleInput(GLFWwindow* window, float deltaTime);
	void handleMouse(double x, double y);

	glm::vec3 getPosition()
	{
		return m_position;
	}

	void setPosition(glm::vec3 position)
	{
		m_position = position;
	}

	void move(glm::vec3 add)
	{
		m_position += add;
	}

	void moveX(float x)
	{
		move(glm::vec3(x, 0.0f, 0.0f));
	}

	void moveY(float y)
	{
		move(glm::vec3(0.0f, y, 0.0f));
	}

	void moveZ(float z)
	{
		move(glm::vec3(0.0f, 0.0f, z));
	}

	float getX()
	{
		return m_position.x;
	}

	void setX(float x)
	{
		m_position.x = x;
	}

	float getY()
	{
		return m_position.y;
	}

	void setY(float y)
	{
		m_position.y = y;
	}

	float getZ()
	{
		return m_position.z;
	}

	void setZ(float z)
	{
		m_position.z = z;
	}

	float getSpeed()
	{
		return m_speed;
	}

	void setSpeed(float speed)
	{
		m_speed = speed;
	}

	float getYaw()
	{
		return m_yaw;
	}

	float getPitch()
	{
		return m_pitch;
	}

	void setYaw(float yaw)
	{
		m_yaw = yaw;
	}

	void setPitch(float pitch)
	{
		if(pitch > 89.0f)
			pitch = 89.0f;

		if(pitch < -89.0f)
			pitch = -89.0f;

		m_pitch = pitch;
	}

	void addYaw(float addYaw)
	{
		setYaw(m_yaw + addYaw);
	}

	void addPitch(float addPitch)
	{
		setPitch(m_pitch + addPitch);
	}

private:
	Game* m_game;
	glm::vec3 m_position;
	float m_yaw;
	float m_pitch;
	float m_speed;
	double m_lastMouseX;
	double m_lastMouseY;
	bool m_firstMouse = true;
};