/*
 * Camera.h
 *
 *  Created on: May 6, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#ifndef FALCON_GRAPHICS_CAMERA_H_
#define FALCON_GRAPHICS_CAMERA_H_

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

//TODO: getters and setters for forward and up.

namespace FF {
class Camera {
private:
	glm::mat4 perspective;
	glm::vec3 position;
	glm::vec3 forward;
	glm::vec3 up;
public:
	Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar);
	virtual ~Camera();

	inline glm::mat4 getViewProjection() const {
		return perspective *  glm::lookAt(position, position + forward, up);
	}
};
}

#endif /* FALCON_GRAPHICS_CAMERA_H_ */
