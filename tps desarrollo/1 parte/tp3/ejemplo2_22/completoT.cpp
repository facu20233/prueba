#include <iostream>
#include <string>
#include <vector>

class RenglonFactura {
private:
    std::string producto;
    int cantidad;
    float montoParcial;

public:
    RenglonFactura(const std::string& producto, int cantidad, float montoParcial)
        : producto(producto), cantidad(cantidad), montoParcial(montoParcial) {
    }

    float calcularMontoParcial() const {
        return cantidad * montoParcial;
    }

    void mostrarInformacion() const {
        std::cout << "Producto: " << producto << std::endl;
        std::cout << "Cantidad: " << cantidad << std::endl;
        std::cout << "Monto Parcial: " << calcularMontoParcial() << std::endl;
    }
};

class Factura {
private:
    int numero;
    std::string fecha;
    std::string cliente;
    std::vector<RenglonFactura> renglones;

public:
    Factura(int numero, const std::string& fecha, const std::string& cliente)
        : numero(numero), fecha(fecha), cliente(cliente) {
    }

    void agregarRenglon(const RenglonFactura& renglon) {
        if (renglones.size() < 10) {
            renglones.push_back(renglon);
        } else {
            std::cout << "No se pueden agregar más renglones a la factura." << std::endl;
        }
    }

    float calcularMontoTotal() const {
        float total = 0.0;
        for (const auto& renglon : renglones) {
            total += renglon.calcularMontoParcial();
        }
        return total;
    }

    void mostrarInformacion() const {
        std::cout << "Número de Factura: " << numero << std::endl;
        std::cout << "Fecha de Emisión: " << fecha << std::endl;
        std::cout << "Cliente: " << cliente << std::endl;
        std::cout << "Renglones de la Factura:" << std::endl;
        for (const auto& renglon : renglones) {
            renglon.mostrarInformacion();
        }
        std::cout << "Monto Total: " << calcularMontoTotal() << std::endl;
    }
};

int main() {
    Factura factura(1, "2023-09-13", "Cliente Ejemplo");

    RenglonFactura renglon1("Producto A", 2, 10.0);
    RenglonFactura renglon2("Producto B", 3, 15.0);

    factura.agregarRenglon(renglon1);
    factura.agregarRenglon(renglon2);

    factura.mostrarInformacion();

    return 0;
}
