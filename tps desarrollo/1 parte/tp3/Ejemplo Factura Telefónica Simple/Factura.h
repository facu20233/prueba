/*
 * Factura.h
 */
#ifndef FACTURA_H_
#define FACTURA_H_
#include "LineaTelefonica.h"
#include "Fecha.h"
#include <vector>
#include <algorithm>

#include <iostream>
using namespace std;

class Factura {

private:
	//Atributos de clase
	static int facturasCreadas; //Autonumerico
	static const float IVA = 0.21;
	//Atributos de instancia
	int numeroFactura;//Se asigna automaticamente dentro del constructor
	Fecha &fechaInicio;
	Fecha &fechaFin;
	LineaTelefonica *linea;

	//Metodos Privados
	LineaTelefonica *getLinea();
	float calcularImporteLlamadas();
	float calcularImporteBruto() ;


public:
	float calcularImporteNeto();
	//Constructor
	Factura(LineaTelefonica *linea, Fecha &fechaI, Fecha &fechaF);
	//Metodo para emitir factura (escribe por pantalla)
	void emitirFactura();
};


#endif /* FACTURA_H_ */
