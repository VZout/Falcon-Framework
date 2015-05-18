/*
 * PointLight.cpp
 *
 *  Created on: May 11, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#include "PointLight.h"

namespace FF {
PointLight::PointLight(glm::vec3 position, glm::vec3 intensities) : GameObject(position) {
	this->intensities = intensities;
}

PointLight::~PointLight() {

}
}

