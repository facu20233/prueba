// iteradorDeFila.h
#include <iostream>
#include "Fila.h"  // Asegúrate de incluir Fila.h si defines la clase Fila en otro archivo.
using namespace std;

class IteradorDeFila
{
private:
    const Fila &fila;
    Nodo *actual; // Puntero al NODO actual

public:
    IteradorDeFila(const Fila &fila) : fila(fila), actual(fila.frente)
    {
        // Inicializar el puntero al primer elemento
    }

    ~IteradorDeFila()
    {
        // Liberar recursos si es necesario
    }

    bool Final() const
    {
        return actual == nullptr;
    }

    void Siguiente()
    {
        if (!Final())
        {
            actual = actual->siguiente;
        }
    }

    int ValorActual() const
    {
        if (!Final())
        {
            return actual->valor;
        }
        throw runtime_error("Iterador llegó al final de la fila.");
    }
    
};
