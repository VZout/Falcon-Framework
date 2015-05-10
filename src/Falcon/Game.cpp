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


/* overall to-do list
 * TODO: Private variables should end with the suffix "_"
 * TODO: All header files should have a .cpp. Yes i am looking at you Transform.h
 * TODO: Rename the namespace FF to ff.
 * TODO: header construction: public protected private
 */

namespace FF {
	Display* Game::display = NULL;

	Game::Game() {
		firstFrame = false;
	}

	Game::~Game() {
	}

	void Game::start(int width, int height, const char* title) {
		display = new Display(width, height, title, std::bind(&Game::gameLoop, this));
	}

	void Game::gameLoop() {
		if(!firstFrame) {
			firstFrame = true;
			init();
		}

		render();
		update();
	}

	void Game::init() {
	}

	void Game::render() {
	}

	void Game::update() {
	}
}

