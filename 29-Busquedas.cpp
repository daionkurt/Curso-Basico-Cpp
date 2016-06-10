//
// Created by carlo on 06/06/2016.
//
#include <iostream>

using namespace std;

int operaciones;
int operacionesLineales;

template <typename T>
int busquedaLineal(T* arreglo, int size, T objetivo){
    for (int i = 0; i < size; ++i) {
        operacionesLineales++;
        if(objetivo==arreglo[i]){
            return i;
        }
    }
}

template <typename T>
int busquedaBinariaRecursiva(T* arreglo,int primero,int ultimo,T objetivo){
    int centro = (primero+ultimo)/2;
    operaciones+=4;
    return (primero==ultimo)?primero:(objetivo<=arreglo[centro])?
              busquedaBinariaRecursiva(arreglo,primero,centro,objetivo):
              busquedaBinariaRecursiva(arreglo,centro+1,ultimo,objetivo);
}

template <typename T>
int busquedaBinaria(T* arreglo,int size,T objetivo){
    return (objetivo<=arreglo[0])?0:(objetivo>arreglo[size-1])?
            size:busquedaBinariaRecursiva(arreglo,0,size,objetivo);
}

void busquedas(){
    const int size = 500000;
    int* arreglo = new int[size];
    int resultado;
    CuentaTiempo tiempo;
    for (int i = 0; i < size; ++i) {
        arreglo[i] = i;
    }
    tiempo.iniciarCuentaTiempo();
    cout<<"El objetivo "<<arreglo[resultado=busquedaLineal(arreglo,size,499999)]<<" esta en la posicion: "<<resultado<<endl;
    cout<<"OP: "<<operacionesLineales<<endl;
    tiempo.terminarCuentaTiempo();
    cout<<endl;
    cout<<endl<<"Tiempo: "<<tiempo.getTiempo()<<endl;

    for (int i = 0; i < size; ++i) {
        arreglo[i] = i;
    }
    tiempo.iniciarCuentaTiempo();
    cout<<"El objetivo "<<arreglo[resultado=busquedaBinaria(arreglo,size,499999)]<<" esta en la posicion: "<<resultado<<endl;
    cout<<"OP: "<<operaciones<<endl;
    tiempo.terminarCuentaTiempo();
    cout<<endl;
    cout<<endl<<"Tiempo: "<<tiempo.getTiempo()<<endl;
}
