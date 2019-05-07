//
// Created by jaccen on 2018/12/26.
//

#ifndef ENGINE_ARNAVI_CONFIGURE_H
#define ENGINE_ARNAVI_CONFIGURE_H

#define AR_ON 1
#define AR_OFF 0
//
#define ENABLE_GLM AR_ON
//
#define ENABLE_GLTF AR_ON
//
#define ENABLE_GUI AR_OFF
//
#define ENABLE_GLES2 AR_ON
//#if ENABLE_GLES2
//#define GLES2
//#endif

#define AR_OSX
//#define AR_ANDROID
//
#if defined(AR_ANDROID)

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <GLES2/gl2platform.h>

// sdk low than android5.0 without it
#ifndef GL_EXT_color_buffer_half_float
#define GL_EXT_color_buffer_half_float 1
#define GL_RGBA16F_EXT 0x881A
#define GL_RGB16F_EXT 0x881B
#endif /* GL_EXT_color_buffer_half_float */
#include <android/log.h>

#elif defined(AR_IOS)
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

#elif defined(AR_OSX)

#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glext.h>
//#include <glad/glad.h>

#elif defined(AR_LINUX)
#include <GL/glut.h>
// OpenGL32库的头文件
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "opengl32.lib") // OpenGL32连接库
#pragma comment(lib, "glew32.lib")   // GLu32连接库

#elif defined(AR_WIN32)

#else

#endif
//

#endif //MAPAUTO_SDK_CONFIGURE_H
