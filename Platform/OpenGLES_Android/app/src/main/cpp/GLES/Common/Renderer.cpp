//
// Created by sxh on 2018/6/4.
//

#include "Renderer.h"
#include "Platform.h"

void surfaceCreated() {
    // 指定刷新颜色缓冲区的颜色
    glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
}

void surfaceChanged(int w, int h) {
    ESLog("viewport: %d, %d", w, h);
    // 设置视口
    glViewport(0, 0, w, h);
}

void drawFrame() {
    // 清除颜色缓冲区
    glClear(GL_COLOR_BUFFER_BIT);
}