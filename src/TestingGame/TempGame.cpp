/*
 * TempGame.cpp
 *
 *  Created on: Apr 7, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#include "TempGame.h"

#include <GL/glew.h>
#include <iostream>

#include "../Graphics/Camera.h"
#include "../Graphics/Shapes/Cube.h"
#include "../Graphics/Shapes/Rectangle.h"
#include "../Graphics/Shapes/Triangle.h"

Triangle* t;
Rectangle* r;
Cube* c;

void TempGame::init() {
	camera = new Camera(45.f, glm::vec3(4,0,10), false);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	t = new Triangle(0.f, 75.f, 120.f, 75.f);
	r = new Rectangle(15.f, 15.f, 75.f, 75.f, 0.f);
	c = new Cube(4, 4, 4);
}

void TempGame::render() {
	camera->update();
	t->render();
	r->render();
	c->render();
}

void TempGame::update() {
	r->rotation++;
	std::cout << camera->lookAt.x << std::endl;
}
