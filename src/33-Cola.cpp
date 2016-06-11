//
// Created by carlo on 07/06/2016.
//
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef int Posicion;

template <typename T>
class Cola{
private:
    T** elementos;
    Posicion inicio;
    Posicion fin;
    int tamanio;
    int cantidad;
    const int tamanioDefault = 10;
public:
    Cola();
    Cola(int);
    void encola(T*);
    T* desencola();
    T* frente();
    T* fondo();
    bool estaVacia();
    bool estaLlena();
    string dameInfo();
    int getCantidad();
};

template <typename T>
Cola<T>::Cola(int tamanio){
    elementos = new T*[this->tamanio=tamanio];
    inicio=fin=cantidad=0;
}

template <typename T>
Cola<T>::Cola():Cola(tamanioDefault){}

template <typename T>
void Cola<T>::encola(T* elemento){
    if(!estaLlena()){
        elementos[fin++] = elemento;
        cantidad++;
    }
    if(fin>tamanio) fin-=tamanio+1;
}

template <typename T>
T* Cola<T>::desencola(){
    T* elemento;
    if(!estaVacia()){
        elemento = elementos[inicio++];
        cantidad--;
    }
    if(inicio>tamanio) inicio-=tamanio+1;
    return elemento;
}

template <typename T>
T* Cola<T>::frente(){
    return estaVacia()? nullptr:elementos[inicio];
}

template <typename T>
T* Cola<T>::fondo(){
    return estaVacia()? nullptr:elementos[fin-1];
}

template <typename T>
bool Cola<T>::estaVacia(){
    return cantidad==0;
}

template <typename T>
bool Cola<T>::estaLlena(){
    return cantidad==tamanio-1;
}

template <typename T>
string Cola<T>::dameInfo(){
    stringstream info;
    for (int i = inicio; i < fin; ++i)
        info<<elementos[i]->valor<<", ";
    return info.str();
}

template <typename T>
int Cola<T>::getCantidad(){
    return cantidad;
}

void colaPropia(){
    Cola<Entero>* enteros = new Cola<Entero>(5);
    cout<<enteros->estaLlena()<<endl;
    cout<<enteros->estaVacia()<<endl;
    cout<<enteros->dameInfo()<<endl;
    cout<<enteros->getCantidad()<<endl;
    enteros->encola(new Entero(15));
    cout<<enteros->frente()->valor<<endl;
    cout<<enteros->estaLlena()<<endl;
    cout<<enteros->estaVacia()<<endl;
    cout<<enteros->dameInfo()<<endl;
    cout<<enteros->getCantidad()<<endl;
    enteros->encola(new Entero(20));
    enteros->encola(new Entero(25));
    enteros->encola(new Entero(30));
    cout<<enteros->frente()->valor<<endl;
    cout<<enteros->dameInfo()<<endl;
    delete enteros->desencola();
    delete enteros->desencola();
    cout<<enteros->frente()->valor<<endl;
    cout<<enteros->fondo()->valor<<endl;
    cout<<enteros->dameInfo()<<endl;
    delete enteros;
}

void colaConQueue(){
    queue<Entero*> enteros;
    cout<<enteros.empty()<<endl;
    cout<<enteros.size()<<endl;
    enteros.push(new Entero(15));
    cout<<enteros.front()->valor<<endl;
    cout<<enteros.size()<<endl;
    cout<<enteros.empty()<<endl;
    enteros.push(new Entero(20));
    enteros.push(new Entero(25));
    enteros.push(new Entero(30));
    cout<<enteros.front()->valor<<endl;
    cout<<enteros.back()->valor<<endl;
    enteros.pop();
    enteros.pop();
    cout<<enteros.front()->valor<<endl;
}

void muestraCola(){
    colaPropia();
    colaConQueue();
}