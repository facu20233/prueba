//============================================================================
// Name        : Herencia3.cpp
// Author      : CW
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Cambio.h"
#include "Dolares.h"

int main() {

	Cambio cambio(120);
	cambio.escribir();
	cout << endl;

	Dolares dolares(120);
	dolares.escribir();

	return 0;
}
