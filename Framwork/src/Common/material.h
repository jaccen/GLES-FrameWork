#pragma once

#include <string>
#include <vector>

#include "shader.h"

class Scene;
class Material
{
public:
	Material(const std::string& name, Shader* shader) : m_name(name), m_shader(shader), m_backFaceCulling(true) {}
	virtual ~Material() {}

	virtual inline const std::string& getName() { return m_name; }
	virtual inline void setName(const std::string& name) { m_name = name; }

	virtual inline Shader* getShader() { return m_shader; }
	virtual inline void setShader(Shader* shader) { m_shader = shader; }

	virtual inline void updateTransform(Transform* transform) {}
	virtual inline void updateUniforms(Camera* camera) {}

	virtual inline void preUpdate(Scene* scene) {}
	virtual inline void postUpdate() {}

	virtual inline void setBackFaceCulling(bool value) { m_backFaceCulling = value; }
	virtual inline bool& getBackFaceCulling() { return m_backFaceCulling; }

	virtual inline void setTiling(glm::vec2& tiling) { m_tiling = tiling; }
	virtual inline glm::vec2& getTiling() { return m_tiling; }

	virtual inline void bindAttributes() {}

private:
	std::string m_name;
	Shader* m_shader;

	bool m_backFaceCulling;
	glm::vec2 m_tiling;
};
