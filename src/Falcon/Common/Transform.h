/*
 * Transform.h
 *
 *  Created on: May 5, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#ifndef FALCON_COMMON_TRANSFORM_H_
#define FALCON_COMMON_TRANSFORM_H_

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

namespace FF {
class Transform {
private:
	glm::vec3 pos;
	glm::vec3 rot;
	glm::vec3 scale;
public:
	Transform(const glm::vec3& pos = glm::vec3(),
			const glm::vec3& rot = glm::vec3(),
			const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f))
			: pos(pos),
			  rot(rot),
			  scale(scale) {

	}

	inline glm::mat4 getModel() const {
		glm::mat4 posMatrix = glm::translate(pos);
		glm::mat4 rotXMatrix = glm::rotate(rot.x, glm::vec3(1, 0, 0));
		glm::mat4 rotYMatrix = glm::rotate(rot.y, glm::vec3(0, 1, 0));
		glm::mat4 rotZMatrix = glm::rotate(rot.z, glm::vec3(0, 1, 0));
		glm::mat4 scaleMatrix = glm::scale(scale);

		glm::mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;

		return posMatrix * rotMatrix * scaleMatrix;
	}

	inline glm::vec3& getPos() { return pos; }
	inline glm::vec3& getRot() { return rot; }
	inline glm::vec3& getScale() { return scale; }

	inline void setPos(const glm::vec3& pos) { this->pos = pos; }
	inline void setRot(const glm::vec3& rot) { this->rot = rot; }
	inline void setScale(const glm::vec3 scale) { this->scale = scale; }
};
}
#endif /* FALCON_COMMON_TRANSFORM_H_ */
