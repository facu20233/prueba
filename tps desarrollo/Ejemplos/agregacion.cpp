#include <iostream>
#include <string>
#include <vector>

class ControlRemoto {
public:
    ControlRemoto(std::string modelo) : modelo(modelo) {}

    void cambiarCanal(int nuevoCanal) {
        std::cout << "Cambiando al canal " << nuevoCanal << std::endl;
    }

private:
    std::string modelo;
};

class Television {
public:
    Television(std::string marca) : marca(marca) {}

    void encender() {
        std::cout << "Encendiendo la televisión de la marca " << marca << std::endl;
    }

    void apagar() {
        std::cout << "Apagando la televisión de la marca " << marca << std::endl;
    }

    // Método que toma un ControlRemoto como parámetro
    void conectarControl(ControlRemoto& control) {
        std::cout << "Conectando el control remoto modelo " << control.modelo << " a la televisión." << std::endl;
    }

private:
    std::string marca;
};

int main() {
    Television miTV("Sony");
    ControlRemoto miControl("RC-123");

    miTV.encender();
    miTV.conectarControl(miControl);

    miControl.cambiarCanal(5);

    miTV.apagar();

    return 0;
}
