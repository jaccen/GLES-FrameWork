#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <functional>

#include "gameLoop.h"

#include "sceneManager.h"
#include "shadermanager.h"


#include "renderer.h"


class Engine
{
public:
    Engine(){}
	Engine(glm::vec2& windowSize);
	~Engine();

	void start();
    void update(float t);
    void render();
	static void update(GameLoop* loop, Engine* self);
	static void render(GameLoop* loop, Engine* self);
	void stop();

	
	inline Renderer* getRenderer() { return m_renderer; }
	
	inline GameLoop* getLoop() { return m_gameLoop; }

	inline SceneManager* getSceneManager() { return m_sceneManager; }
	inline ShaderManager* getShaderManager() { return m_shaderManager; }


private:
	GameLoop* m_gameLoop;

	Renderer* m_renderer;

	SceneManager* m_sceneManager;

	ShaderManager* m_shaderManager;

	glm::vec2 m_windowSize;
};

