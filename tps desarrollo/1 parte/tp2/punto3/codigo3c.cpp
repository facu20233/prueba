// codigo3c.cpp
//============================================================================
// Name        : TP2 - PruebaFila.cpp
// Author      : C�tedra Paradigmas de Programaci�n - FACET - UNT
//============================================================================

#include <iostream>

#include "fila.h"

using namespace std;

typedef int item;
int contarX(Fila F, item X);

int main() {

	// Creo un objeto fila con el constructor por defecto
	Fila F;

	// Controlo si la fila fue inicializada correctamente con el constructor
	if(F.EsFilaVacia())
		cout<<"CORRECTO - La Fila esta vacia"<<endl;
	else
		cout<<"ERROR - La Fila deberia estar vacia"<<endl;

	// Ingreso 3 items a la fila muestro el frente de la fila y la fila completa
	F.Enfila(1);
	F.Enfila(2);
	F.Enfila(3);

	cout<<"El frente de la fila es: "<<F.Frente()<<endl;

	cout<<"Contenido de la fila luego de insertar 3 items"<<endl;
	F.Mostrar();

	// Escribo la longitud de la fila 
	cout<<"Longitud de la fila luego de insertar 3 items: "<<F.Longitud()<<endl;

	// Elimino el frente de la fila y muestro la fila
	F.Defila();

	cout<<"Contenido de la fila luego de eliminar el frente"<<endl;
	F.Mostrar();

	// Pruebo la operaci�n Pertenece con un elemento que se encuentra en la fila 
	if(F.Pertenece(3))
			cout<<"CORRECTO - El elemento pertenece a la fila"<<endl;
		else
			cout<<"ERROR - El elemento si pertence a la fila"<<endl;

	// Pruebo la operaci�n Pertenece con un elemento que se encuentra en la fila 
	if(F.Pertenece(999))
			cout<<"ERROR - El elemento NO pertenece a la fila"<<endl;
		else
			cout<<"CORRECTO - El elemento no pertence a la fila"<<endl;

	// PUNTO 3) c.

	
	// Invoco a la operacion externa contarX que trabaja sobre una copia local del par�metro fila
	int cantidad = contarX(F, 3);

	cout<<"Cantidad de elenentos iguales a X:  "<<cantidad<<endl;


	// Muestro por pantalla la fila luego de la invocacion a la operaci�n mostrar
	cout<<"Muestro por pantalla la fila luego de invocar a la operacion externa contarX"<<endl;
	F.Mostrar();

	// sin constructor copia no se borra la fila
	// constructor copia no se borra la fila
	// con Fila& F se borra la fila

	// PUNTO 3) f.
	Fila F2 = F; //se crea una copia de la  fila
	cout<<"muestro la copia de la fila"<<endl;
	F2.Mostrar();

	return 0 ;
}

// punto 3c
// como usuario
// int contarX(Fila& F, item X) { //para evitar que la fila orginial se vea afectada, al contrario

// toma una copia Fila F, no la original
int contarX(Fila F, item X){
	int contador = 0;

		while(!F.EsFilaVacia()){
			int elemento = F.Frente();
			F.Defila();

			if (elemento == X) {
				contador++;
			}
		}
		// termine se vera la fila vacia

		return contador;
}



