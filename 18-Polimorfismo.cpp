//
// Created by carlo on 01/06/2016.
//
#include <iostream>

using namespace std;

class Persona{
protected:
    string nombre;
    int edad;
    char sexo;
public:
    Persona(string nombre,int edad, char sexo):nombre(nombre),edad(edad),sexo(sexo){
        cout<<"Persona construida"<<endl;
    }
    ~Persona(){
        cout<<"Persona destruida"<<endl;
    }
    virtual string toString(){
        stringstream str;
        str<<"N: "<<nombre<<", E: "<<edad<<", S: "<<sexo;
        return  str.str();
    }
    virtual void imprimeEdad()=0;
};

class Alumno: public Persona{
private:
    int codigo;
public:
    Alumno(string nombre,int edad, char sexo,int codigo):Persona(nombre,edad,sexo),codigo(codigo){
        cout<<"Alumno construido"<<endl;
    }
    ~Alumno(){
        cout<<"Alumno destruido"<<endl;
    }
    string toString(){
        stringstream str;
        str<<"N: "<<nombre<<", E: "<<edad<<", S: "<<sexo<<", C: "<<codigo;
        return  str.str();
    }
    void imprimeEdad(){
        cout<<"Edad del alumno: "<<edad<<endl;
    }
};

class Profesor: public Persona{
private:
    int nss;
public:
    Profesor(string nombre,int edad, char sexo,int nss):Persona(nombre,edad,sexo),nss(nss){
        cout<<"Profesor construido"<<endl;
    }
    ~Profesor(){
        cout<<"Profesor destruido"<<endl;
    }
    string toString(){
        stringstream str;
        str<<"N: "<<nombre<<", E: "<<edad<<", S: "<<sexo<<", NSS: "<<nss;
        return  str.str();
    }
    void imprimeEdad(){
        cout<<"Edad del profesor: "<<edad<<endl;
    }
};

void muestraPolimorfismo(){
    Persona* persona;
    Alumno alumno("Carlos",21,'H',210711118);
    Profesor profesor("Casillas",48,'H',3414521);
    persona = &alumno;
    cout<<persona->toString()<<endl;
    persona = &profesor;
    cout<<persona->toString()<<endl;
    alumno.imprimeEdad();
    profesor.imprimeEdad();
}
