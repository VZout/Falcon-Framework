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
#include <string>
#include <GLFW/glfw3.h>

Display::Display(int width, int height, const char* title, std::function<void()> gameLoop) {
	initGLFW();

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RED_BITS, 8);
	glfwWindowHint(GLFW_GREEN_BITS, 8);
	glfwWindowHint(GLFW_BLUE_BITS, 8);
	glfwWindowHint(GLFW_ALPHA_BITS, 8);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	glfwWindowHint(GLFW_DECORATED, GL_TRUE);

	this->width = width;
	this->height = height;
	this->title = title;
	this->monitor= glfwGetPrimaryMonitor();
	this->mode = glfwGetVideoMode(monitor);

	this->window = glfwCreateWindow(width, height, title, NULL, NULL);
	glfwSetWindowPos(window, mode->width / 2 - this->width / 2, mode->height / 2 - this->height / 2);

	if (window == NULL) {
		std::cerr << "Failed to open GLFW window. Please check if your GPU supports openGL3." << std::endl;
		glfwTerminate();
		std::exit(-1);
	}

	initGLEW();

    while (!glfwWindowShouldClose(window))
    {

    	gameLoop();

        this->update();
    }

    glfwTerminate();
}

void Display::clear(float r, float g, float b, float a) {

}

void Display::update() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Display::initGLFW() {
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW" << std::endl;
		std::exit(-1);
	}
}

void Display::initGLEW() {
	glfwMakeContextCurrent(window);
	glewExperimental = true;
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

Display::~Display() {
	std::cout << "Oops?" << std::endl;
	glfwTerminate();
}