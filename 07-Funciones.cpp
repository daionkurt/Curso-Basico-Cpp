//
// Created by carlo on 31/05/2016.
//
#include <iostream>

using namespace std;

/*Prototipos de funciones*/
int max(int,int); //se pueden declarar unicamene los tipos de los parametros sin nombre para cada uno
int ret(int,int,int=10); //se pueden declarar parámetros opcionales, y darles valores por defecto
void referenceSwap(int& a, int& b); //hay funciones con paso por referencia
void valueSwap(int a, int b); //se pueden declarar los tipos y nombres de los parametros para la función
void pointerSwap(int* a,int* b); //hay funciones con paso por puntero

void muestraFunciones(){
    int a=100;
    int b=200;
    cout<<max(10,16)<<endl;
    cout<<ret(10,10)<<endl;
    cout<<ret(10,10,0)<<endl;
    valueSwap(a,b);
    cout<<a<<" "<<b<<endl;
    referenceSwap(a,b);
    cout<<a<<" "<<b<<endl;
    pointerSwap(&a,&b);
    cout<<a<<" "<<b<<endl;

}

/*Una función con paso de parámetros por referencia, no necesita indicar la referencia a donde
 * apunta en el cuerpo, se pueden usar las simples variables
 * El valor de los parametros pasados, son tambien modificados globalmente no solo en la subrutina
 * Caracter usado: &*/
void referenceSwap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

/*Una función con paso de parámetros por valor, usa copias de las variables por ende el valor de las
 * variables dadas como parametro no serán modificadas en el exterior, solo en la subrutina*/
void valueSwap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

/*Una función con paso de parámetros por puntero, necesita indicar la referencia a donde
 * apunta en el cuerpo, usando las variables parámetro con la notación: variable*
 * El valor de los parametros pasados, son tambien modificados globalmente no solo en la subrutina
 * Caracter usado: * */
void pointerSwap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int ret(int a,int b,int c){
    return a*b*c;
}

int max(int a,int b){
    return a>b?a:b;
}
