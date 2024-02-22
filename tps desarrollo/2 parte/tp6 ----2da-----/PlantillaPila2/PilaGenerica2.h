/*
 * Pila.h
 *
 *  Created on: 20/11/2014
 *      Author: Graciela
 */

#ifndef PILAGENERICA2_H_
#define PILAGENERICA2_H_
using namespace std;

template <class X, int dim=10>
class Pila{
	int tope;
	X arreglo[dim];
	int MAX;
public:
	Pila();
	Pila(const Pila<X,dim> &);

	bool push(X);
	bool pop();
	X top();
	bool esPilavacia();
	void escribir();

	~Pila();
};

template <class X, int dim>
Pila<X,dim>::Pila()
{
	tope=-1;
	MAX=dim;
	cout << endl<<" PILA GENERICA 2 : " << endl;


}

template <class X, int dim>
Pila<X,dim>::	Pila(const Pila<X,dim> &p)
{
	tope=p.tope;
	MAX=p.MAX;
	for(int i=0; i<tope;i++ )
	{
		arreglo[i]=p.arreglo[i];
	}
}

template <class X, int dim>
bool Pila<X,dim>::push(X item){
	bool resultado=  false;
	if(tope+1 <MAX){
		tope++;
		arreglo[tope] = item;
		resultado =true;
	}
	return resultado;
}

template <class X, int dim>
bool Pila<X,dim>:: pop(){
	bool resultado=false;
	if(tope>=0){
		tope--;
		resultado = true;
	}
	return resultado;
}

template <class X, int dim>
X Pila<X,dim>:: top(){
	if(!esPilavacia())
		return arreglo[tope];
	else
		return 0;
}
template <class X, int dim>
bool Pila<X,dim>:: esPilavacia(){
	return tope==-1;
}

template <class X, int dim>
void Pila<X,dim>::escribir(){
	cout << endl<<" PILA GENERICA: " << endl;
	cout << endl<<" PILA : " << endl;
	for(int i=tope; i>=0;i-- )
	{
		cout << arreglo[i]<<endl;
	}
}

template <class X, int dim>
Pila<X,dim>::~Pila()
{
}

#endif /* PILA_H_ */


