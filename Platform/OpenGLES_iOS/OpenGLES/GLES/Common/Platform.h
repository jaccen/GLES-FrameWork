//
// Created by jaccen on 2018/12/4.
//

#ifndef OPENGLES_PLATFORM_H
#define OPENGLES_PLATFORM_H

#define LOG_TAG "GLES"
#define IS_DEBUG 1

#if __ANDROID__

    #include <GLES2/gl2.h>
    //#include <GLES2/gl2ext.h>
    #include <android/log.h>

    #if IS_DEBUG
        #define ESLog(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
    #else
        #define ESLog(...)
    #endif

#elif __APPLE__

    #import <OpenGLES/ES2/gl.h>
    //#import <OpenGLES/ES2/glext.h>
    #import <stdio.h>

    #if IS_DEBUG
        #define ESLog(fmt, ...) printf("%s: ",LOG_TAG);printf((fmt), ##__VA_ARGS__);printf("\n");
    #else
        #define ESLog(fmt, ...)
    #endif

#endif

#endif //OPENGLES_PLATFORM_H
