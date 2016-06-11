//
// Created by Carlos Andrés Fernández Jalomo on 31/05/2016.
// correo: carlosfdez@outlook.com
//
#include <iostream>

using namespace std;

void referencias(){
    int entero = 10;
    int& segundo = entero;
    cout<<"Valor de entero: "<<entero<<endl;
    cout<<"Valor de la referencia a entero: "<<segundo<<endl;
}

void swap(int& a,int& b){
    int temp = a;
    a = b;
    b = temp;
}

void pasoPorReferencia(){
    int a = 10;
    int b = 20;
    cout<<"Valor de a antes: "<<a<<endl;
    cout<<"Valor de b antes: "<<b<<endl;
    swap(a,b);
    cout<<"Valor de a despues: "<<a<<endl;
    cout<<"Valor de b despues: "<<b<<endl;

}

double valores[] = {1,2,3,4,5,6};

double& setValor(int i){
    return valores[i];
}

void retornoPorReferencia(){
    cout<<"Valores antes de cambiar: "<<endl;
    for (int i = 0; i < 6; ++i) {
        cout<<"valores["<<i<<"] = "<<valores[i]<<endl;
    }
    setValor(2) = 20;
    setValor(4) = 40;
    cout<<"Valores despues de cambiar: "<<endl;
    for (int j = 0; j < 6; ++j) {
        cout<<"valores["<<j<<"] = "<<valores[j]<<endl;
    }
}

void muestraReferencias(){
    referencias();
    pasoPorReferencia();
    retornoPorReferencia();
}
