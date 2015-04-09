/*
 * Rectangle.h
 *
 *  Created on: Apr 5, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#ifndef GRAPHICS_SHAPES_RECTANGLE_H_
#define GRAPHICS_SHAPES_RECTANGLE_H_

#include <glm/detail/type_mat.hpp>
#include <GL/glew.h>
#include <glm/glm.hpp>

class Rectangle {
private:
	bool filled;

	GLuint vaoID;
	GLuint vboID;
	GLuint colorBufferID;
	GLuint programID;
	GLuint MatrixID;
	glm::mat4 MVP;

	void cleanup();
	void updateProjector();
	void createVBO();
	void destroyVBO();
	void createShaders();
	void destroyShaders();
public:
	float x;
	float y;
	float width;
	float height;
	float rotation;
	Rectangle(float x, float y, float width, float height, float rotation);
	virtual ~Rectangle();

	void render();
};

#endif /* GRAPHICS_SHAPES_RECTANGLE_H_ */
