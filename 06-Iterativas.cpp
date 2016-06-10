//
// Created by carlo on 31/05/2016.
//
#include <iostream>

using namespace std;

void muestraIterativas(){
    signed short contador = 0;
    /*Primer tipo de iterativas: while
     * Este tipo está basado en primero pregunto luego hago, donde mientras la condición sea cierta
     * siempre ejecutará el código dentro, cuando la condición sea falsa, se termina el bucle
     * Veces de iteración: 0 o más*/
    while(contador<5){
        cout<<"While: "<<contador++<<endl;
    }
    /*Segundo tipo de iterativas: do-while
     * Este tipo está basado en que siempre va a hacer el código al menos 1 vez y si la condición
     * del while() es verdad el código será ejecutado de nuevo hasta que sea falsa
     * Veces de iteración: 1 o más */
    do{
        cout<<"Do While: "<<contador++<<endl;
    }while(contador<10);
    /*Tercer tipo de iteración: for
     * Este tipo está basado en un número determinado de vueltas, y tiene la siguiente notación:
     * for(desde este valor ; mientras se cumpla esta condición; y el valor aumente o decremente)
     * Veces de iteración: 0 o más*/
    for(;contador<20;contador++){
        if(contador==13){
            cout<<"Entro a continue y me lo salto al siguiente bucle"<<endl;
            continue;
        }
        if(contador==17){
            cout<<"Entro a break y salgo del for"<<endl;
            break;
        }
        cout<<"For: "<<contador<<endl;
    }
}
