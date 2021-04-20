#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "camera.h"
#include "render/cube.h"
#include "player/player.h"

class Player;

class Game
{
public:
	Game();

	bool init();
	void loop();

	Camera* getCamera()
	{
		return m_camera;
	}

	void cursorPosCallback(GLFWwindow* window, double x, double y);

public:
	static const int WINDOW_WIDTH = 800;
	static const int WINDOW_HEIGHT = 600;

private:
	void update();
	void render();
	void handleInput();

private:
	GLFWwindow* m_window;
	Cube* m_cube;
	Camera* m_camera;
	Player* m_player;

	float m_deltaTime;
	float m_lastFrame;
};