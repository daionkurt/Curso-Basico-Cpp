# Curso básico de C++
Temas introductorios para la programación en el lenguaje C++

##Descripción
Este es un proyecto personal que inicio como recordatorio para mi mismo sobre las bases de C++, tiene temas separados y graduales, de lo más simple hasta aspectos más complejos de la POO (Programación Orientada a Objetos), tocando novedades del C++11 y C++14, no tiene el objetivo de hacer un expero en C++ a quien lo revise o utilice, pero si como nociones básicas de la interacción entre el programador novato con el lenguaje de programación.

##Requisitos
* Se sugiere tener nociones básicas de los principios teóricos de programación para la comprensión total de lo explicado en los archivos.
* Tener una computadora que tenga:
  - Compilador de C/C++ lo suficientemente actual para poder compilar código propio de C++14 (std=c++1y o c++1y)
  - IDE (Entorno Integral de Desarrollo) o editor de texto
  
###Recomendaciones
Para cubrir los anteriores requisitos se recomienda por parte del autor las siguientes herramientas:
* Compilador: MinGW versión 4.9.2 o superior
* IDE: CLion de Jetbrains (versión estudiantil)

##Temas Contenidos
* Fundamentos de C++
  - Tipos de datos
  - Constantes
  - Modificadores
  - Operadores
  - Estructuras de control selectivas
  - Estructuras de control iterativas
  - Funciones y subrutinas
  - Literales y uso de números
  - Arreglos
  - Cadenas
  - Punteros
  - Referencias
  - Uso de tiempo y fecha
  - Entradas y Salidas
  - Archivos
  - Templates
  - Uso de directivas del preprocesador
  - Memoria dinámica
  - Espacios de nombres
  - Estructuras
  - Ordenamientos
  - Búsquedas
* POO 
  - Clases
  - Sobrecarga de operadores
  - Polimorfismo
  - Templates en clases
  - Controles virtuales
  - Cabeceras
  - Functores
* Novedades de C++11 y C++14
  - Lambda
  - Decltype
  - Apuntadores a funciones
  - Controles virtuales extendidos
* Contenedores
  - TDA Lista
  - TDA Pila
  - TDA Cola
  - TDA Árbol
  - TDA Grafo
  - STL Vector
  - STL Unordered Map
  - STL Unordered Multimap
  - STL Unordered Set
  - STL Unordered Multiset

##Ejemplos de presentación
Los archivos vendrán explicados de la siguiente manera
```
/*Descripción teórica del ejemplo a ver
* Sintaxis
* Notas de aclaración 
*/
void rutinaEjemplo(){
  //codigo del tema actual
}
```
###Notas
Hay 2 archivos que tienes que cuidar bien cuando quieras compilar y ejecutar el proyecto completo:
* main.cpp
* Includes.hpp
Esto por que "Includes.hpp" contiene el enlace #include a todos los archivos de manera simultanea, pero están comentados, cuando requieras ejecutar un archivo de ejemplo en particular se te sugiere descomentar el tema en "Includes.hpp":
```
#ifndef CURSO_C_INCLUDES_HPP
#define CURSO_C_INCLUDES_HPP

//#include "01-TiposDeDatos.cpp"
//#include "02-ConstantesYModificadores.cpp"
#include "03-Operadores.cpp"            -> Tema a revisar
//#include "04-ClasesDeAlmacenamiento.cpp"
//#include "05-Selectivas.cpp"
```
Y de igual manera en "main.cpp":
```
int main(){
//    muestraTiposDatos();
//    muestraConstantesModificadores()
    muestraOperadores();
//    muestraClasesAlmacenamiento();
```
Y una vez hecho estoy quieres usar otro, comentar el anterior y descomentar el nuevo, pero se sugiere siempre tener unicamente 1 descomentado:
```
#ifndef CURSO_C_INCLUDES_HPP
#define CURSO_C_INCLUDES_HPP

//#include "01-TiposDeDatos.cpp"
//#include "02-ConstantesYModificadores.cpp"
//#include "03-Operadores.cpp"            
#include "04-ClasesDeAlmacenamiento.cpp"        -> Nuevo tema a revisar
//#include "05-Selectivas.cpp"
```
No olvidar hacerlo igual en "main.cpp"


##Autor
* **Carlos A. Fernández** - *Totalidad del trabajo* - [DaionKurt](https://github.com/DaionKurt)

##Licencia
Este proyecto está bajo una licencia libre por parte del autor para su uso y modificación según se requiera
