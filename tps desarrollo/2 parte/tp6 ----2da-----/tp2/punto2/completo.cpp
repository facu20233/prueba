#include <iostream>
#include <string>

class pelicula {
private:
    // atrib
    static int autonumerico;
    int codigo;
    std::string titulo;
    std::string director;
    bool estreno;
    float precioBase;
    std::string tipoPelicula;

public:
    // Constructor defecto
    //clase pelicula
    pelicula(){
        codigo = autonumerico++; //código 000
        titulo = "Sin título";
        director = "Sin director";
        estreno = false;
        precioBase = 0.0;
        tipoPelicula = "N";
    }

    // Constructor parámetros
    pelicula(int codigo, std::string titulo, std::string director, bool estreno, float precioBase, std::string tipoPelicula)
        : codigo(codigo), titulo(titulo), director(director), estreno(estreno), precioBase(precioBase), tipoPelicula(tipoPelicula) {
        autonumerico++;
    }

    // Constructor copia
    pelicula(const pelicula& otraPelicula) {
        codigo = autonumerico++;
        titulo = otraPelicula.titulo;
        director = otraPelicula.director;
        estreno = otraPelicula.estreno;
        precioBase = otraPelicula.precioBase;
        tipoPelicula = otraPelicula.tipoPelicula;
    }

    // metodo
    void listarInformacion() {
        std::cout << "Código: " << codigo << std::endl;
        std::cout << "Título: " << titulo << std::endl;
        std::cout << "Director: " << director << std::endl;
        std::cout << "Estreno: " << (estreno ? "Sí" : "No") << std::endl;
        std::cout << "Precio Base: " << precioBase << std::endl;
        std::cout << "Tipo Película: " << tipoPelicula << std::endl;
    }

    // metodo
    float calcularCosto() {
        float costo = precioBase;
        if (tipoPelicula == "I") {
            costo *= 1.30;
        } else if (!estreno) {
            costo *= 0.8;
        }
        return costo;
    }
};

// Inicialización atributo autonumerico
int pelicula::autonumerico = 1;

int main() {

    pelicula pelicula1;  // Constructor defecto
    pelicula1.listarInformacion();
    std::cout << "Costo: " << pelicula1.calcularCosto() << std::endl;

    pelicula pelicula2(100, "Matrix", "Wachowski", true, 10.0, "I");  // Constructor parámetros
    pelicula2.listarInformacion();
    std::cout << "Costo: " << pelicula2.calcularCosto() << std::endl;

    pelicula pelicula3 = pelicula2;  // Constructor copia
    pelicula3.listarInformacion();
    std::cout << "Costo: " << pelicula3.calcularCosto() << std::endl;
    return 0;
}