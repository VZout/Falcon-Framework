/*
 * Main.cpp
 *
 *  Created on: Apr 3, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#include "TempGame.h"

TempGame* game;

int main() {
	game = new TempGame(1280, 720, "Falcon OpenGL 3.3 Context");
	return 0;
}
