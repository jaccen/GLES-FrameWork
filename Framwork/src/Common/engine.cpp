#include "engine.h"


Engine::Engine(glm::vec2& windowSize)
{
	m_windowSize = windowSize;
	
	m_sceneManager = new SceneManager();
	m_shaderManager = new ShaderManager();
    
	m_renderer = new Renderer( m_shaderManager);
	
	//Scene* scene = m_sceneManager->getCurrentScene();
	
}
void Engine::update(float t)
{
    Scene* scene = m_sceneManager->getCurrentScene();
    
    if (scene != nullptr)
    {
        scene->getActiveCamera()->update(t);
        
    }
}
  float i = 0.0;
void Engine::render()
{
    Scene* scene = m_sceneManager->getCurrentScene();
    if (scene != nullptr)
    {
      
        i = i + 0.001;
        if (i > 1.0) {
            i -= 1.0;
        }
        // glClearColor(0.0, 0.0, i, 1.0);
        glm::vec4 color =glm::vec4(i, 0.0, 0.0, 1.0);
        
        scene->setClearColor(color);
        
        m_renderer->clear(scene->getClearColor());
        m_renderer->render(scene, 0.1);
    
    }
}
void Engine::update(GameLoop* loop, Engine* self)
{
    if (false){
		loop->stop();
    }
	Scene* scene = self->m_sceneManager->getCurrentScene();

	if (scene != nullptr)
	{
		scene->getActiveCamera()->update(loop->getFrameTime());
		
	}

}

void Engine::render(GameLoop* loop, Engine* self)
{
    float i = 0.0;
    i = i + 0.1;
    if (i > 1.0) {
        i -= 1.0;
    }
   // glClearColor(0.0, 0.0, i, 1.0);
    glm::vec4 color =glm::vec4(0.0, 0.0, i, 1.0);
	Scene* scene = self->m_sceneManager->getCurrentScene();
    scene->setClearColor(color);
	if (scene != nullptr)
	{
        
		self->m_renderer->clear(scene->getClearColor());
		self->m_renderer->render(scene, loop->getPassedTime());
       // glFlush();
		//self->m_window->swapBuffers();
	}
}

void Engine::start()
{
	//m_gameLoop->start();
}

void Engine::stop()
{
	//m_gameLoop->stop();
}

Engine::~Engine()
{

	delete m_sceneManager;
	delete m_shaderManager;

	delete m_renderer;
	
}
