//
// Created by Carlos Andrés Fernández Jalomo on 31/05/2016.
// correo: carlosfdez@outlook.com
//
#include <iostream>
#include <cmath>        //Cabecera referente a funciones y literales matemáticas (trigonometría, álgebra y constantes)
#include <ctime>        //Cabecera referente al uso de la hora actual, fecha, rangos basados en tiempo y valores aleatorios

using  namespace std;

/*Números
 * ****************************************************************************************************
 * Las variables numéricas son las más usadas y comunes del lenguaje, es importante conocer su valor, tamaño
 * y rangos para el adecuado uso, desperdiciar memoria, es un problema en programas grandes, conocer cuál
 * tipo de variable numérica se adapta mejor a las necesidades evitará la merma innecesaria de memoria.
 * Estos son los tipos de datos numéricos existentes y alguna información sobre los mismos:
 * <tipo_dato>      - <bytes>  - MIN                    -MAX                    - NOTA
 * ----------------------------------------------------------------------------------------------------------
 * short            - 2        - -32768                 - 32767                 - Acepta signed
 * unsigned short   - 2        - 0                      - 65535
 * int              - 4        - 2147483648             - 2147483647            - Acepta signed
 * unsigned int     - 4        - 0                      - 4294967295
 * long             - 4        - 2147483648             - 2147483647            - Acepta signed
 * unsigned long    - 4        - 0                      - 4294967295
 * long long        - 8        - –9223372036854775808   - 9223372036854775807
 * u long long      - 8        - 0                      - 18446744073709551615
 * float            - 4        - 3.4E-38 (7 digitos)    - 3.4E+38 (7 digitos)   - No acepta signed o unsigned
 * double           - 8        - 1.7E-308 (15 digitos)  - 1.7E+308 (15 digitos) - No acepta signed o unsigned
 * */
void muestraNumeros(){
    short s = 10;
    int i = -100;
    long l = 1000;
    float f = 25.5;
    double d = 50.25;
    srand((unsigned)time(nullptr)); //Manera de inicializar el valor de una potencial variable random
    int j = rand(); //rand() se usa una vez se haya usado la linea anterior, otorga un número random

    /*Funciones matemáticas contenidas en cmath*/
    cout<<"cos(d): "        <<cos(d)    <<endl;         //Obtiene el coseno del parámetro
    cout<<"sin(d): "        <<sin(d)    <<endl;         //Obtiene el seno del parámetro
    cout<<"tan(d): "        <<tan(d)    <<endl;         //Obtiene la tangente del parámetro
    cout<<"log(d): "        <<log(d)    <<endl;         //Obtiene el logaritmo del parámetro
    cout<<"abs(i): "        <<abs(i)    <<endl;         //Obtiene el valor absoluto del parámetro
    cout<<"fabs(f): "       <<floor(f)  <<endl;         //Obtiene el valor absoluto del parámetro que sea float,
                                                        // sin considerar los valores flotantes
    cout<<"floor(d): "      <<floor(d)  <<endl;         //redondea hacia abajo
    cout<<"sqrt(f): "       <<sqrt(f)   <<endl;         //obtiene la raiz cuadrada
    cout<<"pow(l,s): "      <<pow(l,s)  <<endl;         //obtiene la potencia
    cout<<"hypot(d): "      <<hypot(d,f)<<endl;         //Obtiene la hipotenusa de 2 angulos
    cout<<"Numero random: " <<j<<endl;                  //Obtene un número aleatorio
}
