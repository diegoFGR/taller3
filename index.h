/*
 * Nombre: Problema4 - Taller 3
 * Descripción: Generar una conversación apartir de un archivo y respuestas digitadas por el usuario
 * Nombre: Diego F. González Rojas
 * Codigo: 1667522
 * Fecha de Creacion: 01-06-2017
 * Fecha de Ult de modificacion: 08-06-2017
 *
*/
//ESTA CLASE ES LA QUE CONTIENE LA PANTALLA INICIAL Y NOS REDIRECCIONA AL APLICATIVO COMO TAL
#ifndef INDEX_H
#define INDEX_H
#include "interfaz.h"

#include <QMainWindow>

namespace Ui {
class index;
}

class index : public QMainWindow
{
    Q_OBJECT

public:
    explicit index(QWidget *parent = 0);
    ~index();

private slots:
    void on_empezar_clicked();

private:
    Ui::index *ui;
};

#endif // INDEX_H
