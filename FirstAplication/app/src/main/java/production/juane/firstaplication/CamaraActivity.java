package production.juane.firstaplication;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.DialogInterface;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.os.Environment;
import android.provider.MediaStore;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.view.View.OnClickListener;

import java.io.File;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;

/*Camara*/
public class CamaraActivity extends AppCompatActivity  {


    /////****** Atributos ******/////

    private String APP_DIRECTORY = "myPictureApp/";
    private String MEDIA_DIRECTORY = APP_DIRECTORY + "media";
    private String TEMPORAL_PICTURE_NAME = "temporal.jpg";

    private final int PHOTO_CODE = 100;
    private final int SELECT_PICTURE = 200;

    private ImageView imageView;


    /*Atributos


    Button btn;
    ImageView img;
    Intent i;
    Bitmap bmp;
    */
    /*Nuevos atributos
    private final String ruta_fotos = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES)+"/Pictures";
    private File file = new File(ruta_fotos);
    */


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_camara);

        imageView = (ImageView) findViewById(R.id.imagen);
        Button button = (Button) findViewById(R.id.btncaptura);

        button.setOnClickListener(new OnClickListener() {

            @Override
            public void onClick(View v) {
                //Conjunto ordenado de caracteres, opciones que el usuario puede leer
                final CharSequence [] options = {"Tomar foto","Elegir de galeria","Cancelar"};
                final AlertDialog.Builder builder = new AlertDialog.Builder(CamaraActivity.this);
                //Titulo
                builder.setTitle("Elige una opción");
                builder.setItems(options, new DialogInterface.OnClickListener() {

                    @Override
                    public void onClick(DialogInterface dialog, int seleccion) {
                        if(options[seleccion] == "Tomar foto")
                        {
                            openCamara();
                        }

                        else if(options[seleccion]=="Elegir de galeria")
                        {
                            /*Lo que hacemos es que podamos elegir las aplicaciones que utilicen las
                             imagenes*/
                            Intent intent = new Intent(Intent.ACTION_PICK, MediaStore.Images.Media.EXTERNAL_CONTENT_URI);
                            intent.setType("image/*");
                            startActivityForResult(intent.createChooser(intent,"Selecciona app de imagen"),SELECT_PICTURE);
                        }

                        else if(options[seleccion]=="Cancelar")
                        {
                            dialog.dismiss(); //deshacer el dialogo
                        }

                    }
                });
                builder.show(); //Mostramos el cuadro del dialogo
            }
        });
    }

    private void openCamara() {
        File file = new File(Environment.getExternalStorageDirectory(),MEDIA_DIRECTORY);
        file.mkdir(); //Crear

        String path = Environment.getExternalStorageDirectory() +File.separator //almacenar donde se guarda la foto, la ruta
        + MEDIA_DIRECTORY + file.separator + TEMPORAL_PICTURE_NAME;

        File newfile = new File(path);

        Intent intent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
        intent.putExtra(MediaStore.EXTRA_OUTPUT,Uri.fromFile(newfile));
        startActivityForResult(intent,PHOTO_CODE);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        switch (requestCode){
            case PHOTO_CODE:
                if(requestCode == RESULT_OK){
                    String dir = Environment.getDataDirectory() + File.separator
                            + MEDIA_DIRECTORY + File.separator + TEMPORAL_PICTURE_NAME;
                        decodedBitmap(dir);
                }
            break;

            case SELECT_PICTURE:
                if(requestCode == RESULT_OK){
                    Uri path = data.getData();
                    imageView.setImageURI(path);
                }
            break;
        }
    }

    private void decodedBitmap(String dir) {
        Bitmap bitmap;
        bitmap = BitmapFactory.decodeFile(dir);

        imageView.setImageBitmap(bitmap);

    }



}



