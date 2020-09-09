En el main se incluye al archivo de las funciones "sorts.h", el main será el test, dichas funciones son para ordenamiento o busqueda.

FUNCIONES:

# ordenaSeleccion

En resumen este algoritmo consiste en encontrar el menor de todos los elementos del arreglo o vector e intercambiarlo con el que está en la primera posición. Luego el segundo mas pequeño, y así sucesivamente hasta ordenarlo todo. Por eso tiene una complejidad de tiempo O(n^2), lo que lo hace ineficaz en listas grandes y, en general, funciona peor que el tipo de inserción similar . El ordenamiento por selección se le amerita por su simplicidad y tiene ventajas de rendimiento sobre algoritmos más complicados en ciertas situaciones, particularmente cuando la memoria auxiliar es limitada. Para este caso se usó para ordenar números de forma ascendente.

# ordenaBurbuja

Este es un algoritmo de los más simples, recorre la lista repetidamente, compara elementos adyacentes y los intercambia si están en el orden incorrecto. El paso a través de la lista se repite hasta que se ordena la lista. Analizando su funcionamiento vemos que para el peor de los casos es que el arreglo esté ordenado de manera contraria a la que el algoritmo ordena, de tal manera que recorrería todo el arreglo por cada elemento, es por eso que su complejidad temporal asintótica es O(n^2). Directamente en el programa se hace de manera secuencial con dos ciclos (for) añidados.

# ordenaMerge

A diferencia con los dos anteriores, este se opera con recursividad y por ende su complejidad espacial ya no es constante porque aumentará memoria. La idea general en su operación de este algoritmo es la de dividir el problema en subproblemas más pequeños. En el programa ya implementado tenemos un caso base que es una lista vacía o de un elemento ya ordenado, tenemos tres funciones auxiliare donde la primera parte la lista en 2 partes, la segunda ordena recursivamente ambas partes y al último la tercera que mezcla ambas divisiones. Si vieramos el comportamiento de este algoritmo en diagráma de árbol vemos puros subarreglos que se sividen en 2, es decir n/2 en el primer nivel, despues n/4 en el segundo, n/8 en el tercero y así sucesivament. Entonces tenemos que temporalmente hasta aquí es log de 2 de n [O(log2 n)], después el paso de combinar mezcla un total de n elementos y se tarda un tiempo O(n), es por eso que multiplicando las complejidades tenemos un O(nlog2(n)).
