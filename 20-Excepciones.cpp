//
// Created by carlo on 01/06/2016.
//
#include <iostream>
#include <exception>

using namespace std;

struct IndexOutOfBoundsException: public exception{
    const char* what() const throw(){
        return "IndexOutOfBoundsException";
    }
};

double division(int a,int b ){
    if(b==0){
        throw "Division entre 0 no es valida";
    }
    return a/b;
}

int muestraExcepciones(){
    double c=0;
    try{
        c = division(40,0);
        cout<<c<<endl;
    }catch(const char* mensaje){
        cout<<mensaje<<endl;
    }
    try{
        throw IndexOutOfBoundsException();
        /*bad_alloc exc;
        throw exc;*/
    }catch(IndexOutOfBoundsException& e){
        cout<<e.what()<<endl;
    }catch(exception& e){
        cout<<"Otra excepcion"<<endl;
        cout<<e.what()<<endl;
    }
}