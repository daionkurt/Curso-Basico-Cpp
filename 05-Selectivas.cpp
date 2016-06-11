//
// Created by Carlos Andrés Fernández Jalomo on 31/05/2016.
// correo: carlosfdez@outlook.com
//
#include <iostream>

using namespace std;

/* Estructuras de control selectivas
 * ****************************************************************************************************
 * Las selectivas son aquellas que controlan si algo sucederá o ejecutará, es decir mediante "decisiones"
 * organizan el flujo de ejecución del programa, mediante la evaluación del cumplimiento o no de una
 * condición o expresión lógica
 * Existen 3 estructuras: if, switch, condicional
 * */
void muestraSelectivas(){
    int a=6;
    int b=2;
    /*Primer tipo de selectiva: if-else if-else
     * ****************************************************************************************************
     * Este tipo de selectiva está basado en preguntas, si esto.. entonces esto, de lo contrario aquello.
     * y pueden extenderse hasta N preguntas.
     * Sintáxis:
     * if (condición ) { código }else{ código }
     * NOTA: En caso de usar el if de la siguiente manera:
     * if(algo==otro_algo){
     * }else if(algo==otro_algo){
     * }else if(algo==otro_algo)....
     * Lo anterior es una selectiva de igualdad, es decir se pregunta usando el operador ==, si esto es
     * muy repetitivo sería prudente considerar si no es mejor hacer uso de un switch*/
    if(a>5){
        cout<<"a es mayor  5"<<endl;
    }else if(a<5){
        cout<<"a es menor a 5"<<endl;
    }else{
        cout<<"a es igual a 5"<<endl;
    }
    /*Segundo tipo de selectiva: switch
     * ****************************************************************************************************
     * Este tipo está basado en la elección, dependiendo del valor que recibe el switch, se ejecuta un caso
     * determinado establecido, de lo contrario se va a default
     * En el ejemplo, switch evalua el valor de 'b' y dependiendo de su valor actual, ejecutará el código
     * correspondiente al caso que cumpla la igualdad con el valor de 'b', actualmente siendo el case 2
     * */
    switch(b){
        case 1: cout<<"B es igual a 1"<<endl; break;
        case 2: cout<<"B es igual a 2"<<endl; break;
        case 3: cout<<"B es igual a 3"<<endl; break;
        default: cout<<"ERROR"<<endl;
    }
    /*Tercer tipo de selectiva: operador ternario
     * ****************************************************************************************************
     * Este tipo está basado en pregunta y arroja un valor izquierdo, y tiene la siguiente notación:
     * condicion ? en_caso_de_que_es_verdad : en_caso_de_que_es_mentira
     * y esto arroja el valor tanto en caso de verdad o falsedad, hacia la izquierda, pudiendo ser asignado
     * o usado para imprimirse*/
    cout<<(a+b>5?"chido":"No")<<endl;
}