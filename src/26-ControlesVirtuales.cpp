//
// Created by carlo on 02/06/2016.
//
#include <iostream>

using namespace std;

/*Uso de override entre clases padre y derivadas*/
class Base{
public:
    virtual void A(float=0.0){};
    virtual void B() const{};
    virtual void C(){
        cout<<"Clase Base"<<endl;
    };
    void D();
};

class Derivada : public Base{
public:
    void A(int=0){}; //No override porque no cambia a A, son distintos
    void B(){}; //No override porque no cambia a B, son distintos
    void C() override{
        cout<<"Clase Derivada"<<endl;
    }; //esto si es válido
    void D(); //Error porque D no es virtual
};

/*Uso de final entre clases padre y derivadas*/
/*Recomendable evitarlo a menos que se tenga un buen motivo para usarlo*/
class Base1{
public:
    virtual void A() final{
        cout<<"Esta es final, no puedes cambiarla"<<endl;
    };
};

class Derivada1:public Base1{
public:
    //virtual void A(); //No puedo hacer override porque A es final
};

class Final final{ };

//class Intento:public Final{ }; //Esto no se puede porque Final es final

/*Uso de default entre clases padre y derivadas*/
/*El default solo se puede implementar para las funciones:
 * -Constructor
 * -Destructor
 * -Constructor copia
 * -Operador =
 * Sirve para que el compilador provea un constructor por defecto aunque
 * se tenga ya uno propio, porque C++ no provee default si hay
 * versiones alternas de estos*/
class Prueba{
public:
    Prueba(int x);
    Prueba() = default;
};

/*Uso de delete entre clases padre y derivadas*/
/*El delete ssirve para evitar que ciertas funciones miembro
 * puedan ser utilizadas */
class Delete{
public:
    Delete(const Delete&) = delete; //No es copiable
    Delete(double);
    Delete(long) = delete; //no acepta long
    Delete(int) = delete; //no acepta int
};

Delete::Delete(double) {
    cout<<"BIEN"<<endl;
}

void muestraControlesVirtuales(){
    Derivada derivada;
    Derivada1 derivada1;
    derivada.C();
    derivada1.A();
    double a = 10; //Este constructor si es valido
    long b = 10; //El constructor está eliminado
    int c = 30; //El constructor está eliminado
    Delete* deleteT = new Delete(a);
}
