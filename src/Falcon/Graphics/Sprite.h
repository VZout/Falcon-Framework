/*
 * Sprite.h
 *
 *  Created on: May 31, 2015
 *      Author: bideb
 */

#ifndef FALCON_GRAPHICS_SPRITE_H_
#define FALCON_GRAPHICS_SPRITE_H_

#include <glm/glm.hpp>
#include "../Common/GameObject.h"

namespace FF {
class Sprite: public GameObject {
public:
	Sprite(glm::vec2 pos);
	virtual ~Sprite();

	void init();
	void render();
	void update();
};
}

#endif /* FALCON_GRAPHICS_SPRITE_H_ */
