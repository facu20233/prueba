/*
 * Iterador.h
 *
 *  Created on: 12/12/2014
 *      Author: Graciela
 */

#ifndef ITERADOR_H_
#define ITERADOR_H_
#include "Arreglo.h"
using namespace std;

class IteradorPar
{
	const Arreglo &arre;
	int i;

public:
	IteradorPar(const Arreglo &arre) :
    arre(arre){
        i = 0;
    };

	~IteradorPar()
    {
        // Liberar recursos si es necesario
    }

    bool Final() const
    {
        return i < arre.MAX;
    }

    void Siguiente()
    {
        if (!Final())
        {
            i = i + 2;
        }
    }

    int ValorActual() const
    {
        if (!Final())
        {
            return arre.arreglo[i];
        }
        throw runtime_error("Iterador llegó al final de la fila.");
    }
};
#endif /* ITERADOR_H_ */
