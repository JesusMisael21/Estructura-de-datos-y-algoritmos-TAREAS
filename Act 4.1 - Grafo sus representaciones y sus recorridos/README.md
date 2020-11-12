En el main se incluye el archivo de las funciones "graph.h", el main será el test, dichas funciones son para las operaciones en las que el usuario pueda manipular los objetos instanciados de graph.

Compilar desde la terminal: g++ main.cpp

# Escenario del Splay Tree

Representación gráfica formada por nodos o vértices que muestra a los actores y aristas que sirven para representar los lazos o relaciones entre los actores. En esta implementación se usarán metodos para recorrerlo en dos distintas formas.

Explicación y análisis de asintótica temporal compleja de cada algoritmo implementado:

# loadGraphMat

Esta función carga las arístas y los almacena en una adyacencia
matriz. Recibe el nombre del archivo y 2 enteros.
El nuevo valor de los nodos es el número de vértices.
Su complejidad: O (n) Lineal. n -> número de líneas. Porque
depende del número de nodos a almacenar.

# loadGraphList

Esta función carga las arístas y los almacena en una lista de adyacencia.
Recibe el nombre del archivo y 2 enteros.
El nuevo valor de los nodos es el número de vértices.
Su omplejidad: O (n) Lineal. n -> número de líneas. Porque 
el número de ejecuciones es igual al número de conexiónes.

# DFS (Deep First Search)

Es un algoritmo de búsqueda no informada utilizado para recorrer todos los nodos de un grafo o árbol (teoría de grafos) de manera ordenada, pero no uniforme. Su funcionamiento consiste en ir expandiendo todos y cada uno de los nodos que va localizando, de forma recurrente, en un camino concreto. Cuando ya no quedan más nodos que visitar en dicho camino, regresa (Backtracking), de modo que repite el mismo proceso con cada uno de los hermanos del nodo ya procesado. Esta visita cada vértice una vez y comprueba todas las arístas del gráfico una vez. Por lo tanto, la complejidad de DFS es O (V + E) siendo V los vertices y E las arístas.

# BFS (Breadth First Search)

Es un algoritmo de búsqueda no informada utilizado para recorrer o buscar elementos en un grafo (usado frecuentemente sobre árboles). Intuitivamente, se comienza en la raíz (eligiendo algún nodo como elemento raíz en el caso de un grafo) y se exploran todos los vecinos de este nodo. A continuación para cada uno de los vecinos se exploran sus respectivos vecinos adyacentes, y así hasta que se recorra todo el árbol. La primera búsqueda tiene un tiempo de ejecución de O (V + E), siendo V los vertices y E las arístas,  ya que cada vértice y cada arista se comprobará una vez.
