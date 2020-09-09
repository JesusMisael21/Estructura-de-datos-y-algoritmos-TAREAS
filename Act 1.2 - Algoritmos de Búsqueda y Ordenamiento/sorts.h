/*
 * sorts.h
 *
 *  Created on: 07/09/2020
 *      Author: Jesus Misael R.C.
 */

#ifndef SORTS_H_
#define SORTS_H_

#include <vector>
#include <list>

template <class T>
class Sorts {
private:
	// Metodos privados son auxiliares o de ayuda para los publicos
	void swap(std::vector<T>&, int, int);
	void mergeSplit(std::vector<T>&, std::vector<T>&, int, int);
	void mergeArray(std::vector<T>&, std::vector<T>&, int, int, int);
	void copyArray(std::vector<T>&, std::vector<T>&, int, int);
	int bs_aux(const std::vector<T>&source,int low,int high,int val);
	
public:
	// Metodos de ordenamiento o busqueda llamados por el main (usuario)
	void ordenaSeleccion(std::vector<T>&);
	void ordenaBurbuja(std::vector<T>&);
	void ordenaMerge(std::vector<T>&);
	int busqSecuencial(const std::vector<T>&,int); 
	int busqBinaria(const std::vector<T>&source,int val);
};
// Declaración del swap
template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}
// Declaración del metodo ordenaSeleccion
template <class T>
void Sorts<T>::ordenaSeleccion(std::vector<T> &source) {
	int pos;

	for (int i = source.size() - 1; i > 0; i--) {
		pos = 0;
		for (int j = 1; j <= i; j++) {
			if (source[j] > source[pos]) {
				pos = j;
			}
		}

		if (pos != i) {
			swap(source, i, pos);
		}
	}
}
// Declaración del metodo ordenaBurbuja
template <class T>
void Sorts<T>::ordenaBurbuja(std::vector<T> &source) {

	for (int i = source.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (source[j] > source[j + 1]) {
				swap(source, j, j + 1);
			}
		}
	}
}
// Declaración del metodo mergeSplit (partir la lista en 2 partes)
template <class T>
void Sorts<T>::mergeSplit(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	int mid;

	if ( (high - low) < 1 ) {
		return;
	}
	mid = (high + low) / 2;
	mergeSplit(A, B, low, mid);
	mergeSplit(A, B, mid + 1, high);
	mergeArray(A, B, low, mid, high);
	copyArray(A, B, low, high);
}
// Declaración del metodo copyArray (mezlar las subdiviciones)
template <class T>
void Sorts<T>::copyArray(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
}
// Declaración del metodo mergeArray (ordenar recursivamente ambas partes)
template <class T>
void Sorts<T>::mergeArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) {
	int i, j, k;

	i = low;
	j = mid + 1;
	k = low;

	while (i <= mid &&j <= high) {
		if (A[i] < A[j]) {
			B[k] = A[i];
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (; j <= high; j++) {
			B[k++] = A[j];
		}
	} else {
		for (; i <= mid; i++) {
			B[k++] = A[i];
		}
	}
}
// Declaración del metodo ordenaMerge
template <class T>
void Sorts<T>::ordenaMerge(std::vector<T> &source) {
	std::vector<T> tmp(source.size());

	mergeSplit(source, tmp, 0, source.size() - 1);
}
// Declaración del metodo busqSecuencial
template <class T>
int Sorts<T>::busqSecuencial(const std::vector<T>&source,int val){
	for (int i = 0; i < source.size(); i++) {
		if (val == source[i]) {
			return i;
		}
	}
	return (-1);
}
// Declaración del metodo bs_aux (contenido del binario)
template <class T>
int Sorts<T>::bs_aux(const std::vector<T>&source,int low,int high,int val) { // o(log(n))
	int mid;

	if (low <= high) {
		mid = (high + low) / 2;
		if (val == source[mid]) {
			return mid;
		} else if (val < source[mid]) {
			return bs_aux(source, low, mid - 1, val);
		} else if (val > source[mid]) {
			return bs_aux(source, mid + 1, high, val);
		}
	}
	return low;
}
// Declaración del metodo busqBinaria
template <class T>
int Sorts<T>::busqBinaria(const std::vector<T>&source,int val) {
	return bs_aux(source, 0,source.size() - 1, val);
}

#endif /* SORTS_H_ */