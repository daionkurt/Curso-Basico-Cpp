//
// Created by Carlos Andrés Fernández Jalomo on 31/05/2016.
// correo: carlosfdez@outlook.com
//
#include <iostream>

using namespace std;

/*Estructuras de control iterativas
 * ****************************************************************************************************
 * Las iterativas son aquellas que controlan la repetición de un bloque de código cero o más veces mediante
 * la evaluación del cumplimiento o no de una condición o expresión lógica, se evalua la condición, y si es cierta
 * ejecuta la instrucción o código y vuelve a preguntar la condición, hasta que la condición sea falsa y continue
 * con el flujo secuencial del programa
 * Existen 3 estructuras: if, switch, condicional
 * */
void muestraIterativas(){
    signed short contador = 0;
    /*Primer tipo de iterativas: while
     * ****************************************************************************************************
     * Este tipo está basado en primero pregunto luego hago, donde mientras la condición sea cierta
     * siempre ejecutará el código dentro, cuando la condición sea falsa, se termina el bucle
     * Veces de iteración: 0 o más*/
    while(contador<5){
        cout<<"While: "<<contador++<<endl;
    }
    /*Segundo tipo de iterativas: do-while
     * ****************************************************************************************************
     * Este tipo está basado en que siempre va a hacer el código al menos 1 vez y si la condición
     * del while() es verdad el código será ejecutado de nuevo hasta que sea falsa
     * Veces de iteración: 1 o más */
    do{
        cout<<"Do While: "<<contador++<<endl;
    }while(contador<10);
    /*Tercer tipo de iteración: for
     * ****************************************************************************************************
     * Este tipo está basado en un número determinado de vueltas, y tiene la siguiente notación:
     * for(desde este valor ; mientras se cumpla esta condición; y el valor aumente o decremente)
     * Veces de iteración: 0 o más*/
    for(;contador<20;contador++){
        if(contador==13){
            cout<<"Entro a continue y me lo salto al siguiente bucle"<<endl;
            continue; //Continue hace que el resto de instrucciones del ciclo después de donde se encuentra el continue
                        //sea saltado y se ejecute el siguente ciclo de iteración, pero no rompe el bucle
        }
        if(contador==17){
            cout<<"Entro a break y salgo del for"<<endl;
            break; //Break hace que el bucle termine donde se encuentre este, sin importar la cantidad de iteraciones
                    //restantes del bucle
        }
        cout<<"For: "<<contador<<endl;
    }
}
