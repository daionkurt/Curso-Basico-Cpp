//
// Created by carlo on 31/05/2016.
//
#include <iostream>

using namespace std;

void muestraEntradasSalidas(){
    string mensaje = "Hola Mundo";
    string error = "Error mortal D:";
    string log = "Error de Clog";
    string nombre;
    int numero;
    cout<<mensaje<<endl;
    cerr<<"ERROR: "<<error<<endl;
    clog<<"ERROR: "<<log<<endl;
    cout<<"Introduce un numero: ";
    cin >> numero;
    cin.ignore();
    cout<<"Introduce un nombre: ";
    getline(cin,nombre);
    cout<<nombre;
}
