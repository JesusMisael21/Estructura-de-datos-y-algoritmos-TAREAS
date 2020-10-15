En el main se incluye al archivo de las funciones "dlist.h", el main será el test, dichas funciones son para las operaciones CRUD (Create, Read (buscar), Update, Delete) algoritmos para manipular una lista doblemente ligada.

Compilar como: g++ -Wno-deprecated main.cpp

Explicación y análisis de complejid temporal asintótica:

# visit

Este método lo manda a llamar el usuario y de manera conjunta llama a las siguientes (diferentes maneras de mostrar el contenido de un árbol):

## preorder

En este método de recorrido, primero se visita el nodo raíz, luego el subárbol izquierdo y finalmente el subárbol derecho. Esto de manera recursiva. Para el peor de los casos es que tenga que recorrer un árbol degenerado, por lo que su complejidad temporál asintótica es O(n).

## inorder

En este método de recorrido, primero se visita el subárbol izquierdo, luego la raíz y luego el subárbol derecho. Siempre debemos recordar que cada nodo puede representar un subárbol en sí mismo, la salida producirá valores clave ordenados en orden ascendente. Para el peor de los casos es que tenga que recorrer un árbol degenerado, por lo que su complejidad temporál asintótica es O(n).

