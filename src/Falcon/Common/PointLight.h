/*
 * PointLight.h
 *
 *  Created on: May 11, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#ifndef FALCON_COMMON_POINTLIGHT_H_
#define FALCON_COMMON_POINTLIGHT_H_

#include "GameObject.h"
#include <glm/glm.hpp>

namespace FF {
class PointLight : GameObject {
private:
	glm::vec3 intensities;
public:
	PointLight(glm::vec3 position, glm::vec3 intensities);
	virtual ~PointLight();

	glm::vec3 getPosition();
	glm::vec3 getIntensity();
};
}

#endif /* FALCON_COMMON_POINTLIGHT_H_ */
