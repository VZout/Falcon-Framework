/*
 * Mesh.cpp
 *
 *  Created on: Apr 11, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#include "Mesh.h"

Mesh::Mesh(Vertex* vertices, unsigned int numVertices) {
	drawCount = numVertices;

	glGenVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);

	glGenBuffers(NUM_BUFFERS, vertexArrayBuffers);
	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0); // 0 = layout number
	glVertexAttribPointer(
			0, //0 = layout number
			3,
			GL_FLOAT,
			GL_FALSE,
			0,
			(void*)0
	);

	glBindVertexArray(0); // 0 = layout number
}

Mesh::~Mesh() {
	glDeleteVertexArrays(1, &vertexArrayObject);
}

void Mesh::draw() {
	glBindVertexArray(vertexArrayObject);

	glDrawArrays(GL_TRIANGLES, 0, drawCount); // drawCount = amount of vertices

	glBindVertexArray(0); // 0 = layout number
}
