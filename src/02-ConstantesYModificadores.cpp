//
// Created by Carlos Andrés Fernández Jalomo on 30/05/2016.
// correo: carlosfdez@outlook.com
//
#include <iostream>

/*Macro-definiciones
 * ****************************************************************************************************
 * Las macro definiciones son basicamente un alias que podemos usar en el código, en el cual por ser una definición a
 * nivel de compilador serán reemplazados en tiempo de compilación por el valor o expresión dada a su derecha, y se
 * usa la directiva #define para establecerlos
 * Si sintáxis es:  #define "ALIAS_SIN_ESPACIOS" "valor o expresión"
 * por ejemplo en el que está debajo:
 * #define LENGTH 10, se indica que hay una directiva llamada LENGTH(su alias) que tiene un valor 10, cuando en una
 * parte del código se use LENGTH, cuando se compile, este se reemplazará por un 10, que es su valor definido
 * cout<<LENGTH<<endl       una vez compilado sería como        cout<<10<<endl;
 * */
#define LENGTH 10
#define WIDTH 5

/*Espacios de nombres
 * ****************************************************************************************************
 * Esto es la llamada a un espacio de nombres, significaría: "Usted ha incluido el fichero de cabecera y
 * quiere hacer uso de todos los elementos del espacio std sin tener que indicar explicitamente que pertenecen a este
 * y para no causar conflictos con otros nombres, en este caso std tiene contenido cout, cin, endl, y demás directivas
 * que usamos en el archivo pasado, y que invocabamos mediante std::cout y std::endl, ahora
 * haciendo "using" del espacio de nombres "std", podemos invocarlos directamente como cout y endl*/
using namespace std;

/*Literales
 * ****************************************************************************************************
 * Las literales son identificadores numericos, alfabéticos o semánticos que permiten identificar el tipo de
 * notación o forma en que se expresa una variable, es decir, si queremos que un entero sea hexadecimal, decimal,
 * octal, etc. Pero tambien existen literales de cadena y caracter que sirven como secuencias de escape (
 * indicadores de funcionamiento) para el cout, que es el flujo de salida del programa*/
void muestraLiterales(){
    cout<<"Literales Enteras"<<endl;
    int a,b,c,d,e,f,g;
    a=212;      //Esto es un número cuya literal implicita es la del decimal por no especificarse otra cosa
    b=215u;     //Esto es un número cuya literal indica que es un numero sin signo
    c=0xFeeL;   //Esto es la notación de un número hexadecimal tipo Long
                //NOTA: 0x indica hexadecimal, y la L al final indica Long, quedando el valor en "Fee" que es 4078
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    /*Literales enteras es la forma en la que se puede representar un entero en distintas notaciones*/
    a=85;   //decimal
    b=0213; //octal
    c=0x4b; //hexadecimal
    d=30;   //int
    e=30u;  //unsigned int
    f=30l;  //long
    g=30ul; //unsigned long
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<d<<endl;
    cout<<e<<endl;
    cout<<f<<endl;
    cout<<g<<endl;
    cout<<"Literales flotantes"<<endl;
    float af,bf,cf,df;
    af=3.14159;         //Con punto decimal explicito
    bf=314159E-5L;      //Con notación de exponente
                        //Ambos son iguales una vez impresos/usados
    cout<<af<<endl;
    cout<<bf<<endl;
    /*Las literales de caracter sirven como escape de impresión, es decir, hay ciertos caracteres propios del lenguaje
     * que no se permiten imprimir asi como asi, ejemplos: ' " ? * \  porque el compilador los interpreta como
     * instrucciones del lenguaje y no como caracteres imprimibles, para evitar eso se deben anteponer al caracter
     * '\' para que el compilador los detecte como imprimibles, */
    cout<<"Literales de caracter"<<endl;
    cout<<"\\"<<endl; //imprime el caracter  '\'
    cout<<"\'"<<endl; //imprime el caracter  '''
    cout<<"\""<<endl; //imprime el caracter '"'
    cout<<"\?"<<endl; //imprime el caracter  '?'
    cout<<"\a"<<endl; //Hace sonar la alarma del sistema
    cout<<"\b"<<endl; //Da un backspace
    cout<<"\n"<<endl; //Hace un salto de linea
    cout<<"\r"<<endl; //Hace una corrida de carro (Salto de linea)
    cout<<"\t"<<endl; //Da un tabulador al imprimir
    cout<<"Literales de cadena"<<endl;
    cout<<"hello, dear"<<endl;
    cout<<"hello,\
            dear"<<endl;
    cout<<"hello, "
            "d"
            "ear"<<endl;
    /*Las literales de cadena permiten a una cadena extenderse, fragmentarse y absorver otras cadenas mediante el uso de
     * " " " contiguas, lo que indica que la cadena sigue, o con \ para indicar un tabulador de 8 espacios
     * Tambien existen las cadenas RAW que imprimen tal cual se muestran, pero eso se verá en otro archivo más adelante*/
}

/*Modificadores
 * ****************************************************************************************************
 * Los modificadores son palabras reservadas que hacen que la variable por si sola obtenga propiedades unicas,
 * por ejemplo los modificadores:
 * - unsigned: significa que el valor no puede tener signo, es decir solo abarca los positivos
 * - signed: significa que el valor puede o no, tener signo, es decir abarca la totalidad del especto
 *      bit     unsigned    signed
 *      000     0            0
 *      001     1            1
 *      010     2            2
 *      011     3            3
 *      100     4           -4
 *      101     5           -3
 *      110     6           -2
 *      111     7           -1
 *
 * - const: significa que el valor es constante pero solo en tiempo de ejecución, es decir que el compilador no sabe
 *          que es constante hasta que el programa ya comenzó a ejecutarse
 * - constexpr: significa que el valor es constante desde el tiempo de compilación, es decir que el compilador
 *          antes de ejecutar el programa, ya sabe que esto es una expresión constante y permite hacer operaciones
 *          sobre ellas, cosa que no sucede con const
 * */
void muestraModificadores(){
    constexpr int value = 10; //Constante en tiempo de compilación
    const int constVal = 20; //Constante en tiempo de ejecución
    short int i;
    short unsigned int j;
    short signed int k = WIDTH*LENGTH;
    j=50000;
    i=j;
    cout<<"Modificadores"<<endl;
    cout<<i<<" "<<j<<endl;
    cout<<value<<endl;
    cout<<constVal<<endl;
    cout<<k<<endl;
    cout<<sizeof(int)<<endl;
    cout<<sizeof(unsigned int)<<endl;
    cout<<sizeof(signed int)<<endl;
    cout<<"Modificadores externos"<<endl;
    /*Las variables de tipo volatil indica que si bien la optimización puede cambiar el while del ejemplo a while(true) debido
     * a que aparentemente no tiene forma de salir del bucle, el que sea de tipo volatile indica que algun factor externo que
     * el compilador no alcanza a vislumbrar, puede cambiar la variable y romper el bucle, por ende no se optimiza a while(true)*/
    volatile int volatil=0;
    while(volatil==0){
        cout<<volatil--<<endl;
    }
    cout<<"Hola Mundo"<<endl;
}

void muestraConstantesModificadores(){
    muestraLiterales();
    muestraModificadores();
}