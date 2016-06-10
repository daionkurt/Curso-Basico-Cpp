//
// Created by carlo on 31/05/2016.
//
#include <iostream>

using namespace std;

void muestraSelectivas(){
    int a=6;
    int b=2;

    /*Primer tipo de selectiva: if-else if-else
     * Este tipo de selectiva está basado en preguntas, si esto.. entonces esto, de lo contrario aquello.*/
    if(a>5){
        cout<<"a es mayor  5"<<endl;
    }else if(a<5){
        cout<<"a es menor a 5"<<endl;
    }else{
        cout<<"a es igual a 5"<<endl;
    }
    /*Segundo tipo de selectiva: switch
     * Este tipo está basado en la elección, dependiendo del valor que recibe el switch, se ejecuta un caso
     * determinado establecido, de lo contrario se va a default*/
    switch(b){
        case 1: cout<<"B es igual a 1"<<endl; break;
        case 2: cout<<"B es igual a 2"<<endl; break;
        case 3: cout<<"B es igual a 3"<<endl; break;
        default: cout<<"ERROR"<<endl;
    }
    /*Tercer tipo de selectiva: operador ternario
     * Este tipo está basado en pregunta y arroja un valor izquierdo, y tiene la siguiente notación:
     * condicion ? en_caso_de_que_es_verdad : en_caso_de_que_es_mentira
     * y esto arroja el valor tanto en caso de verdad o falsedad, hacia la izquierda, pudiendo ser asignado
     * o usado para imprimirse*/
    cout<<(a+b>5?"chido":"No")<<endl;
}