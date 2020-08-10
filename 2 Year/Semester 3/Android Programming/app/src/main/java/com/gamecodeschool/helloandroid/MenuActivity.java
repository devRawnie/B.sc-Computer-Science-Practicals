package com.gamecodeschool.helloandroid;

import android.content.Intent;
import android.net.Uri;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.widget.TextView;

public class MenuActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {

        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.first_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId())
        {
            case R.id.dial_number:
                Intent dialNumber = new Intent(Intent.ACTION_DIAL);
                startActivity(dialNumber);
                break;
            case R.id.browse_web:
                Uri webPage = Uri.parse("https://developer.android.com/");
                Intent browseWeb = new Intent(Intent.ACTION_VIEW, webPage);
                startActivity(browseWeb);
                break;
            case R.id.about_us_menu:
                TextView tv = (TextView) findViewById(R.id.textViewInMenu);
                tv.setText(R.string.about_us);
                break;
        }
    return true;
    }
}
