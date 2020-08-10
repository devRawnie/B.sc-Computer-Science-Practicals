package com.gamecodeschool.helloandroid;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class ExplicitExample1 extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_explicit_example1);
final Button  button =  findViewById(R.id.send_button_exp1);
button.setOnClickListener(new View.OnClickListener() {
    @Override
    public void onClick(View v) {
        EditText editText = (EditText) findViewById(R.id.edit_text_exp1);
        String content = editText.getText().toString();
        Intent send_msg_exp2 = new Intent(v.getContext(), ExplicitExample2.class);
        send_msg_exp2.putExtra("text", content);
        startActivity(send_msg_exp2);
    }
});


    }



    }




