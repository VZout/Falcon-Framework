/*
 * Display.cpp
 *
 *  Created on: Apr 3, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#include "Display.h"

#include <cstdlib>
#include <iostream>
#include <glm/glm.hpp>
#include <functional>
#include <fstream>

#include "../Common/ShaderLoader.h"

using namespace glm;

int Display::WIDTH = 0;
int Display::HEIGHT = 0;
const char* Display::TITLE = NULL;
GLFWwindow* Display::WINDOW = NULL;
GLFWmonitor* Display::MONITOR = NULL;
const GLFWvidmode* Display::MODE = NULL;

Display::Display() {

}

Display::~Display() {
	// TODO Auto-generated destructor stub
}

void Display::createWindow(int width, int height, const char* title, bool antiAliasing, std::function<void()> initMethod, std::function<void()> renderLoop, std::function<void()> updateLoop) {
	initGLFW();
	if (antiAliasing) {
		glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL

	WIDTH = width;
	HEIGHT = height;
	TITLE = title;
	MONITOR = glfwGetPrimaryMonitor();
	MODE = glfwGetVideoMode(MONITOR);

	WINDOW = glfwCreateWindow(WIDTH, HEIGHT, TITLE, NULL, NULL);
	glfwSetWindowPos(WINDOW, MODE->width / 2 - WIDTH / 2,
			MODE->height / 2 - HEIGHT / 2);

	if (WINDOW == NULL) {
		std::cerr
				<< "Failed to open GLFW window. Please check if your gpu supports openGL3." << std::endl;
		glfwTerminate();
		std::exit(-1);
	}

	initGLEW();

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(WINDOW, GLFW_STICKY_KEYS, GL_TRUE);

	//Game.cpp's Initialization Method.
	initMethod();

	do {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Game.cpp's Render loop.
		renderLoop();
		updateLoop();

		// Swap buffers
		glfwSwapBuffers(WINDOW);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(WINDOW, GLFW_KEY_ESCAPE) != GLFW_PRESS
			&& glfwWindowShouldClose(WINDOW) == 0);
}

void Display::initGLFW() {
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW" << std::endl;
		std::exit(-1);
	}
}

void Display::initGLEW() {
	glfwMakeContextCurrent(WINDOW); // Initialize GLEW
	glewExperimental = true; // Needed in core profile
	if (glewInit() != GLEW_OK) {
		std::cerr << "Failed to initialize GLEW" << std::endl;
		std::exit(-1);
	}

	std::cout << std::endl;
	std::cout << "###########OpenGL Info###########" <<  std::endl;
	std::cout << "OpenGL Version: " << glGetString(GL_VERSION) <<  std::endl;
	std::cout << "OpenGL Vendor: " << glGetString(GL_VENDOR) <<  std::endl;
	std::cout << "Shading Language Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) <<  std::endl;
	std::cout << "#################################" << std::endl;
	std::cout << std::endl;
}
