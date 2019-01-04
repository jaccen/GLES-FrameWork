package com.sxh.opengles;

import android.content.Context;
import android.opengl.GLSurfaceView;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/**
 * Created by sxh on 2018/6/4.
 */

public class GLESView extends GLSurfaceView implements GLSurfaceView.Renderer {

    public GLESView(Context context) {
        super(context);
        // 设置OpenGL ES版本
        setEGLContextClientVersion(2);
        // 设置渲染模式 RENDERMODE_CONTINUOUSLY RENDERMODE_WHEN_DIRTY
        //setRenderMode(RENDERMODE_WHEN_DIRTY);
        // 设置渲染器
        setRenderer(this);
    }

    @Override
    public void onSurfaceCreated(GL10 gl10, EGLConfig eglConfig) {
        surfaceCreated();
    }

    @Override
    public void onSurfaceChanged(GL10 gl10, int w, int h) {
        surfaceChanged(w, h);
    }

    @Override
    public void onDrawFrame(GL10 gl10) {
        drawFrame();
    }

    static {
        System.loadLibrary("GLES");
    }

    private native void surfaceCreated();
    private native void surfaceChanged(int w, int h);
    private native void drawFrame();
}
