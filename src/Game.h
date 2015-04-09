/*
 * Game.h
 *
 *  Created on: Apr 3, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#ifndef GAME_H_
#define GAME_H_
class Camera;

class Game {
public:
	Game();
	virtual ~Game();
	void create(int width, int height, const char* title);
	virtual void init();
	virtual void render();
	virtual void update();
	static Camera* camera;
};

#endif /* GAME_H_ */
