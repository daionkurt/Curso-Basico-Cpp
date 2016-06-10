//
// Created by carlo on 01/06/2016.
//
#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
inline T const& max(T const& a,T const& b){
    return a<b?b:a;
}

template <typename T>
inline T min(T& a,T& b){
    return a>b?b:a;
}

template <class T>
class Array{
private:
    vector<T> elementos;
public:
    void agrega(T elemento){
        elementos.push_back(elemento);
    }
    void elimina(){
        if(estaVacia()){
            throw  out_of_range("Vacia");
        }
        elementos.pop_back();
    }
    T top(){
        if(estaVacia()){
            throw  out_of_range("Vacia");
        }
        return elementos.back();
    }
    inline bool estaVacia(){
        return elementos.empty();
    }
};


void muestraTemplates(){
    int a=29,b=40;
    cout<<"max: "<<max(a,b)<<endl;
    cout<<"min: "<<min(a,b)<<endl;
    try{
        Array<int> intArray;
        Array<string> stringArray;
        intArray.agrega(2);
        cout<<intArray.top()<<endl;
        stringArray.agrega("A");
        cout<<stringArray.top()<<endl;
        stringArray.elimina();
        cout<<stringArray.top()<<endl;
    }catch(exception& e){
        cout<<e.what()<<endl;
    }
}

