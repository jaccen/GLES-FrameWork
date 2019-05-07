#include "entityRenderer.h"
#include "scene.h"

EntityRenderer::EntityRenderer(ShaderManager* shaderManager)
{
	m_shaderManager = shaderManager;
	m_basicShader = m_shaderManager->getShader("sleep");
    if(m_basicShader == nullptr)
    {
        m_basicShader = new Shader("");
      
    }
}

void EntityRenderer::render(Scene* scene, double delta)
{

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	m_basicShader->bind();

	std::vector<class Mesh*> meshes = scene->getMeshes();

	for (unsigned int i = 0; i < meshes.size(); ++i)
	{
		Mesh* mesh = meshes[i];
		Material* material = mesh->getMaterial();

		if (material->getBackFaceCulling() == true)
		{
			glCullFace(GL_BACK);
			glEnable(GL_CULL_FACE);
		}

        glBindVertexArrayAPPLE(mesh->getVao());
		mesh->toggleAttributes(true);
		m_basicShader->setUniformMat4fv("mTransform", mesh->getTransform()->getTransformation());
		material->preUpdate(scene);

		if (mesh->isVisible())
			mesh->draw();

		for (unsigned int j = 0; j < mesh->getInstances().size(); ++j)
		{
			if (mesh->getInstances()[j]->isVisible())
			{
				m_basicShader->setUniformMat4fv("mTransform", mesh->getInstances()[j]->getTransform()->getTransformation());
				mesh->getInstances()[j]->draw();
			}
		}

		if (material->getBackFaceCulling() == true)
			glDisable(GL_CULL_FACE);

		mesh->toggleAttributes(false);
		material->postUpdate();
        glBindVertexArrayAPPLE(0);
		
	}

	m_basicShader->unbind();

}

EntityRenderer::~EntityRenderer()
{

}
