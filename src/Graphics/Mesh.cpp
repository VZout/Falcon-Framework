/*
 * Mesh.cpp
 *
 *  Created on: Apr 11, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#include "Mesh.h"

#include <GL/glu.h>
#include <cstdlib>
#include <iostream>
#include <GL/glew.h>

Mesh::Mesh(GLfloat vertices[], unsigned int numVertices) {
	drawCount = numVertices;

	for(unsigned int i = 0; i < sizeof(vertices); i++) {
		std::cout << "Vertex Data after passed trough constructor: " << vertices[i] << " out of size: " << sizeof(vertices) << std::endl;
	}

	GLenum ErrorCheckValue = glGetError();

	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);

	glGenBuffers(NUM_BUFFERS, &vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(
			0, //0 = layout number
			4,
			GL_FLOAT,
			GL_FALSE,
			0,
			0
	);
	glEnableVertexAttribArray(0); // 0 = layout number

	glBindVertexArray(0); // 0 = layout number

	ErrorCheckValue = glGetError();
	fprintf(
	stderr, "ERROR: Could not create a VBO: %s \n",
			gluErrorString(ErrorCheckValue));
}

Mesh::~Mesh() {
	glDeleteVertexArrays(NUM_BUFFERS, &vaoID);
}

void Mesh::draw() {
	glBindVertexArray(vaoID);

	glDrawArrays(GL_TRIANGLES, 0, drawCount); // drawCount = amount of vertices

	glBindVertexArray(0); // 0 = layout number
}
