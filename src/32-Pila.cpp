//
// Created by carlo on 07/06/2016.
//
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

typedef int Posicion;

template <typename T>
class Pila{
private:
    T** elementos;
    Posicion tope;
    int cantidad;
    const int cantidadDefault = 10;
public:
    Pila();
    Pila(int);
    ~Pila();
    void apila(T*);
    T* desapila();
    T* dameTope();
    bool estaVacia();
    bool estaLlena();
    string dameInfo();
};

template <typename T>
Pila<T>::Pila(int cantidad){
    elementos = new T*[this->cantidad=cantidad];
    tope=-1;
}

template <typename T>
Pila<T>::Pila():Pila(cantidadDefault){}

template <typename T>
Pila<T>::~Pila(){
    delete elementos;
}

template <typename T>
void Pila<T>::apila(T* elemento){
    elementos[++tope] = elemento;
}

template <typename T>
T* Pila<T>::desapila(){
    return !estaVacia()?elementos[tope--]:-1;
}

template <typename T>
T* Pila<T>::dameTope(){
    return !estaVacia()?elementos[tope]: nullptr;
}

template <typename T>
bool Pila<T>::estaVacia(){
    return tope==-1;
}

template <typename T>
bool Pila<T>::estaLlena(){
    return tope==cantidad-1;
}

template <typename T>
string Pila<T>::dameInfo(){
    stringstream info;
    for (int i = 0; i <= tope; ++i)
        info<<elementos[i]->valor<<", ";
    return info.str();
}

void pilaPropia(){
    Pila<Entero>* enteros = new Pila<Entero>(5);
    cout<<enteros->estaVacia()<<endl;
    cout<<enteros->dameTope()<<endl;
    enteros->apila(new Entero(1));
    enteros->apila(new Entero(2));
    enteros->apila(new Entero(3));
    enteros->apila(new Entero(4));
    cout<<enteros->estaVacia()<<endl;
    cout<<enteros->estaLlena()<<endl;
    cout<<enteros->dameInfo()<<endl;
    delete enteros;
}

void pilaConStack(){
    cout<<"Con Stack"<<endl;
    stack<Entero> enteros;
    stack<float> flotantes;
    Entero a(9);
    enteros.push(a);
    enteros.emplace(15);
    cout<<enteros.size()<<endl;
    cout<<enteros.top().valor<<endl;
    enteros.pop();
    cout<<enteros.size()<<endl;
    flotantes.push(1.2);
    flotantes.push(2.4);
    flotantes.push(3.6);
    flotantes.push(4.8);
    flotantes.push(5.0);
    for (int i = 0,j = flotantes.size(); i < j; ++i) {
        cout<<flotantes.top()<<endl;
        flotantes.pop();
    }
    flotantes.push(4.8);
    flotantes.push(5.0);
    flotantes.emplace(6.7);
    for (int i = 0,j = flotantes.size(); i < j; ++i) {
        cout<<flotantes.top()<<endl;
        flotantes.pop();
    }
}

void muestraPila(){
    pilaPropia();
    pilaConStack();
}