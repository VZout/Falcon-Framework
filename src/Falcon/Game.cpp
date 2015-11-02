/*
 * Game.cpp
 *
 *  Created on: Apr 3, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#include "Game.h"

#include <functional>
#include <iostream>
#include <glm/glm.hpp>

#include "Graphics/Display.h"

/* overall to-do list
 * TODO: Private variables should end with the suffix "_"
 * TODO: All header files should have a .cpp. Yes i am looking at you Transform.h
 * TODO: Rename the namespace FF to ff.
 * TODO: header construction: public protected private
 */

namespace FF {
Display* Game::display = NULL;
Camera Game::camera(glm::vec3(0,0,-4), 70.0f, 720 / 720, 0.01f, 1000.0f);
Time Game::time;

Game::Game() {
	firstFrame = false;
}

Game::~Game() {
}

void Game::start(int width, int height, const char* title) {
	display = new Display(width, height, title,
			std::bind(&Game::gameLoop, this));
}

void Game::gameLoop() {
	if (!firstFrame) {
		firstFrame = true;
		init();
	}

	render();
	update();
}

void Game::init() {
}

void Game::render() {
	for(unsigned int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->render();
	}
}

void Game::update() {
	time.update();

	for(unsigned int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->update();
	}
}

void Game::add(GameObject* gameObject) {
	gameObjects.push_back(gameObject);
	gameObject->init();
}

void Game::remove(unsigned int index) {

}

std::vector<GameObject*> Game::getGameObjects() {
	return gameObjects;
}

}

