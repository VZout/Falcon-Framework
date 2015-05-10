#include "Camera.h"

namespace FF {

Camera::Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar) {
	this->perspective = glm::perspective(fov, aspect, zNear, zFar);
	this->position = pos;
	this->forward = glm::vec3(0, 0, 1);
	this->up = glm::vec3(0, 1, 0);
}

Camera::~Camera() {

}

}
