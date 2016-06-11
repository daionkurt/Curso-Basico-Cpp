//
// Created by Carlos Andrés Fernández Jalomo on 31/05/2016.
// correo: carlosfdez@outlook.com
//
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>      //Cabecera que incluye las operaciones sobre los flujos de iostream almacenandolos en objetos

/*Cadenas de forma tradicional (Uso de C)
 * ****************************************************************************************************
 * En C++ existen 2 formas de declarar y usar cadenas, la versión tradicional de C, que ya está depreciada en C++11 y
 * posteriores
 * Esto es el uso de cadenas de forma tradicional en C, en la que se hace uso de un arreglo de caracteres consecutivos
 * para dar la forma de una cadena de texto*/
void cadenasTradicionales(){
    char nombre[7] = {'C','a','r','l','o','s','\0'}; //se declara igual que un arreglo, NOTA: siempre al final se debe
                                                   //de poner el caracter nulo '\0' para terminar con una cadena
    char apellido[] = "Fernandez"; //de igual manera se puede declar un arreglo sin tamaño y pasarle una cadena totalmente
    const char* cadena = "Hola Mundo"; //o sin la notación de arreglo, se puede hacer uso del const char* para indicar cadena
    char copia[11];
    char copia2[] = "Hail ";
    strcpy(copia,cadena); //copia el contenido de cadena en copia
    strcat(copia2,copia); //concatena el contenido de copia y copia 2 y lo deja en copia 2
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Apellido: "<<apellido<<endl;
    cout<<"Strcpy: "<<copia<<endl;
    cout<<"Strcat: "<<copia2<<endl;
    cout<<"Strlen: "<<strlen(copia2)<<endl;  //strlen() regresa la longitud de la cadena
    /*strcmp() regresa  0 si las cadenas son iguales, mayor a 0 si la primera cadena es mayor a la segunda
     * y menor a 0 si la segunda cadena es mayor a la primera*/
    cout<<"Strcmp a==b: "<<strcmp(copia,copia)<<endl;
    cout<<"Strcmp a<b: "<<strcmp(copia2,copia)<<endl;
    cout<<"Strcmp a>b: "<<strcmp(copia,copia2)<<endl;
    cout<<"Strchr: "<<strchr(copia,'a')<<endl; //strchr() corta la cadena e imprime de la ubicación del caracter dado en delante
    cout<<"Strstr: "<<strstr(copia2,copia)<<endl; //strstr() imprime de la ubicación de la cadena en delante
}

/*En C++ es preferible usar la clase <string> para el uso de cadenas ya que contiene método más útiles y es
 * orientada a objetos*/
void cadenasComoClase(){
    string str1 = "Hola ";
    string str2 = "Mundo";
    string str3;
    str3 = str1;
    cout<<"str3: "<<str3<<endl;
    str3 = str1 + str2;
    cout<<"str3: "<<str3<<endl;
    cout<<"str3 size: "  <<str3.size()<<endl; //size() arroja el tamaño de la cadena
    cout<<"str3 length: "<<str3.length()<<endl; //lenght() arroja la longitud en caracteres de la cadena
    cout<<"str3 max_size: "<<str3.max_size()<<endl; //max_size arroja el máximo tamaño que puede tener dicha cadena
    cout<<"str3 capacity: "<<str3.capacity()<<endl; //capacity arroja la capacidad actual de la cadena
    cout<<"str3 at: "<<str3.at(7)<<endl; //regresa el caracter en la posición dada de la cadena
    cout<<"str3 swap: "<<"The "<<str1<<" has "<<str2<<endl;
    str1.swap(str2); //intercambia el valor de la cadena
    cout<<"str3 swap: "<<"The "<<str1<<" has "<<str2<<endl;
    str3.back() = 'O'; //cambia el últmo caracter por el valor igualado
    cout<<"str3 back: "<<str3<<endl;
    str3.front() = 'h'; //cambia el primer caracter por el valor igualado
    cout<<"str3 front: "<<str3<<endl;
    str3.clear(); //elimina el contenido de la cadena
    cout<<"str3 clear: "<<str3<<endl;
    cout<<"str3 empty: "<<str3.empty()<<endl; //booleano que informa si la cadena está o no vacía
}

void muestraCadenas(){
    cadenasTradicionales();
    cadenasComoClase();
}