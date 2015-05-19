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
#include <string>
#include "../Loaders/OBJLoader.h"
//TODO move getters to class.

namespace FF {

struct Vertex
{
public:
	Vertex(const glm::vec3& pos, const glm::vec2& texCoords, const glm::vec3& normal) {
			this->pos = pos;
			this->texCoords = texCoords;
			this->normal = normal;
		}

		glm::vec3* GetPos() { return &pos; }
		glm::vec2* GetTexCoord() { return &texCoords; }
		glm::vec3* GetNormal() { return &normal; }

	private:
		glm::vec3 pos;
		glm::vec2 texCoords;
		glm::vec3 normal;
	};

	enum MeshBufferPositions {
		POSITION_VB,
		TEXCOORD_VB,
		NORMAL_VB,
		INDEX_VB
	};

	class Mesh {
	private:

		static const unsigned int NUM_BUFFERS = 4;

		GLuint vertexArrayObject;
		GLuint vertexArrayBuffers[NUM_BUFFERS];
		unsigned int numIndices;

		void initMesh(const IndexedModel& model);

	public:
		Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);
		Mesh(const std::string& path);
		virtual ~Mesh();

		void draw();
	};
}
#endif /* GRAPHICS_MESH_H_ */
