/*
 * Texture.h
 *
 *  Created on: Apr 22, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#ifndef FALCON_GRAPHICS_TEXTURE_H_
#define FALCON_GRAPHICS_TEXTURE_H_

#include "GL/glew.h"

namespace FF {
class Texture {
private:
	GLuint texture;
	int width;
	int height;
public:
	Texture(const char* fileName);
	virtual ~Texture();

	void bind(unsigned int unit);

	int getWidth();
	int getHeight();
};
}

#endif /* FALCON_GRAPHICS_TEXTURE_H_ */
