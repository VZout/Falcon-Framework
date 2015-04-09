/*
 * Cube.h
 *
 *  Created on: Apr 5, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#ifndef GRAPHICS_SHAPES_CUBE_H_
#define GRAPHICS_SHAPES_CUBE_H_

#include <glm/detail/type_mat.hpp>
#include <GL/glew.h>
#include <glm/glm.hpp>

class Cube {
private:
	bool textured;
	GLuint vertexbuffer;
	GLuint Texture;
	GLuint TextureID;
	GLuint uvbuffer;
	GLuint programID;
	GLuint MatrixID;
	glm::mat4 MVP;
public:
	Cube(float scaleX, float scaleY, float scaleZ);
	virtual ~Cube();
	void render();
};

#endif /* GRAPHICS_SHAPES_CUBE_H_ */
