//
// Created by carlo on 31/05/2016.
//
#include <iostream>
#include <typeinfo>

using namespace std;

/*La variable tipo auto, infiere su tipo en base al valor con el que se inicializa, es un tipo en cierto modo genérico*/
void storageClasses(){
    auto a=true; //variable automática
    //auto a=15.42;
    cout<<"La variable a es de tipo: "<<typeid(a).name()<<endl;
}

void muestraClasesAlmacenamiento(){
    storageClasses();
}
