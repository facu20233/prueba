/*
 * LineaTelefonica.cpp
 */


#include "LineaTelefonica.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


//Inicializo el dato miembro estatico
float LineaTelefonica::abono = 500;

LineaTelefonica::LineaTelefonica(const string numero, const string titular){
	numeroTelefono=numero;
	nombreTitular=titular;
}

//La relacion entre LineaTelefonica y LLamada es una COMPOSICION
//Por lo tanto la linea telefonica debe encargarse de crear/destruir
//los objetos del tipo Llamada
bool LineaTelefonica::agregarLlamada(tipoLlamada tipo, Fecha &fecha, Hora &horaI, int duracionL){
	Llamada *nuevaLlamada = crearLlamadaSegunTipo(tipo, fecha, horaI, duracionL);
	llamadas.insert(llamadas.end(), nuevaLlamada);
	return true;
};
Llamada *LineaTelefonica::crearLlamadaSegunTipo(tipoLlamada tipo, Fecha &fecha, Hora &horaI, int duracionL){
	Llamada* nuevaLlamada;
	switch(tipo){
		case local: nuevaLlamada = new Local(fecha, horaI, duracionL); break;
		case interurbana: nuevaLlamada = new Interurbana(fecha, horaI, duracionL); break;
		case celular: nuevaLlamada = new Celular(fecha, horaI, duracionL); break;
	}
	return nuevaLlamada;
}


string LineaTelefonica::getNumero(){
	return numeroTelefono;
}
string LineaTelefonica::getTitular(){
	return nombreTitular;
}

float LineaTelefonica::getAbono(){
	return abono;
}
float LineaTelefonica::calcularImporte(Fecha &fechaI, Fecha &fechaF){
	float importe=0;
	vector<Llamada*>::iterator it;
	for (it=llamadas.begin(); it!=llamadas.end(); ++it){
		if(fechaF>= (*it)->getFechaLlamada() && (*it)->getFechaLlamada()>= fechaI)
			importe+= (*it)->costoLlamada();
	}
	return importe;
}

//Al eliminarse la LineaTelefonica, se deben eliminar
//todas las llamadas asociadas a la misma
LineaTelefonica::~LineaTelefonica(){
	vector<Llamada*>::iterator it;
	for (it=llamadas.begin(); it!=llamadas.end(); ++it){
		delete (*it); //Llama al detructor de Llamada y libera la memoria
	}
	llamadas.clear();
}
ostream & operator<<(ostream& salida, LineaTelefonica *linea) {
	salida << "  Linea= " << linea->getNumero()<< "    | "<< "   Titular= " << linea->getTitular() <<  endl;
	return salida;
}





