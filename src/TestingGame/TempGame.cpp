/*
 * TempGame.cpp
 *
 *  Created on: Apr 7, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#include "TempGame.h"

#include <iostream>
#include "../Graphics/Shader.h"
#include "../Graphics/Mesh.h"

Shader* shader;
Mesh* mesh;

TempGame::TempGame() {
}

TempGame::~TempGame() {
}

void TempGame::init() {
	GLfloat vertices[] = {
	    -0.8f, -0.8f, 0.0f, 1.0f,
	    0.0f, 0.8f, 0.0f, 1.0f,
	    0.8f, -0.8f, 0.0f, 1.0f,
	  };

	for(unsigned int i = 0; i < sizeof(vertices); i++) {
			std::cout << "Vertex Data before passed: " << vertices[i] << " out of size: " << sizeof(vertices) << std::endl;
		}

	shader = new Shader("res/basicShader");
	mesh = new Mesh(vertices, 1);
}

void TempGame::render() {
	shader->bind();
	mesh->draw();
}

void TempGame::update() {
}
