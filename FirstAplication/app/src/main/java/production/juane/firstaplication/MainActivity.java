package production.juane.firstaplication;

import android.app.Activity;
import android.content.Intent;
//import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.google.android.gms.appindexing.AppIndex;
import com.google.android.gms.common.api.GoogleApiClient;


public class MainActivity extends AppCompatActivity {

    /*Variables*/

   // private GoogleMap googleMap;
   // private MapView mapView;

    //Definimos el boton
    Button ver;
    Button foto;


/*
    public void onClick(View v){
        //Define el campo de texto
        TextView campo_texto = (TextView)findViewById(R.id.button_ver);

        //Define la actividad
        Intent i = new Intent(this,mapa.class);
        i.putExtras(i);

        //Inicia la actividad
        startActivity(i);
    }
*/
    /**
     * ATTENTION: This was auto-generated to implement the App Indexing API.
     * See https://g.co/AppIndexing/AndroidStudio for more information.
     */
    private GoogleApiClient client;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        client = new GoogleApiClient.Builder(this).addApi(AppIndex.API).build();

        ver = (Button)findViewById(R.id.button_ver);
        ver.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent verMaps = new Intent(MainActivity.this,MapsActivity.class);
                startActivity(verMaps);
            }
        });

        this.foto =(Button)findViewById(R.id.btntoma_foto);
        foto.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent tomarFoto = new Intent(MainActivity.this,CamaraActivity.class);
                startActivity(tomarFoto);
            }
        });
    }


}
