/*
 * Mesh.cpp
 *
 *  Created on: Apr 11, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#include "Mesh.h"

#include <GL/glu.h>
#include <GL/gl.h>
#include <cstdlib>
#include <iostream>
#include <GL/glew.h>
#include <stdio.h>

// TODO: I need 2 constructors. 1 for vertices + color and 1 for vertices + texCoords.
	//And in the future another constructor for model + color and model + texCoords.

namespace FF {
Mesh::Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices) {
		IndexedModel model;

		for(unsigned int i = 0; i < numVertices; i++) {
			model.positions.push_back(*vertices[i].GetPos());
			model.texCoords.push_back(*vertices[i].GetTexCoord());
			model.normals.push_back(*vertices[i].GetNormal());
		}

		for (unsigned int i = 0; i < numIndices; i++) {
			model.indices.push_back(indices[i]);
		}

		initMesh(model);
	}

	Mesh::Mesh(const std::string& path) {
		IndexedModel model = OBJModel(path).ToIndexedModel();

		initMesh(model);
	}

	Mesh::~Mesh() {
		glDeleteBuffers(NUM_BUFFERS, vertexArrayBuffers);
		glDeleteVertexArrays(1, &vertexArrayObject);
	}

	void Mesh::initMesh(const IndexedModel& model) {

		numIndices = model.indices.size();
		GLenum ErrorCheckValue = glGetError();

		glGenVertexArrays(1, &vertexArrayObject);
		glBindVertexArray(vertexArrayObject);

		glGenBuffers(NUM_BUFFERS, vertexArrayBuffers);

		//Pos Buffer
		glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[POSITION_VB]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(model.positions[0]) * model.positions.size(), &model.positions[0], GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

		//Texture Buffer
		glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[TEXCOORD_VB]);
	    glBufferData(GL_ARRAY_BUFFER, sizeof(model.texCoords[0]) * model.texCoords.size(), &model.texCoords[0], GL_STATIC_DRAW);
	    glEnableVertexAttribArray(1);
	    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

		ErrorCheckValue = glGetError();
		if(ErrorCheckValue)
			fprintf(stderr, "ERROR: Could not create a VBO: %s \n", gluErrorString(ErrorCheckValue));

		//Normal Buffer
		glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[NORMAL_VB]);
	    glBufferData(GL_ARRAY_BUFFER, sizeof(model.normals[0]) * model.normals.size(), &model.normals[0], GL_STATIC_DRAW);
	    glEnableVertexAttribArray(2);
	    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

		//Index Buffer
	 	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertexArrayBuffers[INDEX_VB]);
	    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(model.indices[0]) * model.indices.size(), &model.indices[0], GL_STATIC_DRAW);
	}

	void Mesh::draw() {
	 	glBindVertexArray(vertexArrayObject);

		glDrawElementsBaseVertex(GL_TRIANGLES, numIndices, GL_UNSIGNED_INT, 0, 0);
		glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);
	}
}
