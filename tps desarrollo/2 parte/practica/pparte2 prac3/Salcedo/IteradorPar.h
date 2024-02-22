#ifndef ITERADORPAR_H_
#define ITERADORPAR_H_

#include <iostream>
#include "Arreglo.h"
using namespace std;

class Arreglo;

class IteradorPar
{
private:
    const Arreglo &arreglo;
    int i;
public:
    IteradorPar(const Arreglo &arreglo, int i):
    arreglo(arreglo), i(i) {}

    ~IteradorPar(){
        // 
    }

    bool Final() const
    {
        if (i < arreglo.MAX)
        {
            return false;
        }else
        {
            return true;
        }
    }

    void Siguiente()
    {
        if (!Final())
        {
            i = i+2;
        }
    }

    int ValorActual() const
    {
        if (!Final())
        {
            return arreglo.arreglo[i];
        }
        throw runtime_error("Iterador llegó al final de la fila.");
    }

};

#endif 

