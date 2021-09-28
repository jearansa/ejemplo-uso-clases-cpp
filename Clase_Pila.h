
// Sobre la conveniencia de usar las órdenes de
// precompilación "ifndef", "define", "endif":
// http://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files

#ifndef PILA_H
#define PILA_H 1

// Vamos a trabajar con pilas de enteros
typedef int telemento;

class Pila {

        // 1. Constantes de clase
        // número máximo de datos que habrá en la pila
        // lo declaramos como const y static.
        // En este caso lo inicializaremos en la propia declaración,
        // porque se va a usar en el propio *.h
        // Generalmente es mejor darle un valor inicial en el fichero "*.cpp"
      private:
        constexpr static int MAX = 100;

        // 2. Atributos de clase:
        // Declaramos aquí un atributo que va a representar el número de pilas creadas
        // Como es un atributo estático,
        // debemos iniciarlo antes de los constructores de la clase,
        // pero C++ no permite hacerlo en el fichero *.h,
        // por lo tanto la inicialización debe ir al fichero .cpp
      public:
        static int numPilas;

        // 3. Atributos de clase
      private:
        int num;
        telemento datos [MAX];

        // 4. Constructores de clase
      public:
        Pila ( );

        // 5. Métodos propios de la clase
      public:
        void apilar( telemento d );
        bool pilaVacia ( );
        telemento cima ( );
        void desapilar ( );

};

#endif
