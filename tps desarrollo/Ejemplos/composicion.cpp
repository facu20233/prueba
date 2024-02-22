#include <iostream>
#include <string>

class ControlRemoto {
public:
    ControlRemoto(std::string modelo) : modelo(modelo) {}

    void cambiarCanal(int nuevoCanal) {
        std::cout << "Cambiando al canal " << nuevoCanal << " usando el control remoto " << modelo << std::endl;
    }

private:
    std::string modelo;
};

class Television {
public:
    Television(std::string marca, std::string modeloControl) : marca(marca), control(modeloControl) {}

    void encender() {
        std::cout << "Encendiendo la televisión de la marca " << marca << std::endl;
    }

    void apagar() {
        std::cout << "Apagando la televisión de la marca " << marca << std::endl;
    }

    void cambiarCanal(int nuevoCanal) {
        control.cambiarCanal(nuevoCanal);
    }

private:
    std::string marca;
    ControlRemoto control; // Control remoto como parte de la televisión
};

int main() {
    Television miTV("Sony", "RC-123");

    miTV.encender();
    miTV.cambiarCanal(5);
    miTV.apagar();

    return 0;
}
