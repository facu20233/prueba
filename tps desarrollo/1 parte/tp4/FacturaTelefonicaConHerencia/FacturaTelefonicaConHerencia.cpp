//============================================================================
// Name        : FacturaTelefónicaSimple.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "factura.h"
#include "Llamada.h"
//#include "LineaTelefonica.h"

using namespace std;

int main() {
	Fecha fInicio(1,9,2017);
	Fecha f2(2,9,2017);
	Fecha f3(3,9,2017);
	Fecha f4(4,9,2017);
	Fecha fFin(10,10,2017);
	Fecha fFueraRango1(12,8,2017);
	Fecha fFueraRango2(12,10,2017);
	Hora h1, h2(22,14,56);

	//Pruebo que cada tipo de llamada funcione correctamente
	Local llamadaLocal(f2, h1, 10);
	cout<<"Costo Llamada Local: "<<llamadaLocal.costoLlamada()<<endl;

	Interurbana llamadaInterurbana(f2, h1, 10);
	cout<<"Costo Llamada Interurbana: "<<llamadaInterurbana.costoLlamada()<<endl;

	Celular llamadaCelular(f2, h1, 10);
	cout<<"Costo Llamada Celular: "<<llamadaCelular.costoLlamada()<<endl;

	//Creo una línea telefónica y le agrego llamadas de distinto tipo
	LineaTelefonica linea1("4223344","Juan Perez");
	linea1.agregarLlamada(local, f2, h1, 10);
	linea1.agregarLlamada(interurbana, f2, h1, 10);
	linea1.agregarLlamada(celular, f2, h1, 10);

	cout<<endl<<"Importe de llamadas de linea1: "<<linea1.calcularImporte(fInicio, f2)<<endl<<endl;


/*
	Llamada *ptrBase = &llamadaLocal;
	cout<<"Costo Local: "<<ptrBase->costoLlamada()<<endl;
*/
	/*
	//Creo una Factura
	Factura factura(&linea1, fInicio, fFin);
	factura.emitirFactura();
	*/



	return 0;
}

