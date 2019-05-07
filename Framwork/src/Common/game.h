#pragma once

#include <iostream>
#include <algorithm>  


#include "engine.h"
#include "shader.h"
#include "mesh.h"
#include "basicMaterial.h"
#include "light.h"
#include "camera.h"

class Game
{ 
public:
	Game(Engine* engine);
	~Game();


	void update(double delta);
    void init();
private:
	Engine* m_engine;
	float m_angle;
	Light* m_light;
	Light* m_lightS;
	Light* m_lightR;
	
	Scene* m_scene;
    Camera* m_camera;
	Mesh* m_dread;

};
