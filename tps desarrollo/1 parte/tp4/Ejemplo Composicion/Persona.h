/*
 * Persona.h
 *
 *  Created on: 6/11/2014
 *      Author: Graciela
 */

#ifndef PERSONA_H_
#define PERSONA_H_
#include "Fecha.h"

using namespace std;

class Persona {

	string nombre;
	string apellido;
	long int dni;
	Fecha fechaNacimientoTC;
	Fecha *fechaNacimientoTE;

public:
	Persona(string nomb, string ape, long int doc, int dia, int mes, int anio);
	~Persona();

	void setFechaNacimiento(int d, int m, int a);
	string getNombre();
	string getApellido();
	long int getDni();
	Fecha getFechaTC();
	Fecha* getFechaTE();

	//Sobrecarga del operador de inserción de
	//flujo como amiga de la clase Persona
	friend ostream& operator<<(ostream &salida, Persona &P);

};


#endif /* PERSONA_H_ */
