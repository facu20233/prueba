#include <iostream>
#include "evento.h"
#include "aplicacion.h"
#include "corporativo.h"
#include "personal.h"
using namespace std;

int main() {
    // Crear una instancia de la aplicación
    aplicacion miAplicacion;

    // Crear afuera
    servicio* servicio1 = new servicio(1, "Catering", 50.0);
    servicio* servicio2 = new servicio(2, "Decoración", 100.0);
    servicio* servicio3 = new servicio(3, "Música en vivo", 200.0);

    // creo evento 
    // COMPOSICION
    miAplicacion.registrarEvento(1, "Evento de Cumpleaños", "2023-10-06", 50, 2);
    miAplicacion.registrarEvento(2, "Reunión Corporativa", "2023-11-15", 200, 1);

    // Agregar servicios a eventos
    miAplicacion.getEventos()[0]->agregarServicio(servicio1);
    miAplicacion.getEventos()[0]->agregarServicio(servicio2);
    miAplicacion.getEventos()[1]->agregarServicio(servicio3);

    // Crear eventos personalizados y 
    // crear adentro
    // personal eventoPersonal(3, "Evento Personalizado", "2023-12-20", 30, 5);
    // corporativo eventoCorporativo( "Evento Corporativo", "2024-01-10", 100, "ABC Company", true);

    // Agregar servicios a eventos personalizados y corporativos
    // AGREGACION
    // eventoPersonal.agregarServicio(servicio1);
    // eventoCorporativo.agregarServicio(servicio2);
    // eventoCorporativo.agregarServicio(servicio3);

    // personal
    personal eventoPersonal = miAplicacion.registrarEvento(111, "fiesta","2023-09-11",10, 6, );
    // corporativo
    miAplicacion.registrarEvento(112, "fiesta2","2023-09-11",10, 5, false, ); 

    // Generar resumen de facturación para un mes específico
    miAplicacion.generarResumenFacturacion(11); // Noviembre

    // Liberar la memoria de los servicios
    delete servicio1;
    delete servicio2;
    delete servicio3;

    return 0;
}
