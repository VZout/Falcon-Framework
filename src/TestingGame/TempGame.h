/*
 * TempGame.h
 *
 *  Created on: Apr 7, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#ifndef TESTINGGAME_TEMPGAME_H_
#define TESTINGGAME_TEMPGAME_H_

#include "../Game.h"

class TempGame : public Game {
public:
	TempGame(int width, int height, const char* title);
	void render();
	void update();
	~TempGame();
};

#endif /* TESTINGGAME_TEMPGAME_H_ */
