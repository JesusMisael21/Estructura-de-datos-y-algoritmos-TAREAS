En el main se incluye al archivo de las funciones "dlist.h", el main será el test, dichas funciones son para las operaciones CRUD (Create, Read (buscar), Update, Delete) elementos en la estructura de datos.

En caso de tener windows compilar como: g++ -Wno-deprecated main.cpp

Explicación y análisis de complejid temporal asintótica:

# add

Este es una función o en este caso como se trabaja con orientado a objetos, es un método que como algoritmo se encarga de añadir elementos a una lista al final del último elemento. Para encontrar su complejidad temporal asintótica debamos identificar n, para este caso hay dos opciones para tomar n, primeramente la tomaremos como la cantidad de elementos ya insertados con la que cuenta la lista, por lo tanto, al ingresar otro elemento este tiene que recorrer elemento por elemento hasta llegar al elemento nulo, es decir, al principio de la lista por lo que tenemos una complejidad temporal asintótica O(n). Ahora, si n es la cantidad de elementos que debemos insertar en una lista, como cada elemento insertado tiene que pasar por cada uno de los que ya se insertaron, este tiende a ser mayor a una complejidad lineal para el peor de los casos, y siguiendo la jerarquía nos demanda a una complejidad asintótica de O(n^2).

# find

Este método recibe un tipo de elemento de acuerdo al tipo de lista y regresa la posición en donde se encuentra ese elemento. Para este elemento se implementa un algoritmo de busqueda secuencial, es decir, para buscar un elemento se tiene que pasar por cada elemento uno por uno empezando con la cabeza, por lo tanto el peor de los casos es cuando el elemento se encuentra al final de la lista, teniendo una complejidad temporal asintótica O(n).

# update

Para este método se necesita un argumento de dos elementos, recibe la posición a actualizar y el elemento que se va a insertar en dicha posición. El algoritmo que cuenta es parecido al de find (busqueda secuencial), tiene que pasar por cada una de las posiciones empezando desde la posición 0 hasta llegar a la posición deseada. Entonces, para el peor de los casos es cuando se quiera actualizar el elemento final de la lista, así teniendo una complejidad temporal asintótica O(n).

# remove

En este metodo se recibe la posición del elemento a eliminar haciendo la lista más chica en 1 cada ves que se utilice (siempre y cuando la cantidad de elementos de la lista sea diferente de cero). Para eliminar la posición deseada se tiene que pasar por cada una de las anteriores, entonces para el peor de los casos es que se quisiera eliminar el elemento final de la lista, así teniendo la complejidad temporal asintótica O(n). Tengamos en cuenta que tenemos una k sumandose a la temporalidad, esta representa la cantidad de pasos en la que redirecciona los enlaces de los nodos, sin embargo esta no se cuenta en nuestra complejidad , por lo que se descarta.

Adicional se incluyen dos metodos mas que se usan para leer y convertir los elementos de una lista en una cadena, esto para que el main (test) pueda comparar resultados.

# toStringForward

Como se menciona anteriormente, este es un algoritmo que convierte el valor de cada nodo en un caracter y lo añade en una cadena de caracteres. Trabaja de forma secuencial, lee elemento por elemento empezando por la cabeza y termina el proceso con la lectura de la cola. Como el proceso es secuencial en donde la cantidad de pasos es igual a la cantidad de elementos (n), se deduce que tiene una complejidad temporal asintótica O(n).

# toStringBackward

Este método es parecido al anterior, la abastracción es la misma, trabaja de forma secuencial, con la diferencia de que lee elemento por elemento empezando por la cola y termina el proceso con la lectura de la cabeza. Como el proceso es secuencial en donde la cantidad de pasos es igual a la cantidad de elementos (n), se deduce que tiene una complejidad temporal asintótica O(n).

Estos dos últimos algoritmos se mandan a llamar uno seguido del otro, que es donde el main hace la prueba para asegurarse que realmente la lista esté doblemente ligada, por lo que si las unimos, siguiendo la jerarquía de complejidades, la complejidad temporal asintótica demanda O(n^2).
