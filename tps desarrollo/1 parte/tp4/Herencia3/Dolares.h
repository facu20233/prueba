/*
 * Derivada.h
 *
 *  Created on: 7/11/2014
 *      Author: Graciela
 */

#ifndef DERIVADA_H_
#define DERIVADA_H_
#include <iostream>

#include "Cambio.h"

namespace std {

class Dolares: public Cambio {
	static float cotizacion;
public:
	Dolares(float m):Cambio(m*Dolares::cotizacion){};

	float getMonto(){
		return this->Cambio::getMonto() / Dolares::cotizacion;
	};
	void escribir(){
		this->Cambio::escribir();
		cout << "Monto: USD " << this->getMonto()<<endl;
	}

};

float Dolares::cotizacion = 125.18; //Cotizacion del dolar en la Bolsa Argentina

} /* namespace std */

#endif /* DERIVADA_H_ */


