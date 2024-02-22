//============================================================================
// Name        : Composicion.cpp
// Author      : CW
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Persona.h"

using namespace std;

int main() {

	int dia, mes, anio;
	Persona P("Juan", "Perez", 123456, 22, 10,1990);
	cout <<P<<endl;

	//Cambio el valor en TE
	//creando un nuevo O Fecha
	P.setFechaNacimiento(22,10,1990);
	cout <<P<<endl;
	return 0;
}
