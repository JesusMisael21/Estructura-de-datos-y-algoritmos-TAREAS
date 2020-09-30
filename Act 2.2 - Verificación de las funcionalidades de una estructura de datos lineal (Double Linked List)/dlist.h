/*
 * list.h
 *  Created on: 26/09/2020
 *      Author: Jesús Misael Reséndiz Cruz
 */

#ifndef DLIST_H_
#define DLIST_H_

#include <string>
#include <sstream>
#include <iostream>
#include "exception.h"

template <class T> class DList;
template <class T> class DListIterator;

// Clase DLink, me permite crear los nodos
template <class T>
class DLink {
private:
	DLink(T);
	DLink(T, DLink<T>*, DLink<T>*);
	DLink(const DLink<T>&);

	T	    value;
	DLink<T> *previous;
	DLink<T> *next;

	friend class DList<T>;
	friend class DListIterator<T>;
};

template <class T>
DLink<T>::DLink(T val) : value(val), previous(0), next(0) {}

template <class T>
DLink<T>::DLink(T val, DLink *prev, DLink* nxt) : value(val), previous(prev), next(nxt) {}

template <class T>
DLink<T>::DLink(const DLink<T> &source) : value(source.value), previous(source.previous), next(source.next) {}

//Clase DList, en ella se crearán la serie de nodos
template <class T>
class DList {
public:
	//Prototipo de los constructores, es sobrecarga
	DList();
	DList(const DList<T>&) throw (OutOfMemory);
	~DList();
	// Prototipo de los metodos/funciones para manipular la lista
	void add(T) throw (OutOfMemory);
	int find(T) const;
	bool update(int, T) throw (IndexOutOfBounds);
	void    remove(int) throw (IndexOutOfBounds);
	bool empty() const;
	void clear();
	std::string toStringForward() const;
	std::string toStringBackward() const;
	void operator= (const DList&) throw (OutOfMemory);

	void addBefore(DListIterator<T>&, T) throw (IllegalAction, OutOfMemory);
	void addAfter(DListIterator<T>&, T) throw (IllegalAction, OutOfMemory);
	
	// Variables que no me interesan que el usuario vea (auxiliares)
private:
	DLink<T> *head;
	DLink<T> *tail;
	int 	 size;

	friend class DListIterator<T>;
};

// Definición de los constructores
template <class T>
DList<T>::DList() : head(0), tail(0), size(0) {}
// Sobrecarga, dependiendo de la creación de una lista o nodos
template <class T>
DList<T>::~DList() {
	clear();
}

// Definición del add (añade elemento a la ultima posicion de la lista)
template <class T>
void DList<T>::add(T val) throw (OutOfMemory) {
	DLink<T> *newLink;

	newLink = new DLink<T>(val);
	if (newLink == 0) {
		throw OutOfMemory();
	}

	if (empty()) {
		head = newLink;
		tail = newLink;
	} else {
		tail->next = newLink;
		newLink->previous = tail;
		tail = newLink;
	}
	size++;
}

// Definición del find (busca un elemento de acuerdo a su valor recibido y retorna la posicion)
template <class T>
int DList<T>::find(T val) const {
	DLink<T> *p;

	p = head;
	int i=0;
	while (p != 0) {
		if (p->value == val) {
			return i;
		}
		p = p->next;
		i++;
	}
	return -1;
}

// Definición de update (actualiza la posicion deseada con el valor introducido)
template <class T>
bool DList<T>::update(int index, T val) throw (IndexOutOfBounds) {
	int pos;
	DLink<T> *p;
	if (index<0 || index>=size){
		throw IndexOutOfBounds();
	}

	p=head;
	pos=0;
	while (pos!=index){
		p=p->next;
		pos++;
	}
	p->value=val;
	return true;
}

// Definición de remove (elinina el nodo en la posición deseada)
template <class T>
void DList<T>::remove(int index) throw (IndexOutOfBounds) {
	DLink<T> *p;
  p = head;
  int pos = 0;
  if(index == 0){
    head = p->next;
    p->next->previous = 0;
    delete p;
    size --;
    return;
  }

  while (pos != index){
    p = p->next;
    pos++;
  }
  p->previous->next = p->next;
  p->next->previous = p->previous;
  delete p;
  size--;
}

// Definición de empy (para saber si hay elementos en la lista)
template <class T>
bool DList<T>::empty() const {
	return (head == 0 && tail == 0);
}

// Definición de clear (elimina todos los nodos de la lista)
template <class T>
void DList<T>::clear() {
	DLink<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	tail = 0;
	size = 0;
}

// Definición de toStringForward (se usa para leer la lista en forma de array de atras hacia adelante)
template <class T>
std::string DList<T>::toStringForward() const {
	std::stringstream aux;
	DLink<T> *p;

	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

// Definición de toStringBackward (se usa para leer la lista en forma de array de adelante hacia atras )
template <class T>
std::string DList<T>::toStringBackward() const {
		std::stringstream aux;
		DLink<T> *p;
		
		p = tail;
		aux << "[";
		while (p != 0) {
			aux << p->value;
			if (p->previous != 0) {
				aux << ", ";
			}
			p = p->previous;
		}
		aux << "]";
		return aux.str();
	}

#endif /* DLIST_H_ */