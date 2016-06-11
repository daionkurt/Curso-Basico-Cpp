//
// Created by carlo on 01/06/2016.
//
#include <iostream>

using namespace std;

namespace espacio{
    void funcion(){
        cout<<"Estas usando la funcion en ::espacio::"<<endl;
    }
}

namespace segundoEspacio{
    void funcion(){
        cout<<"Estas usando la funcion en ::segundoEspacio::"<<endl;
    }
    namespace anidado{
        void funcion(){
            cout<<"Estas usando la funcion anidada"<<endl;
        }
    }
}

using namespace segundoEspacio::anidado;

void muestraNamespace(){
    espacio::funcion();
    segundoEspacio::funcion();
    funcion();
}
