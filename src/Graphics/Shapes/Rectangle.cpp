/*
 * Rectangle.cpp
 *
 *  Created on: Apr 5, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#include "Rectangle.h"

#include <GL/glew.h>
#include <functional>
#include <glm/glm.hpp>
#include <glm/common.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../../Common/ShaderLoader.h"
#include "../Camera.h"
#include "../../Game.h"

Rectangle::Rectangle(float x, float y, float width, float height, float rotation) {
	filled = true;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->rotation = rotation;

	updateProjector();
	createShaders();
	createVBO();
}

Rectangle::~Rectangle() {
	// TODO Auto-generated destructor stub
}

void Rectangle::render() {

	cleanup();
	updateProjector();
	createShaders();
	createVBO();

	if(filled)
		glDrawArrays(GL_TRIANGLES, 0, 6);
	else
		glDrawArrays(GL_LINES, 0, 8);
}

void Rectangle::updateProjector() {
	glm::mat4 Model = glm::mat4(1.0f);
	Model = glm::translate(Model, glm::vec3(x + width / 2, y + height / 2, 0.f));
	Model = glm::rotate(Model, rotation, glm::vec3(0, 0, 1.f));
	Model = glm::translate(Model, glm::vec3(-x - width / 2, -y - height / 2, 0.f));

	MVP = Game::camera->projection * Game::camera->view * Model;
}

void Rectangle::createVBO() {
	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);

	// An array of 3 vectors which represents 3 vertices
	if(filled) {
		GLfloat vertices[] = {
		   x + width, y + height, 0.0f,
		   x, y + height, 0.0f,
		   x + width, y, 0.0f,

		   x, y, 0.0f,
		   x + width, y, 0.0f,
		   x, y + height, 0.0f,
		};

		glGenBuffers(1, &vboID);
		glBindBuffer(GL_ARRAY_BUFFER, vboID);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(0);
	} else {
		GLfloat vertices[] = {
		   0, 0, 0.0f,
		   0 + width, 0, 0.0f,

		   0 + width, 0, 0.0f,
		   0 + width, 0 + height, 0.0f,

		   0 + width, 0 + height, 0.0f,
		   0, 0 + height, 0.0f,

		   0, 0 + height, 0.0f,
		   0, 0, 0.0f,
		};

		glGenBuffers(1, &vboID);
		glBindBuffer(GL_ARRAY_BUFFER, vboID);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(0);
	}

	GLfloat colors[] = {
			1.0f, 0.0f, 0.0f, 1.0f,
			0.0f, 1.0f, 0.0f, 1.0f,
			0.0f, 0.0f, 1.0f, 1.0f,
			1.0f, 0.0f, 0.0f, 1.0f,
			0.0f, 0.0f, 1.0f, 1.0f,
			0.0f, 1.0f, 0.0f, 1.0f,
	};

	glGenBuffers(1, &colorBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, colorBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);
}

void Rectangle::destroyVBO() {
	glDisableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &colorBufferID);
	glDeleteBuffers(1, &vboID);

	glBindVertexArray(0);
	glDeleteVertexArrays(1, &vaoID);
}

void Rectangle::createShaders() {
	programID = LoadShaders("SimpleVertexShader.glsl", "SimpleFragmentShader.glsl");
	MatrixID = glGetUniformLocation(programID, "MVP");

	glLinkProgram(programID);
	glUseProgram(programID);
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void Rectangle::destroyShaders() {
	GLenum ErrorCheckValue = glGetError();

	glUseProgram(0);
	glDeleteProgram(programID);

	ErrorCheckValue = glGetError();
	if (ErrorCheckValue != GL_NO_ERROR) {
		fprintf(stderr, "ERROR: Could not destroy the shaders: %s \n",gluErrorString(ErrorCheckValue));
		exit(-1);
	}
}

void Rectangle::cleanup() {
	destroyVBO();
	destroyShaders();
}
