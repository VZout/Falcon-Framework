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

	enum AntiAliasing {
		AA_OFF = 0,
		AA_X2 = 2,
		AA_X4 = 4,
		AA_X8 = 8,
		AA_X16 = 16
	};

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
		GLFWwindow* getWindow();
		GLFWmonitor* getMonitor();

		void setAA(AntiAliasing aa);
	};
}

#endif /* DISPLAY_H_ */
