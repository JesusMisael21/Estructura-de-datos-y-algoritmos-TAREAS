En el main se incluye al archivo de las funciones "splay.h", el main será el test, dichas funciones son para las operaciones en las que el usuario pueda manipular los objetos instanciados de heap.

Compilar como: g++ -Wno-deprecated main.cpp

# Escenario del Splay Tree

Un árbol de splay es un árbol de búsqueda binario con la propiedad adicional de que los elementos a los que se accedió recientemente son de acceso rápido nuevamente. Al igual que los árboles de búsqueda binaria autoequilibrados , un árbol de distribución realiza operaciones básicas como la inserción, búsqueda y eliminación en el tiempo amortizado O(log n).

Explicación y análisis de complejid temporal asintótica de cada algoritmo implementado:

# add (insert)

Para insertar un valor x en un árbol de distribución:
* Inserte x como con un árbol de búsqueda binario normal .
* cuando se inserta un elemento, se realiza una expansión.
* Como resultado, el nodo x recién insertado se convierte en la raíz del árbol.
Alternativamente:
* Utilice la operación de división para dividir el árbol en el valor de x en dos subárboles: S y T.
* Cree un nuevo árbol en el que x es la raíz, S es su subárbol izquierdo y T es su subárbol derecho.

Para todos los casos el elemento añadido se posiciona al final del árbol, después tiene que recorrer nivel por nivel hasta llegar a la raíz, para esto la cantidad de pasos ejecutados para lo anterior es logaritmico a comparación a la cantidad de elementos añadidos, así teniendo una complejidad temporal asintótica O(log n)


