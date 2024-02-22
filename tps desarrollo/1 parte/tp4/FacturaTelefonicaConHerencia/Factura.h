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
	float calcularImporteNeto();

public:
	//Constructor
	Factura(LineaTelefonica *linea, Fecha &fechaI, Fecha &fechaF);
	//Metodo para emitir factura (escribe por pantalla)
	void emitirFactura();
};
//Inicializo el dato miembro estatico
int Factura::facturasCreadas=13456;

Factura::Factura(LineaTelefonica *lineaT, Fecha &fechaI, Fecha &fechaF):fechaInicio(fechaI),fechaFin(fechaF){
	this->numeroFactura=++Factura::facturasCreadas;
	this->linea=lineaT;
}
LineaTelefonica *Factura::getLinea(){
	return this->linea;
}

float Factura::calcularImporteLlamadas(){
	return this->getLinea()->calcularImporte(this->fechaInicio, this->fechaFin);
}
float Factura::calcularImporteBruto() {
	return this->getLinea()->getAbono() + this->calcularImporteLlamadas();
};


float Factura::calcularImporteNeto(){
	return (1.0+this->IVA)*this->calcularImporteBruto();
}

void Factura::emitirFactura(){
	cout<<"                              FACTURA: "<<this->numeroFactura<<endl;
	cout << "  -------------------------------------------" << endl;
 	cout <<this->getLinea();
	cout << "  -------------------------------------------" << endl<< endl;
	cout << "  Resumen de Consumo" << endl;
	cout << "  -------------------------------------------" << endl;
	cout << "     Abono .......... $ " << this->getLinea()->getAbono()<< endl;
	cout << "     Llamadas........ $ " << this->calcularImporteLlamadas()<< endl;
	cout << "  -------------------------------------------" << endl;
	cout << "  Total bruto ....... $ " << this->calcularImporteBruto()<< endl;
	cout << "  Total neto (+IVA).. $ " << this->calcularImporteNeto() << endl;
}

#endif /* FACTURA_H_ */
