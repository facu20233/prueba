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

class Arreglo
{
	// privado por defecto
	const int indefinido;
	int *arreglo;
	int MAX;
	int *reservarMemoria(unsigned int tama);

	friend class IteradorPar;
	friend class IteradorInverso;
	friend class IteradorTradicional;
	friend class IteradorPares;
	friend class IteradorImpares;

public:
	Arreglo(unsigned int dim, int indef);
	Arreglo(const Arreglo &arre);
	int &operator[](int posicion);
	void escribir();
	int Primer();
	int capacidad();
	bool pertenece(int X);
	~Arreglo();

	// Arreglo &operator=(const Arreglo &otro)
	// {
	// 	if (this != &otro)
	// 	{					  // Evitar la auto-asignación
	// 		delete[] arreglo; // Liberar la memoria actual
	// 		MAX = otro.MAX;
	// 		indefinido = otro.indefinido;
	// 		arreglo = new int[MAX];
	// 		for (int i = 1; i < MAX; ++i)
	// 		{
	// 			arreglo[i] = otro.arreglo[i];
	// 		}
	// 	}
	// 	return *this;
	// }

	Arreglo operator+(const Arreglo &otro) const
	{
		Arreglo resultado(MAX - 1, indefinido); // Crear un arreglo del mismo tamaño que el original
		for (int i = 1; i < MAX; ++i)
		{
			resultado.arreglo[i] = arreglo[i] + otro.arreglo[i]; // Sumar los elementos correspondientes
		}
		return resultado;
	}

	bool operator==(const Arreglo &otro) const
	{
		if (MAX != otro.MAX)
		{
			return false; // Los arreglos tienen diferentes tamaños
		}
		for (int i = 1; i < MAX; ++i)
		{
			if (arreglo[i] != otro.arreglo[i])
			{
				return false; // Los elementos no son iguales
			}
		}
		return true; // Los arreglos son iguales
	}
};

int *Arreglo::reservarMemoria(unsigned int tama)
{
	int *reserva = new int[tama];
	if (reserva == NULL)
	{
		cout << "Problema: no se pudo realizar la reserva";
	}
	return reserva;
}

Arreglo::Arreglo(unsigned int dim, int indef) : indefinido(indef)
{
	this->MAX = dim + 1; // Se agrega un elemento mas para trabajar con arreglo[0] como indefinido del tipo de dato
	this->arreglo = reservarMemoria(this->MAX);
	if (this->arreglo == NULL)
		this->MAX = 0;
	else
		for (int i = 0; i < this->MAX; i++)
			this->arreglo[i] = this->indefinido;
}

Arreglo::Arreglo(const Arreglo &arre) : indefinido(arre.indefinido)
{
	this->MAX = arre.MAX;
	this->arreglo = reservarMemoria(this->MAX);
	if (this->arreglo == NULL)
		this->MAX = 0;
	else
		for (int i = 0; i < this->MAX; i++)
			this->arreglo[i] = arre.arreglo[i];
}

int &Arreglo::operator[](int posicion)
{
	// posicion pertenece al intervalo  [1,MAX)
	if (0 < posicion && posicion < this->MAX)
	{
		return this->arreglo[posicion];
	}
	else
		return this->arreglo[0];
}

void Arreglo::escribir()
{
	cout << endl
		 << " CONTENEDOR INT:" << endl;
	for (int i = 1; i < this->MAX; i++)
	{
		cout << "     " << this->arreglo[i] << endl;
	}
}

//*
int Arreglo::Primer()
{

	return this->arreglo[MAX];
}

int Arreglo::capacidad()
{
	return this->MAX;
}

bool Arreglo::pertenece(int X)
{
	int k = 1;
	while (k < this->MAX && this->arreglo[k] != X)
	{
		k++;
	}
	return k < this->MAX;
}

Arreglo::~Arreglo()
{
	this->MAX = 0;
	delete[] this->arreglo;
};

#endif /* ARREGLO_H_ */
