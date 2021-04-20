#include "game.h"

#include <iostream>

Game::Game()
{
	
}

bool Game::init()
{
	if(!glfwInit())
	{
		std::cout << "Failed to initialize GLFW!" << std::endl;
		return false;
	}

	m_window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "OpenGL Template", nullptr, nullptr);

	if(!m_window)
	{
		std::cout << "Failed to create GLFW window!" << std::endl;
		glfwTerminate();
		return false;
	}
	
	glfwMakeContextCurrent(m_window);
	glfwSetWindowUserPointer(m_window, this);
	glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	auto cursorPosCallback = [](GLFWwindow* window, double x, double y) {
		auto me = (Game*)glfwGetWindowUserPointer(window);
		me->cursorPosCallback(window, x, y);
	};

	glfwSetCursorPosCallback(m_window, cursorPosCallback);

	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD!" << std::endl;
		return false;
	}

	m_cube = new Cube();
	m_camera = new Camera(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	m_player = new Player(this);
	m_player->setPosition(glm::vec3(0.0f, 0.0f, 3.0f));

	return true;
}

void Game::loop()
{
	glEnable(GL_DEPTH_TEST);

	while(!glfwWindowShouldClose(m_window))
	{
		handleInput();

		update();
		render();

		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}

	glfwTerminate();
}

void Game::handleInput()
{
	m_player->handleInput(m_window, m_deltaTime);
}

void Game::update()
{
	float currentTime = glfwGetTime();
	m_deltaTime = currentTime - m_lastFrame;
	m_lastFrame = currentTime;

	m_camera->setPosition(m_player->getPosition());
	m_camera->setYawPitch(m_player->getYaw(), m_player->getPitch());
	m_camera->update();
}

void Game::render()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m_cube->render(*m_camera);
}

void Game::cursorPosCallback(GLFWwindow* window, double x, double y)
{
	m_player->handleMouse(x, y);
}