//
// Created by carlo on 08/06/2016.
//
#include <iostream>

using namespace std;

bool funcionA(int, int, bool (*)(int));
bool funcionB(int);
bool funcion2(float(*)(int),int);
bool funcion3(bool(*)());
float funcion4(int);
bool funcion5();

void (*func1)();
void (*func2)(int);
int (*func3)();
int (*func4)(int);
float (*func5)(int);
bool (*func6)();
double (*func7)(int);

void muestraPunterosFuncion(){
    int x = 113;
    int y = 226;
    if(funcionA(x,y,funcionB))
        cout<<"Cierto"<<endl;
    else
        cout<<"Falso"<<endl;

    cout<<funcion2(funcion4,3)<<endl;
    cout<<funcion3(funcion5)<<endl;
}

bool funcionA(int a,int b,bool (*verificar)(int)){
    if(((*verificar)(a)) && ((*verificar)(b)))
        return true;
}

bool funcionB(int a){
    return a>100;
}

bool funcion2(float(*comprueba)(int),int a){
    return (*comprueba)(a);
}

bool funcion3(bool(*comprueba)()){
    return (*comprueba)();
}

float funcion4(int a){
    return a%2==0;
}

bool funcion5(){
    return true;
}