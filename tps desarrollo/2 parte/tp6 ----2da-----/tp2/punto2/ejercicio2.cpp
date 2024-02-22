#include <iostream>

/*
class cuentaObjeto {
private:
    // atributos
    static int objCreados;  //estatico    
    static int objDestruidos; //estatico  
public:
    //metodo 
    cuentaObjeto() {
        objCreados++;
    }

    cuentaObjeto(const cuentaObjeto&) {
        objCreados++;
    }

    cuentaObjeto& metodo() {
        return *this;
    }

    static void mostrarResumen() {
        std::cout << "Objetos creados: " << objCreados << std::endl;
        std::cout << "Objetos destruidos: " << objDestruidos << std::endl;
    }

    ~cuentaObjeto() {
        objDestruidos++;
    }
};
*/ 

class pelicula {
private:
    // atributos
    static int autonumerico;  //estatico    
    int codigo; 
    std::string titulo;
    std::string director;
    bool estreno;
    float precioBase;
    std::string tipoPelicula; //{N, I}
public:
    //metodo 
    void listarInformacion(){
        std::cout << "autonum: " << autonumerico << std::endl;
        std::cout << "cod: " << codigo << std::endl;
        std::cout << "tit: " << titulo << std::endl;
        // ...
    }

    float calcularCosto(){
        float costo, precioBase;
        costo = precioBase;
        if (tipoPelicula == "I")
        {
            costo = costo*1.30;
        }else
        {
            if (estreno == 0)
            {
                costo = costo*0.8;
            }
        }
        return costo;
    }
};
