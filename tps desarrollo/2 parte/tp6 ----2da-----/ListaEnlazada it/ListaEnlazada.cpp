//============================================================================
// Name        : ListaEnlazada.cpp
// Author      : CW
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Lista.h"
#include "Iterador.h"

#define MAX 5
using namespace std;
bool pertenece(Lista &l, item x);

int main() {

	Lista l1;
	int i;
	for(i=1;i<=MAX ;i++){
		l1.insertar(i);
	}

	l1.escribir();
	//Si no tuviera la funcion escribir,
	//�C�mo hago para escribir los elementos de la lista?

	/*
	int cant = l1.cantidad();
	cout<<endl<<"Escribo la lista desde el main"<<endl;
	for(i=1;i<=cant;i++){
		cout<<l1.elemento()<<endl;
		l1.borrar();
	}
	*/
	if(l1.esVacia())
		cout<<"Lista vacia"<<endl;
	else
		cout<<"Lista con elementos"<<endl;



	cout<<endl<<"Escribo la lista desde el main con ITERADOR"<<endl;
	Iterador it(l1);
	for( ; it.hayMasElementos();it.avanzar()){
		cout<<it.elementoActual()<<" - ";
	}
	cout <<endl;

	if(l1.esVacia())
		cout<<"Lista vacia"<<endl;
	else
		cout<<"Lista con elementos"<<endl;

	if(pertenece(l1,4))
		cout<<"Pertenece"<<endl;
	else
		cout<<"NO Pertenece"<<endl;




	return 0;

}


bool pertenece(Lista &l, item x)
{
	Iterador it(l);
	bool resultado = false;
	while(!resultado && it.hayMasElementos()){
		resultado = it.elementoActual() == x;
		it.avanzar();
	}
	return resultado;
}

