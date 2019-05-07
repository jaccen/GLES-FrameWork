//
// Created by jaccen on 2018/12/24.
//

#ifndef ENGINE_ARNAVI_APPLICATION_H
#define ENGINE_ARNAVI_APPLICATION_H

#include <iostream>
#ifdef AR_GLFW
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#endif
class App
{
    App(){}
    ~App()  {
        
    }
    
    void init();
};
#endif // ENGINE_ARNAVI_APPLICATION_H
