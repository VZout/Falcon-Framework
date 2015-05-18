/*
 * GameObject.h
 *
 *  Created on: May 11, 2015
 *      @Author: Viktor Zoutman
 *		@Version: 1.0
 */

#ifndef FALCON_COMMON_GAMEOBJECT_H_
#define FALCON_COMMON_GAMEOBJECT_H_

#include <glm/glm.hpp>
#include <vector>
#include "../Graphics/Mesh.h"
#include "../Graphics/Shader.h"
#include "../Graphics/Texture.h"
#include "Transform.h"

namespace FF {
class GameObject {
private:
	//TODO: maybe add a index property inside mesh shader and texture so the user can specify what gets called first.
	FF::Transform transform;
	std::vector<FF::GameObject*> children;
	std::vector<FF::Mesh*> meshes;
	std::vector<FF::Shader*> shaders;
	std::vector<FF::Texture*> textures;

public:
	GameObject(Transform transform);
	virtual ~GameObject();

	virtual void init() = 0;
	virtual void render() = 0;
	virtual void update() = 0;

	void add(GameObject* child);
	void add(Mesh* mesh);
	void add(Shader* shader);
	void add(Texture* texture);

	void remove(GameObject* child);
	void remove(Mesh* mesh);
	void remove(Shader* shader);
	void remove(Texture* texture);

	void removeChild(unsigned int index);
	void removeMesh(unsigned int index);
	void removeShader(unsigned int index);
	void removeTexture(unsigned int index);

	void setTransform(Transform transform);
	Transform& getTransform();

	std::vector<GameObject*> getChildren();
	std::vector<Mesh*> getMeshes();
	std::vector<Shader*> getShaders();
	std::vector<Texture*> getTextures();
};
}

#endif /* FALCON_COMMON_GAMEOBJECT_H_ */
