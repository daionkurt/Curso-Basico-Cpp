//
// Created by carlo on 07/06/2016.
//
#include <iostream>
#include <array>
#include <list>
#include <algorithm>

using namespace std;

typedef int Posicion;

template <typename T>
class Lista{
private:
    T** elementos;
    Posicion ult;
    string nombre;
    int capacidad;
    const Posicion IndexOutOfBounds=-1;
    const int capacidadDefecto=30;
public:
    Lista();
    Lista(string,int);
    ~Lista();
    bool inserta(T*);
    bool inserta(T*,Posicion);
    Posicion localiza(T*);
    T* recupera(Posicion);
    T* suprime(Posicion);
    Posicion primero();
    Posicion ultimo();
    Posicion fin();
    Posicion anterior(Posicion);
    Posicion siguiente(Posicion);
    bool estaVacia();
    bool estaLlena();
    int getLength();
    int getCapacidad();
    void purga();
    Lista* concatena(Lista&);
    bool igual(T*,T*);
    void imprime();
    string getNombre();
};

template <typename T>
Lista<T>::Lista(string nombre,int capacidad){
    ult = IndexOutOfBounds;
    this->nombre = nombre;
    elementos = new T*[this->capacidad=capacidad];
}

template <typename T>
Lista<T>::Lista():Lista("NaN",capacidadDefecto){}

template <typename T>
Lista<T>::~Lista(){
    while(!estaVacia()){
        delete suprime(primero());
    }
    delete[] elementos;
}

template <typename T>
bool Lista<T>::inserta(T* elemento,Posicion posicion){
    if(estaLlena()){
        T** temp = new T*[capacidad+1];
        for (int i = 0; i < capacidad; ++i) {
            temp[i] = elementos[i];
        }
        delete elementos;
        elementos = temp;
        capacidad++;
    }
    if(posicion>=primero() && posicion<=fin()){
        for (Posicion p = ult; p>=posicion; p--) {
            elementos[p+1] = elementos[p];
        }
        ult++;
        elementos[posicion] = elemento;
        return true;
    }else return nullptr;
}

template <typename T>
bool Lista<T>::inserta(T* elemento){
    return inserta(elemento,fin());
}

template <typename T>
Posicion Lista<T>::localiza(T* elemento){
    for(Posicion p=primero(),q=ult;p!=q;p=siguiente(p)){
        if(igual(recupera(p),elemento)){
            return p;
        }
    }
    return fin();
}

template <typename T>
T* Lista<T>::recupera(Posicion posicion){
    return (posicion>=primero() && posicion<=ult)?elementos[posicion]: nullptr;
}

template <typename T>
T* Lista<T>::suprime(Posicion posicion){
    Posicion p,q;
    T* eliminado;
    if(posicion>=primero() && posicion<=ult){
        q=--(ult);
        eliminado = elementos[posicion];
        for(p=posicion;p<=q;p++) {
            elementos[p] = elementos[p + 1];
        }
        return eliminado;
    }else return nullptr;
}

template <typename T>
Posicion Lista<T>::primero(){
    return (!estaVacia())?0:fin();
}

template <typename T>
Posicion Lista<T>::ultimo(){
    return (estaVacia())?IndexOutOfBounds:anterior(fin());
}

template <typename T>
Posicion Lista<T>::fin(){
    return ult+1;
}

template <typename T>
Posicion Lista<T>::anterior(Posicion posicion){
    return (posicion>=primero() && posicion<=fin())?posicion-1:IndexOutOfBounds;
}

template <typename T>
Posicion Lista<T>::siguiente(Posicion posicion){
    return (posicion>=primero() && posicion<=ult)?posicion+1:IndexOutOfBounds;
}

template <typename T>
bool Lista<T>::estaVacia(){
    return ult<=IndexOutOfBounds;
}

template <typename T>
bool Lista<T>::estaLlena(){
    return ult>=capacidad-1;
}

template <typename T>
int Lista<T>::getLength(){
    return ult+1;
}

template <typename T>
int Lista<T>::getCapacidad(){
    return capacidad;
}

template <typename T>
void Lista<T>::purga(){
    Posicion q;
    for(Posicion p=primero();p!=fin();p=siguiente(p)){
        q=siguiente(p);
        while(q!=fin()) {
            if(igual(recupera(p),recupera(q))) delete suprime(q);
            else q=siguiente(q);
        }
    }
}

template <typename T>
Lista<T>* Lista<T>::concatena(Lista& lista) {
    Lista<T>* m = new Lista;
    Posicion p=primero(),q=fin();
    while(p!=q){
        m->inserta(recupera(p));
        p=siguiente(p);
    }
    p=lista.primero();
    q=lista.fin();
    while(p!=q){
        m->inserta(lista.recupera(p));
        p=lista.siguiente(p);
    }
    return m;
}

template <typename T>
bool Lista<T>::igual(T* a,T* b){
    return a!= nullptr && b!= nullptr && (a)->valor==(b)->valor;
}

template <typename T>
void Lista<T>::imprime(){
    for(Posicion p=primero(),q=fin();p!=q;p=siguiente(p)){
        cout<<"Elemento: "<<recupera(p)->valor<<endl;
    }
}

template <typename T>
string Lista<T>::getNombre(){
    return nombre;
}

class Entero{
public:
    int valor;
    Entero(int valor){
        this->valor=valor;
    }
};

class Flotante{
public:
    float valor;
    Flotante(float valor){
        this->valor=valor;
    }
};

void listaPropia(){
    Lista<Entero> enteros("Lista de enteros",10);
    Lista<Flotante>* flotantes = new Lista<Flotante>("Lista de flotantes",5);
    cout<<enteros.getNombre()<<", "<<enteros.getCapacidad()<<", "<<enteros.getLength()<<endl;
    cout<<flotantes->getNombre()<<", "<<flotantes->getCapacidad()<<", "<<flotantes->getLength()<<endl;
    enteros.inserta(new Entero(1));
    enteros.inserta(new Entero(2));
    enteros.inserta(new Entero(3));
    enteros.inserta(new Entero(4));
    flotantes->inserta(new Flotante(2.1));
    flotantes->inserta(new Flotante(3.2));
    flotantes->inserta(new Flotante(4.3));
    flotantes->inserta(new Flotante(5.4));
    enteros.imprime();
    flotantes->imprime();
    cout<<enteros.getNombre()<<", "<<enteros.getCapacidad()<<", "<<enteros.getLength()<<endl;
    cout<<flotantes->getNombre()<<", "<<flotantes->getCapacidad()<<", "<<flotantes->getLength()<<endl;
    delete enteros.suprime(2);
    enteros.imprime();
    enteros.inserta(new Entero(7),1);
    cout<<enteros.localiza(new Entero(7))<<endl;
    enteros.imprime();
    cout<<enteros.recupera(2)->valor<<endl;
    cout<<enteros.recupera(enteros.anterior(2))->valor<<endl;
    cout<<enteros.recupera(enteros.siguiente(2))->valor<<endl;
    cout<<enteros.recupera(enteros.primero())->valor<<endl;
    cout<<enteros.recupera(enteros.ultimo())->valor<<endl;
    cout<<"vacia: "<<enteros.estaVacia()<<endl;
    cout<<"llena: "<<enteros.estaLlena()<<endl;
    cout<<enteros.igual(enteros.recupera(0),enteros.recupera(0))<<endl;
    cout<<enteros.igual(enteros.recupera(0),enteros.recupera(1))<<endl;
    enteros.inserta(new Entero(0));
    enteros.inserta(new Entero(0));
    enteros.inserta(new Entero(0));
    enteros.inserta(new Entero(0));
    enteros.imprime();
    enteros.purga();
    enteros.imprime();
    cout<<enteros.getNombre()<<", "<<enteros.getCapacidad()<<", "<<enteros.getLength()<<endl;
    delete flotantes;
}

template <typename T>
void print(T e){
    cout<<e<<" ";
}

void listaConArray(){
    array<int,5> enteros;
    array<float,4> flotantes{{4.1,3.2,2.3,1.4}};
    enteros[0] = 10;
    enteros[1] = 15;
    enteros[2] = 20;
    enteros[3] = 25;
    enteros[4] = 30;
    cout<<enteros.at(0)<<endl;
    cout<<get<1>(enteros)<<endl;
    for(auto& s: flotantes){
        cout<<s<<" ";
    }
    sort(flotantes.begin(),flotantes.end());
    cout<<endl;
    for_each(flotantes.begin(),flotantes.end(),print<float>);
    cout<<endl;
    for_each(enteros.begin(),enteros.end(),print<int>);
}

void listaConList(){
    list<int> enteros;
    list<int>::iterator iterator1;
    iterator1 = enteros.begin();
    cout<<enteros.empty()<<endl;
    enteros.insert(iterator1,1);
    enteros.insert(iterator1,2);
    enteros.insert(iterator1,4);
    enteros.insert(iterator1,3);
    enteros.insert(iterator1,2);
    enteros.insert(iterator1,1);
    cout<<enteros.front()<<endl;
    cout<<enteros.back()<<endl;
    for_each(enteros.begin(),enteros.end(),print<int>);
    cout<<endl;
    enteros.sort();
    for_each(enteros.begin(),enteros.end(),print<int>);
    cout<<endl;
    enteros.remove(1);
    enteros.unique();
    enteros.push_back(5);
    enteros.push_front(9);
    for_each(enteros.begin(),enteros.end(),print<int>);
    cout<<endl;
    enteros.pop_back();
    enteros.pop_front();
    for_each(enteros.begin(),enteros.end(),print<int>);
}

void muestraLista(){
    listaPropia();
    listaConArray();
    listaConList();
}
