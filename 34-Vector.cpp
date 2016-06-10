//
// Created by carlo on 07/06/2016.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void printout(T elemento){
    cout<<elemento->valor<<", ";
}

void muestraVector(){
    vector<Entero*>* enteros = new vector<Entero*>();
    vector<Entero*>* copia;
    cout<<enteros->size()<<endl;
    enteros->shrink_to_fit();
    cout<<enteros->size()<<endl;
    enteros->insert(enteros->end(),new Entero(4));
    enteros->insert(enteros->end(),new Entero(5));
    enteros->insert(enteros->end(),new Entero(6));
    enteros->insert(enteros->end(),new Entero(7));
    enteros->insert(enteros->end(),new Entero(8));
    enteros->insert(enteros->end(),new Entero(9));
    cout<<enteros->size()<<endl;
    cout<<enteros->at(0)->valor<<endl;
    enteros->insert(enteros->end(),new Entero(10));
    enteros->push_back(new Entero(12));
    cout<<enteros->size()<<endl;
    for_each(enteros->begin(),enteros->end(),printout<Entero*>);
    enteros->erase(enteros->begin()+2);
    cout<<endl;
    for_each(enteros->begin(),enteros->end(),printout<Entero*>);
    enteros->erase(enteros->begin(),enteros->begin()+3);
    cout<<endl;
    for_each(enteros->begin(),enteros->end(),printout<Entero*>);
    cout<<endl;
    cout<<enteros->capacity()<<endl;
    cout<<enteros->size()<<endl;
    enteros->shrink_to_fit();
    cout<<enteros->capacity()<<endl;
    cout<<enteros->size()<<endl;
}