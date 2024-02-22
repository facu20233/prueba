#include <iostream>
#include "Producto.h"
#include "ProductoAlimenticio.h"
#include "ProductoDeLimpieza.h"

int main()
{
    // Crear un Producto de Limpieza
    ProductoDeLimpieza limpieza(101, "Detergente", 5.0, true);

    // Crear un Producto Alimenticio
    ProductoAlimenticio alimento(202, "Pan", 2.0, false, 9, 2024, true);

    // Mostrar información de los productos
    std::cout << "Producto de Limpieza:" << std::endl;
    limpieza.listarInformacion();
    std::cout << "Es Tóxico: " << (limpieza.esToxico() ? "Sí" : "No") << std::endl;
    std::cout << "Precio Final con IVA: $" << limpieza.calcularPrecio() << std::endl;

    std::cout << "\nProducto Alimenticio:" << std::endl;
    alimento.listarInformacion();
    std::cout << "Está Vencido: " << (alimento.estaVencido(9, 2023) ? "Sí" : "No") << std::endl;
    std::cout << "Es Apto para Celiacos: " << (alimento.esAptoCeliacos() ? "Sí" : "No") << std::endl;
    std::cout << "Precio Final con IVA: $" << alimento.calcularPrecio() << std::endl;

    return 0;
}
