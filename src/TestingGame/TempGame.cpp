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

int i = 0;

TempGame::TempGame() {
}

void TempGame::render() {
}

void TempGame::update() {
	i++;
	std::cout << "FrameCount = " << i << std::endl;
}

TempGame::~TempGame() {
}
