// restaurante.h
#include <iostream>
#include "pedido.h"
using namespace std;

// relacion de  composicion entre restaurante y pedido
class restaurante
{
private:
    pedido** listaPedidos;
    int capacidad;
    int cantidadPedidos;
public:
    restaurante(int capacidad)
    {
        capacidad = capacidad;
        cantidadPedidos = 0;
        listaPedidos = new pedido*[capacidad];
    }
    ~restaurante(){
        for (int i = 0; i < cantidadPedidos; ++i)
        {
            delete listaPedidos[i];
        }
        delete[] listaPedidos;
    }

    void agregarPedido(pedido* pedido){
        if (cantidadPedidos < capacidad)
        {
            listaPedidos[cantidadPedidos] = pedido;
            cantidadPedidos++;
        }
        else
        {
            cout << "No se puede agregar más pedidos. Capacidad máxima alcanzada." << endl;
        }
    }
    void calcularMontoTotalDelDia(string fecha){
        float montoTotal = 0;
        for (int i = 0; i < cantidadPedidos; ++i)
        {
            if (listaPedidos[i]->getFecha() == fecha)
            {
                montoTotal += listaPedidos[i]->calcularMontoApagar();
            }
        }
        cout << "Monto total recaudado el día " << fecha << ": $" << montoTotal << endl;
    }

    void listarPedidos(){
        for (int i = 0; i < cantidadPedidos; ++i)
        {
            cout << "Pedido #" << i + 1 << ":" << endl;
            listaPedidos[i]->listarInformacionPedido();
            cout << "------------------------" << endl;
        } 
    }
};


