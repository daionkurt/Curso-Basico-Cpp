//
// Created by carlo on 31/05/2016.
//
#include <iostream>
#include <cmath>
#include <ctime>

using  namespace std;

void muestraNumeros(){
    short s = 10;
    int i = -100;
    long l = 1000;
    float f = 25.5;
    double d = 50.25;
    srand((unsigned)time(nullptr)); //Manera de inicializar el valor de una potencial variable random
    int j = rand(); //rand() se usa una vez se haya usado la linea anterior, otorga un número random

    cout<<"cos(d): "<<cos(d)<<endl; //Obtiene el coseno del parámetro
    cout<<"sin(d): "<<sin(d)<<endl; //Obtiene el seno del parámetro
    cout<<"tan(d): "<<tan(d)<<endl; //Obtiene la tangente del parámetro
    cout<<"log(d): "<<log(d)<<endl; //Obtiene el logaritmo del parámetro
    cout<<"abs(i): "<<abs(i)<<endl; //Obtiene el valor absoluto del parámetro
    cout<<"fabs(f): "<<floor(f)<<endl; //Obtiene el valor absoluto del parámetro que sea float, sin considerar los valores flotantes
    cout<<"floor(d): "<<floor(d)<<endl; //redondea hacia abajo
    cout<<"sqrt(f): "<<sqrt(f)<<endl; //obtiene la raiz cuadrada
    cout<<"pow(l,s): "<<pow(l,s)<<endl; //obtiene la potencia
    cout<<"hypot(d): "<<hypot(d,f)<<endl; //Obtiene la hipotenusa de 2 angulos
    cout<<"Numero random: "<<j<<endl;
}
