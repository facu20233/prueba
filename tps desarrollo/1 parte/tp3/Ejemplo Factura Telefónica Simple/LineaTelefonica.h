
#ifndef LINEA_H_
#define LINEA_H_
#include "Llamada.h"
#include <vector>
#include <algorithm>

#include <iostream>
using namespace std;

class LineaTelefonica {

private:
	string numeroTelefono;
	string nombreTitular;
	static float abono;//Comun a todas las lineas
	vector<Llamada*> llamadas;

public:
	//Constructor
	LineaTelefonica(const string numero, const string titular);

	//Metodo que agrega una llamada a la Linea Telefónica
	bool agregarLlamada(Fecha &fecha, Hora &horaI, int duracionL);

	//Metodo que calcula el importe de las llamadas realizadas entre esas fechas
	float calcularImporte(Fecha &fechaI, Fecha &fechaF);

	//Getters
	static float getAbono();
	string getNumero();
	string getTitular();

	//Destructor
	~LineaTelefonica();
};

//Sobrecarga del operador de inserción de flujo para escribir
//en un flujo de salida la información de una Linea Telefonica
ostream & operator<<(ostream& salida, LineaTelefonica *linea);

#endif /* LINEA_H_ */
