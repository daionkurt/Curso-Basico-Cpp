//
// Created by Carlos Andrés Fernández Jalomo on 31/05/2016.
// correo: carlosfdez@outlook.com
//
#include <iostream>
#include <typeinfo>

using namespace std;

/*Clases de almacenamiento
 * ****************************************************************************************************
 * Una clase de almacenamiento en el contexto de declaraciones de variable de C++ es un especificador de tipo que rige
 * la ubicación de memoria, la vinculación y la duración de objetos.Un objeto determinado puede tener solo una clase de
 * almacenamiento.Las variables definidas dentro de un bloque tienen almacenamiento automático, a menos que se especifique
 * lo contrario con los especificadores extern, static o thread_local.Las variables y objetos automáticos no tienen ninguna
 * vinculación; no son visibles para código fuera del bloque.*/
/*La variable tipo auto, infiere su tipo en base al valor con el que se inicializa, es un tipo en cierto modo genérico*/
void claseDeAlmacenamiento(){
    auto a=true; //variable automática de tipo almacenamiento, sin embargo ya no se considera así, por ende las clases
                //de almacenamiento han sido relegadas a partir del C++11
    //auto a=15.42; //Es válido declarar esto porque auto inferirá que es de tipo float
    cout<<"La variable a es de tipo: "<<typeid(a).name()<<endl;
}

void muestraClasesAlmacenamiento(){
    claseDeAlmacenamiento();
}
