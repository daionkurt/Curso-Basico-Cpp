//
// Created by carlo on 31/05/2016.
//
#include <iostream>

using namespace std;

class Caja{
private:
    double alto;
protected:
    double ancho;
};

class CajaPequenia: public Caja{
public:
    void setAncho(double ancho){
        this->ancho=ancho;
    }
    double getAncho(){
        return ancho;
    }
};

class AlumnoPrueba{
private:
    string nombre;
    int codigo;
    string carrera;
public:
    static int contador;
    AlumnoPrueba(){}
    AlumnoPrueba(string nombre,int codigo,string carrera){
        setNombre(nombre);
        setCodigo(codigo);
        setCarrera(carrera);
        contador++;
        cout<<"Alumno construido"<<endl;
        cout<<"Contador de objetos: "<<contador<<endl;
    }
    AlumnoPrueba(string nombre): nombre(nombre){
        contador++;
        cout<<"Alumno construido, nombre: "<<nombre<<endl;
        cout<<"Contador de objetos: "<<contador<<endl;
    }
    AlumnoPrueba(const AlumnoPrueba &alumno){
        cout<<"Constructor copia"<<endl;
        nombre = alumno.nombre;
        codigo = alumno.codigo;
        carrera = alumno.carrera;
        contador++;
        cout<<"Contador de objetos: "<<contador<<endl;
    }
    AlumnoPrueba(AlumnoPrueba* alumno){
        cout<<"Constructor copia"<<endl;
        nombre = alumno->nombre;
        codigo = alumno->codigo;
        carrera = alumno->carrera;
        contador++;
        cout<<"Contador de objetos: "<<contador<<endl;
    }
    ~AlumnoPrueba(){
        contador--;
        cout<<"Alumno destruido"<<endl;
    }
    inline void setNombre(string nombre){
        this->nombre=nombre;
    }
    inline void setCodigo(int codigo){
        this->codigo=codigo;
    }
    inline void setCarrera(string carrera){
        this->carrera=carrera;
    }
    inline string getNombre(){
        return nombre;
    }
    inline int getCodigo(){
        return codigo;
    }
    inline string getCarrera(){
        return carrera;
    }
    int comparaCodigo(AlumnoPrueba alumno){
        return this->codigo>alumno.codigo;
    }
    AlumnoPrueba operator+(const AlumnoPrueba& a){
        AlumnoPrueba alumno;
        alumno.nombre = this->nombre+a.nombre;
        alumno.codigo = this->codigo+a.codigo;
        alumno.carrera = this->carrera+a.carrera;
        return alumno;
    }
    string toString();
    friend void imprimeCarrera(AlumnoPrueba alumno);
};

int AlumnoPrueba::contador = 0;

void imprimeCarrera(AlumnoPrueba alumno){
    cout<<"Carrera del alumno Friend: "<<alumno.carrera<<endl;
}

string AlumnoPrueba::toString() {
    stringstream info;
    info<<"Nombre: "<<getNombre()<<"\t| ";
    info<<"Codigo: "<<getCodigo()<<"\t| ";
    info<<"Carrera: "<<getCarrera()<<endl;
    return info.str();
}

void muestraClases(){
    AlumnoPrueba* alumno = new AlumnoPrueba("Carlos",218737234,"INCO");
    AlumnoPrueba* alumno2 = new AlumnoPrueba("Andres");
    AlumnoPrueba* alumno3 = new AlumnoPrueba(alumno2);
    AlumnoPrueba alumno4("Michael",123456789,"INNI");
    AlumnoPrueba alumno5 = alumno4;
    AlumnoPrueba alumno6;
    cout<<alumno->toString()<<endl;
    cout<<alumno2->toString()<<endl;
    cout<<alumno3->toString()<<endl;
    cout<<alumno4.toString()<<endl;
    cout<<alumno5.toString()<<endl;
    imprimeCarrera(alumno);
    imprimeCarrera(alumno4);
    cout<<alumno4.comparaCodigo(alumno5)<<endl;
    alumno6 = alumno4 + alumno5;
    cout<<"Datos del 6: "<<alumno6.toString()<<endl;
    cout<<"Contador de objetos: "<<alumno5.contador<<endl;
    delete alumno;
    delete alumno2;
    delete alumno3;
}
