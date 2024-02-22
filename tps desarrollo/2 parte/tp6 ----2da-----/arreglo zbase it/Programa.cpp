#include <iostream>

class Iterador {
private:
    int* ptr;

public:
    Iterador(int* p) : ptr(p) {}

    // Operador de pre-incremento
    Iterador& operator++() {
        ++ptr;
        return *this;
    }

    // Operador de post-incremento
    Iterador operator++(int) {
        Iterador temp = *this;
        ++(*this);
        return temp;
    }

    // Operador de indirección
    int& operator*() const {
        return *ptr;
    }

    // Operador de igualdad
    bool operator==(const Iterador& otro) const {
        return ptr == otro.ptr;
    }

    // Operador de desigualdad
    bool operator!=(const Iterador& otro) const {
        return !(*this == otro);
    }
};

int main() {
    int arreglo[] = {1, 2, 3, 4, 5};

    Iterador inicio(arreglo);
    Iterador fin(arreglo + 5); // Apunta al final del arreglo

    // Iterar sobre el arreglo usando el iterador
    for (Iterador it = inicio; it != fin; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
