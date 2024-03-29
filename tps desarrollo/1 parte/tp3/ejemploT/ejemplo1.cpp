#include <iostream>
#include <string>
#include <vector>

class Curso {
public:
    Curso(const std::string& nombre) : nombre(nombre) {}

    std::string getNombre() const {
        return nombre;
    }

private:
    std::string nombre;
};

class Departamento {
public:
    Departamento(const std::string& nombre) : nombre(nombre) {}

    void agregarCurso(Curso* curso) {
        cursos.push_back(curso);
    }

    void mostrarCursos() const {
        std::cout << "Cursos en el departamento de " << nombre << ":\n";
        for (const Curso* curso : cursos) {
            std::cout << curso->getNombre() << "\n";
        }
    }

private:
    std::string nombre;
    std::vector<Curso*> cursos;
};

int main() {
    Curso* curso1 = new Curso("Matemáticas");
    Curso* curso2 = new Curso("Física");
    Curso* curso3 = new Curso("Programación");

    Departamento departamento("Ciencias");

    departamento.agregarCurso(curso1);
    departamento.agregarCurso(curso2);
    departamento.agregarCurso(curso3);

    departamento.mostrarCursos();

    // Liberar la memoria de los cursos
    delete curso1;
    delete curso2;
    delete curso3;

    return 0;
}