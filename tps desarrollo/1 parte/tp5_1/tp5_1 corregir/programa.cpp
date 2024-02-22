#include <iostream>
#include "evento.h"
#include "aplicacion.h"
#include "corporativo.h"
#include "personal.h"
using namespace std;

int main() {

    // Crear la aplicación
    aplicacion miAplicacion;

    // Crear algunos servicios
    // creo un servicio afuera
    servicio* servicio1 = new servicio(1, "Banquete", 50.0);
    servicio* servicio2 = new servicio(2, "Decoracion", 30.0);

    // Crear eventos corporativos y/o personales
    // creando un evento
    corporativo* eventoCorp1 = new corporativo(101, "Evento Corporativo 1", "2023-10-15", 80, "Empresa XYZ", true);
   
    // esto es agregacion porque le estoy pasando un servicio
    eventoCorp1->agregarServicio(servicio1);
    eventoCorp1->agregarServicio(servicio2);

    personal* eventoPers1 = new personal(102, "Evento Personal 1", "2023-11-05", 30, 10);
    eventoPers1->agregarServicio(servicio1);

    // Registrar los eventos en la aplicación
    // esto esta mal porque estoy pasando un evento
    // pasar los parametros para crear un evento
    miAplicacion.registrarEvento(eventoCorp1);
    miAplicacion.registrarEvento(eventoPers1);

    // Generar un resumen de facturación para el mes 10 (octubre)
    miAplicacion.generarResumenFacturacion(10);

    // Liberar memoria de servicios y eventos (esto debería hacerse en la aplicación real)
    delete servicio1;
    delete servicio2;
    delete eventoCorp1;
    delete eventoPers1;

    return 0;
}
