/*
 * Cube.cpp
 *
 *  Created on: Apr 5, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#include "Cube.h"

#include <iostream>

#include "../../Common/ImageLoader.h"
#include "../../Common/ShaderLoader.h"
#include "../../Game.h"
#include "../Camera.h"

Cube::Cube(float scaleX, float scaleY, float scaleZ) {
	textured = true;

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	if(textured)
		programID = LoadShaders( "SimpleTexturedCubeVertexShader.glsl", "SimpleTexturedCubeFragmentShader.glsl");
	else
		programID = LoadShaders( "SimpleCubeVertexShader.glsl", "SimpleCubeFragmentShader.glsl");

	MatrixID = glGetUniformLocation(programID, "MVP");

	//Load image.
	Texture = loadBMP_custom("uvtemplate.bmp");
	// Get a handle for our "myTextureSampler" uniform (in the .glsl file)
	TextureID  = glGetUniformLocation(programID, "myTextureSampler");

	// Two UV coordinatesfor each vertex. They were created with Blender. You'll learn shortly how to do this yourself.
	static const GLfloat g_uv_buffer_data[] = {
		0.000059f, 1.0f-0.000004f,
		0.000103f, 1.0f-0.336048f,
		0.335973f, 1.0f-0.335903f,
		1.000023f, 1.0f-0.000013f,
		0.667979f, 1.0f-0.335851f,
		0.999958f, 1.0f-0.336064f,
		0.667979f, 1.0f-0.335851f,
		0.336024f, 1.0f-0.671877f,
		0.667969f, 1.0f-0.671889f,
		1.000023f, 1.0f-0.000013f,
		0.668104f, 1.0f-0.000013f,
		0.667979f, 1.0f-0.335851f,
		0.000059f, 1.0f-0.000004f,
		0.335973f, 1.0f-0.335903f,
		0.336098f, 1.0f-0.000071f,
		0.667979f, 1.0f-0.335851f,
		0.335973f, 1.0f-0.335903f,
		0.336024f, 1.0f-0.671877f,
		1.000004f, 1.0f-0.671847f,
		0.999958f, 1.0f-0.336064f,
		0.667979f, 1.0f-0.335851f,
		0.668104f, 1.0f-0.000013f,
		0.335973f, 1.0f-0.335903f,
		0.667979f, 1.0f-0.335851f,
		0.335973f, 1.0f-0.335903f,
		0.668104f, 1.0f-0.000013f,
		0.336098f, 1.0f-0.000071f,
		0.000103f, 1.0f-0.336048f,
		0.000004f, 1.0f-0.671870f,
		0.336024f, 1.0f-0.671877f,
		0.000103f, 1.0f-0.336048f,
		0.336024f, 1.0f-0.671877f,
		0.335973f, 1.0f-0.335903f,
		0.667969f, 1.0f-0.671889f,
		1.000004f, 1.0f-0.671847f,
		0.667979f, 1.0f-0.335851f
	};

	// Our vertices. Tree consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
	// A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
	static const GLfloat g_vertex_buffer_data[] = {
		-scaleX / 2, -scaleY / 2, -scaleZ / 2, // triangle 1 : begin
		-scaleX / 2, -scaleY / 2, scaleZ / 2,
		-scaleX / 2, scaleY / 2, scaleZ / 2, // triangle 1 : end
		scaleX / 2, scaleY / 2,-scaleZ / 2, // triangle 2 : begin
		-scaleX / 2, -scaleY / 2,-scaleZ / 2,
		-scaleX / 2, scaleY / 2,-scaleZ / 2, // triangle 2 : end
		scaleX / 2, -scaleY / 2, scaleZ / 2,
		-scaleX / 2, -scaleY / 2,-scaleZ / 2,
		scaleX / 2, -scaleY / 2,-scaleZ / 2,
		scaleX / 2, scaleY / 2,-scaleZ / 2,
		scaleX / 2, -scaleY / 2,-scaleZ / 2,
		-scaleX / 2, -scaleY / 2,-scaleZ / 2,
		-scaleX / 2, -scaleY / 2,-scaleZ / 2,
		-scaleX / 2, scaleY / 2, scaleZ / 2,
		-scaleX / 2, scaleY / 2,-scaleZ / 2,
		scaleX / 2, -scaleY / 2, scaleZ / 2,
		-scaleX / 2, -scaleY / 2, scaleZ / 2,
		-scaleX / 2, -scaleY / 2,-scaleZ / 2,
		-scaleX / 2, scaleY / 2, scaleZ / 2,
		-scaleX / 2, -scaleY / 2, scaleZ / 2,
		scaleX / 2, -scaleY / 2, scaleZ / 2,
		scaleX / 2, scaleY / 2, scaleZ / 2,
		scaleX / 2, -scaleY / 2,-scaleZ / 2,
		scaleX / 2, scaleY / 2,-scaleZ / 2,
		scaleX / 2, -scaleY / 2,-scaleZ / 2,
		scaleX / 2, scaleY / 2, scaleZ / 2,
		scaleX / 2, -scaleY / 2, scaleZ / 2,
		scaleX / 2, scaleY / 2, scaleZ / 2,
		scaleX / 2, scaleY / 2,-scaleZ / 2,
		-scaleX / 2, scaleY / 2,-scaleZ / 2,
		scaleX / 2, scaleY / 2, scaleZ / 2,
		-scaleX / 2, scaleY / 2,-scaleZ / 2,
		-scaleX / 2, scaleY / 2, scaleZ / 2,
		scaleX / 2, scaleY / 2, scaleZ / 2,
		-scaleX / 2, scaleY / 2, scaleZ / 2,
		scaleX / 2, -scaleY / 2, scaleZ / 2
	};

	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	// The following commands will talk about our 'vertexbuffer' buffer
	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);
}

Cube::~Cube() {
	// TODO Auto-generated destructor stub
}

void Cube::render() {
	glm::mat4 Model = glm::mat4(1.0f);
	MVP = Game::camera->projection * Game::camera->view * Model;

	glUseProgram(programID);

	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

	// Bind our texture in Texture Unit 0
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, Texture);
	// Set our "myTextureSampler" sampler to user Texture Unit 0
	glUniform1i(TextureID, 0);

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

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glVertexAttribPointer(
		1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
		2,                                // size : U+V => 2
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
	);

	glDrawArrays(GL_TRIANGLES, 0, 12*3);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

