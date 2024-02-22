#include <iostream>
#include <string>
#include <ctime>

class pelicula {
private:
    static int autonumerico;
    int codigo;
    std::string titulo;
    std::string director;
    std::string fechaEstreno; // Cambio: fecha de estreno en formato AAAA-MM-DD
    float precioBase;
    std::string tipoPelicula;

public:
    pelicula() {
        codigo = autonumerico++;
        titulo = "Sin título";
        director = "Sin director";
        fechaEstreno = "0000-00-00"; // Cambio: fecha de estreno inicial
        precioBase = 0.0;
        tipoPelicula = "N";
    }

    pelicula(int codigo, std::string titulo, std::string director, std::string fechaEstreno, float precioBase, std::string tipoPelicula)
        : codigo(codigo), titulo(titulo), director(director), fechaEstreno(fechaEstreno), precioBase(precioBase), tipoPelicula(tipoPelicula) {
        autonumerico++;
    }

    pelicula(const pelicula& otraPelicula) {
        codigo = autonumerico++;
        titulo = otraPelicula.titulo;
        director = otraPelicula.director;
        fechaEstreno = otraPelicula.fechaEstreno;
        precioBase = otraPelicula.precioBase;
        tipoPelicula = otraPelicula.tipoPelicula;
    }

    void listarInformacion() {
        std::cout << "Código: " << codigo << std::endl;
        std::cout << "Título: " << titulo << std::endl;
        std::cout << "Director: " << director << std::endl;
        std::cout << "Fecha de Estreno: " << fechaEstreno << std::endl;
        std::cout << "Es Estreno: " << (esEstreno() ? "Sí" : "No") << std::endl;
        std::cout << "Precio Base: " << precioBase << std::endl;
        std::cout << "Tipo Película: " << tipoPelicula << std::endl;
    }

    float calcularCosto() {
        float costo = precioBase;
        if (tipoPelicula == "I") {
            costo *= 1.30;
        } else if (!esEstreno()) {
            costo *= 0.8;
        }
        return costo;
    }

    bool esEstreno() {
        // Obtener la fecha actual
        std::time_t t = std::time(nullptr);
        std::tm* now = std::localtime(&t);
        int currentYear = now->tm_year + 1900;

        // Extraer el año de la fecha de estreno
        int estrenoYear = std::stoi(fechaEstreno.substr(0, 4));

        // Determinar si pasaron menos de 5 años desde el estreno
        return (currentYear - estrenoYear) < 5;
    }
};

int pelicula::autonumerico = 1;

int main() {
    pelicula pelicula1;
    pelicula1.listarInformacion();
    std::cout << "Costo: " << pelicula1.calcularCosto() << std::endl;

    pelicula pelicula2(100, "Matrix", "Wachowski", "1999-03-31", 10.0, "I");
    pelicula2.listarInformacion();
    std::cout << "Costo: " << pelicula2.calcularCosto() << std::endl;

    pelicula pelicula3 = pelicula2;
    pelicula3.listarInformacion();
    std::cout << "Costo: " << pelicula3.calcularCosto() << std::endl;

    return 0;
}
