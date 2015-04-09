/*
 * loadShader.h
 *
 *  Created on: Apr 3, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#ifndef COMMON_SHADERLOADER_H_
#define COMMON_SHADERLOADER_H_

#include <GL/glew.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);

#endif /* COMMON_SHADERLOADER_H_ */
