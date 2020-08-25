/*
 * funciones.h
 *
 *  Created on: 25/08/2020
 *      Author: MisaelResendiz
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <iostream>

// Clase Funciones 
class Funciones{
public:
	// Funcion que suma los n primeros numeros con iteracion
	long sumaIterativa(int n){
		long acum=0;
		for (int i=1;i<=n;i++){
			acum += i;
		}
		return acum;
	}
	// Funcion que suma los n primeros numeros con recursividad
	long sumaRecursiva(int n){
		if (n == 1) {return 1;}
		
		else if (n<=0){return 0;}
		
		else {return n + sumaRecursiva(n - 1);}
	}
	// Funcion que suma los n primeros numeros con formula de Gauss
	long sumaDirecta(int n){
		return n*(n+1)/2;
	}
};

#endif /* FUNCIONES_H_ */