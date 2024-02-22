/*
 * Llamada.h
 */

#ifndef LLAMADA_H_
#define LLAMADA_H_
#include "Hora.h"
#include "Fecha.h"

using namespace std;

class Llamada {
protected:
	static float costoBase; //Comun a todas las llamadas
	Fecha fechaLlamada;
	Hora horaInicio;
	int duracion;
public:
	//Constructores
	Llamada();
	Llamada(Fecha &fecha, Hora &horaI, int duracionL);

	//Metodo que calcula el costo de la llamada
	virtual float costoLlamada();

	//Getters
	Fecha getFechaLlamada();
	Hora getHoraLlamada();
	int getDuracion();

}; //Fin de la clase LLamada

//Sobrecarga del operador de insercion de  flujo para
//escribir en un flujo de salida la información de una llamada
ostream & operator<<(ostream& salida, Llamada *llamada);

// CLASES DERIVADAS DE LLAMADA

class Local:public Llamada{

public:
	Local(Fecha &fecha, Hora &horaI, int duracionL);
	float costoLlamada();
};

class Interurbana:public Llamada{
public:
	Interurbana(Fecha &fecha, Hora &horaI, int duracionL);
	float costoLlamada();
};

class Celular:public Llamada{
public:
	Celular(Fecha &fecha, Hora &horaI, int duracionL);
	float costoLlamada();
};
#endif /* LLAMADA_H_ */
