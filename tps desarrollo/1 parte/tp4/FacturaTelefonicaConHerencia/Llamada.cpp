/*
 * Llamada.cpp
 */
#include <iostream>
#include "Llamada.h"

using namespace std;

// FUNCIONES CLASE LLAMADA----------------------------------------------------------------

//Inicializo el dato miembro estatico
float Llamada::costoBase = 1;

Llamada::Llamada(){
	duracion=0;
};

Llamada::Llamada(Fecha &fecha, Hora &horaI, int duracionL):fechaLlamada(fecha),horaInicio(horaI){
		duracion=duracionL;
}

float Llamada::costoLlamada(){
	//return this->costoBase*this->duracion;
	return 0;
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

// FUNCIONES CLASE LOCAL ----------------------------------------------------------------
Local::Local(Fecha &fecha, Hora &horaI, int duracionL):Llamada(fecha, horaI, duracionL){};

float Local::costoLlamada(){
	return this->costoBase*this->duracion;
};

// FUNCIONES CLASE INTERURBANA----------------------------------------------------------------

Interurbana::Interurbana(Fecha &fecha, Hora &horaI, int duracionL):Llamada(fecha, horaI, duracionL){};

float Interurbana::costoLlamada(){
	float costoMinuto = costoBase*1.7;
	if(horaInicio>22 || horaInicio==22 || 6>horaInicio || 6==horaInicio)
				costoMinuto=this->costoBase;

	return costoMinuto*this->duracion;
};

// FUNCIONES CLASE CELULAR----------------------------------------------------------------
Celular::Celular(Fecha &fecha, Hora &horaI, int duracionL):Llamada(fecha, horaI, duracionL){};

float Celular::costoLlamada(){
	float costoMinuto = costoBase*1.8;
	float costo=costoMinuto*this->duracion;
	if (this->duracion>5)
		costo = costoMinuto*5 + costoMinuto*0.70*(this->duracion - 5);
	return costo;
}




