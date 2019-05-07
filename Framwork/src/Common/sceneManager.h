#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "scene.h"
#include "manager.h"


class SceneManager : public Manager
{
public:
	SceneManager();
	~SceneManager();

	inline std::vector<class Scene*> getScenes() { return m_scenes; }
	inline void setCurrentScene(unsigned int index) { m_currentScene = index; }

	Scene* addScene(const std::string& name);
	void deleteScene(const std::string& name);
	void listScenes();

	Scene* getSceneByName(const std::string& name);
	Scene* getCurrentScene() { return m_scenes[m_currentScene]; }

private:
	unsigned int m_sceneCount;
	unsigned int m_currentScene = 0;
	std::vector<Scene*> m_scenes;
};
