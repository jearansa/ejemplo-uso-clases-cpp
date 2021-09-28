
// Este fichero define los m�todos de la clase "Pila"
// Por tanto, debemos asegurarnos de incluir el fichero
// donde la misma se declara

#include "Clase_Pila.h"

// Atributos est�ticos:
int Pila::numPilas = 0;

// Constructor; conviene inicializar todos los atributos de la clase
Pila::Pila ( ) {
    Pila::numPilas = Pila::numPilas + 1;
    // Lo anterior es equivalente a "numPilas = Pila::numPilas + 1"
	this->num=0;
	for (int i = 0; i < Pila::MAX; i++){
        this->datos [i] = 0;
    }
}

// Resto de m�todos de la clase;
void Pila::apilar(telemento d){
	if (this->num < Pila::MAX-1) // Id�nticamente podr�amos haber hecho "(this->MAX) - 1"
	{
		this->datos[this->num]=d;
		this->num=this->num + 1;
	}
}

bool Pila::pilaVacia( ) {
	return (this->num == 0);
}

telemento Pila::cima( ) {
	return(this->datos[this->num - 1]);
}

void Pila::desapilar( ) {
	this->num = this->num-1;
}
