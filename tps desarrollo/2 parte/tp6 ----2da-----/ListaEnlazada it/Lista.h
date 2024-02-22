/*
 * Lista.h
 *
 *  Created on: 12/12/2014
 *      Author: Graciela
 */

#ifndef LISTA_H_
#define LISTA_H_
#include "Nodo.h"
#include <iostream>
using namespace std;

class Lista {
	Nodo* lista;
	int longitud;

public:
	Lista():lista(NULL),longitud(0){};

	void insertar(item dato){
		Nodo* nuevo = new Nodo(dato, lista);
		lista=nuevo;
		longitud++;
	};

	void borrar(){
		if(!esVacia()){
			Nodo* aux= lista;
			lista = lista->getSiguiente();
			delete aux;
			longitud--;
		}
	};

	item elemento(){
		if(!esVacia())
			return lista->getDato();
		else
			return INDEFINIDO;
	};

	int cantidad(){return longitud;};

	bool esVacia(){return longitud==0;};

	virtual ~Lista(){
		for(int i=0;i<longitud;i++)
			borrar();
	};
	void escribir(){
		cout<<"Lista: ";
		for(Nodo*aux=lista;aux!=NULL;aux=aux->getSiguiente()){
				cout<<aux->getDato()<<" ";
			}
			cout<<endl;
		};

	friend class Iterador;

};


#endif     /* LISTA_H_ */

/*
void escribir(){
	cout<<"Lista: ";
	for(Nodo*aux=lista;aux!=NULL;aux=aux->getSiguiente()){
			cout<<aux->getDato()<<" ";
		}
		cout<<endl;
	};
*/

