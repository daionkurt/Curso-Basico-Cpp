//
// Created by Carlos Andrés Fernández Jalomo on 31/05/2016.
// correo: carlosfdez@outlook.com
//
#include <iostream>
using namespace std;

/*Operadores básicos para variables primitivas
 * ****************************************************************************************************
 * Los operadores son aquellos que especifican una evaluación que se realizará con 1 o más operandos
 * estos poseen precedencia y asociatividad según las leyes de agrupación de las matemáticas
 * - La prioridad especifica el orden en que se realizan las operaciones en las expresiones que contienen
 *      mas de un operador
 * - La asociatividad especifica que, si en una expresión que tiene varios operadores con la misma prioridad,
 *      un operando se agrupa con el de la izquierda o con el de la derecha
 * A continuación una tabla donde se especifica esto, de la forma:
 * <Nombre del operador>                - <Operador>        - Grado de Prioridad (menor es más prioritario)
 *
 * Sin asociatividad ---------------------------------------------
 * Resolución de ámbito                 -   ::              - 1
 *
 * Asociatividad de izquierda a derecha --------------------------
 * Objeto o puntero                     - . o ->            - 2
 * Subíndice                            - []                - 2
 * Llamada a función                    - ()                - 2
 * Incremento postfijo                  - ++                - 2
 * Decremento postfijo                  - --                - 2
 * Nombre de tipo                       - typeid()          - 2
 * Conversiones de tipos constante      - const_cast        - 2
 * Conversiones de tipo dinámica        - dynamic_cast      - 2
 * Conversiones de tipo reinterpretado  - reinterpret_cast  - 2
 * Conversiones de tipo estática        - static_cast       - 2
 * Puntero a miembro                    - .* o ->*          - 4
 * Multiplicación                       - *                 - 5
 * División                             - /                 - 5
 * Módulo                               - %                 - 5
 * Adición                              - +                 - 6
 * Resta                                - -                 - 6
 * Desplazamiento a la izquierda        - <<                - 7
 * Desplazamiento a la derecha          - >>                - 7
 * Menor que                            - <                 - 8
 * Mayor que                            - >                 - 8
 * Menor o igual que                    - <=                - 8
 * Mayor o igual que                    - >=                - 8
 * Igualdad                             - ==                - 9
 * Desigualdad                          - !=                - 9
 * AND bit a bit                        - &                 - 10
 * XOR bit a bit                        - ^                 - 11
 * OR bit a bit                         - |                 - 12
 * AND lógico                           - &&                - 13
 * OR lógico                            - ||                - 14
 * Coma                                 - ,                 - 18
 *
 * Asociatividad de derecha a izquierda --------------------------
 * Tamaño de objeto o tipo              - sizeof            - 3
 * Incremento prefijo                   - ++                - 3
 * Decremento prefijo                   - --                - 3
 * Complemento a uno                    - ~                 - 3
 * NOT lógico                           - !                 - 3
 * Negación Unaria                      - -                 - 3
 * Unario más                           - +                 - 3
 * Dirección de                         - &                 - 3
 * Direccionamiento indirecto           - *                 - 3
 * Crear objeto                         - new               - 3
 * Destruir objeto                      - delete            - 3
 * Conversión de tipos expicita         - cast: ()          - 3
 * Condicional                          - ? :               - 15
 * Asignación                           - =                 - 16
 * Asignación y multiplicación          - *=                - 16
 * Asignación y división                - /=                - 16
 * Asignación y módulo                  - %=                - 16
 * Asignación y suma                    - +=                - 16
 * Asignación y resta                   - -=                - 16
 * Asignación y desplazamiento izq      - <<=               - 16
 * Asignación y desplazamiento der      - >>=               - 16
 * Asignación y AND bit a bit           - &=                - 16
 * Asignación y XOR bit a bit           - ^=                - 16
 * Asignación y OR bit a bit            - |=                - 16
 * Throw                                - throw             - 17
 * Nota: se pueden sobrecargar los operadores para variables de un tipo propio*/
void operadores() {
    int a=10, b=20;
    cout << endl << "Operadores"<< endl;
    cout << "VALOR DE A: "      << a            << endl;
    cout << "VALOR DE B: "      << b            << endl;
    cout << "Suma: "            << (a + b)      << endl;
    cout << "Resta: "           << (a - b)      << endl;
    cout << "Multi: "           << (a * b)      << endl;
    cout << "Division: "        << (b / a)      << endl;
    cout << "Modulo: "          << (b % a)      << endl;
    cout << "Incremento: "      << (++a)        << endl;
    cout << "Decremento: "      << (--b)        << endl;
    cout << "Igualdad: "        << (a == b)     << endl;
    cout << "Diferencia: "      << (a != b)     << endl;
    cout << "Mayor que: "       << (a > b)      << endl;
    cout << "Menor que: "       << (a < b)      << endl;
    cout << "Mayor igual: "     << (a >= b)     << endl;
    cout << "Menor igual: "     << (a <= b)     << endl;
    cout << "AND Logico: "      << (a && b)     << endl;
    cout << "OR Logico: "       << (a || b)     << endl;
    cout << "NOT Logico: "      << (!a && b)    << endl;
    cout << "AND Bitwise: "     << (a & b)      << endl;
    cout << "OR Bitwise: "      << (a | b)      << endl;
    cout << "XOR: "             << (a ^ b)      << endl;
    cout << "Complemento: "     << (~a)         << endl;
    cout << "Left Shift: "      << (a << 2)     << endl;
    cout << "Right Shift: "     << (a >> 2)     << endl;
}

void muestraOperadores(){
    operadores();
}
