//
// Created by carlo on 31/05/2016.
//
#include <iostream>

using namespace std;

class Cajita{
private:
    int alto;
    int ancho;
    int largo;
public:
    Cajita(){}
    Cajita(int alto,int ancho,int largo):alto(alto),ancho(ancho),largo(largo){}
    Cajita operator+(const Cajita& c){
        Cajita caja;
        caja.alto = this->alto+c.alto;
        caja.ancho = this->ancho+c.ancho;
        caja.largo = this->largo+c.largo;
        return caja;
    }
    Cajita operator-(const Cajita& c){
        Cajita caja;
        caja.alto = this->alto-c.alto;
        caja.ancho = this->ancho-c.ancho;
        caja.largo = this->largo-c.largo;
        return caja;
    }
    Cajita operator-(){
        alto=-alto;
        ancho=-ancho;
        largo=-largo;
        return Cajita(alto,ancho,largo);
    }
    bool operator<(const Cajita& c){
        if(this->alto<c.alto && this->ancho<c.ancho){
            return true;
        }else if(this->alto==c.alto && this->ancho<c.ancho && this->largo<c.largo){
            return true;
        }
        return false;
    }
    friend ostream &operator<<(ostream &output, const Cajita& c){
        output<<"A: "<<c.alto<<", C: "<<c.ancho<<", L: "<<c.largo;
        return output;
    }
    friend istream &operator>>(istream &input, Cajita& c){
        input>>c.alto>>c.ancho>>c.largo;
        return input;
    }
    string toString(){
        stringstream str;
        str<<"Alto: "<<alto<<", Ancho: "<<ancho<<", Largo: "<<largo;
        return str.str();
    }
};

class Arreglo{
private:
    int arreglo[10];
public:
    Arreglo(){
        register int i;
        for (int i = 0; i < 10; ++i) {
            arreglo[i] = i;
        }
    }
    int &operator[](int i){
        if(i>10){
            cout<<"Index out of bounds"<<endl;
            return arreglo[0];
        }
        return arreglo[i];
    }
};

void muestraSobrecarga(){
    Cajita caja(5,10,15),caja1(10,15,20),caja2(3,6,9);
    Cajita caja3,caja4,caja5;
    cout<<caja.toString()<<endl;
    -caja;
    cout<<caja.toString()<<endl;
    caja3 = caja+caja1;
    cout<<caja3.toString()<<endl;
    caja4 = caja1-caja2;
    cout<<caja4.toString()<<endl;
    cout<<((caja1<caja2)?"Caja 1 es menor":"Caja 2 es menor")<<endl;
    cout<<caja2<<endl;
    cout<<"Provee datos para la caja 5: ";
    cin>>caja5;
    cout<<caja5<<endl;

    Arreglo arreglo;
    cout<<"Valor de arreglo[2]: "<<arreglo[2]<<endl;
    cout<<"Valor de arreglo[5]: "<<arreglo[5]<<endl;
    cout<<"Valor de arreglo[15]: "<<arreglo[15]<<endl;
}