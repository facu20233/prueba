/*
 * Llamada.cpp
 */
#include <iostream>
#include "Llamada.h"

using namespace std;

//Inicializo el dato miembro estatico
float Llamada::costoBase = 1;

Llamada::Llamada(){
	duracion=0;
	//¿Cómo se inicializa el resto de los atributos?
};

Llamada::Llamada(Fecha &fecha, Hora &horaI, int duracionL):fechaLlamada(fecha),horaInicio(horaI){
		duracion=duracionL;
}

float Llamada::costoLlamada(){
	return this->costoBase*this->duracion;
}

Fecha Llamada::getFechaLlamada(){
	return this->fechaLlamada;
}
Hora Llamada::getHoraLlamada(){
	return this->horaInicio;
}
int Llamada::getDuracion(){
	return this->duracion;
}

ostream & operator<<(ostream& salida, Llamada *llamada) {
	salida<< "Llamada "<<endl;
	salida<< "Fecha "<<llamada->getFechaLlamada()<<endl;
	salida<< "Hora de inicio "<<llamada->getHoraLlamada()<<endl;
	salida<< "Duracion "<<llamada->getDuracion()<<endl;
	salida<< "Costo "<<llamada->costoLlamada()<<endl;
	return salida;
}






