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
	static void initGLFW();
	static void initGLEW();
public:
	static void createWindow(int width, int height, const char* title, bool antiAliasing, std::function<void()> initMethod, std::function<void()> renderLoop, std::function<void()> updateLoop);
	static GLFWwindow* WINDOW;
	static GLFWmonitor* MONITOR;
	static const GLFWvidmode* MODE;
	static int WIDTH;
	static int HEIGHT;
	static const char* TITLE;

	Display();
	virtual ~Display();
};

#endif /* DISPLAY_H_ */
