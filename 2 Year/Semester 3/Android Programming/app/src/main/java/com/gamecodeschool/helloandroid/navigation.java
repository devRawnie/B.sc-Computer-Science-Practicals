package com.gamecodeschool.helloandroid;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class navigation extends AppCompatActivity {

     Intent intent;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_navigation);
    }

    public void openActivityLifecycle(View view) {
    intent = new Intent(view.getContext(), ActivityExample.class);
    startActivity(intent);
    }

    public void openHelloWorld(View view) {
        intent = new Intent(view.getContext(), MyActivity.class);
        startActivity(intent);
    }

    public void openExplicitIntent(View view) {
        intent = new Intent(view.getContext(), ExplicitExample1.class);
        startActivity(intent);
    }

    public void openEmailActivity(View view) {
        intent = new Intent(view.getContext(), GmailActivity.class);
        startActivity(intent);
    }

    public void openSpinnerExample(View view) {
        intent = new Intent(view.getContext(), SpinnerActivity.class);
        startActivity(intent);
    }

    public void openMenuExample(View view) {
        intent = new Intent(view.getContext(), MenuActivity.class);
        startActivity(intent);
    }
}
