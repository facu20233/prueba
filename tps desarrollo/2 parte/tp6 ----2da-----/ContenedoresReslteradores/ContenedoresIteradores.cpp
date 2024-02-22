//============================================================================
// Name        : ContenedoresIteradores.cpp
// Author      : CW
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include <list> //Incluyo el contenedor list de la STL
#include <iterator> //Incluyo el iterador de la STL
#define MAX 10

using namespace std;


template<class T>
void escribirLista(const list<T>  &l);

int main() {

		list<int> l;

		int elementos[MAX]={1,2,3,4,5,6,7,8,9,10};

		cout <<"Tamaño inicial: "<<l.size()<<endl;

		if(l.empty())
			cout <<"La lista está vacia"<<endl;
		else
			cout <<"La lista NO está vacia"<<endl;

		cout<<endl;
		l.push_front(1);
		l.push_front(2);
		l.push_front(3);
		l.push_back(4);
		l.push_back(5);
		l.push_back(6);
		escribirLista(l);
		//Inserto al final de la lista los elementos del arreglo
		l.insert(l.end(), elementos, elementos+MAX);
		cout<<endl<<"Lista con elementos del arreglo: "<<endl;
		escribirLista(l);

		l.sort();
		cout<<endl<<"Lista Ordenada: "<<endl;
		escribirLista(l);

		l.unique();
		cout<<endl<<"Lista sin repeticiones: "<<endl;
		escribirLista(l);

		l.insert(l.begin(), elementos, elementos+3);
		cout<<endl<<"Lista despues de insertar 3 elementos: "<<endl;
		escribirLista(l);

		l.pop_front();
		l.pop_back();
		cout<<endl<<"Lista despues de borrar el principio y el final: "<<endl;
		escribirLista(l);

		l.remove(2);
		cout<<endl<<"Lista despues de eliminar el nro 2: "<<endl;
		escribirLista(l);

	return 0;
}

template<class T>
void escribirLista(const list<T>  &l)
{
		//Creo un iterador constante para recorrer la lista
		typename list<T>::const_iterator it;
		cout << "Lista: "<<endl;

		for(it=l.begin(); it!=l.end();it++ )
		{
			cout << *it<< " ";
		}
		cout << endl;
}


