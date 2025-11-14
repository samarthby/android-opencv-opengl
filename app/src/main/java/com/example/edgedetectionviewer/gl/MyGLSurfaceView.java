package com.example.edgedetectionviewer.gl;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.util.AttributeSet;

public class MyGLSurfaceView extends GLSurfaceView {

    private final MyGLRenderer renderer;

    // Constructor used when inflating from XML
    public MyGLSurfaceView(Context context, AttributeSet attrs) {
        super(context, attrs);

        setEGLContextClientVersion(2);
        renderer = new MyGLRenderer();
        setRenderer(renderer);

        // We only render when new frame is available
        setRenderMode(GLSurfaceView.RENDERMODE_WHEN_DIRTY);
    }

    public MyGLSurfaceView(Context context) {
        this(context, null);
    }

    public MyGLRenderer getRenderer() {
        return renderer;
    }
}
