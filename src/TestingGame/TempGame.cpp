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

Vertex vertices[] = {
		Vertex(glm::vec3(-0.5, -0.5, 0)),
		Vertex(glm::vec3(0, 0.5, 0)),
		Vertex(glm::vec3(0.5, -0.5, 0)),
};

Shader* shader;
Mesh* mesh;

TempGame::TempGame() {
}

TempGame::~TempGame() {
}

void TempGame::init() {
	shader = new Shader("res/basicShader");
	mesh = new Mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
}

void TempGame::render() {
	shader->bind();
	mesh->draw();
}

void TempGame::update() {
}
