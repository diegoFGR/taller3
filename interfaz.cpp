/*
 * Nombre: Problema4 - Taller 3
 * Descripción: Generar una conversación apartir de un archivo y respuestas digitadas por el usuario
 * Nombre: Diego F. González Rojas
 * Codigo: 1667522
 * Fecha de Creacion: 01-06-2017
 * Fecha de Ult de modificacion: 08-06-2017
 *
*/

#include "interfaz.h"
#include "ui_interfaz.h"



interfaz::interfaz(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::interfaz)
{
    ui->setupUi(this);
}

interfaz::~interfaz()
{
    delete ui;
}

void interfaz::on_archivo_clicked() //ESTE METODO ES LA QUE PIDE EL ARCHIVO TXT Y COGE PALABRA POR PALBRA PARA EXTRAER LOS
                                    //DATOS REQUERIDOS
{
   QString archivo,nom,edad,estado;
   QStringList tipoC;   //GENERAMOS UN STRING LIST PARA MOSTRARLO EN EL INPUT DIALOG Y EL USUARIO PUEDA ELEGIR EL TIPO DE CONVERSACION
   tipoC << "Normal";
   tipoC << "Aleatorio";
   archivo = QInputDialog::getText(this, "Subir txt", "Ingrese la ruta archivo");
   QString tipo = QInputDialog::getItem(this,"Elemento", "Elija el tipo de conversación: ",tipoC);
   QString texto;
   QFile archivo1(archivo);
   if(archivo1.open(QIODevice::ReadOnly))
   {
       QTextStream leer(&archivo1);

       texto.append(leer.readAll());
       archivo1.close();
   }
   QString xlinea;

   /*EN ESTA PARTE VAMOS TOMANDO LINEA POR LINEA Y GUARDANDOLA EN UNA STRING LIST ES ALGO SIMILAR A LO QUE SE HACIA EN LA LIBRERIA
   <FSTREAM>*/
   QStringList lines = texto.split("\n", QString::SkipEmptyParts);
   QStringList palabra;
   static int i = 0;
   xlinea = lines.at(i);
   palabra = xlinea.split(" ",QString::SkipEmptyParts);
   nom = palabra.at(0);
   edad = palabra.at(1);
   estado = palabra.at(2);

   //INSTANCIAMOS EL OBJETO, Y ALMACENAMOS LOS DATOS EN EL VECTOR "listaPersonas"
   Persona *p1 = new Persona(nom,edad,estado,tipo);
   listaPersonas.push_back(p1);
}

/*EN ESTA FUNCION CREAREMOS EL ARCHIVO TXT DONDE SE VA A GUARDAR LA CONVERSACIÓN EL CUAL ESTARÁ UBICANDO EN LA CARPETA BUIL... QUE
 * SE CREA AL EJECUTAR EL PROGRAMA, TAMBIEN IREMOS GUARDANTO LO QUE SE ESCRIBE EN UNA VARIABLE PARA MOSTRAR EN PANTALLA
 */
void interfaz::setDatosLog(QString renglon)
{
    QString contAnt,contAct;
    QFile log("conversacion.txt");

    if(log.open(QIODevice::ReadOnly))
    {
        QTextStream leer(&log);
        contAnt.append(leer.readAll());
        log.close();
    }

    if(log.open(QIODevice::WriteOnly))
    {
        QTextStream escribir(&log);
        escribir<<contAnt;
        escribir<<renglon;
        log.close();
    }

    if(log.open(QIODevice::ReadOnly))
    {
        QTextStream leer(&log);
        contAct.append(leer.readAll());

        log.close();
    }

    ui->plainTextEdit->setPlainText(contAct);

}

/*ESTE METODO ES UTILIZADA PARA VACIAR EL TABLERO (PLAIN TEXT)*/
void interfaz::on_guardar_clicked()
{
    QFile log("conversacion.txt");
    if(log.open(QIODevice::WriteOnly))
    {
        QTextStream escribir(&log);
        escribir<<"";
        log.close();
    }
    ui->plainTextEdit->setPlainText("");
}

/*EN ESTE METODO EXTRAEMOS LOS DATOS DEL VECTOR, CREAMOS UN ARRAY CON LAS POSIBLES RESPUESTAS (ÉSTE ES CREADO PENSANDO EN LAS RESPUESTAS ALEATORIAS),
 *VALIDAMOS SI LA CONVERSACIÓN SERÁ NORMAL Ó ALEATORIA, UNA VEZ HECHO ESTO SE REALIZA EL MISMO PROCESO QUE SE HACIA EN EL TALLER 2
 * Y POR ULTIMO SE LE PASA AL METODO setDatosLog LO QUE VA A IR MOSTRANDO
 */
void interfaz::on_enviar_clicked()
{


    QString nDato,nombre,edad,estado,tipo;
     nombre=listaPersonas[0]->getNombre();
     edad=listaPersonas[0]->getEdad();
     estado=listaPersonas[0]->getEstado();
     tipo=listaPersonas[0]->getTipo();

    QString respuesta[] = {"hola, me llamo "+nombre+" y hoy esta nublado",estado+" y voy a conquistar el mundo",edad+" me gané el baloto","esta muy bien, gracias por preguntar","AMD :), es lo maximo","si, es genial :), creo..."};


    if(tipo.compare("Normal")==0)
    {
       nDato.append(ui->lineEdit->text());
        if(nDato == "hola")
        {
            nDato.append("\r\n");
            nDato.append(respuesta[0]);
            nDato.append("\r\n");
        }
        else if(nDato == "como vas?")
        {
            nDato.append("\r\n");
            nDato.append(respuesta[1]);
            nDato.append("\r\n");
        }
        else if(nDato == "tu edad?")
        {
            nDato.append("\r\n");
            nDato.append(respuesta[2]);
            nDato.append("\r\n");
        }
        else if(nDato == "como esta el clima?")
        {
            nDato.append("\r\n");
            nDato.append(respuesta[3]);
            nDato.append("\r\n");
        }
        else if(nDato == "cual es tu procesador favorito?")
        {
            nDato.append("\r\n");
            nDato.append(respuesta[4]);
            nDato.append("\r\n");
        }
        else if(nDato == "te gusta Ingenieria de Sistemas?")
        {
            nDato.append("\r\n");
            nDato.append(respuesta[5]);
            nDato.append("\r\n");
        }
        else if(nDato == "chao")
        {
            nDato.append("\r\n");
            nDato.append("chao");
            close();
         }
    }
    else if(tipo.compare("Aleatorio")==0)
    {
        nDato.append(ui->lineEdit->text());
        if(nDato == "chao")
        {
            nDato.append("\r\n");
            nDato.append("chao");
            close();
        }
        else
        {
            int num;
            num = 0 + rand() % 5;
            nDato.append("\r\n");
            nDato.append(respuesta[num]);
            nDato.append("\r\n");
        }
    }


    setDatosLog(nDato);
}
