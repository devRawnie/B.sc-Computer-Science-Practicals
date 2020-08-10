package com.gamecodeschool.helloandroid;

//import android.app.Activity;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Toast;

public class ActivityExample extends AppCompatActivity{

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_example);

                Toast.makeText(this, "Activity is created", Toast.LENGTH_SHORT).show();
                     }

            @Override
            protected void onStart() {
                // TODO Auto-generated method stub
                super.onStart();
                Toast.makeText(this, "Activity is started", Toast.LENGTH_SHORT).show();
                 }

            @Override
            protected void onRestart() {
                // TODO Auto-generated method stub
                super.onRestart();
                Toast.makeText(this, "Activity is Restarted", Toast.LENGTH_SHORT).show();
                }

            @Override
            protected void onResume() {
                // TODO Auto-generated method stub
                super.onResume();
                Toast.makeText(this, "Activity is Resumed", Toast.LENGTH_SHORT).show();
                }

            @Override
            protected void onPause() {
                // TODO Auto-generated method stub
                super.onPause();
                Toast.makeText(this, "Activity is Paused", Toast.LENGTH_SHORT).show();
                }

            @Override
            protected void onStop() {
                // TODO Auto-generated method stub
                super.onStop();
                Toast.makeText(this, "Activity is Stopped", Toast.LENGTH_SHORT).show();
                }

            @Override
            protected void onDestroy() {
                // TODO Auto-generated method stub
                super.onDestroy();
                Toast.makeText(this, "Activity is Destroyed", Toast.LENGTH_SHORT).show();
                }



        }

