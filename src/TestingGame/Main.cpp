/*
 * Main.cpp
 *
 *  Created on: Apr 3, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#include "TempGame.h"

using namespace std;

TempGame* game;

int main() {
	game = new TempGame();
	game->create(1024,768,"OpenGL 3 Context");
	return 0;
}
