//
// Created by Carlos Andrés Fernández Jalomo on 30/05/2016.
// correo: carlosfdez@outlook.com
//
#include <iostream>
#include <cstring>
#include <typeinfo>
#include <string>

/*Definición de tipos de datos o variables externas*/
extern int global; //variable que se encuentra en un archivo externo
typedef int Enterito; //De define un nuevo tipo de dato llamado "Entero" como int

/*Creación de una TDA Estructura*/
struct Estructura{
    signed int id;
    char cadena[15];
};

/*Creación de una TDA Unión*/
union Union{
    int a;
    float b;
    long c;
};

/*Tamaño de cada variable primitiva existente:
 * -Se debe tomar en cuenta que estos datos podrían cambiar de máquina a máquina ya que
 * el tamaño depende de la arquitectura y SO sobre el cuál se ejecuta siendo por ejemplo el caso
 * de un <long int>:
 * SO de 8 y 16 bits:   sizeof(long int) = 2
 * SO de 32 bits:       sizeof(long int) = 4
 * SO de 64 bits:       sizeof(long int) = 8*/
void muestraTamanioTiposDatos(){
    std::cout<<"Size de los tipos de datos primitivos"<<std::endl<<std::endl;
    std::cout<<"Size of char: "          << sizeof(char)             <<std::endl;
    std::cout<<"Size of unsigned char: " << sizeof(unsigned char)    <<std::endl;
    std::cout<<"Size of signed char: "   << sizeof(signed char)      <<std::endl;
    std::cout<<"Size of int: "           << sizeof(int)              <<std::endl;
    std::cout<<"Size of unsigned int: "  << sizeof(unsigned int)     <<std::endl;
    std::cout<<"Size of signed int: "    << sizeof(signed int)       <<std::endl;
    std::cout<<"Size of short: "         << sizeof(short)            <<std::endl;
    std::cout<<"Size of unsigned short: "<< sizeof(unsigned short)   <<std::endl;
    std::cout<<"Size of signed short: "  << sizeof(signed short)     <<std::endl;
    std::cout<<"Size of long: "          << sizeof(long)             <<std::endl;
    std::cout<<"Size of unsigned long: " << sizeof(unsigned long)    <<std::endl;
    std::cout<<"Size of signed long: "   << sizeof(signed long)      <<std::endl;
    std::cout<<"Size of float: "         << sizeof(float)            <<std::endl;
    std::cout<<"Size of double: "        << sizeof(double)           <<std::endl;
    std::cout<<"Size of long double: "   << sizeof(long double)      <<std::endl;
    std::cout<<"Size of wchar_t: "       << sizeof(wchar_t)          <<std::endl;
}

void showDataTypes(){
    std::cout<<std::endl<<"Tipos primitivos"<<std::endl<<std::endl;
    extern int global;

    std::cout<<std::endl<<"Tipos compuestos"<<std::endl<<std::endl;
    typedef int TipoElemento;
    enum Color{rojo, naranja, amarillo, blanco}; /*Tipo enumerado, el inicio por defecto tiene el valor de 0, en caso de iniciarlizar
 *                                                en un número determinado se usa lo siguiente:
 *                                                enum Tipo{valor1=<numero_que_se_desea_usar_como_inicio>,valor2,valor3}
 *                                                y el resto tendrá el valor autoincremental del primero*/
    Color ncolor = rojo; //Se pueden declarar variables del tipo enumarado y asignarle valor
    TipoElemento elemento = 450;
    Estructura estructura;
    estructura.id = 4;
    strcpy(estructura.cadena,"Hola mundo");

    std::cout<<ncolor   <<std::endl;
    std::cout<<elemento <<std::endl;
    std::cout<<estructura.id        <<std::endl;
    std::cout<<estructura.cadena    <<std::endl;
    std::cout<<"Size of full struct: "  << sizeof(Estructura)   <<std::endl; //La struct toma el tamaño de la suma de sus componentes
    std::cout<<"Size of full union: "   << sizeof(Union)        <<std::endl; //la union toma el tamaño del elemento con el tamaño mayor
}

void showExternVariable(){
    std::cout<<"Valor variable externa: "<<(++global)<<std::endl;
}

void showIdentifiers(){
    int a=10, b=20;
    std::cout<<std::endl<<"Identificadores de tipos de datos"<<std::endl<<std::endl;
    if(typeid(Enterito) == typeid(int))  //typeid(tipo) regresa un type_info para comparar variables
        std::cout << "int y Entero son el mismo tipo" << std::endl;
    //typeid(tipo).name() regresa el identificador semántico del tipo de variable
    std::cout<<"Identificador de int:  "			<<typeid(a).name() 				<<std::endl; //i
    std::cout<<"Identificador de float:  "			<<typeid(float).name() 			<<std::endl; //f
    std::cout<<"Identificador de double:  "			<<typeid(double).name() 		<<std::endl; //d
    std::cout<<"Identificador de short:  "			<<typeid(short).name() 			<<std::endl; //s
    std::cout<<"Identificador de long:  "			<<typeid(long).name() 			<<std::endl; //l
    std::cout<<"Identificador de bool:  "			<<typeid(bool).name() 			<<std::endl; //b
    std::cout<<"Identificador de unsigned int:  "	<<typeid(unsigned int).name() 	<<std::endl; //j
    std::cout<<"Identificador de unsigned long:  "	<<typeid(unsigned long).name() 	<<std::endl; //m
    std::cout<<"Identificador de unsigned short:  "	<<typeid(unsigned short).name()	<<std::endl; //t
    std::cout<<"Identificador de char:  "	        <<typeid(char).name()	        <<std::endl; //c
    std::cout<<"Identificador de wchar_t: "         <<typeid(wchar_t).name()	    <<std::endl; //w
    std::cout<<"Identificador de string: "          <<typeid(std::string).name()	<<std::endl; //Ss
}

/*getType(var) es una función que permite regresar en modo cadena el tipo de la variable que se le otorga como parametro*/
std::string getType(auto var){
    switch(typeid(decltype(var)).name()[0]){
        case 'i': return "Integer";
        case 'f': return "Float";
        case 'd': return "Double";
        case 's': return "Short";
        case 'l': return "Long";
        case 'b': return "Boolean";
        case 'j': return "Unsigned Integer";
        case 'm': return "Unsigned Long";
        case 't': return "Unsigned Short";
        case 'c': return "Character";
        case 'S': return "String";
    }
}

void getTypes(){
    int a;
    float b;
    double c;
    short d;
    long e;
    bool f;
    unsigned int g;
    unsigned long h;
    unsigned short i;
    char j;
    std::string k;
    std::cout<<"Obtención de datos"<<std::endl;
    std::cout<<"La variable a es de tipo:  "<<getType(a)<<std::endl;
    std::cout<<"La variable b es de tipo:  "<<getType(b)<<std::endl;
    std::cout<<"La variable c es de tipo:  "<<getType(c)<<std::endl;
    std::cout<<"La variable d es de tipo:  "<<getType(d)<<std::endl;
    std::cout<<"La variable e es de tipo:  "<<getType(e)<<std::endl;
    std::cout<<"La variable f es de tipo:  "<<getType(f)<<std::endl;
    std::cout<<"La variable g es de tipo:  "<<getType(g)<<std::endl;
    std::cout<<"La variable h es de tipo:  "<<getType(h)<<std::endl;
    std::cout<<"La variable i es de tipo:  "<<getType(i)<<std::endl;
    std::cout<<"La variable j es de tipo:  "<<getType(j)<<std::endl;
    std::cout<<"La variable k es de tipo:  "<<getType(k)<<std::endl;
}

void muestraTiposDatos(){
    muestraTamanioTiposDatos();
    showDataTypes();
    showExternVariable();
    showIdentifiers();
    getTypes();
}