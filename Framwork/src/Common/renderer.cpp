#include "renderer.h"

Renderer::Renderer( ShaderManager* shaderManager)
{

	m_entityRenderer = new EntityRenderer(shaderManager);

	glEnable(GL_MULTISAMPLE);
}

void Renderer::clear(const glm::vec4& color)
{
	glClearColor(color.r, color.g, color.b, color.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

void Renderer::render(Scene* scene, double delta)
{
	glViewport(0, 0, (GLsizei)1920, 1080);

   m_entityRenderer->render(scene, delta);
}

Renderer::~Renderer()
{
	delete m_entityRenderer;
}
