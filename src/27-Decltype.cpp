//
// Created by carlo on 02/06/2016.
//
#include <iostream>

using namespace std;

/*Decltype obtiene el tipo dependiendo de aquello sobre lo que opera
 * Aplica las siguientes reglas:
 * 1- Si la expresión es una variable, el resultado es el tipo de la variable
 * 2- Si la expresión es una función, el resultado es el tipo de retorno
 * 3- Si es un L-valor, el resultado es una referenci al tipo de la expresión
 * 4- En otr caso, el resultado es el tipo de la expresión*/

auto funcion(int a,int b) -> int{
    return a+b;
}

auto multi(int a,float b) -> float{
    return float(a)*b;
}

template <typename T, typename R>
auto suma(T t, R r) -> decltype(t+r){
    return t+r;
};

void muestraDecltype(){
    int i = 0;
    int &r = i;
    decltype(i) a = i; //int a (regla 1)
    decltype(3) b = i; //int b (regla 4)
    decltype(r) c = i; //int &c (regla 1)
    decltype((i)) d = i; //int &d (regla 3)
    auto v = 3;
    decltype(3) ww = 3;
    cout<<"Tipo de a: "<< typeid(a).name()<<endl;
    cout<<"Tipo de b: "<< typeid(b).name()<<endl;
    cout<<"Tipo de c: "<< typeid(c).name()<<endl;
    cout<<"Tipo de d: "<< typeid(d).name()<<endl;
    cout<<funcion(2,3)<<endl;

    auto x = 1+2;
    auto y = suma(1,1.2);
    auto z = {1,2};
    auto w = multi(4,2.6);
    cout<<"Tipo de x: "<< typeid(x).name()<<endl;
    cout<<"Tipo de y: "<< typeid(y).name()<<endl;
    cout<<"Tipo de z: "<< typeid(z).name()<<endl;
    cout<<"Tipo de w: "<< typeid(w).name()<<endl;
    cout<<"valor de w: "<<w<<endl;
}