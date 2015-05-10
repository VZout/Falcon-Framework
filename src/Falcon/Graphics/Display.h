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
#include <string>

#include "Camera.h"

struct GLFWmonitor;
struct GLFWvidmode;
struct GLFWwindow;

//TODO: Add the last getters and setters.
//TODO: Add get aspect ratop getter and setter.

namespace FF {
	class Display {
	private:
		int width;
		int height;
		GLFWwindow* window;
		GLFWmonitor* monitor;
		const GLFWvidmode* mode;
		const char* title;

		void initGLFW();
		void initGLEW();
		std::string getOSName();

	public:
		Display(int width, int height, const char* title, std::function<void()> gameLoop);
		virtual ~Display();

		int& getWidth();
		int& getHeight();
	};
}

#endif /* DISPLAY_H_ */
