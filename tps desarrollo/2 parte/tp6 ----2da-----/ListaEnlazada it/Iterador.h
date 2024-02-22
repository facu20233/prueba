/*
 * Iterador.h
 *
 *  Created on: 12/12/2014
 *      Author: Graciela
 */

#ifndef ITERADOR_H_
#define ITERADOR_H_
#include "Lista.h"
using namespace std;

class Iterador
{
	const Lista &listaEnlazada;
	Nodo *actual;

public:
	Iterador(const Lista &l) : listaEnlazada(l), actual(l.lista){};
	// Iterador(const Lista &l):actual(l.lista){};

	bool hayMasElementos()
	{
		return actual != NULL;
	};

	item elementoActual()
	{
		return actual->getDato();
	};

	void avanzar()
	{
		actual = actual->getSiguiente();
	};
};
#endif /* ITERADOR_H_ */
