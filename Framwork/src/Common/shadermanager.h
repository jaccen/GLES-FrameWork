#pragma once

#include <string>
#include <map>
#include <iostream>
#include <set>
#include <dirent.h>

#include "shader.h"
#include "manager.h"

class ShaderManager : public Manager
{
public:
	ShaderManager();
	~ShaderManager();

	void loadShaders(const std::string& path);
	inline void addShader(const std::string& name, Shader* shader) { m_shaders[name] = shader; }
	inline Shader* getShader(const std::string& name) { return m_shaders[name]; }

private:
	std::map<std::string, Shader*> m_shaders;
	std::set<std::string> m_shadersList;
};

