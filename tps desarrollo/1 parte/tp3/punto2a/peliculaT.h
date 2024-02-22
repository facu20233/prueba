// // pelicula.h
// #include <iostream>
// #include <string>
// #include "persona.h"

// class Pelicula {
// private:
//     static int autonumerico;
//     int codigo;
//     std::string titulo;
//     Persona director; // Cambiar el tipo de director a Persona
//     bool estreno;
//     float precioBase;
//     std::string tipoPelicula;

// public:
//     // Constructor defecto
//     Pelicula() {
//         codigo = autonumerico++;
//         titulo = "Sin título";
//         director = Persona("Sin director", "Sin biografía", 0); // Crear una Persona por defecto
//         estreno = false;
//         precioBase = 0.0;
//         tipoPelicula = "N";
//     }

//     // Cons parám
//     Pelicula(int codigo, std::string titulo, Persona director, bool estreno, float precioBase, std::string tipoPelicula)
//         : codigo(codigo), titulo(titulo), director(director), estreno(estreno), precioBase(precioBase), tipoPelicula(tipoPelicula) {
//         autonumerico++;
//     }

//     // Constrcopia
//     Pelicula(const Pelicula& otraPelicula) {
//         codigo = autonumerico++;
//         titulo = otraPelicula.titulo;
//         director = otraPelicula.director;
//         estreno = otraPelicula.estreno;
//         precioBase = otraPelicula.precioBase;
//         tipoPelicula = otraPelicula.tipoPelicula;
//     }

//     // Método para obtener la biografía del director incluyendo su edad
//     std::string getBiografiaDirector() {
//         return director.GetNombre() + ": " + director.GetBiografia() + " (Edad: " + std::to_string(director.GetEdad()) + ")";
//     }

//     // Resto de métodos (listarInformacion, calcularCosto) no cambian
// };