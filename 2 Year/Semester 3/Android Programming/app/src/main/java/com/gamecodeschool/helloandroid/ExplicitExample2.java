package com.gamecodeschool.helloandroid;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class ExplicitExample2 extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_explicit_example2);
        TextView textView = findViewById(R.id.text_view_exp2);
        Intent rintent = getIntent();
            String str = rintent.getStringExtra("text");
            textView.setText(str);

    }


}
