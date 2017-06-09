#ifndef NORMAL_H
#define NORMAL_H

#include "persona.h"
#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QScrollBar>

class Normal : public Persona
{
    public:
        Normal(QString nombre,QString edad,QString estado);
         //void retorno();
};

#endif // NORMAL_H
