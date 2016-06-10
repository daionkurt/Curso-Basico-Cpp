//
// Created by carlo on 31/05/2016.
//
#include <iostream>
using namespace std;

/*Operadores básicos para variables primitivas
 * Nota: se pueden sobrecargar los operadores para variables de un tipo propio*/
void operadores() {
    int a=10, b=20;
    cout << endl << "Operadores" << endl;
    cout << "VALOR DE A: " << a << endl;
    cout << "VALOR DE B: " << b << endl;
    cout << "Suma: " << (a + b) << endl;
    cout << "Resta: " << (a - b) << endl;
    cout << "Multi: " << (a * b) << endl;
    cout << "Division: " << (b / a) << endl;
    cout << "Modulo: " << (b % a) << endl;
    cout << "Incremento: " << (++a) << endl;
    cout << "Decremento: " << (--b) << endl;
    cout << "Igualdad: " << (a == b) << endl;
    cout << "Diferencia: " << (a != b) << endl;
    cout << "Mayor que: " << (a > b) << endl;
    cout << "Menor que: " << (a < b) << endl;
    cout << "Mayor igual: " << (a >= b) << endl;
    cout << "Menor igual: " << (a <= b) << endl;
    cout << "AND Logico: " << (a && b) << endl;
    cout << "OR Logico: " << (a || b) << endl;
    cout << "NOT Logico: " << (!a && b) << endl;
    cout << "AND Bitwise: " << (a & b) << endl;
    cout << "OR Bitwise: " << (a | b) << endl;
    cout << "XOR: " << (a ^ b) << endl;
    cout << "Complemento: " << (~a) << endl;
    cout << "Left Shift: " << (a << 2) << endl;
    cout << "Right Shift: " << (a >> 2) << endl;
}

void muestraOperadores(){
    operadores();
}
