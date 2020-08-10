package com.gamecodeschool.helloandroid;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class GmailActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
         final Button sendMail;

         super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_gmail);
    sendMail =  findViewById(R.id.send_mail);
    sendMail.setOnClickListener(new View.OnClickListener() {
        @Override
        public void onClick(View v) {

            EditText address= (EditText)findViewById(R.id.email_address);
            EditText subject = (EditText)findViewById(R.id.subject);
            EditText body = (EditText)findViewById(R.id.body);
            String sendAddress = address.getText().toString();
            String sendSubject = subject.getText().toString();
            String sendBody =    body.getText().toString();
            Intent mailIntent = new Intent(Intent.ACTION_SEND);
            mailIntent.setType("text/html");
            mailIntent.putExtra(Intent.EXTRA_EMAIL, new String[] {sendAddress});
            mailIntent.putExtra(Intent.EXTRA_SUBJECT, sendSubject);
            mailIntent.putExtra(Intent.EXTRA_TEXT, sendBody);
            startActivity(Intent.createChooser(mailIntent, "send mail"));
//            sendMailIntent.setData(Uri.parse("mailto:"));
//            sendMailIntent.putExtra(Intent.EXTRA_EMAIL, new String[]{toText.getText().toString()});

        }
    });
    }
}
