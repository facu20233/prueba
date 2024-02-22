#include <iostream>
#include "publicacion.h"
#include "libro.h"
#include "revista.h"
#include "venta.h"
#include "sistema.h"
using namespace std;

int main(){
    publicacion *libro1 = new libro("libro1",2300,100.0,888,"facu",true);
    publicacion *revista1 = new revista("revista1",2000,200.0,999,10,2,"accion");
    
    venta* venta1 = new venta(1, "9-09-18");
    venta1->agregarArticulo(libro1);
    venta1->agregarArticulo(revista1);

    sistema libreria;
    libreria.registrarVenta(venta1);

    float montoTotalMes = libreria.calcularMontoTotalEnMes(9);
    cout << "monto mes X" << montoTotalMes << endl;

    delete libro1;
    delete revista1;

    return 0;    
}

