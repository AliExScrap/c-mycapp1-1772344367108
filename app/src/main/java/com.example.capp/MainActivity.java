package com.example.capp;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;
import android.widget.ScrollView;
import android.graphics.Color;

public class MainActivity extends Activity {
    static { System.loadLibrary("capp"); }
    
    public native String runMain();
    
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        ScrollView scroll = new ScrollView(this);
        TextView tv = new TextView(this);
        tv.setTextColor(Color.WHITE);
        tv.setBackgroundColor(Color.parseColor("#1E1E1E"));
        tv.setPadding(24, 24, 24, 24);
        tv.setTextSize(14);
        tv.setTypeface(android.graphics.Typeface.MONOSPACE);
        
        try {
            String result = runMain();
            tv.setText(result);
        } catch (Exception e) {
            tv.setText("Error: " + e.getMessage());
        }
        scroll.addView(tv);
        setContentView(scroll);
    }
}