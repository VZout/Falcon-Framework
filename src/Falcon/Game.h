/*
 * Game.h
 *
 *  Created on: Apr 3, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#ifndef GAME_H_
#define GAME_H_


#include "Graphics/Display.h"

namespace FF {
	class Game {
	private:
		bool firstFrame;
	public:
		Game();
		virtual ~Game();

		void start(int width, int height, const char* title);

		static Display* display;

		void gameLoop();
		virtual void init() = 0;
		virtual void render() = 0;
		virtual void update() = 0;
	};
}

#endif /* GAME_H_ */
