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

#include "Graphics/Display.h"

Display* Game::display = NULL;

Game::Game() {
}

void Game::start(int width, int height, const char* title) {
	display = new Display(width, height, title, std::bind(&Game::gameLoop, this));
}

Game::~Game() {
}

void Game::gameLoop() {
	render();
	update();
}

void Game::render() {
}

void Game::update() {

}

