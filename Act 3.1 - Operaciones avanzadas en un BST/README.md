En el main se incluye al archivo de las funciones "dlist.h", el main será el test, dichas funciones son para las operaciones CRUD (Create, Read (buscar), Update, Delete) algoritmos para manipular una lista doblemente ligada.

Compilar como: g++ -Wno-deprecated main.cpp

Explicación y análisis de complejid temporal asintótica:

# visit

Este método lo manda a llamar el usuario y de manera conjunta llama a las siguientes (diferentes maneras de mostrar el contenido de un árbol):

## preorder

En este método de recorrido, primero se visita el nodo raíz, luego el subárbol izquierdo y finalmente el subárbol derecho. Esto de manera recursiva. Para el peor de los casos es que tenga que recorrer un árbol degenerado, por lo que su complejidad temporál asintótica es O(n).

## inorder

En este método de recorrido, primero se visita el subárbol izquierdo, luego la raíz y luego el subárbol derecho. Siempre debemos recordar que cada nodo puede representar un subárbol en sí mismo, la salida producirá valores clave ordenados en orden ascendente. Para el peor de los casos es que tenga que recorrer un árbol degenerado, por lo que su complejidad temporál asintótica es O(n).

## postorder

En este método transversal, el nodo raíz se visita en último lugar, de ahí el nombre. Primero atravesamos el subárbol izquierdo, luego el subárbol derecho y finalmente el nodo raíz. Para el peor de los casos es que tenga que recorrer un árbol degenerado, por lo que su complejidad temporál asintótica es O(n).

## level by level

Muestra los nodos en todos los niveles uno por uno comenzando desde la raíz y después con los subárboles de izquierda a derecha. Se usa un for para llamar n veces a una función que recorre los n elementos del árbol, por lo que su complejidad temporál asintótica es O(n^2).

# height

Regresa la profundida máxima del árbol en donde la raíz es 1. Toma el subárbol más profundo para regresar dicho nivel. Puede haber un caso en el que haya un árbol degenerado en el que los pasos de recorrido en la profundida sea igual a la cantidad de elementos, ante esto nos encontramos con una complejidad temporal asintótica O(n).

# ancestors

Desplegará los ancestros de un dato (todos los nodos arriba de n hasta llegar a la raiz). Permanece la abstracción que para el peor de los casos es cuando se tenga un árbol degenerado y tenga que pasar por los n elementos para llegar al dato, por eso su complejidad temporál asintótica es O(n).

# whatlevelamI

Regresará un entero que indica el nivel en que se encuentra un dato, o -1 en caso de que no se encuentre en el BST. Para cuando se tenga un árbol degenerado y se quiera buscar el elemento más profundo, los pasos de recorrido serán igual a la acantidad de elementos dentro del árbol, así teniendo una complejidad temporal asintótica O(n).
