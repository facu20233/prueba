// persona.h
#ifndef PERSONA_H // en que caso usa encab error de redef
#define PERSONA_H //
#include <iostream>
#include <string>

class Persona {
private:
    std::string nombre;
    std::string biografia;
    int edad;

public:
    // constr def, 
    Persona(){
        // inic
        nombre = "agregar";
        biografia = "agregar";
        edad = 0;
    }

    // Constructor param inic datos
    Persona(const std::string& nombre, const std::string& biografia, int edad) 
        : nombre(nombre), biografia(biografia), edad(edad) {}

    // obt nom
    std::string GetNombre() const {
        return nombre;
    }

    // obt bio
    std::string GetBiografia() const {
        return biografia;
    }

    // obt edad
    int GetEdad() const {
        return edad;
    }

};

#endif // PERSONA_H