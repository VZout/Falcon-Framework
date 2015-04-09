/*
 * Game.h
 *
 *  Created on: Apr 3, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#ifndef GAME_H_
#define GAME_H_

#include <string>

class Display;

class Camera;

class Game {
public:
	Game(int width, int height, const char* title);

	static Display* display;
	static Camera* camera;

	void gameLoop();
	virtual void render() = 0;
	virtual void update() = 0;

	virtual ~Game();
};

#endif /* GAME_H_ */
