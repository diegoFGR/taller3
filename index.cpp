/*
 * Nombre: Problema4 - Taller 3
 * Descripción: Generar una conversación apartir de un archivo y respuestas digitadas por el usuario
 * Nombre: Diego F. González Rojas
 * Codigo: 1667522
 * Fecha de Creacion: 01-06-2017
 * Fecha de Ult de modificacion: 08-06-2017
 *
*/

#include "index.h"
#include "ui_index.h"

index::index(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::index)
{
    ui->setupUi(this);
}

index::~index()
{
    delete ui;
}

void index::on_empezar_clicked()
{

    interfaz *ventana1 = new interfaz(this);
    ventana1->show();
}
