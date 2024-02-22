#include <iostream>
#include <vector>

class Cama {
public:
    Cama(int numero) : numeroCama(numero) {
        // Constructor de Cama
    }

private:
    int numeroCama;
};

class Habitacion {
public:
    Habitacion(int numero) : numeroHabitacion(numero) {
        // Constructor de Habitacion
    }

    void agregarCama(int numero) {
        Camas.push_back(Cama(numero));
    }

private:
    int numeroHabitacion;
    std::vector<Cama> Camas;
};

class Hotel {
public:
    Hotel(std::string nombre) : nombreHotel(nombre) {
        // Constructor de Hotel
    }

    Habitacion* agregarHabitacion(int numero) {
        Habitaciones.push_back(Habitacion(numero));
        return &Habitaciones.back();
    }


private:
    std::string nombreHotel;
    std::vector<Habitacion> Habitaciones;
};

int main() {
    Hotel miHotel("Hotel Ejemplo");

    miHotel.agregarHabitacion(101)->agregarCama(1);
    miHotel.agregarHabitacion(101)->agregarCama(2);

    miHotel.agregarHabitacion(102)->agregarCama(1);
    miHotel.agregarHabitacion(102)->agregarCama(2);
    miHotel.agregarHabitacion(102)->agregarCama(3);

    return 0;
}

