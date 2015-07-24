/*
 * GameObject.cpp
 *
 *  Created on: May 11, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#include "GameObject.h"

#include <algorithm>
#include <iostream>
#include <iterator>

#include "../Game.h"
#include "../Graphics/Camera.h"

namespace FF {

GameObject::GameObject(Transform transform) {
	this->transform = transform;
}

GameObject::~GameObject() {

}

void GameObject::init() {
}

void GameObject::render() {
	for(unsigned int i =0; i < children.size(); i++) {
		children[i]->render();
	}

	for(unsigned int i =0; i < shaders.size(); i++) {
		shaders[i]->bind();
	}

	for(unsigned int i =0; i < textures.size(); i++) {
		textures[i]->bind(0); //TODO: Add a way to let the user select the 0/unit in .bind();
	}

	for(unsigned int i =0; i < meshes.size(); i++) {
		meshes[i]->draw();
	}
}

void GameObject::update() {
	for(unsigned int i =0; i < children.size(); i++) {
		children[i]->update();
	}

	for(unsigned int i =0; i < shaders.size(); i++) {
		shaders[i]->update(transform, Game::camera);
	}
}

void GameObject::add(GameObject* child) {
	child->init();
	children.push_back(child);
}

void GameObject::add(Shader* shader) {
	shaders.push_back(shader);
}

void GameObject::add(Texture* texture) {
	textures.push_back(texture);
}

void GameObject::add(Mesh* mesh) {
	meshes.push_back(mesh);
}

void GameObject::remove(GameObject* child) {
	children.erase(std::remove(children.begin(), children.end(), child), children.end());
}

void GameObject::remove(Mesh* mesh) {
	meshes.erase(std::remove(meshes.begin(), meshes.end(), mesh), meshes.end());
}

void GameObject::remove(Shader* shader) {
	shaders.erase(std::remove(shaders.begin(), shaders.end(), shader), shaders.end());
}

void GameObject::remove(Texture* texture) {
	textures.erase(std::remove(textures.begin(), textures.end(), texture), textures.end());
}

void GameObject::removeChild(unsigned int index) {
	children.erase(children.begin() + (index - 1));
}

void GameObject::removeMesh(unsigned int index) {
	meshes.erase(meshes.begin() + (index - 1));
}

void GameObject::removeShader(unsigned int index) {
	shaders.erase(shaders.begin() + (index - 1));
}

void GameObject::removeTexture(unsigned int index) {
	textures.erase(textures.begin() + (index - 1));
}

void GameObject::setTransform(Transform transform) {
	this->transform = transform;
}

Transform& GameObject::getTransform() {
	return transform;
}

std::vector<GameObject*> GameObject::getChildren() {
	return children;
}

std::vector<Mesh*> GameObject::getMeshes() {
	return meshes;
}

std::vector<Shader*> GameObject::getShaders() {
	return shaders;
}

std::vector<Texture*> GameObject::getTextures() {
	return textures;
}

}
