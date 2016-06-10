//
// Created by carlo on 01/06/2016.
//

#include <cstdlib>
#include <fstream>

#define MAX_ALUMNOS 3
#define SALTO_DE_LINEA "\r\n"
#define NOMBRE_ARCHIVO_ALUMNOS "Alumno.txt"
#define SEPARADOR_CAMPOS ","

using namespace std;

struct Alumnot{
    int codigo;
    string nombre;
};

Alumnot alumnos[MAX_ALUMNOS];
int cuentaAlumnos;

void pausa(){
    cout << "Presiona enter para continuar . . ." << endl;
    cin.get();
}

bool registrarAlumno(){
    cout << "Registro de Alumno" << endl;
    if (cuentaAlumnos<MAX_ALUMNOS){
        cout << "Registro #" << cuentaAlumnos+1 << "." << endl;
        cout << "Dame el codigo: ";
        cin >> alumnos[cuentaAlumnos].codigo;
        cout << "Dame el nombre: ";
        cin >> alumnos[cuentaAlumnos++].nombre;
        return true;
    }
    else{
        cout << "No hay mas espacio para captura" << endl;
        return false;
    }
}

void guardarAlumnos(){
    ofstream archivo;
    cout << "Guardando archivo " << NOMBRE_ARCHIVO_ALUMNOS << "...";
    archivo.open(NOMBRE_ARCHIVO_ALUMNOS,ios::out);
    archivo << cuentaAlumnos << SEPARADOR_CAMPOS << "Total" << endl;
    for(int i=0;i<cuentaAlumnos;i++){
        archivo << alumnos[i].codigo << SEPARADOR_CAMPOS
        << alumnos[i].nombre << endl;
    }
    archivo.close();
    cout << "Hecho." << endl;
}

bool cargarAlumnos(){
    ifstream archivo;
    char separador;
    string cadena;
    cout << "Cargando archivo " << NOMBRE_ARCHIVO_ALUMNOS << "...";
    archivo.open(NOMBRE_ARCHIVO_ALUMNOS,ios::in);
    archivo >> cuentaAlumnos;
    archivo >> cadena;
    if (archivo.is_open()){
        for(int i=0;i<cuentaAlumnos;i++){
            archivo >> alumnos[i].codigo;
            archivo >> separador;
            archivo >> alumnos[i].nombre;
        }
        cout << "Hecho" << endl;
        archivo.close();
        return true;
    }
    else{
        cout << "No se pudo abrir el archivo." << endl;
        return false;
    }
}

void listarAlumnos(){
    cout << "Lista de Alumnos" << endl;
    for(int i=0;i<cuentaAlumnos;i++){
        cout << alumnos[i].codigo << "\t" << alumnos[i].nombre << endl;
    }
}

void muestraArchivos()
{
    cout << "Lectura y Escritura de Archivos de Texto" << endl;
    if (cargarAlumnos()){
        listarAlumnos();
    }
    if (registrarAlumno()){
        guardarAlumnos();
    }
}