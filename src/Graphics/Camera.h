/*
 * Camera.h
 *
 *  Created on: Apr 4, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#ifndef GRAPHICS_CAMERA_H_
#define GRAPHICS_CAMERA_H_

#include <glm/glm.hpp>

class Camera {
public:
	Camera();
	Camera(float fov, glm::vec3 position, bool ortho);
	void update();
	glm::mat4 projection;
	glm::mat4 view;

	glm::vec3 position;
	glm::vec3 lookAt;
	float rotation;

	bool ortho;
	float fov;
	float ratio;
	float displayRangeMin;
	float displayRangeMax;
	float viewWidth;
	float viewHeight;
};

#endif /* GRAPHICS_CAMERA_H_ */
