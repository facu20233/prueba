//============================================================================
// Name        : TP2 - PruebaFila.cpp
// Author      : C�tedra Paradigmas de Programaci�n - FACET - UNT
//============================================================================

#include <iostream>

#include "Fila.h"

using namespace std;

void contarX(Fila F, item X);

int main() {

	/* Creo un objeto vector */
	Vector v;

	/* Muestro la informaci�n del vector recien creado */
	cout<<"Capacidad del vector: "<<v.getCapacidad()<<endl;
	cout<<"Datos del Vector (sin inicializar):"<<endl;
	cout<<v<<endl;

	/* Ingreso datos al vector por teclado*/
	cout<<"Ingrese los elementos del vector:"<<endl;
	cin>>v;

	/* Muestro el vector con los datos ingresados */
	cout<<"Datos del Vector (ingresados por teclado):"<<endl;
	cout<<v<<endl;

	/* Cambio valor del vector en la posicion y muestro 3 */
	v[2] = 1000;
	cout<<"Datos del Vector (con 3er elemento cambiado):"<<endl;
	cout<<v<<endl;

	/*PUNTO 3.c*/
	/* Invoco a la operacion externa mostrarPositivos que trabaja sobre una copia local del par�metro */
	//mostrarPositivos(v);

	/* Muestro por pantalla el vector luego de la invocacion a la operaci�n mostrar */
	// cout<<v<<endl;

	return 0 ;
}

void mostrarPositivos(Vector v){
	cout<<endl<<"Vector con elementos positivos"<<endl;
	for(int i=0; i<v.getCapacidad();i++)
		if(v[i]<=0)
			v[i]=INDEFINIDO;
	cout<<v<<endl;
}