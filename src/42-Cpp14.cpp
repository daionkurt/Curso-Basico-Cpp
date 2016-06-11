//
// Created by carlo on 08/06/2016.
//
#include <iostream>
#include <chrono>

using namespace std;

/*Agrupación de digitos*/
void ejemploAgrupacionDigitos(){
    auto entero_literal = 1'000'000;
    auto punto_flotante_literal = 0.000'015'3;
    auto binario_literal = 0b0100'1100'0110;
    auto indebido = 1'0'0'000'00;
    cout<<entero_literal<<endl;
    cout<<punto_flotante_literal<<endl;
    cout<<binario_literal<<endl;
    cout<<indebido<<endl;
}

/*Lambda genérico*/
auto lambda = [](auto x, auto y){return x+y;};
unique_ptr<int> ptr(new int(10));
auto lambda1 = [valor = move(ptr)]{return *valor;};

void ejemploLambda(){
    cout<<lambda(3,4)<<endl;
    cout<<lambda(1.2,1.4)<<endl;
    cout<<lambda(true,false)<<endl;
}

/*Definicion de depreciado*/
[[deprecated]]
int cuadrado(int a,int b=2){
    int x = a;
    for (int i = 1; i < b; ++i) {
        x*=x;
    }
    return x;
}

int cuadrado2(int a){
    return a*a;
}

void ejemploDeprecated(){
    cout<<"cuadrado: "<<cuadrado(5)<<endl;
    cout<<"cuadrado: "<<cuadrado2(5)<<endl;
}

/*Uso de Chrono para literales*/
using namespace chrono_literals;
void ejemploLiterales() {
    auto str = "hola mundo"s;
    auto hora = 14h;
    auto min = 54min;
    auto seg = 34s;
    auto ms = 24ms;
    auto us = 35us;
    auto ns = 11ns;
    cout << typeid(str).name() << endl;
    cout << typeid(hora).name() << endl;
    cout << typeid(min).name() << endl;
    cout << typeid(seg).name() << endl;
    cout << typeid(ms).name() << endl;
    cout << typeid(us).name() << endl;
    cout << typeid(ns).name() << endl;
    cout<<hora.count()<<":"<<min.count()<<":"<<seg.count()<<":"<<ms.count();
    cout<<":"<<us.count()<<":"<<ns.count()<<endl;

}

void muestraCpp14(){
    ejemploAgrupacionDigitos();
    ejemploLambda();
    ejemploDeprecated();
    ejemploLiterales();
}
