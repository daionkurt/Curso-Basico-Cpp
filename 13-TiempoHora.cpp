//
// Created by Carlos Andrés Fernández Jalomo on 31/05/2016.
// correo: carlosfdez@outlook.com
//
#include <iostream>
#include <ctime>

using namespace std;

void horaActual(){
    time_t ahora = time(0);
    char* fecha = ctime(&ahora);
    cout<<"La hora y fecha local es: "<<fecha;
    tm* gmtm = gmtime(&ahora);
    fecha = asctime(gmtm);
    cout<<"La fecha y hora UTC es: "<<fecha<<endl;
}

void formateoDeHora(){
    time_t ahora = time(0);
    cout<<"Numero de segundos desde 1 Enero, 1970: "<<ahora<<endl;
    tm* ltm = localtime(&ahora);
    cout<<"Anio: "<<1900+ltm->tm_year<<endl;
    cout<<"Mes: "<<1+ltm->tm_mon<<endl;
    cout<<"Dia: "<<ltm->tm_mday<<endl;
    cout<<"Hora: "<<1+ltm->tm_hour<<":"<<1+ltm->tm_min<<":"<<1+ltm->tm_sec<<endl;
}

void muestraTiempoHora(){
    horaActual();
    formateoDeHora();
}