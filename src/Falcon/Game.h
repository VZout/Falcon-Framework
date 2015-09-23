/*
 * Game.h
 *
 *  Created on: Apr 3, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#ifndef GAME_H_
#define GAME_H_
#include <vector>
#include "Graphics/Display.h"
#include "Common/GameObject.h"
#include "Graphics/Camera.h"

namespace FF {
	class Game {
	private:
		bool firstFrame;
		std::vector<GameObject*> gameObjects;

	public:
		Game();
		virtual ~Game();

		static Display* display;
		static Camera camera;

		void start(int width, int height, const char* title);

		void gameLoop();
		virtual void init() = 0;
		virtual void render() = 0;
		virtual void update() = 0;

		void add(GameObject* gameObject);
		void remove(unsigned int index);
		std::vector<GameObject*> getGameObjects();
	};
}

#endif /* GAME_H_ */
