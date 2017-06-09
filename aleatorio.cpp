#include "aleatorio.h"

Aleatorio::Aleatorio(QString nombre,QString edad,QString estado) : Persona(nombre,edad,estado)
{

}
/*
void Aleatorio::conversacion()
{
    Persona::conversacion();
    QString respuesta[] = {"hola, me llamo "+nombre+" y hoy esta nublado",estado+" y voy a conquistar el mundo",edad+" me gané el baloto","esta muy bien, gracias por preguntar","AMD :), es lo maximo","si, es genial :), creo..."};


    QString comando;
    cout<<"Ingrese un comando"<<endl;

    while(comando!= "chao")
        {
            cin>>comando;
            int num;
            num = 0 + rand() % 5;
            cout<<respuesta[num]<<endl;

        }
        cout << "chao" << endl;
}

*/
