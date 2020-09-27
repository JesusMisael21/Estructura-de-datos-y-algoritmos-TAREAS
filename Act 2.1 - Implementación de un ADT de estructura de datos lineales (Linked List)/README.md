En el main se incluye al archivo de las funciones "list.h", el main será el test, dichas funciones son para las operaciones CRUD (Create, Read (buscar), Update, Delete) elementos en la estructura de datos.

En caso de tener windows compilar como: g++ -Wno-deprecated main.cpp

Explicación y análisis de complejid temporal asintótica:

# add

Este es una función o en este caso como se trabaja con orientada a objetos, es un método que como algoritmo se encarga de añadir elementos a una lista al final del último elemento. Para encontrar su complejidad temporal asintótica debamos identificar n, para este caso hay dos opciones para tomar n, primeramente la tomaremos como la cantidad de elementos ya insertados con la que cuenta la lista, por lo tanto, al ingresar otro elemento este tiene que recorrer elemento por elemento hasta llegar al elemento nulo, es decir, al principio de la lista por lo que tenemos una complejidad temporal asintótica O(n). Ahora, si n es la cantidad de elementos que debemos insertar en una lista, como cada elemento insertado tiene que pasar por cada uno de los que se insertaron este tiende a ser mayor a una complejidad lineal para el peor de los casos, y siguiendo la jerarquía nos demanda a una complejidad asintótica de O(n^2).

# find

Este método recibe un tipo de elemento de acuerdo al tipo de lista y regresa la posición en donde se encuentra ese elemento. Para este elemento se implementa un algoritmo de busqueda secuencial, es decir, para buscar un elemento se tiene que pasar por cada elemento uno por uno emezando con la cabeza, por lo tanto el peor de los casos es cuando el elemento se encuentra al final de la lista, teniendo una complejidad temporal asintótica O(n).

# update

Para este método se necesita un argumento de dos elementos, recibe la posición a actualizr y el elemento por el cual se va a remplazar. El algoritmo que cuenta es parecido al de find (busqueda secuencial), tiene que pasar por cada una de las posiciones empezando desde la posición 0 hasta llegar a la posición deseada. Entonces, para el peor de los casos es cuando se quiera actualizar el elemento final de la lista, así teniendo una complejidad temporal asintótica O(n).

# remove

En este metodo se recibe la posición del elemento a eliminar haciendo la lista más chica en -1 cada ves que se utilice (siempre y cuando la cantidad de elementos de la lista sea diferente de cero). Para eliminar la posición deseada se tiene que pasar por cada una de las anteriores, entonces para el peor de los casos es que se quisiera eliminar el elemento final de la lista, así teniendo la complejidad temporal asintótica O(n).
