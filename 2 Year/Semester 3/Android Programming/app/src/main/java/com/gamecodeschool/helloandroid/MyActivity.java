package com.gamecodeschool.helloandroid;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
//import android.view.Window;

public class MyActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
       // requestWindowFeature(Window.FEATURE_NO_TITLE);
        setContentView(R.layout.my_layout);
        //displays a simple hello world in the center of the screen
    }
}