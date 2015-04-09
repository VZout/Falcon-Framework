/*
 * Display.h
 *
 *  Created on: Apr 3, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <functional>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Display {
private:
	void initGLFW();
	void initGLEW();
public:
	Display(int width, int height, const char* title, std::function<void()> gameLoop);

	GLFWwindow* window;
	GLFWmonitor* monitor;
	const GLFWvidmode* mode;
	int width;
	int height;
	const char* title;

	void clear(float r, float g, float b, float a);
	void update();

	virtual ~Display();
};

#endif /* DISPLAY_H_ */
