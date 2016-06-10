//
// Created by carlo on 08/06/2016.
//
#include <iostream>

using namespace std;

class PruebaFunctor{
private:
    int x;
public:
    PruebaFunctor(int x): x(x){}
    string operator()(){return "Prueba Functor exitosa";}
    int operator()(int y){return x+y;}
};

void muestraFunctores(){
    PruebaFunctor pruebaFunctor(5);
    cout<<pruebaFunctor()<<endl;
    cout<<pruebaFunctor(6)<<endl;

}