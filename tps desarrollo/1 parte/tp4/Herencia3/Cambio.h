/*
 * Base.h
 *
 *  Created on: 7/11/2014
 *      Author: Graciela
 */

#ifndef CAMBIO_H_
#define CAMBIO_H_
#include <iostream>


namespace std {

class Cambio {
protected:
	float monto;  //Guarda el monto en Pesos Argentinos
public:
	Cambio(float m):monto(m){};

	float getMonto(){
		return monto;
	};

	void escribir(){
		cout << "Monto: $ " << monto<<endl;
	};
};

} /* namespace std */

#endif /* CAMBIO_H_ */
