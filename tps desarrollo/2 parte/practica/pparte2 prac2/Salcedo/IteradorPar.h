#ifndef ITERADORPAR_H
#define ITERADORPAR_H
#include <iostream>
#include "Arreglo.h"
using namespace std;

class IteradorPar
{
private:
    const Arreglo& arre;
    int indice;
public:
    IteradorPar(const Arreglo &arre, int indice) : arre(arre), indice(indice)
    {
        // Inicializar el puntero al primer elemento
    }

    ~IteradorPar(){
        // 
    }

    bool Final() const
    {
        if (indice < arre.MAX)
        {
            return false;
        }else
        {
            return true;

        }
        
        // return indice < arre.MAX - 1;
    }

    void Siguiente()
    {
        indice = indice + 2;
    }

    int ValorActual() const
    {
        if (!Final())
        {
            return arre.arreglo[indice];
        }
        else
        {
            cout << "Error: Índice fuera de rango." << endl;
            return int();
        }
    }

};

#endif

