/*
 * Llamada.h
 */

#ifndef LLAMADA_H_
#define LLAMADA_H_
#include "Hora.h"
#include "Fecha.h"

using namespace std;

class Llamada {
	static float costoBase; //Comun a todas las llamadas
	Fecha fechaLlamada;
	Hora horaInicio;
	int duracion;

public:
	//Constructores
	Llamada();
	Llamada(Fecha &fecha, Hora &horaI, int duracionL);

	//Metodo que calcula el costo de la llamada
	float costoLlamada();

	//Getters
	Fecha getFechaLlamada();
	Hora getHoraLlamada();
	int getDuracion();

}; //Fin de la clase LLamada

//Sobrecarga del operador de insercion de  flujo para
//escribir en un flujo de salida la información de una llamada
ostream & operator<<(ostream& salida, Llamada *llamada);

#endif /* LLAMADA_H_ */
