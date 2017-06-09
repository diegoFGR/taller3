/*
 * Nombre: Problema4 - Taller 3
 * Descripción: Generar una conversación apartir de un archivo y respuestas digitadas por el usuario
 * Nombre: Diego F. González Rojas
 * Codigo: 1667522
 * Fecha de Creacion: 01-06-2017
 * Fecha de Ult de modificacion: 08-06-2017
 *
*/

//ESTA CLASE ES LA INTERFAZ PRINCIPAL
#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "index.h"
#include "persona.h"
//DECLARAMOS LAS DIFERENTES LIBRERIAS DE QT QUE VAMOS A USAR
#include <QVector>
#include <QWidget>
#include <QInputDialog>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>

namespace Ui {
class interfaz;
}

class interfaz : public QWidget
{
    Q_OBJECT

public:
    explicit interfaz(QWidget *parent = 0);
    ~interfaz();

    void setDatosLog(QString renglon);


private slots:
    void on_enviar_clicked(); //ESTE METODO ES EL QUE ENVIA EL MENSAJE

    void on_guardar_clicked();//ESTE METODO LIMPIA LA PANTALLA (LO PENSABA USAR PARA GUARDAR LA CONVERSACION)

    void on_archivo_clicked();//ESTE METODO INVOCA UN INPUT_DIALOG EN EL CUAL ESCRIBIMOS LA RUTA DEL ARCHIVO Y SELECCIONAMOS EL TIPO
                              //DE CONVERSACION QUE VAMOS A TENER.

private:
    Ui::interfaz *ui;
    QVector<Persona*> listaPersonas;// VECTOR QUE ALMACENARA LOS DATOS DE LA PERSONA DEL .TXT
};

#endif // INTERFAZ_H
