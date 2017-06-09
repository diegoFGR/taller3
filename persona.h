/*
 * Nombre: Problema4 - Taller 3
 * Descripción: Generar una conversación apartir de un archivo y respuestas digitadas por el usuario
 * Nombre: Diego F. González Rojas
 * Codigo: 1667522
 * Fecha de Creacion: 01-06-2017
 * Fecha de Ult de modificacion: 08-06-2017
 *
*/

//CLASE PERSONA
#ifndef PERSONA_H
#define PERSONA_H
#include <QMainWindow>
class Persona
{
    public:
        Persona();
        Persona(QString nombreIn,QString edadIn,QString estadoIn, QString tipoIn);
        QString getNombre();
        QString getEdad();
        QString getEstado();
        QString getTipo();

    private: // LOS ATRIBUTOS SON NOMBRE,EDAD,ESTADO Y UN TIPO EL CUAL PUEDE SER NORMAL Ó ALEATORIO
        QString nombre;
        QString edad;
        QString estado;
        QString tipo;
};

#endif // PERSONA_H
