//
// Created by carlo on 08/06/2016.
//
#include <iostream>

using namespace std;

/*Expresiones constantes generalizadas*/
//int dame_cinco() {return 5;} //Esto no compila por no ser constante en ejecución
constexpr int dame_cinco() {return 5;}
int algun_valor[dame_cinco() + 7]; // Crea un arreglo de 12 enteros. Legal en C++11
constexpr double aceleracion_de_gravedad = 9.8;
constexpr double gravedad_lunar = aceleracion_de_gravedad / 6.0;

/*Listas de inicialización */
class ClaseSecuencia{
public:
    vector<int> elementos;
    ClaseSecuencia(initializer_list<int> lista):elementos(lista){
        cout<<"Construida con "<<lista.size()<<" elementos"<<endl;
    }
    void append(initializer_list<int> lista){
        elementos.insert(elementos.end(),lista.begin(),lista.end());
    }
    pair<const int*, size_t> c_arr() const{
        return {&elementos[0],elementos.size()};
    };
};
void ejemploListasInicializacion(){
    ClaseSecuencia var = {1,2,3,4};
    for(auto& x : var.elementos) cout<<x<<", ";
    cout<<endl;
    var.append({5,6,7});
    for(auto& x : var.elementos) cout<<x<<", ";
    cout<<endl;
}

/*Construccion de objetos*/
class AlgunTipo  {
    int numero;
public:
    AlgunTipo(int numero) : numero(numero) {}
    AlgunTipo() : AlgunTipo(42) {}
};

/*Inicializacion de miembros*/
class AlgunaClase {
private:
    int valor = 5;
public:
    AlgunaClase() {}
    explicit AlgunaClase(int valor):valor(valor) {}
    int getValor(){return valor;}
};
void ejemploInicializacionMiembros(){
    AlgunaClase var;
    AlgunaClase var1(4);
    cout<<var.getValor()<<endl;
    cout<<var1.getValor()<<endl;
}

/*Override, default y final explicitos
 * Ver archivo: 26-ControlesVirtuales.cpp
 * */

/*Constante puntero null*/
void foo(char *){}
void foo(int){}
void ejemploPunterosNullptr(){
    char* pc = nullptr;
    int*  pi = nullptr;
    bool   b = nullptr;
    //int    i = nullptr; //Esto da error
    foo(nullptr);
}

/*Enumerados*/
enum class Enumeracion{
    valor1,
    valor2,
    valor3 = 100,
    valor4 // tiene 101
};
enum class Enumeracion2 : unsigned int{
    valor1,
    valor2
};
enum Enumeracion3 : char {high = 'h',low='l'};
ostream& operator<<(ostream& os,Enumeracion3 al){
    return os<< static_cast<char>(al);
}
void ejemploEnumerados(){
    Enumeracion3 enumerado = Enumeracion3::high;
    cout<<enumerado<<endl;
}

/*Using*/
typedef void (*Tipo)(double);		// Viejo estilo
using Tipo = void (*)(double);

/*String*/
void ejemploString(){
    string u8= u8"Cadena UTF-8";
    string raw = R"delimiter(El dato de \ la cadena")delimiter";
    string raw2 = R"(Prueba \n segunda \t)";
    cout<<u8"Cadena UTF-8"<<endl;
    cout<<u"Cadena UTF-16"<<endl;
    cout<<U"Cadena UTF-32"<<endl;
    cout<<raw<<endl;
    cout<<raw2<<endl;
}


/*Expresiones regulares
 * Ejemplo contenido en 25-Lambda.cpp
 * */
void ejemploRegex(){
    cout<<"Expresiones Regulares"<<endl;
    string input;
    string inte=R"((\+|-)?[[:digit:]]+)";
    regex integer(inte);
    //regex integer("(\\+|-)?[[:digit:]]+");
    regex flotante("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?");
    for (int k = 0; k < 4; ++k) {
        cout<<"Dame un entero: ";
        cin>>input;
        if(regex_match(input,integer))
            cout<<"Es un entero"<<endl;
        else if(regex_match(input,flotante))
            cout<<"Es un flotante"<<endl;
        else
            cout<<"Entrada invalida"<<endl;
    }
}

void muestraCpp11(){
    ejemploListasInicializacion();
    ejemploInicializacionMiembros();
    ejemploPunterosNullptr();
    ejemploEnumerados();
    ejemploString();
    ejemploRegex();
}