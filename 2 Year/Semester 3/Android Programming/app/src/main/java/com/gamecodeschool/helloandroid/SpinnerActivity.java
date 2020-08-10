package com.gamecodeschool.helloandroid;

import android.app.Activity;
import android.media.Image;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.Spinner;
import android.widget.Toast;

public class SpinnerActivity extends AppCompatActivity implements AdapterView.OnItemSelectedListener {
    private ImageView images;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_spinner);
        images = (ImageView) findViewById(R.id.planetsImage);
        Spinner spinner = (Spinner) findViewById(R.id.spinnerEx);
        ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(this, R.array.planets_images, android.R.layout.simple_spinner_item);
        spinner.setAdapter(adapter);
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spinner.setOnItemSelectedListener(this);
    //Before adding the line above, the onItemSelected method was not working
        spinner.setSelection(10);
    }

    @Override
    public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
        if(position<10)
            Toast.makeText(parent.getContext(), "You have selected " + parent.getItemAtPosition(position), Toast.LENGTH_SHORT).show();

        switch(position) {
        case 0: images.setImageResource(R.drawable.solar);
                break;
        case 1: images.setImageResource(R.drawable.sun);
                break;
        case 2: images.setImageResource(R.drawable.mercury);
            break;
        case 3: images.setImageResource(R.drawable.venus);
            break;
        case 4: images.setImageResource(R.drawable.earth);
            break;
        case 5: images.setImageResource(R.drawable.mars);
            break;
        case 6: images.setImageResource(R.drawable.jupiter);
            break;
        case 7: images.setImageResource(R.drawable.saturn);
            break;
        case 8: images.setImageResource(R.drawable.uranus);
            break;
        case 9: images.setImageResource(R.drawable.neptune);
            break;
        case 10:
        default:    images.setImageResource(0);
    }
    }


    @Override
    public void onNothingSelected(AdapterView<?> parent) {

    }
}


