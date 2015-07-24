/*
 * Time.cpp
 *
 *  Created on: May 29, 2015
 *      Author: bideb
 */

#include "Time.h"

#include <GLFW/glfw3.h>
#include <iostream>
#include <stdio.h>

namespace FF {
Time::Time() {
	lastTime = glfwGetTime();
	nbFrames = 0;
	fps = 0;
}

Time::~Time() {
	// TODO Auto-generated destructor stub
}

void Time::update() {
	double currentTime = glfwGetTime();
	nbFrames++;

	if (currentTime >= lastTime + 1) {
		fps = nbFrames;
		nbFrames = 0;
		lastTime = glfwGetTime();
	}
}
}
