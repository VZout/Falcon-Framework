/*
 * Triangle.h
 *
 *  Created on: Apr 4, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#ifndef GRAPHICS_SHAPES_TRIANGLE_H_
#define GRAPHICS_SHAPES_TRIANGLE_H_

#include <glm/detail/type_mat.hpp>
#include <GL/glew.h>
#include <glm/glm.hpp>

class Triangle {
private:
	GLuint vertexbuffer;
	GLuint programID;
	GLuint MatrixID;
	glm::mat4 MVP;

	float x;
	float y;
	float width;
	float height;
public:
	Triangle(float x, float y, float width, float height);
	virtual ~Triangle();

	void render();
};

#endif /* GRAPHICS_SHAPES_TRIANGLE_H_ */
