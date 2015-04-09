/*
 * Game.cpp
 *
 *  Created on: Apr 3, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#include "Game.h"

#include <GL/glew.h>
#include <functional>

#include "Graphics/Camera.h"
#include "Graphics/Display.h"

Camera* Game::camera = new Camera();

Game::Game() {
	// TODO Auto-generated constructor stub
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

void Game::create(int width, int height, const char* title) {
	Display::createWindow(width, height, title, true, std::bind(&Game::init, this), std::bind(&Game::render, this), std::bind(&Game::update, this));
}

void Game::init() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Game::render() {

}

void Game::update() {

}

