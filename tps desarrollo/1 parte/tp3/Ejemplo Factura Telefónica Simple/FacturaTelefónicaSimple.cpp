//============================================================================
// Name        : FacturaTelefónicaSimple.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "factura.h"

using namespace std;
ostream& operator<<(ostream& salida, Factura &fact){
	salida<<"Importe Neto: $"<<fact.calcularImporteNeto()<<endl;
	return salida;
};
int main() {
	Fecha fIncio(1,9,2017);
	Fecha f2(2,9,2017);
	Fecha f3(3,9,2017);
	Fecha f4(4,9,2017);
	Fecha fFin(10,10,2017);
	Fecha fFueraRango1(12,8,2017);
	Fecha fFueraRango2(12,10,2017);

	LineaTelefonica linea1("4223344","Juan Perez");
	Hora h1, h2(22,14,56);
	linea1.agregarLlamada(fFueraRango1, h1, 15);
	linea1.agregarLlamada(f2, h1, 15);
	linea1.agregarLlamada(f3, h1, 10);
	linea1.agregarLlamada(f4, h2, 10);
	linea1.agregarLlamada(fFueraRango2, h1, 6);

	Factura factura(&linea1, fIncio, fFin);
	factura.emitirFactura();
	cout<<factura;

	return 0;
}

