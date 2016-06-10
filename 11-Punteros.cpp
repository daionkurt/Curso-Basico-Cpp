//
// Created by carlo on 31/05/2016.
//
#include <iostream>
#include <ctime>

using namespace std;

void punteros(){
    int integer = 30;
    int* integerPointer;
    int* numeros;
    int** libros;
    integerPointer = &integer;
    cout<<"Valor de la variable: "<<integer<<endl;
    cout<<"Direccion almacenada en el pointer: "<<integerPointer<<endl;
    cout<<"Valor del pointer: "<<*integerPointer<<endl;
    *integerPointer = 60;
    cout<<"Valor de la variable: "<<integer<<endl<<endl;
    cout<<"Apuntadores como arreglos dinamicos: "<<integer<<endl;
    numeros = new int[5];
    for (int i = 0; i < 5; ++i) {
        numeros[i] = i*2;
        cout<<numeros[i]<<endl;
    }
    libros = new int*[2];
    int contador=1;
    for (int i = 0; i < 2; ++i) {
        libros[i] = new int[2];
        for (int j = 0; j < 2; ++j) {
            libros[i][j]=contador++;
            cout<<libros[i][j]<<", ";
        }
    }
    cout<<"FIN"<<endl;
    delete integerPointer;
    integerPointer = nullptr;
    for (int k = 0; k < 2; ++k) {
        delete libros[k];
    }
    delete libros;
}

void nullPointers(){
    int* puntero = nullptr;
    cout<<"Valor del puntero: "<<puntero<<endl;
    if(puntero) cout<<"Existe"<<endl;
    if(!puntero) cout<<"No existe"<<endl;
}

void punterosAritmeticos(){
    const int MAX = 3;
    int arreglo[] = {1,2,3};
    int* puntero;
    puntero = arreglo;
    for (int i = 0; i < MAX; ++i) {
        cout<<"Direccion del arreglo["<<i<<"] = "<<puntero<<endl;
        cout<<"Varor del arreglo["<<i<<"] = "<<*puntero<<endl;
        puntero++;
    }
    puntero = &arreglo[MAX-1];
    for (int j = MAX; j > 0; --j) {
        cout<<"Direccion del arreglo["<<j<<"] = "<<puntero<<endl;
        cout<<"Varor del arreglo["<<j<<"] = "<<*puntero<<endl;
        puntero--;
    }
    puntero = arreglo;
    int i=0;
    while(puntero <= &arreglo[MAX-2]){
        cout<<"Direccion del arreglo["<<i<<"] = "<<puntero<<endl;
        cout<<"Varor del arreglo["<<i<<"] = "<<*puntero<<endl;
        puntero++;
        i++;
    }
    delete puntero;
    puntero = nullptr;
}

void punterosContraArreglos(){
    int arreglo[] = {5,10,15};
    int* puntero;
    puntero = arreglo;
    for (int i = 0; i < 3; ++i) {
        cout<<"Direccion del arreglo["<<i<<"] = "<<puntero<<endl;
        cout<<"Varor del arreglo["<<i<<"] = "<<*puntero<<endl;
        puntero++;
    }
    for (int j = 0; j < 3; ++j) {
        *arreglo = j;
    }
    delete puntero;
    puntero = nullptr;
}

void arreglosDePunteros(){
    int arreglo[] = {1,2,3};
    int *puntero[3];
    for (int i = 0; i < 3; ++i) {
        puntero[i] = &arreglo[i];
    }
    for (int j = 0; j < 3; ++j) {
        cout<<"Valor del puntero["<<j<<"] = "<<*puntero[j]<<endl;
    }
    const char *nombres[3] = {
            "Carlos Andres",
            "Eduardo Villanueva",
            "Vidal Sanchez"
    };
    for (int k = 0; k < 3; ++k) {
        cout<<"Valor de nombres["<<k<<"] = "<<nombres[k]<<endl;
    }
}

void punteroAPuntero(){
    int entero;
    int* apuntador;
    int** puntero;
    entero = 1000;
    apuntador = &entero;
    puntero = &apuntador;
    cout<<"Valor de entero: "<<entero<<endl;
    cout<<"Valor del apuntador: "<<*apuntador<<endl;
    cout<<"Valor del puntero: "<<**puntero<<endl;
}

void dameSegundos(unsigned long *sec){
    *sec = 60;
}

double damePromedio(int* arreglo,int size){
    int suma=0;
    for (int i = 0; i < size; ++i) {
        suma+=arreglo[i];
    }
    return double(suma)/size;
}

void pasandoPunteros(){
    unsigned long sec;
    dameSegundos(&sec);
    cout<<"Segundos: "<<sec<<endl;
    int arreglo[] = {1,2,3,4,5,6};
    double promedio = damePromedio(arreglo,lenght(arreglo));
    cout<<"El promedio es: "<<promedio<<endl;
}

int* dameNumerosRandom(){
    static int numeros[10];
    srand((unsigned)time(nullptr));
    for (int i = 0; i < 10; ++i) {
        numeros[i] = rand();
        cout<<numeros[i]<<endl;
    }
    return numeros;

}

void recibiendoPunteros(){
    int* puntero;
    puntero = dameNumerosRandom();
    for (int i = 0; i < 10; ++i) {
        cout<<"*(puntero+"<<i<<"): "<<*(puntero+i)<<endl;
    }
    delete puntero;
}

void muestraPunteros(){
    punteros();
    nullPointers();
    punterosAritmeticos();
    punterosContraArreglos();
    arreglosDePunteros();
    punteroAPuntero();
    pasandoPunteros();
    recibiendoPunteros();
}