/*
 * Factura.cpp
 *
 *  Created on: 9/9/2020
 *      Author: Graciela
 */

#include "Factura.h"
#include <vector>
#include <algorithm>

#include <iostream>
using namespace std;

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

