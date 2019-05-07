#pragma once

#include "scene.h"
#include "shaderManager.h"
#include "shader.h"

#include "entityRenderer.h"


class Renderer
{
public:
	Renderer(ShaderManager* shaderManager);
	~Renderer();
	void clear(const glm::vec4& color);
	void render(Scene* scene, double delta);

private:
	EntityRenderer* m_entityRenderer;
};

