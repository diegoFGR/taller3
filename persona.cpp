/*
 * Nombre: Problema4 - Taller 3
 * Descripción: Generar una conversación apartir de un archivo y respuestas digitadas por el usuario
 * Nombre: Diego F. González Rojas
 * Codigo: 1667522
 * Fecha de Creacion: 01-06-2017
 * Fecha de Ult de modificacion: 08-06-2017
 *
*/

//EN ESTE CPP BASICAMENTE INICIALIZAMOS VARIABLES, CREAMOS EL CONSTRUCTOR Y GETTERS
#include "persona.h"

Persona::Persona()
{
    nombre = "";
    edad = "";
    estado ="";
    tipo = "";
}

Persona::Persona(QString nombreIn, QString edadIn, QString estadoIn, QString tipoIn)
{
    nombre = nombreIn;
    edad = edadIn;
    estado = estadoIn;
    tipo = tipoIn;
}

QString Persona::getNombre()
{
    return nombre;
}

QString Persona::getEdad()
{
    return edad;
}

QString Persona::getEstado()
{
    return estado;
}

QString Persona::getTipo()
{
    return tipo;
}
