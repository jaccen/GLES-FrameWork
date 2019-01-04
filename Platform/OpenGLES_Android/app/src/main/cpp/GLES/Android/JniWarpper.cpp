//
// Created by sxh on 2018/6/4.
//

#include <jni.h>
#include "../Common/Renderer.h"

extern "C" {

JNIEXPORT void JNICALL Java_com_sxh_opengles_GLESView_surfaceCreated(JNIEnv *env, jobject obj) {
    surfaceCreated();
}

JNIEXPORT void JNICALL Java_com_sxh_opengles_GLESView_surfaceChanged(JNIEnv *env, jobject obj, jint width, jint height) {
    surfaceChanged(width, height);
}

JNIEXPORT void JNICALL Java_com_sxh_opengles_GLESView_drawFrame(JNIEnv *env, jobject obj) {
    drawFrame();
}

}