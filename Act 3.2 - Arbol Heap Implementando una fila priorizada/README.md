En el main se incluye al archivo de las funciones "heap.h", el main será el test, dichas funciones son para las operaciones en las que el usuario pueda manipular los objetos instanciados de heap.

Compilar como: g++ -Wno-deprecated main.cpp

# ¿Qué es el heap (fila priorizada)?

Es un ADT (tipo de datos abstracto) que generaliza tanto la cola como la pila.  Una cola de prioridades un elemento con mayor prioridad será desencolado antes que un elemento de menor prioridad. Si dos elementos tienen la misma prioridad, se desencolarán siguiendo el orden de cola.

Explicación y análisis de complejid temporal asintótica de cada algoritmo implementado:

# push

Este algoritmo agrega un dato a la fila, para el mejor de los casos es que el dato introducido sea el menor o del grupo que tiene menor prioridad, ante eso tenemos Ω(1) ya que no tiene que ordenar, pero para el peor de los casos es que este sea el dato con mayor prioridad así reordenando para escalarlo hasta la raíz, por lo que pasa de nivel en nivel hasta llegar a dicho puesto, ante esto se tiene O(log(n)).

# pop

Este algoritmo saca de la fila el dato que tiene mayor prioridad "el que está en la raíz" (haciendo referencia a un árbol). Entonces, siguiendo la funcionalidad de este, al sacar al elemento priorizado, el algoritmo toma al último elemento de la fila (menos priorizado) y lo pone como el de mayor prioridad, esto anterior se hace para todos los casos Ω(2), pero a partir de ahí se decide la complejidad asintótica (empieza el reordenamiento), ya que para el peor de los casos es que este valor sea depositado en la última posición de la fila (último nivel si lo vemos en forma de árbol) teniendo así una complejidad temporal asintótica O(log(n)).
