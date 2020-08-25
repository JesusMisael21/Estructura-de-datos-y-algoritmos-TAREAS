En el main se incluye al archivo de las funciones que será el "Test", dichas funciones son para sumar los primeros n numeros consecutivos.

FUNCIONES:

#suma Iterativa

Análisis de complejidad temporal

El algoritmo recorre n pasos ya que usa un ciclo que va i = 1 hatsa n. Considerando el mejor de los casos en donde n sea 1 o 0, el algoritmo como mínimo es un paso o mejor dicho una complejidad constante Ω(1), para el peor de los casos es que el algoritmo realice una serie de pasos para sumar iterativamente, analisando los casos prueba vemos que cuando n se duplique el numero de pasos o iteraciones tambien duplicarán, al igual que cuando se triplique, por lo tanto la complejidad temporal asintótica es lineal O(n).

#suma Recursiva

Análisis de complejidad temporal

Al igual que en la complejidad temporal del iterativo, con la diferencia de que este algoritmo se manda a llamar así mismo n veces, su complejidad normal es lineal O(n), pero este análisis se queda muy justo y para el peor de los casos para este algoritmo, jerarquicamente el análisis temporal lo lleva a O(n*n).

Este es un análisis similar a la complejidad temporal del iterativo, con la diferencia de que este algoritmo se manda a llamar así mismo n veces. Vemos que en nuestro algoritmo tenemos dos casos base, cuando n sea menor igual a 0 (esto cuando el usuario manda un dato de este tipo) y cuando n sea igual a 1 (cuando el algoritmo al entrar en la funcion para una (n-1) detecte dicha transformacion), estos casos base tambien representan lo mejor de los casos que podemos tener, donde la complejidad temporal es constante Ω(1). De lo contrario tenemos al peor de los casos porque entraríamos a la recursividad donde la funcion se llame a sí misma n veces teniendo la complejidad temporal asintótica lienal O(n).

#suma Directa

Análisis de complejidad temporal

La complejidad temporal de este algoritmo es muy diferente ante los dos anteriores, este solo necesita pasar por una ves ante la funcion para obtener el resultado no importando el valor de n ya que el entero pasa por la formula de Gauss, por lo tanto, la complejidad temporal es constante O(1).
