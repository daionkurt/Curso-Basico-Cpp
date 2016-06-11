//
// Created by Carlos Andrés Fernández Jalomo on 31/05/2016.
// correo: carlosfdez@outlook.com
//
#include <iostream>
#include <iomanip>      //Cabecera que contiene manipuladores de salida e impresión
#include <ctime>

using namespace std;
using std::setw;

/*Arreglos
 * ****************************************************************************************************
 * Los arreglos son colecciones de objetos de un determinado tipo, agrupados para formar una sola entidad
 * es decir, es como si tuvieramos muchos objetos bajo un solo identificador, pero esta indentificador
 * tuviera casillas, y cada objeto se guardara en 1 casillas. Ejemplo, tenemos un espacio que queremos llenar
 * con cajas, podríamos definir caja por caja de manera individual:
 *   +-------+   +-------+    +-------+    +-------+
 *   |   a   |   |   b   |    |   c   |    |   d   |
 *   +-------+   +-------+    +-------+    +-------+
 *   Pero tendriamos variables llamadas: caja1, caja2, caja3, caja4, y esto puede volverse tedioso e imposible
 *   en estos casos, mejor usamos arreglos que una elementos de un mismo tipo. Creamos un arreglo que se llame
 *   "Cajas" y entonces lo ponemos de tamaño 4, y en lugar de caja1, caja2, etc... tendríamos un mismo
 *   identificador "Cajas" pero con indices (se usan [] para indicar índices y siempre comienza en el indice 0)
 *   , como cajas[0], cajas[1], cajas[2]:
 *   +-------+-------+-------+-------+
 *   |   a   |   b   |   c   |   d   |
 *   +-------+-------+-------+-------+
 *      [0]     [1]     [2]     [3]
 *    En los arreglos, si declaramos el arreglo de 4, sus posiciones iran del 0 al 3, siempre el inicio es el 0
 *    y la posición maxima, es  N-1, en caso de usar un índice fuera de esto, podrían causar errores
 * ****************************************************************************************************
 * Formas de inicializar arreglos*/
void arreglosSimples(){
    //int enteros[10];                          //se declara el tamaño pero no se inicializa con algun valor establecido
    //int enteros[10] = {1,2,3,4,5,6,7,8,9,10}; //se declara con el tamaño y aparte usando una lista de inicialización
                                                // se dan valores a las posiciones
    int enteros[] = {1,2,3,4,5,6,7,8,9,10};     //no se declara el tamaño pero se infiere por la cantidad de elementos
                                                // de la lista de inicialización
    cout<<"Element"<<setw(13)<<"Value"<<endl;
    /*Podemos usar iterativas para recorrer los arreglos, ya que sus posiciones son contiguas
     * Recoremos que siempre debemos ir dese 0 que es la posición inicial, hasta N-1 o en los bucles
     * mientras que i sea menor al tamaño del arreglo*/
    for(int i=0;i<10;i++){
        cout<<setw(7)<<i<<setw(13)<<enteros[i]<<endl;   //setw(N) sirve para formatear al salida dandole espaciado
    }
}
/*Tambien se puedne declarar arreglos de dos dimensiones, en este caso alto y ancho*/
void arreglosMultidimensionales(){
    int enteros[3][4] = {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    }; //esta es una forma visualmente más entendible de inicializar una matriz de 3x4
    //int entero[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};   //tambien se podría ser así, y obtiene la posición
                                                        // automáticamente según el tamaño designado
    cout<<enteros[2][3]<<endl;
    for(int i=0;i<3;i++) {
        for (int j=0;j<4;j++) {
            cout << "a[" << i << "][" << j << "]: " << enteros[i][j] << endl;
        }
    }
}

/*Los punteros como son variables dinámicas tambien pueden funcionar como arreglos, al tener un espacio ternicamente libre
 * de asignación de elementos, el apuntador sirve como inicio del arreglo y enlaza a los demás*/
void punterosArreglos(){
    int enteros[5] = {1,2,3,4,5};
    int* puntero;
    puntero = enteros;
    cout<<"Valores del arreglo usando el puntero"<<endl;
    for (int i = 0; i < 5; ++i) {
        cout<<"*(puntero) + "<<i<<"): "<<*(puntero+i)<<endl;
    }
    cout<<"Valores del arreglo usando el arreglo como direccion"<<endl;
    for (int i = 0; i < 5; ++i) {
        cout<<"*(enteros) + "<<i<<"): "<<*(enteros+i)<<endl;
    }
}

/*La forma en que se retorna un arreglo es indicando el apuntador del tipo del arreglo a retornar*/
int* getRandom(){
    static int arreglo[10];
    srand((unsigned)time(nullptr));
    for (int i = 0; i < 10; ++i) {
        arreglo[i] = rand();
        cout<<arreglo[i]<<endl;
    }
    return arreglo;
}

void retornarArreglos(){
    int* puntero;
    puntero = getRandom();      //El arreglo puntero es obtenido de la función de getRandom()
    for(int i=0;i<10;i++){
        cout<<"*(puntero+"<<i<<"): "<<*(puntero+i)<<endl;
    }
}

/*la manera en que se pasa por parámetro un arreglo, es igual, pasando el tipo por apuntador
 * con la notación <tipo_dato>* nombre_de_arreglo */
double funcion1(int* parametro,int size){
    int suma=0;
    for (int i = 0; i < size; ++i) {
        suma+=parametro[i];
    }
    return double(suma)/size;
}
/*La segunda forma de pasarlo es indicarlo como un arreglo con su tamaño
 * con la notación <tipo_dato> nombre_de_arreglo[tamanio] */
double funcion2(int parametro[10],int size){
    int suma=0;
    for (int i = 0; i < size; ++i) {
        suma+=parametro[i];
    }
    return double(suma)/size;
}

/*La tercera forma de pasarlo es indicarlo como un arreglo sin su tamaño, para ser inferido o pasar el size del parámetro
 * con la notación <tipo_dato> nombre_de_arreglo[] */
double funcion3(int parametro[],int size){
    int suma=0;
    for (int i = 0; i < size; ++i) {
        suma+=parametro[i];
    }
    return double(suma)/size;
}

template<class T, size_t N>
size_t getLenght(T (&)[N]){
    return N;
}

/*Esta es una función que nos retorna la cantidad de elementos que tiene un arreglo*/
template<class T>
int lenght(T &elemento){
    return (sizeof(elemento)/sizeof(*elemento));
}

void pasarArreglos(){
    int arreglo[5] = {1,2,3,4,5};
    double promedio;
    promedio = funcion1(arreglo,getLenght(arreglo));
    cout<<"Promedio es: "<<promedio<<endl;
    promedio = funcion2(arreglo,getLenght(arreglo));
    cout<<"Promedio es: "<<promedio<<endl;
    promedio = funcion3(arreglo,getLenght(arreglo));
    cout<<"Promedio es: "<<promedio<<endl;
    cout << "Length = " << lenght(arreglo)<<endl;
}

void muestraArreglos(){
    arreglosSimples();
    arreglosMultidimensionales();
    punterosArreglos();
    retornarArreglos();
    pasarArreglos();
}