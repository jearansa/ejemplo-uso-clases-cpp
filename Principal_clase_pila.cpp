
// En este fichero vamos a generar un programa cliente
// de nuestra anterior clase "Pila"

// Librerías de entrada y salida de datos por la consola
#include <iostream>
#include <cstdlib>

// Debemos incluir el fichero de declaración de la clase Pila
// No incluimos el fichero de definición de la misma, "Clase_Pila.cpp".

#include "Clase_Pila.h"

using namespace std;

int main (){

    // Declaramos y costruimos un puntero a un objeto de la clase Pila
    // ¿Dónde está la declaración del objeto?
    // ¿Dónde su reserva de memoria?
    // ¿Qué valor inicial habrá tomado el mismo?

    Pila * mi_pila_pares = new Pila ( );

    // Declaramos (y C++ internamente construye) un objeto de la clase Pila
    // ¿Qué valor inicial habrá tomado el objeto construido?

    Pila mi_pila_multiplos_de_tres;

    // Veamos ahora cómo podemos acceder a los atributos estáticos:
    // Como en este caso lo hemos declarado como "public", directamente podemos hacer:

    cout << endl;
    cout << "**********************************************" << endl;
    cout << "Acceso a atributos estáticos: " << endl;
    cout << endl;

    cout << "El atributo accedido desde la propia clase: "
            << Pila::numPilas << endl;

    cout << "El atributo accedido desde un puntero cualquiera: "
            << mi_pila_pares->numPilas << endl;

    cout << "El atributo accedido desde un objeto cualquiera: "
            << mi_pila_multiplos_de_tres.numPilas << endl;

    cout << endl;
    cout << "**********************************************" << endl;
    cout << "Uso de los métodos de clase desde objetos y punteros a objetos: " << endl;
    cout << endl;


    for (int i = 0; i < 15; i++){
        mi_pila_pares->apilar ( 2 * i );
        mi_pila_multiplos_de_tres.apilar ( 3 * i );
    }

    for (int i = 0; i < 15; i++){
        cout << "El elemento en la cima de mi_pila_pares es "
                << mi_pila_pares->cima() << endl;
        mi_pila_pares->desapilar ( );
        cout << "El elemento en la cima de mi_pila_multiplos_de_tres "
                << mi_pila_multiplos_de_tres.cima() << endl;
        mi_pila_multiplos_de_tres.desapilar ( );
    }

    // Aquí estudiamos el modelo de memoria de C++
    // Atención a la diferencia entre usar tipos básicos, punteros y objetos;

    // 01. Tipos básicos;

    cout << endl;
    cout << "**********************************************" << endl;
    cout << "Gestión en memoria de objetos: " << endl;
    cout << endl;

    int x = 5;

    int y = x;

    x = 2 * x;

    cout << "El valor de x después de modificarlo: " << x << endl;

    cout << "El valor de y después de modificar x: " << y << endl;

    // 02. Objetos (sin usar punteros)

    // Atención, la pila "mi_pila_multiplos_de_tres" ahora se encuentra vacía:

    cout << endl;
    cout << "**********************************************" << endl;
    cout << "Gestión en memoria de objetos sin usar punteros: " << endl;
    cout << endl;

    for (int i = 0; i < 15; i++){
        mi_pila_multiplos_de_tres.apilar ( 3 * i );
    }

    Pila copia_mi_pila_multiplos_de_tres = mi_pila_multiplos_de_tres;

    for (int i = 15; i < 30; i++){
        mi_pila_multiplos_de_tres.apilar ( 3 * i );
    }

    // ¿Cuántos y qué valores nos encontramos ahora en la pila "copia_mi_pila_multiplos_de_tres"?
    cout << "¿Cuántos y qué valores nos encontramos ahora "
            << " en la pila ''copia_mi_pila_multiplos_de_tres''?" << endl;

     for (int i = 0; i < 15; i++){
        cout << "El elemento en la cima de mi_pila_multiplos_de_tres "
                << mi_pila_multiplos_de_tres.cima() << endl;
        mi_pila_multiplos_de_tres.desapilar ( );
        cout << "El elemento en la cima de copia_mi_pila_multiplos_de_tres "
                << copia_mi_pila_multiplos_de_tres.cima() << endl;
        copia_mi_pila_multiplos_de_tres.desapilar ( );
    }

    // 03. Objetos (usando punteros)

    // Atención, la pila "mi_pila_pares" ahora se encuentra vacía:

    cout << endl;
    cout << "**********************************************" << endl;
    cout << "Gestión en memoria de objetos usando punteros: " << endl;
    cout << endl;

    for (int i = 0; i < 15; i++){
        mi_pila_pares->apilar ( 2 * i );
    }

    Pila * copia_mi_pila_pares = mi_pila_pares;

    for (int i = 15; i < 30; i++){
        mi_pila_pares->apilar ( 2 * i );
    }

    // ¿Cuántos y qué valores nos encontramos ahora en la pila "copia_mi_pila_pares"?
    cout << "¿Cuántos y qué valores nos encontramos ahora en la pila ''copia_mi_pila_pares''?" << endl;

     for (int i = 0; i < 15; i++){
        cout << "El elemento en la cima de mi_pila_pares "
                << mi_pila_pares->cima ( ) << endl;
        mi_pila_pares->desapilar ( );
        cout << "El elemento en la cima de copia_mi_pila_pares "
                << copia_mi_pila_pares->cima ( ) << endl;
        copia_mi_pila_pares->desapilar ( );
    }

    // ¿Cómo afectará el anterior comportamiento al paso de parámetros a funciones?

    // Observa que en C++ podemos pasar de parámetro
    //   - un objeto,
    //   - un puntero a un objeto,
    //   - o un objeto con el modificador "&"
    // y cada uno de los casos anteriores tendr? un comportamiento distinto.
    // En la Práctica 03 observaremos cada uno de estos casos.


    return 0;
 }
