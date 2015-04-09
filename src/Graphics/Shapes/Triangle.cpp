/*
 * Triangle.cpp
 *
 *  Created on: Apr 4, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#include "Triangle.h"

#include <GL/glew.h>
#include <functional>
#include <glm/glm.hpp>
#include <glm/common.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../../Common/ShaderLoader.h"
#include "../Camera.h"
#include "../../Game.h"

Triangle::Triangle(float x, float y, float width, float height) {

	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	programID = LoadShaders( "SimpleVertexShader.glsl", "SimpleFragmentShader.glsl" );
	MatrixID = glGetUniformLocation(programID, "MVP");

	glm::mat4 Model = glm::mat4(1.0f);
	MVP = Game::camera->projection * Game::camera->view * Model;

	// An array of 3 vectors which represents 3 vertices
	static const GLfloat g_vertex_buffer_data[] = {
	   x + width, y + height, 0.0f,
	   x, y + height, 0.0f,
	   x + width / 2, y, 0.0f,
	};

	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexbuffer);

	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
}

Triangle::~Triangle() {
}

void Triangle::render() {
	glUseProgram(programID);

	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
	   0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
	   3,                  // size
	   GL_FLOAT,           // type
	   GL_FALSE,           // normalized?
	   0,                  // stride
	   (void*)0            // array buffer offset
	);

	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
}

