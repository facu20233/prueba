/*
 * PARADIGMAS DE PROGRAMACION - 2do PARCIAL 2022 - 06/12/22
 *
 * APELLIDO Y NOMBRE:
 *
 * Arreglo.h
 *
 */

#ifndef ARREGLO_H_
#define ARREGLO_H_
#include <iostream>
using namespace std;

template <typename T>
class IteradorPar;

template <typename T>
class Arreglo
{
	const T indefinido;
	T *arreglo;
	int MAX;
	T *reservarMemoria(unsigned int tama);
	friend class IteradorPar<T>;
	
public:
	Arreglo(unsigned int dim, T indef);
	Arreglo(const Arreglo &arre);
	T &operator[](int posicion);
	void escribir();
	int Primer();
	int capacidad();
	bool pertenece(T X);
	~Arreglo();
};

template <typename T>
T *Arreglo<T>::reservarMemoria(unsigned int tama)
{
	T *reserva = new T[tama];
	if (reserva == NULL)
	{
		cout << "Problema: no se pudo realizar la reserva";
	}
	return reserva;
}

template <typename T>
Arreglo<T>::Arreglo(unsigned int dim, T indef) : indefinido(indef)
{
	this->MAX = dim + 1; // Se agrega un elemento mas para trabajar con arreglo[0] como indefinido del tipo de dato
	this->arreglo = reservarMemoria(this->MAX);
	if (this->arreglo == NULL)
		this->MAX = 0;
	else
		for (int i = 0; i < this->MAX; i++)
			this->arreglo[i] = this->indefinido;
}

template <typename T>
Arreglo<T>::Arreglo(const Arreglo &arre) : indefinido(arre.indefinido)
{
	this->MAX = arre.MAX;
	this->arreglo = reservarMemoria(this->MAX);
	if (this->arreglo == NULL)
		this->MAX = 0;
	else
		for (int i = 0; i < this->MAX; i++)
			this->arreglo[i] = arre.arreglo[i];
}

template <typename T>
T &Arreglo<T>::operator[](int posicion)
{
	// posicion pertenece al intervalo  [1,MAX)
	if (0 < posicion && posicion < this->MAX)
	{
		return this->arreglo[posicion];
	}
	else
		return this->arreglo[0];
}

template <typename T>
void Arreglo<T>::escribir()
{
	cout << endl
		 << " CONTENEDOR INT:" << endl;
	for (int i = 1; i < this->MAX; i++)
	{
		cout << i <<":     " << this->arreglo[i] << endl;
	}
}

template <typename T>
int Arreglo<T>::Primer()
{
	
	return this->arreglo[MAX];
}
template <typename T>
int Arreglo<T>::capacidad()
{
	return this->MAX;
}

template <typename T>
bool Arreglo<T>::pertenece(T X)
{
	int k = 1;
	while (k < this->MAX && this->arreglo[k] != X)
	{
		k++;
	}
	return k < this->MAX;
}

template <typename T>
Arreglo<T>::~Arreglo()
{
	this->MAX = 0;
	delete[] this->arreglo;
};

#endif /* ARREGLO_H_ */
