#include <iostream>
#include <vector>
using namespace std;
using namespace System;

// Lista Enlazada con Cabeza y Cola
class CCliente {
	//Atributos
private:

public:
	CCliente();
	~CCliente();
};

class CNodo {
private:
	//CCliente cliente;
	int dato;
	CNodo* siguiente;
	CNodo* anterior;
public:
	CNodo(int _dato) {
		dato = _dato;
		siguiente = anterior = nullptr; // las conexiones se haran al momento de insertar el nuevo nodo
	}
	~CNodo() {}
	// Comportamientos
	int getDato() { return dato; }
	void setDato(int _dato) { dato = _dato; }
	void setSiguiente(CNodo* _siguiente) { siguiente = _siguiente; }
	CNodo* getSiguiente() { return siguiente; }
	void setAnterior(CNodo* _anterior) { anterior = _anterior; }
	CNodo* getAnterior() { return anterior;}

};

class CListaDobleEnlazada
{
private:
	CNodo* cabeza;
	CNodo* ultimo;
public:
	CListaDobleEnlazada(){
		cabeza = nullptr;
		ultimo = nullptr;
	}
	~CListaDobleEnlazada(){}

	// COMPORTAMIENTOS
	// insertar al inicio
	void insertarInicio(int valor){
		CNodo* nuevo = new CNodo(valor);
		if (cabeza == nullptr) {	// Verificar si es que no hay elementos en la lista
			cabeza = nuevo;
			ultimo = nuevo;
		}
		else {
			// Insercion por delante
			nuevo->setSiguiente(cabeza);
			cabeza->setAnterior(nuevo);
			cabeza = nuevo;
		}
	}
	// insertar al final
	void insertarFinal(int valor) {
		CNodo* nuevo = new CNodo(valor);
		if (ultimo == nullptr) {	// Verificar si es que no hay elementos en la lista
			cabeza = nuevo;
			ultimo = nuevo;
		}
		else {
			// Insercion por delante
			ultimo->setSiguiente(nuevo);
			nuevo->setAnterior(ultimo);
			ultimo = nuevo;
		}
	}

	// Recorrer del primero al ultimo
	void mostrarDesdePrimero() {
		cout << "\nLista desde el primero :  " << endl;
		CNodo* actual = cabeza;

		cout << "nullptr" <<endl;
		while (actual != nullptr) {
			cout << actual->getDato() << " <--> " << endl;
			actual = actual->getSiguiente();
		}
		cout << "nullptr" << endl;
	}
	// Recorrer del ultimo al primero
	void mostrarDesdeUltimo() {
		cout << "\nLista desde el ultimo :  " << endl;
		CNodo* actual = ultimo;

		cout << "nullptr" << endl;
		while (actual != nullptr) {
			cout << actual->getDato() << " <--> " << endl;
			actual = actual->getAnterior();
		}
		cout << "nullptr" << endl;
	}
	// Buscar un valor
	bool buscar(int valor) {
		CNodo* actual = cabeza;
		while (actual != nullptr) {
			if (actual->getDato() == valor) {
				return true;
			}
			actual = actual->getSiguiente();
		}
		return false;
	}
	// Eliminar un valor (obviamente el nodo que contiene el valor)
	//Eliminar valor (obviamente el nodo que contiene el valor)
	void eliminar(int valor) {
		CNodo* actual = cabeza;
		while (actual != nullptr)
		{
			if (actual->getDato() == valor)
			{
				//significa que el nodo es el cabeza
				if (actual == cabeza)
				{
					cabeza = actual->getSiguiente();
					if (actual != nullptr)
					{
						cabeza->setAnterior(nullptr);
					}
					else {
						ultimo = nullptr;
					}
				}
				else if (actual == ultimo) //significa que el nodo es el ultimo
				{
					ultimo = actual->getAnterior();
					if (ultimo != nullptr)
					{
						ultimo->setSiguiente(nullptr);
					}
					else {
						cabeza = nullptr;
					}
				}
				else {
					//en el caso que el valor del nodo este en el medio
					actual->getAnterior()->setSiguiente(actual->getSiguiente());
					actual->getSiguiente()->setAnterior(actual->getAnterior());
				}
				delete actual;
				cout << "Nodo " << valor << " ha sido eliminado" << endl;
				return; //rompe la funcion
			}
			actual = actual->getSiguiente();
		}
		cout << "Dato " << valor << " NO ha sido encontrado" << endl;
	}

};




int main() {
	//cout << "\tListas Doblemente Enlazadas con Puntero al Inicio y al Final" << endl;
	//cout << "\tListas Simplemente Enlazadas con Puntero al Inicio" << endl;
	
	cout << "\tLista Enlazada con Cabeza y Cola" << endl;

	Random ra;

	CListaDobleEnlazada lista;
	lista.insertarFinal(1);
	lista.insertarFinal(ra.Next(10,50));
	lista.insertarFinal(ra.Next(10,50));
	lista.insertarFinal(ra.Next(10,50));
	lista.insertarFinal(70);
	lista.insertarFinal(ra.Next(10,50));
	lista.insertarFinal(100);

	lista.mostrarDesdePrimero();
	lista.mostrarDesdeUltimo();

	if (lista.buscar(10)) {
		cout << "Elemento encontrado! " << endl;
	}
	else {
		cout << "Elemento no encontrado! " << endl;
	}

	lista.mostrarDesdePrimero();
	cout << "\nEliminar Elemento" << endl;
	lista.eliminar(70);
	lista.mostrarDesdePrimero();




	system("pause>>null");
	return 0;
}