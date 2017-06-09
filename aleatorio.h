#ifndef ALEATORIO_H
#define ALEATORIO_H
#include "persona.h"
#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QScrollBar>

class Aleatorio : public Persona
{
    public:
        Aleatorio(QString nombre,QString edad,QString estado);

};

#endif // ALEATORIO_H
