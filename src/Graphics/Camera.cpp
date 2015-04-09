/*
 * Camera.cpp
 *
 *  Created on: Apr 4, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#include "Camera.h"

#include <glm/gtc/matrix_transform.inl>
#include <iostream>

#include "../Game.h"
#include "Display.h"

Camera::Camera() {
	ortho = false;
	displayRangeMin = 0.1f;
	displayRangeMax = 100.f;
	ratio = 4.f / 3.f;
	this->fov = fov;
	this->viewWidth = Display::WIDTH;
	this->viewHeight = Display::HEIGHT;

	this->position = glm::vec3(4,3,20);
	this->lookAt = glm::vec3(0,0,0);
	rotation = 0;
}

Camera::Camera(float fov, glm::vec3 position, bool ortho) {
	this->ortho = ortho;
	displayRangeMin = -0.1f;
	displayRangeMax = 100.f;
	ratio = 4.f / 3.f;
	this->fov = fov;
	this->viewWidth = Display::WIDTH;
	this->viewHeight = Display::HEIGHT;

	this->position = position;
	this->lookAt = glm::vec3(0,0,0);
	rotation = 0;
}

void Camera::update() {
	if(ortho)
		projection = glm::ortho(0.0f, Game::camera->viewWidth, Game::camera->viewHeight, 0.0f, 1.0f, -1.0f );
	else
		projection = glm::perspective(fov, ratio, 0.1f, 100.f);

	view = glm::lookAt(
			position,
			lookAt,
			glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	);

	projection = glm::rotate(projection, rotation, glm::vec3(position.x, position.y, position.z));;
}
