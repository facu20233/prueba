#include <iostream>
#include "evento.h"
#include "aplicacion.h"
#include "corporativo.h"
#include "personal.h"
using namespace std;

int main()
{
    aplicacion miAplicacion;

    // Registrar un evento corporativo
    evento *eventoCorp = miAplicacion.registrarEvento(1, "Evento Corporativo", "2023-10-15", 50, 3, false, 0, "Empresa ABC", false);

    servicio *servicio1 = new servicio(1, "Catering", 100.0);
    servicio *servicio2 = new servicio(2, "Música en vivo", 50.0);
    servicio *servicio3 = new servicio(3, "Decoración", 75.0);
    eventoCorp->agregarServicio(servicio1);
    eventoCorp->agregarServicio(servicio2);
    eventoCorp->agregarServicio(servicio3);

    // Registrar un evento personal
    evento *eventoPers = miAplicacion.registrarEvento(2, "Evento Personal", "2023-10-20", 30, 2, true, 5, "", false);
    
    servicio *servicio4 = new servicio(4, "Dj", 80.0);
    servicio *servicio5 = new servicio(5, "Iluminación", 40.0);
    eventoPers->agregarServicio(servicio4);
    eventoPers->agregarServicio(servicio5);

    // Generar resumen de facturación para el mes de octubre (mes 10)
    miAplicacion.generarResumenFacturacion(10);

    return 0;
}
