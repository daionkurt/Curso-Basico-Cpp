//
// Created by carlo on 01/06/2016.
//
#include <iostream>

using namespace std;

class Box{
public:
    Box(){
        cout<<"Construido!"<<endl;
    }
    ~Box(){
        cout<<"Destruido!"<<endl;
    }
};

void muestraMemoriaDinamica(){
    double* valor = nullptr;
    if(!(valor=new double)){
        cout<<"Error"<<endl;
    }else{
        cout<<"Bien"<<endl;
    }
    delete valor;
    double* a = new double;
    *a = 12345.99;
    cout<<"Valor de a: "<<*a<<endl;
    delete a;
    char* b = new char[20];
    delete[] b;
    double** arreglo = new double*[4];
    for (int i = 0; i < 4; ++i) {
        arreglo[i] = new double[3];
    }
    signed short contador=0;
    for (int j = 0; j <4; ++j) {
        for (int i = 0; i < 3; ++i) {
            arreglo[j][i] = contador;
        }
    }
    delete[] arreglo;

    cout<<"Inicializar y eliminar arreglo 1 dimensión"<<endl;
    Box* arregloBox = new Box[4];
    delete[] arregloBox;
    cout<<"Inicializar y eliminar arreglo 2 dimensión"<<endl;
    Box** segundo = new Box*[3];
    for (int i = 0; i < 3; ++i) {
        segundo[i] = new Box[3];
    }
    for (int i = 0; i < 3; ++i) {
        delete[] segundo[i];
    }
    delete[] segundo;
    cout<<"Inicializar y eliminar arreglo 3 dimensión"<<endl;
    int altura=2,anchura=3,profundidad=4;
    Box*** tercero = new Box**[altura];
    for (int i = 0; i < altura; ++i) {
        tercero[i] = new Box*[anchura];
        for (int j = 0; j < anchura; ++j) {
            tercero[i][j] = new Box[profundidad];
        }
    }
    for (int i = 0; i < altura; ++i) {
        for (int j = 0; j < anchura; ++j) {
            delete[] tercero[i][j];
        }
        delete[] tercero[i];
    }
    delete[] tercero;

}
