// pedido.h
#include <iostream>
#include "elementoPedido.h"
using namespace std;

class pedido
{
private:
    string codPedido;
    string fecha;
    elementoPedido** listaElementos;
    int cantidadElementos;
    int capacidadElementos;
public:
    pedido(string codigo, string fecha){
        codPedido = codigo;
        fecha = fecha;
        capacidadElementos = 10; // Capacidad inicial para elementos del pedido (puedes ajustarla según tus necesidades)
        cantidadElementos = 0;
        listaElementos = new elementoPedido*[capacidadElementos];
    }
    ~pedido();

    void agregarElemento(elementoPedido* elemento){

    }

    float calcularMontoApagar(){
        // 
    }

    void listarInformacionPedido(){
        // 
    }
    
    string getFecha(){
        return fecha;
    }
    
};


