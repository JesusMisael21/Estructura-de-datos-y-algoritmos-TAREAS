/*
 * heap.h
 *
 *  Created on: 20/10/2015
 *      Author: clase
 */

#ifndef HEAP_H_
#define HEAP_H_

#include <string>
#include <sstream>
#include "exception.h"
#include <iostream>

// creamos la clase Heap
template <class T>
class Heap {
private:
	// atributos y metodos auxiliares que no debe acceder el usuario
	T *data;
	unsigned int tam;
	unsigned int parent(unsigned int) const;
	unsigned int left(unsigned int) const;
	unsigned int right(unsigned int) const;
	void heapify(unsigned int);
	void swap(unsigned int, unsigned int);
public:
	// constructor y destructor
	Heap(unsigned int) throw (OutOfMemory);
	~Heap();
	// atributo y metodos que el usuario puede usar para manipular el heap
	bool empty() const;
	bool full() const;
	void push(T) throw (Overflow);
	T pop() throw (NoSuchElement);
	void clear();
	std::string toString() const;
	int size();
	T top() const;
	
	unsigned int siz;
};
// definicion del constructor
template <class T>
Heap<T>::Heap(unsigned int sze) throw (OutOfMemory) {
	tam = sze;
	data = new T[tam];
	if (data == 0) {
		throw OutOfMemory();
	}
	siz = 0;
}
// definicion del destructor
template <class T>
Heap<T>::~Heap() {
	delete [] data; data = 0;
	tam = 0; siz = 0;
}
// definicion del metodo size (regresa el tamaño de elementos almacenados)
template <class T>
int Heap<T>::size() {
	return siz;
}
// definicion del metodo empty (boleano, esta vacia o no está vacia)
template <class T>
bool Heap<T>::empty() const {
	return (siz == 0);
}
// definicion del metodo full (boleano, esta llena o no esta llena)
template <class T>
bool Heap<T>::full() const {
	return (siz == tam);
}
// definicion del metodo parent (auxiliar para push)
template <class T>
unsigned int Heap<T>::parent(unsigned int pos) const {
	return (pos - 1) / 2;
}
// definicion del metodo left (retorna el hijo izquierdo del argumento)
template <class T>
unsigned int Heap<T>::left(unsigned int pos) const {
	return ((2 * pos) + 1);
}
// definicion del metodo right (retorna el hijo derecho del argumento)
template <class T>
unsigned int Heap<T>::right(unsigned int pos) const {
	return ((2 * pos) + 2);
}
// definicion del metodo swap (auxiliar para heapify)
template <class T>
void Heap<T>::swap(unsigned int i, unsigned int j) {
	T aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}
// definicion del metodo heapify (ordena por elementos con mayor prioridad)
template <class T>
void Heap<T>::heapify(unsigned int pos) {
	unsigned int le = left(pos);
	unsigned int ri = right(pos);
	unsigned int min = pos;
	if (le <= siz && data[le] < data[min]) {
		min = le;
	}
	if (ri <= siz && data[ri] < data[min]) {
		min = ri;
	}
	if (min != pos) {
		swap(pos, min);
		heapify(min);
	}
}
// definicion del metodo push (añade otro elemento al heap)
template <class T>
void Heap<T>::push(T val) throw (Overflow) {
	unsigned int pos;
	if (full()) {
		throw Overflow();
	}

	pos = siz;
	siz++;
	while (pos > 0 && val < data[parent(pos)]) {
		data[pos] = data[parent(pos)];
		pos = parent(pos);
	}
	data[pos] = val;
}
// definicion del metodo pop (saca o elimina del heap al elemento priorisado)
template <class T>
T Heap<T>::pop() throw (NoSuchElement) {
	if (empty()) {
		throw NoSuchElement();
	}
	T aux = data[0];

	data[0] = data[--siz];
	heapify(0);
	return aux;
}
// definicion del metodo siz (referenciamos al heap sin elementos)
template <class T>
void Heap<T>::clear() {
	siz = 0;
}
// definicion del metodo top (retorna al elemento priorisado)
template <class T>
T Heap<T>::top() const {
	return data[0];
}
// definicion del metodo toString (retorna al heap en forma de cadena)
template <class T>
std::string Heap<T>::toString() const {
	std::stringstream aux;
	aux << "[";	for (unsigned int i = 0; i < siz; i++) {
		if (i != 0) {
			aux << " ";
		} aux << data[i];
	} aux << "]";
	return aux.str();
}

#endif /* HASH_H_ */
	