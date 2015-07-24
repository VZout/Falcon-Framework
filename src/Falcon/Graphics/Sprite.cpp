/*
 * Sprite.cpp
 *
 *  Created on: May 31, 2015
 *      Author: bideb
 */

#include <iostream>

#include "Sprite.h"

namespace FF {
Sprite::Sprite(glm::vec2 pos) : GameObject(Transform(glm::vec3(pos.x, pos.y, 0))) {
	// TODO Auto-generated constructor stub
}

Sprite::~Sprite() {
	// TODO Auto-generated destructor stub
}

void Sprite::init() {
	GameObject::init();

	FF::Vertex vertices[] = {
	                    FF::Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(1.0, 0.0), glm::vec3(1,0,0)),
	                    FF::Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0), glm::vec3(0,0.5,0)),
	                    FF::Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 1.0), glm::vec3(1,0,0)),
	};

    unsigned int indices[] = {0,1,2};

	add(new FF::Shader("res/basicTextureShader"));
	add(new FF::Texture("res/texture.png"));
	add(new FF::Mesh(vertices, sizeof(vertices)/sizeof(vertices[0]), indices, sizeof(indices)));
}

void Sprite::render() {
	GameObject::render();
}

void Sprite::update() {
	GameObject::update();
}

}

