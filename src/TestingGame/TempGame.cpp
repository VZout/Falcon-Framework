/*
 * TempGame.cpp
 *
 *  Created on: Apr 7, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#include "TempGame.h"

#include <iostream>

/*Triangle* t;
Rectangle* r;
Cube* c;*/

TempGame::TempGame(int width, int height, const char* title) : Game(width, height, title) {
}

void TempGame::render() {
	std::cout << "Stuff" << std::endl;
}

void TempGame::update() {
	std::cout << "Stuff" << std::endl;
}

TempGame::~TempGame() {
}
