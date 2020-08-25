En el main se incluye al archivo de las funciones que será el "Test", dichas funciones son para sumar los primeros n numeros consecutivos.

FUNCIONES:

#suma Iterativa

Análisis de complejidad temporal

El algoritmo recorre n pasos ya que usa un ciclo que va i = 1 hatsa n por lo que se le denominaría lineal O(n), sin embargo esta complejidad lineal es justa y para el peor de los casos su complejidad (dependiendo la entrada valor de n) es O(n*n).

#suma Recursiva

Análisis de complejidad temporal

Al igual que en la complejidad temporal del iterativo, con la diferencia de que este algoritmo se manda a llamar así mismo n veces, su complejidad normal es lineal O(n), pero este análisis se queda muy justo y para el peor de los casos para este algoritmo, jerarquicamente el análisis temporal lo lleva a O(n*n).

#suma Directa

Análisis de complejidad temporal

La complejidad temporal de este algoritmo es muy diferente ante los dos anteriores, este solo necesita pasar por una ves ante la funcion para obtener el resultado no importando el valor de n ya que el entero pasa por la formula de Gauss, por lo tanto, la complejidad temporal es constante O(1).
