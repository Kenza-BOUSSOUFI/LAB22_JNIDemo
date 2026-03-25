package com.example.lab22_jnidemo;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    public native String helloFromJNI();
    public native int factorial(int n);
    public native String reverseString(String s);
    public native int sumArray(int[] values);

    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView tvMessage   = findViewById(R.id.tvMessage);
        TextView tvFactoriel = findViewById(R.id.tvFactoriel);
        TextView tvInverse   = findViewById(R.id.tvInverse);
        TextView tvSomme     = findViewById(R.id.tvSomme);

        tvMessage.setText(helloFromJNI());

        int fact7 = factorial(-5);
        if (fact7 >= 0) {
            tvFactoriel.setText("Factoriel de 7 = " + fact7);
        } else {
            tvFactoriel.setText("Erreur factoriel, code = " + fact7);
        }

        String reversed = reverseString("JNI is powerful!");
        tvInverse.setText("Texte inverse : " + reversed);

        int[] numbers = {};
        int sum = sumArray(numbers);
        tvSomme.setText("Somme du tableau = " + sum);
    }
}




























