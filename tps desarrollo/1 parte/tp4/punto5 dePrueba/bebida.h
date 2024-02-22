// bebida.h
#include <iostream>
#include "elementoPedido.h"
using namespace std;

class bebida : public elementoPedido
{
private:
    // string codigo;
    // string descripcion;
    float capacidad;
    float precio;

public:
    bebida(string codigo, string descripcion, float capacidad, float precio);
    ~bebida();

    // calcular precio
};


