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

namespace FF {
	class Mesh {
	private:

		enum {
			POSITION_VB, TEXCOORD_VB, NUM_BUFFERS
		};

		GLuint vaoID;
		GLuint vboID;
		GLuint cboID;

		unsigned int drawCount;
	public:
		Mesh(GLfloat vertices[], GLfloat colors[], GLfloat texCoords[], unsigned int numVertices);
		void setColor(GLfloat colors[], GLfloat numVertices);
		virtual ~Mesh();

		void draw();
	};
}
#endif /* GRAPHICS_MESH_H_ */
