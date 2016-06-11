//
// Created by Carlos Andrés Fernández Jalomo on 31/05/2016.
// correo: carlosfdez@outlook.com
//
#include <iostream>

using namespace std;

/*Funciones
 * ****************************************************************************************************
 * Las funciones son trozos de código funcional y reutilizable en cualquier parte del proyecto que tengan
 * alcance, se utiliza para operaciones y funciones como su nombre lo dice, que requiera del mismo
 * comportamiento muchas veces, por ejemplo, una función que eleve al cuadrado, que obtenga las
 * tablas de multiplicar, que averigue si una condición se cumple, pero con más ejemplos, esto quedará más claro*/
/*Prototipos de funciones
 * ****************************************************************************************************
 * Los prototipos son la definición de una función seguida por ; en lugar de los {} de implementación, esto quiere
 * decir que en el archivo o en algún sitio, está la implementación de esta función, y esto solo permite al compilador
 * que existe, no importa que se haya implementado despúes de hacerse uso en otro lado, en los prototipos no es
 * necesario declarar los nombres de los argumentos, unicamente los tipos de datos de los mismos
 * Los datos que reciben las funciones entre los parentesis son llamados argumentos o parámetros, y funcionan
 * para que la función se comunique con el exterior cuando es llamada, es decir, esta obtiene datos del entorno
 * externo y tiene un tipo de retorno que es como el resultado que brinda*/
int max(int,int);                   //se pueden declarar unicamene los tipos de los parametros sin nombre para cada uno
int ret(int,int,int=10);            //se pueden declarar parámetros opcionales, y darles valores por defecto
                                    //al darle =valor a un parametro este obtiene ese valor por defecto, cuando no es dado
                                    //cuando se llama a la función
void referenceSwap(int& a, int& b); //hay funciones con paso por referencia
void valueSwap(int a, int b);       //se pueden declarar los tipos y nombres de los parametros para la función
void pointerSwap(int* a,int* b);    //hay funciones con paso por puntero

/*Aqui se hace uso de las funciones, aunque no están implementadas aun a este punto del código, esto debido a
 * que tenemos los prototipos arriba, si no estuvieran los prototipos, y las funciones estuvieran igual abajo, esto
 * resultaría en un error de compilación*/
void muestraFunciones(){
    int a=100;
    int b=200;
    cout<<max(10,16)<<endl;
    cout<<ret(10,10)<<endl;
    cout<<ret(10,10,0)<<endl;
    valueSwap(a,b);         //Pasamos por valor, es decir, se copia la variable, pero solo es una copia
    cout<<a<<" "<<b<<endl;
    referenceSwap(a,b);     //Pasamos por refeencia, es decir, la variable como tal, y su valor es afectado
    cout<<a<<" "<<b<<endl;
    pointerSwap(&a,&b);     //Pasamos la referencia al puntero, es decir, la variable en si misma, y su valor es afectado
    cout<<a<<" "<<b<<endl;
}

/*Una función con paso de parámetros por referencia, no necesita indicar la referencia a donde
 * apunta en el cuerpo, se pueden usar las simples variables
 * El valor de los parametros pasados, son tambien modificados globalmente no solo en la subrutina
 * Caracter usado en la función:    &
 * forma de pasar los parametros:   (a)
 * */
void referenceSwap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

/*Una función con paso de parámetros por valor, usa copias de las variables por ende el valor de las
 * variables dadas como parametro no serán modificadas en el exterior, solo en la subrutina
 * Caracter usado en la función:    ninguno
 * forma de pasar los parametros:   (a)
 * */
void valueSwap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

/*Una función con paso de parámetros por puntero, necesita indicar la referencia a donde
 * apunta en el cuerpo, usando las variables parámetro con la notación: variable*
 * El valor de los parametros pasados, son tambien modificados globalmente no solo en la subrutina
 * Caracter usado en la función:    *
 * forma de pasar los parametros:   (&a)
 * */
void pointerSwap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*Función con 3 parámetros que regresa la multiplicación entre los valores de estos*/
int ret(int a,int b,int c){
    return a*b*c;
}

/*Función de 2 parámetros, que regresa cual de los 2 es mayor*/
int max(int a,int b){
    return a>b?a:b;
}
