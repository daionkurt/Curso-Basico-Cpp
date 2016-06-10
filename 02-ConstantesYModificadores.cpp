//
// Created by carlo on 30/05/2016.
//
#include <iostream>

//Macrodefiniciones
#define LENGHT 10
#define WIDTH 5

using namespace std;

void showConstansLiterals(){
    cout<<"Literales Enteras"<<endl;
    int a,b,c,d,e,f,g;
    a=212;
    b=215u;
    c=0xFeeL;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    /*Literales enteras es la forma en la que se puede representar un entero en distintas notaciones*/
    a=85;   //decimal
    b=0213; //octal
    c=0x4b; //hexadecimal
    d=30;   //int
    e=30u;  //unsigned int
    f=30l;  //long
    g=30ul; //unsigned long
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<d<<endl;
    cout<<e<<endl;
    cout<<f<<endl;
    cout<<g<<endl;
    cout<<"Literales flotantes"<<endl;
    float af,bf,cf,df;
    af=3.14159;
    bf=314159E-5L;
    cout<<af<<endl;
    cout<<bf<<endl;
    cout<<"Literales de caracter"<<endl;
    cout<<"\\"<<endl; //print '\'
    cout<<"\'"<<endl; //print '''
    cout<<"\""<<endl; //print'"'
    cout<<"\?"<<endl; //print '?'
    cout<<"\a"<<endl; //ring bell
    cout<<"\b"<<endl; //backspace
    cout<<"\n"<<endl; //salto de linea
    cout<<"\r"<<endl; //corrida de carro
    cout<<"\t"<<endl; //tabulador
    cout<<"Literales de cadena"<<endl;
    cout<<"hello, dear"<<endl;
    cout<<"hello,\
            dear"<<endl;
    cout<<"hello, " "d" "ear"<<endl;
}

void showModifiers(){
    constexpr int value = 10; //Constante en tiempo de compilación
    const int constVal = 20; //Constante en tiempo de ejecución
    short int i;
    short unsigned int j;
    short signed int k = WIDTH*LENGHT;
    j=50000;
    i=j;
    cout<<"Modificadores"<<endl;
    cout<<i<<" "<<j<<endl;
    cout<<value<<endl;
    cout<<constVal<<endl;
    cout<<k<<endl;
    cout<<sizeof(int)<<endl;
    cout<<sizeof(unsigned int)<<endl;
    cout<<sizeof(signed int)<<endl;
    cout<<"Modificadores externos"<<endl;
    /*Las variables de tipo volatil indica que si bien la optimización puede cambiar el while del ejemplo a while(true) debido
     * a que aparentemente no tiene forma de salir del bucle, el que sea de tipo volatile indica que algun factor externo que
     * el compilador no alcanza a vislumbrar, puede cambiar la variable y romper el bucle, por ende no se optimiza a while(true)*/
    volatile int volatil=0;
    while(volatil==0){
        cout<<volatil--<<endl;
    }
    cout<<"Hola Mundo"<<endl;
}

void muestraConstantesModificadores(){
    showConstansLiterals();
    showModifiers();
}