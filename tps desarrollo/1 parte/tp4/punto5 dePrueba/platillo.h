// plattillo.h
#include <iostream>
#include "elementoPedido.h"
#include "ingrediente.h"
using namespace std;

// relacion de agregacion entre platllo y ingredientes
class platillo : public elementoPedido
{
private:
    // string codigo;
    // string descripcion;
    float precioBase;
    ingrediente** listaIngredientes;
    
public:
    platillo(/* args */);
    ~platillo();
    void agregarIngrediente(ingrediente* ingrediente){
        // 
    }

    // calcularPrecio
};


