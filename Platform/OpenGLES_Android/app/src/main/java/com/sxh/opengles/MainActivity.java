package com.sxh.opengles;

import android.app.Activity;
import android.os.Bundle;
import android.widget.FrameLayout;


public class MainActivity extends Activity {

    private FrameLayout frameLayout;
    private GLESView glesView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        frameLayout = findViewById(R.id.frameLayout);

        glesView = new GLESView(this);
        frameLayout.addView(glesView);
    }

}
