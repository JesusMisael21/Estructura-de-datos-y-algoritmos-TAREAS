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

Para todos los casos el elemento añadido se posiciona al final del árbol, después tiene que recorrer nivel por nivel hasta llegar a la raíz, para esto la cantidad de pasos ejecutados para lo anterior es logaritmico a comparación a la cantidad de elementos añadidos, así teniendo una complejidad temporal asintótica O(log n).

# remove (delete)

Para eliminar un nodo x , use el mismo método que con un árbol de búsqueda binaria:
* Si x tiene dos hijos:
* Cambie su valor con el del nodo más a la derecha de su subárbol izquierdo (su predecesor en orden) o el nodo más a la izquierda de su subárbol derecho (su sucesor en orden).
* En su lugar, elimine ese nodo.

De esta forma, la eliminación se reduce al problema de eliminar un nodo con 0 o 1 hijos. A diferencia de un árbol de búsqueda binaria, en un árbol de distribución después de la eliminación, colocamos el padre del nodo eliminado en la parte superior del árbol.
* El nodo que se va a eliminar se muestra primero, es decir, se lleva a la raíz del árbol y luego se elimina. deja el árbol con dos subárboles.
* Los dos subárboles se unen luego mediante una operación de "unión".

Para el peor de los casos es que se quiera eliminar el elemento que tenga mayor profundidad en el árbol, entonces para eliminar tiene que recorrer todos los niveles que están arriba de él, así comporandolo con la cantidad de datos tenemos tiempos logarítmicos, una temporalidad O(log n) para este escenario.

# find

Este algoritmo es idéntico al árbol binario, busca recursivamente el elemento solicitado. En este escenario es posible tener un árbol degenerado y este junto a la situación de que se queira encontrar al elemento con mayor profundidad hacen el peor de los casos, tendrá que navegar el algoritmo por cada uno de los elementos, así teniendo una complejidad temporal asintótica O(n).

# inorder

En este método de recorrido para mostrar los elementos en pantalla, primero se visita el subárbol izquierdo, luego la raíz y luego el subárbol derecho. Siempre debemos recordar que cada nodo puede representar un subárbol en sí mismo, la salida producirá valores clave ordenados en orden ascendente. Para el peor de los casos es que tenga que recorrer un árbol degenerado, por lo que su complejidad temporál asintótica es O(n).

# size

Regresa la cantidad de datos que tiene el árbol. Este manda a llamar a un atributo propio del árbol en el que incrementa cuando se añade un elemento y decrementa cuando se borra alguno de ellos. Entonces, para todos los casos se tiene una complejidad lineal, O(1) expresado asintóticamente.
