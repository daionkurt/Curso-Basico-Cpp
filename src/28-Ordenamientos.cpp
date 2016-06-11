//
// Created by carlo on 06/06/2016.
//
#include <iostream>
#include "30-CuentaTiempo.hpp"

using namespace std;
template <typename T> void bubbleSort(T*,int);
template <typename T> void insertSort(T*,int);
template <typename T> void selectSort(T*,int);
template <typename T> void shellSort(T*,int);
template <typename T> void swap(T*,T*);

void ordenamientos(){
    const int size = 50000;
    int* arreglo = new int[size];
    CuentaTiempo tiempo;
    for (int i = 0,j = size; i < size; ++i, --j) {
        arreglo[i] = j;
        //cout<<arreglo[i]<<", ";
    }
    tiempo.iniciarCuentaTiempo();
    bubbleSort(arreglo,size);
    tiempo.terminarCuentaTiempo();
    cout<<endl;
    cout<<endl<<"Tiempo: "<<tiempo.getTiempo()<<endl;


    for (int i = 0,j = size; i < size; ++i, --j) {
        arreglo[i] = j;
        //cout<<arreglo[i]<<", ";
    }
    tiempo.iniciarCuentaTiempo();
    insertSort(arreglo,size);
    tiempo.terminarCuentaTiempo();
    cout<<endl;
    cout<<endl<<"Tiempo: "<<tiempo.getTiempo()<<endl;


    for (int i = 0,j = size; i < size; ++i, --j) {
        arreglo[i] = j;
        //cout<<arreglo[i]<<", ";
    }
    tiempo.iniciarCuentaTiempo();
    selectSort(arreglo,size);
    tiempo.terminarCuentaTiempo();
    cout<<endl;
    cout<<endl<<"Tiempo: "<<tiempo.getTiempo()<<endl;


    for (int i = 0,j = size; i < size; ++i, --j) {
        arreglo[i] = j;
        //cout<<arreglo[i]<<", ";
    }
    tiempo.iniciarCuentaTiempo();
    shellSort(arreglo,size);
    tiempo.terminarCuentaTiempo();
    cout<<endl;
    cout<<endl<<"Tiempo: "<<tiempo.getTiempo()<<endl;
}

template <typename T>
void bubbleSort(T* arreglo,int size){
    cout<<endl<<"Bubble Sort";
    for (int i = 1 ; i <size; ++i)
        for (int j = 0; j < size-1; ++j)
            if(arreglo[j]>arreglo[j+1])
                swap(&arreglo[j],&arreglo[j+1]);
}

template <typename T>
void insertSort(T* arreglo,int size){
    int j;
    cout<<endl<<"Insert Sort";
    for (int i = 1; i < size; ++i) {
        T x = arreglo[i];
        j = i-1;
        while(j>=0 && arreglo[j]>x){
            arreglo[j+1] = arreglo[j];
            j-=1;
        }
        arreglo[j+1] = x;
    }
}

template <typename T>
void selectSort(T* arreglo,int size){
    int max;
    cout<<endl<<"Select Sort";
    for (int i = 0; i < size-1; ++i) {
        max = i;
        for (int j = i+1; j < size; ++j) {
            if(arreglo[j] < arreglo[max]){
                max = j;
            }
        }
        swap(arreglo[i],arreglo[max]);
    }
}

template <typename T>
void shellSort(T* arreglo,int size){
    int temp,k;
    cout<<endl<<"Shell Sort";
    for(int i = size/2; i>0; i/=2){
        for (int j = i; j < size; ++j) {
            temp = arreglo[j];
            k = j;
            while(k>=i && temp<arreglo[k-i]){
                arreglo[k] = arreglo[k-i];
                k-=i;
            }
            arreglo[k]=temp;
        }
    }
}

template <typename T>
void swap(T* a,T* b){
    T aux = *a;
    *a = *b;
    *b = aux;
}