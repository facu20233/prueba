/*
 * Persona.cpp
 *
 *  Created on: 6/11/2014
 *      Author: Graciela
 */

#include "Persona.h"
#include <iostream>

using namespace std;

Persona::Persona(string nomb, string ape, long int doc, int dia, int mes, int anio): fechaNacimientoTC(dia, mes, anio){
																				//lista de inicializador de miembro que llama al constructor de
																				//Fecha para inicializar el objeto miembro fechaNacimiento


	cout<<"Constructor de Persona"<<endl;
	this->nombre=nomb;
	this->apellido=ape;
	this->dni = doc;
	this->fechaNacimientoTE = new Fecha;

}
void Persona::setFechaNacimiento(int dia, int mes, int anio){
	delete this->fechaNacimientoTE; //Libero la memoria asignada dinámicamente
	this->fechaNacimientoTE = new Fecha(dia, mes, anio);
}
Persona::~Persona(){
	delete this->fechaNacimientoTE;
	cout<<"Chau Persona: "<<this->nombre<<" "<<this->apellido<<endl;
}
string Persona::getNombre(){return this->nombre;};
string Persona::getApellido(){return this->apellido;};
long int Persona::getDni(){return this->dni;};
Fecha Persona::getFechaTC(){return this->fechaNacimientoTC;};
Fecha* Persona::getFechaTE(){return this->fechaNacimientoTE;};

ostream& operator<<(ostream &salida, Persona &P){

	salida<<endl<<"Nombre: "<<P.getNombre()<<endl;
	salida<<"Apellido: "<<P.getApellido()<<endl;
	salida<<"DNI: "<<P.getDni()<<endl;
	salida<<"Fecha de Nacimiento TC: "<<P.getFechaTC().toString()<<endl;
									//invoca a la funcion toString() con un objeto de clase Fecha
	salida<<"Fecha de Nacimiento TE: "<<P.getFechaTE()->toString()<<endl;
	Fecha fechaActual;
	int edad = fechaActual - P.getFechaTC();
	salida<<"Edad: "<<edad<<endl;
	return salida;
}

