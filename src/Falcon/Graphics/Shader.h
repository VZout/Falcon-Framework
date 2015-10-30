/*
 * Shader.h
 *
 *  Created on: Apr 11, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#ifndef GRAPHICS_SHADER_H_
#define GRAPHICS_SHADER_H_

#include <GL/glew.h>
#include <string>
#include "Camera.h"

#include "../Common/Transform.h"

namespace FF {
	class Shader {
	private:
		static const unsigned int NUM_SHADERS = 2;
		static const unsigned int NUM_UNIFORMS = 3;

		GLuint shaders[NUM_SHADERS];
		GLuint uniforms[NUM_UNIFORMS];

		GLuint createShader(const std::string& text, GLenum shaderType);
		std::string loadShader(const std::string& fileName);
		void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);

	public:
		Shader(const std::string& fileName);
		virtual ~Shader();

		GLuint program; // Should be private. Temporary not due to Text2D.h
		void bind();
		void update(const Transform& transform, const Camera& camera);
	};
}

#endif /* GRAPHICS_SHADER_H_ */
