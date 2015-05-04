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

// TODO: I need 2 constructors. 1 for vertices + color and 1 for vertices + texCoords.
	//And in the future another constructor for model + color and model + texCoords.
namespace FF {
	Mesh::Mesh(GLfloat vertices[], GLfloat colors[], GLfloat texCoords[], unsigned int numVertices) {

		drawCount = numVertices / 4;
		GLenum ErrorCheckValue = glGetError();

		glGenVertexArrays(1, &vaoID);
		glBindVertexArray(vaoID);

		//Pos Buffer
		glGenBuffers(NUM_BUFFERS, &vboID);
		glBindBuffer(GL_ARRAY_BUFFER, vboID);
		glBufferData(GL_ARRAY_BUFFER, numVertices, vertices, GL_STATIC_DRAW);
		glVertexAttribPointer(
				0, //0 = layout number
				4,
				GL_FLOAT,
				GL_FALSE,
				0,
				0
		);

		//Color Buffer
		glGenBuffers(NUM_BUFFERS, &cboID);
		glBindBuffer(GL_ARRAY_BUFFER, cboID);
		glBufferData(GL_ARRAY_BUFFER, numVertices, colors, GL_STATIC_DRAW);
		glVertexAttribPointer(
				1, //1 = layout number
				4,
				GL_FLOAT,
				GL_FALSE,
				0,
				0
		);

		//Texture Buffer
		glGenBuffers(NUM_BUFFERS, &cboID);
		glBindBuffer(GL_ARRAY_BUFFER, cboID);
		glBufferData(GL_ARRAY_BUFFER, numVertices, texCoords, GL_STATIC_DRAW);
		glVertexAttribPointer(
				2, //2 = layout number
				2,
				GL_FLOAT,
				GL_FALSE,
				0,
				0
		);

		glEnableVertexAttribArray(0); // 0 = layout number
		glEnableVertexAttribArray(1); // 1 = layout number
		glEnableVertexAttribArray(2); // 2 = layout number

		ErrorCheckValue = glGetError();
		if(ErrorCheckValue)
			fprintf(stderr, "ERROR: Could not create a VBO: %s \n", gluErrorString(ErrorCheckValue));
	}

	Mesh::~Mesh() {
		glDeleteVertexArrays(NUM_BUFFERS, &vaoID);
	}

	void Mesh::draw() {
		glBindVertexArray(vaoID);

		glDrawArrays(GL_TRIANGLES, 0, drawCount); // drawCount = amount of vertices

		glBindVertexArray(0);
		glBindVertexArray(1);
		glBindVertexArray(2);
	}

	void Mesh::setColor(GLfloat colors[], GLfloat numVertices) {
		glGenBuffers(NUM_BUFFERS, &cboID);
		glBindBuffer(GL_ARRAY_BUFFER, cboID);
		glBufferData(GL_ARRAY_BUFFER, numVertices, colors, GL_STATIC_DRAW);
		glVertexAttribPointer(1, //1 = layout number
				4,
				GL_FLOAT,
				GL_FALSE, 0, 0);

		glEnableVertexAttribArray(1); // 1 = layout number
	}
}
