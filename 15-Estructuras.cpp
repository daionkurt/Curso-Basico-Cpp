//
// Created by carlo on 31/05/2016.
//
#include <iostream>

using namespace std;

struct Personita{
    string nombre;
    int edad;
    double salario;
    char sexo;
};

typedef struct {
    string nombre;
    int codigo;
}Alumnito;

void imprimeEstructura(struct Personita persona){
    cout<<"Nombre: "<<persona.nombre<<endl;
    cout<<"Edad: "<<persona.edad<<endl;
    cout<<"Salario: "<<persona.salario<<endl;
    cout<<"Sexo: "<<persona.sexo<<endl;
}

void imprimeEstructuraPuntero(struct Personita* persona){
    cout<<"Nombre: "<<persona->nombre<<endl;
    cout<<"Edad: "<<persona->edad<<endl;
    cout<<"Salario: "<<persona->salario<<endl;
    cout<<"Sexo: "<<persona->sexo<<endl;
}

void muestraEstructura(){
    struct Personita persona;
    Alumnito* alumno = new Alumnito();
    persona.nombre = "Carlos Fernandez";
    persona.edad = 21;
    persona.salario = 17800.00;
    persona.sexo = 'H';
    imprimeEstructura(persona);
    imprimeEstructuraPuntero(&persona);
    alumno->nombre = "Diego Cervantes";
    alumno->codigo = 210711732;
    cout<<"Nombre alumno: "<<alumno->nombre<<endl;
    cout<<"Codigo alumno: "<<alumno->codigo<<endl;
    delete alumno;
}