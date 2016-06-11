//
// Created by Carlos Andrés Fernández Jalomo on 30/05/2016.
// correo: carlosfdez@outlook.com
//
/*Librerias de uso del lenguaje
 * ****************************************************************************************************
 * Estos son archivos de encabezado que contienen instrucciones y palabras definidas para hacer uso del lenguaje*/
#include <iostream>     //Contiene todo el estándar de entradas y salidas básicas de la consola, asi como tipos de datos
#include <cstring>      //Contiene lo referente a instrucciones y funciones complejas de uso de cadenas de caracteres
#include <typeinfo>     //Contiene lo necesario para el uso de tipos de datos conpuestos y obtención de tipos
#include <string>       //Libreria STL de cadenas del lenguaje, contiene lo básico de uso de cadenas

/*<todo> REQUERIMIENTOS:
 * <todo> - Compilador C/C++ (Se recomienda MinGW 4.XX que soporte la compilación de std=c++1y tambien llamado C++14, ambas notaciones son iguales)
 * <todo> - Entorno Integral de Desarrollo o IDE para uso de C++ (Se recomienda CLion versión estudiantil)
 * */

/*<todo> Antes de empezar...
 * <todo> Primero, se debe hacer énfasis a lo siguiente:
 * <todo>   Existe el método int main(){} este es el que contiene las instrucciones principales del programa y es el que
 * <todo> indica qué se hará dentro del sistema, el compilador busca este método como punto de partida del programa, en
 * <todo> caso de no encontrarlo, el programa simplemente no funciona.
 * <todo> Un método es una pieza de código con la sintáxis:   tipo_de_retorno  nombre_metodo(argumentos){}
 * <todo> que puede ser llamado desde otra parte del código para su uso, se debe tener en cuenta que durante estos archivos
 * <todo> se hará uso de las palabras "funcion", "método" o "subrutina" para hacer énfasis al anterior principio*/


/*Definición de tipos de datos o variables externas
 * ****************************************************************************************************
 * Mediante el uso de la palabra reservada "typedef" se puede definir un identificador más cómodo
 * para un tipo de dato o una expresión de un tipo de dato.
 * El uso de la palabra reservada "extern" hace alusión a que la variable está ubicada en otro archivo externo
 * para que el compilador no marque error en caso de no encontrarla en el ámbito actual
 * */
extern int variableExterna; //variable que se encuentra en un archivo externo
typedef int Entero; //De define un nuevo tipo de dato llamado "Entero" como int

/*Creación de una TDA Estructura
 * ****************************************************************************************************
 * La palabra "struct" permite crear estructuras de datos complejas, es decir, un tipo de variable que contiene
 * campos a modo de atributos de la estructura en cuestión, siendo estos de cualquier tipo de dato
 * Sintaxis
 * struct "NombreEstructura{
 *      tipo_variable variable;
 * }
 * Su tamaño es igual a la suma de los tamaños de las variables que tiene esta estructura, pero hay que tener en
 * cuenta el padding de variables, es decir: el tamaño de unión o separación entre variables, por ejemplo:
 * Hay una estructura de esta forma:
 * struct{
 *      char a[3];      //sizeof = 3
 *      short int b;    //sizeof = 2
 *      long int c;     //sizeof = 4
 *      char d[3];      //sizeof = 3
 * }
 * y por lo anterior se creería que el tamaño sería de 12, modelado como:
 *   +-------+-------+-------+-------+
 *   |           a           |   b   |
 *   +-------+-------+-------+-------+
 *   |   b   |           c           |
 *   +-------+-------+-------+-------+
 *   |   c   |           d           |
 *   +-------+-------+-------+-------+
 * sin embargo esto es incorrecto, ya que el procesador lo visualiza así para una mayor facilidad:
 *   +-------+-------+-------+
 *   |           a           |
 *   +-------+-------+-------+
 *   |       b       |
 *   +-------+-------+-------+-------+
 *   |               c               |
 *   +-------+-------+-------+-------+
 *   |           d           |
 *   +-------+-------+-------+
 * Dejando espacios libres entre variables, pero por la misma organización, el procesador usa paddings para mentener
 * contiguos los espacios de la estructura, puesto que estas deben siempre formar una figura LxL es decir, un cuadrado
 * o un rectangolo completo, por ende termina siendo de esta manera:
 *   +-------+-------+-------+-------+
 *   |           a           | pad1  |
 *   +-------+-------+-------+-------+
 *   |       b       |     pad2      |
 *   +-------+-------+-------+-------+
 *   |               c               |
 *   +-------+-------+-------+-------+
 *   |           d           | pad3  |
 *   +-------+-------+-------+-------+
 *   Y su tamaño termina siendo de 16, se debe de tener esto en cuenta cuando se trabajen con estructuras o clases
 *   y que el acomodo en la visualización del procesador será iniciando con la primera variable y en delante.
 * */
struct Estructura{
    signed int id;
    char cadena[15];
};

/*Creación de una TDA Unión
 * ****************************************************************************************************
 * Las uniones son una estructura especial de C++ que almacena elementos de diferentes tipos en las mismas
 * posiciones de memoria, pero no de manera simultanea, es decir que la union tendrá el valor del tipo
 * actual al que se haga referencia.
 * El tamaño de las uniones viene dado por la variable interna de mayor tamaño, es decir que el sizeof()
 * de la union será igual al sizeof mayor de cualquiera de sus variables
 * */
union Union{
    int a;
    float b;
    long c;
};

/*Tamaño de cada variable primitiva existente:
 * ****************************************************************************************************
 * La instrucción "sizeof(var/type)" es usada para obtener el tamaño de un tipo de dato o de una variable en
 * particular pero esto es relativo a la máquina.
 * -Se debe tomar en cuenta que estos datos podrían cambiar de máquina a máquina ya que
 * el tamaño depende de la arquitectura y SO sobre el cuál se ejecuta siendo por ejemplo el caso
 * de un <long int>:
 * SO de 8 y 16 bits:   sizeof(long int) = 2
 * SO de 32 bits:       sizeof(long int) = 4
 * SO de 64 bits:       sizeof(long int) = 8
 * A continuación están todos los tipos de datos primitivos existentes y sus tamaños*/
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

/*Declaración
 * ****************************************************************************************************
 * Con declaración se refiere a hacer uso de un tipo de dato mediante la sintaxis
 * tipo_de_dato nombre_variable;
 * Donde tipo de dato es el nombre del tipo que queremos usar, ya sea uno primitivo o uno compuesto como
 * las estructuras, uniones, enumerados o clases(que se verán más adelante)
 * la instrucción de salida cout
 * está definida en el espacio de nombres de "std" el cuál se puede implementar mediante lo siguiente:
 *
 * using namespace std;
 *
 * para poder hacer lo siguiente:
 *
 * cout<<"Texto<<endl;
 *
 * o no incluirlo y tener que hacer esto:
 *
 * std::cout<<"Texto<<std::endl;
 *
 * como es el caso de este ejemplo, no se recomienda usar el "using namespace std" más que en el archivo main o principal
 * ya que podría causar un conflicto de nombres de espacio en otros archivos de cabecera*/
void muestraTiposDeDatos(){
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
    std::cout<<"Size of full struct: "  << sizeof(Estructura)   <<std::endl; //La struct toma el tamaño de la suma de sus componentes y el padding
    std::cout<<"Size of full union: "   << sizeof(Union)        <<std::endl; //la union toma el tamaño del elemento con el tamaño mayor
}

/*Variables y alcances
 * ****************************************************************************************************
 * Las variables pueden ser de 3 tipos:
 * Locales: están dentro de una función o método o el main y sus alcances y valores se reducen a estos.
 *          Estas tienen valores basura por defecto, es decir, un valor raro, que debe ser limpiado mediante la inicialización:
 *          variable = valor_de inicio; / variable = 0;
 * Globales: están fuera de una función, método o el main, y sus alcances son de todo el archivo y los otros archivos que los incluyan
 *          Estas tienen por defecto un valor 0 si son numericas o '\0' si son caracteres o cadenas
 * Externas: están en un archivo alejado del archivo de uso, y aún asi se puede usar, pero sus alcances y valores solo
 *              se extienden a donde se hacen referencia.
 *          Estas, al igual que las locales, tienen basura, y deben ser inicializadas, pero su inicialización alcanza a todos
 *          los ámbitos y no solo un archivo o área local
 * */
void muestraVariableExterna(){
    std::cout<<"Valor variable externa: "<<(++variableExterna)<<std::endl;
}

/*Identificadores de tipos
 * ****************************************************************************************************
 * Los identificadores son caracteres que permiten al compilador identificar de qué tipo de variable se trata,
 * normalmente no son usados por el programador, a menos que se está haciendo algo de bajo nivel, es decir con
 * mucha interacción directa al compilador, esta identificación es visualizada mediante el uso de:
 * typeid(variable).name()
 * esto regresa el caracter semántico de identificación de la variable*/
void muestraIdentificadores(){
    int a=10, b=20;
    std::cout<<std::endl<<"Identificadores de tipos de datos"<<std::endl<<std::endl;
    if(typeid(Entero) == typeid(int))  //typeid(tipo) regresa un type_info para comparar variables
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

/*La variable auto es una variable de tipo automático que permite inferir tipos de datos desconocidos,
 * de la familia del decltype(), estos 2 serán abordados más adelante como parte de C++11
 * dameTipo(var) es una función que permite regresar en modo cadena el tipo de la variable que se le otorga como parametro*/
std::string dameTipo(auto var){
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

/*Esta es una subrutina que permite hacer uso e impresión de la función anterior "dameTipo(var)"*/
void muestraDameTipos(){
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
    std::cout<<"La variable a es de tipo:  "<<dameTipo(a)<<std::endl;
    std::cout<<"La variable b es de tipo:  "<<dameTipo(b)<<std::endl;
    std::cout<<"La variable c es de tipo:  "<<dameTipo(c)<<std::endl;
    std::cout<<"La variable d es de tipo:  "<<dameTipo(d)<<std::endl;
    std::cout<<"La variable e es de tipo:  "<<dameTipo(e)<<std::endl;
    std::cout<<"La variable f es de tipo:  "<<dameTipo(f)<<std::endl;
    std::cout<<"La variable g es de tipo:  "<<dameTipo(g)<<std::endl;
    std::cout<<"La variable h es de tipo:  "<<dameTipo(h)<<std::endl;
    std::cout<<"La variable i es de tipo:  "<<dameTipo(i)<<std::endl;
    std::cout<<"La variable j es de tipo:  "<<dameTipo(j)<<std::endl;
    std::cout<<"La variable k es de tipo:  "<<dameTipo(k)<<std::endl;
}

/*Función de muestra de todo lo contenido en el archivo*/
void muestraTiposDatos(){
    muestraTamanioTiposDatos();
    muestraTiposDeDatos();
    muestraVariableExterna();
    muestraIdentificadores();
    muestraDameTipos();
}