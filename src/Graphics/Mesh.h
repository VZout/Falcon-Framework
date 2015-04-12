/*
 * Mesh.h
 *
 *  Created on: Apr 11, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#ifndef GRAPHICS_MESH_H_
#define GRAPHICS_MESH_H_

#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex {
private:
	glm::vec4 pos;
public:
	Vertex(const glm::vec4& pos) {
		this->pos = pos;
	}
};

class Mesh {
private:

	enum {
		POSITION_VB, NUM_BUFFERS
	};

	GLuint vaoID;
	GLuint vboID;
	unsigned int drawCount;
public:
	Mesh(GLfloat vertices[], unsigned int numVertices);
	virtual ~Mesh();

	void draw();
};

#endif /* GRAPHICS_MESH_H_ */
