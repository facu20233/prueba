  #include <iostream>

class CuentaObjeto {
private:
    // atributos
    static int objCreados;  //estatico    
    static int objDestruidos; //estatico  
public:
    //metodo 
    // clase
    CuentaObjeto() {
        objCreados++;
    }

    CuentaObjeto(const CuentaObjeto&) {
        objCreados++;
    }

    CuentaObjeto& metodo() {
        return *this;
    }

    static void mostrarResumen() {
        std::cout << "Objetos creados: " << objCreados << std::endl;
        std::cout << "Objetos destruidos: " << objDestruidos << std::endl;
    }

    // destr
    ~CuentaObjeto() {
        objDestruidos++;
    }
};