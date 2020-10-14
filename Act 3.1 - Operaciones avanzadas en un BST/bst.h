/*
 * bst.h
 *
 *  Created on: 12/10/2020
 *      Author: Jesús Misael Reséndiz Cruz
 */

#ifndef BST_H_
#define BST_H_

#include <string>
#include <sstream>
#include <iostream>

template <class T> class BST;
// clase Node, nodos que tendrá mi arbol
template <class T>
class Node {
private:
	// atributos que definen a un nodo
	T value;
	Node *left, *right;

public:
	// prototipo de los constructores Node
	Node(T);
	Node(T, Node<T>*, Node<T>*);
	// prototipo de las funciones a las que puede acceder el usuario para manipular el arbol
	void printlevel(std::stringstream&, int) const;
	bool ancestors(T, std::stringstream&) const; 
	void add(T);
	bool find(T);
	int whatlevelamI(T);
	void remove(T);
	void removeChilds();
	void inorder(std::stringstream&) const;
	void preorder(std::stringstream&) const;
	void postorder(std::stringstream&) const;
	void levelorder(std::stringstream&) const;
	
	int height() const;

	friend class BST<T>;
};
// definición de los constructores para Node
template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0) {}
// se aplica sobrecarga dependiendo a la necesidad de instanciar
template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri)
	: value(val), left(le), right(ri) {}
// definición de la función add (permite añadir un elemento de tipo template al nodo)
template <class T>
void Node<T>::add(T val) {
	if (val < value) {
		if (left != 0) {
			left->add(val);
		} else {
			left = new Node<T>(val);
		}
	} else {
		if (right != 0) {
			right->add(val);
		} else {
			right = new Node<T>(val);
		}
	}
}
// definición de la función find (devuelve valor boleano dependiendo si encuentra o no el elemento buscado) 
template <class T>
bool Node<T>::find(T val) {
	if (val == value) {
		return true;
	} else if (val < value) {
		return (left != 0 && left->find(val));
	} else if (val > value) {
		return (right != 0 && right->find(val));
	}
	return false;
}
// definición de la función whatlevelamI (devuelve el nivel de profundidad en el que se encuentra val)
template <class T>
int Node<T>::whatlevelamI(T val) {
	if (val == value) {
		return 1;
	} else if (val < value) {
		if(left != 0)
			return left->whatlevelamI(val) + 1;
	} else if (val > value) {
		if (right != 0)
		return right->whatlevelamI(val) + 1;
	}
	return -9999;
}

// definición de la función ancestors (devuelve todos los nodos arribas de val hasta llegar a la raiz)
template <class T>
bool Node<T>::ancestors(T val, std::stringstream &aux) const{

	if (val == value) {
	  return true;
	} else if (val < value) {
		if (aux.tellp() != 1) {
			aux << " ";
		}
		aux << value;
		return (left != 0 && left->ancestors(val,aux));
	} else if (val > value) {
		if (aux.tellp() != 1) {
			aux << " ";
		}
		aux << value;
		return (right != 0 && right->ancestors(val,aux));
	}
	return false;
}
// definición de la función remove (busca el elemento introducido y lo borra)
template <class T>
void Node<T>::remove(T val) {
	Node<T> * succ, *old;

	if (val < value) {
		if (left != 0) {
			if (left->value == val) {
				old = left;
				succ = left->succesor();
				if (succ != 0) {
					succ->left = old->left;
					succ->right = old->right;
				}
				left = succ;
				delete old;
			} else {
				left->remove(val);
			}
		}
	} else if (val > value) {
		if (right != 0) {
			if (right->value == val) {
				old = right;
				succ = right->succesor();
				if (succ != 0) {
					succ->left = old->left;
					succ->right = old->right;
				}
				right = succ;
				delete old;
			} else {
				right->remove(val);
			}
		}
	}
}
// definición de la función removeChilds (borra los elementos a los que apunta)
template <class T>
void Node<T>::removeChilds() {
	if (left != 0) {
		left->removeChilds();
		delete left;
		left = 0;
	}
	if (right != 0) {
		right->removeChilds();
		delete right;
		right = 0;
	}
}
// definición de la función inorder (primera forma de mostrar el ordenamiento)
template <class T>
void Node<T>::inorder(std::stringstream &aux) const {
	if (left != 0) {
		left->inorder(aux);
	}
	if (aux.tellp() != 1) {
		aux << " ";
	}
	aux << value;
	if (right != 0) {
		right->inorder(aux);
	}
}
// definición de la función preorder (segunda forma de mostrar el ordenamiento)
template <class T>
void Node<T>::preorder(std::stringstream &aux) const {
	aux << value;
	if (left != 0) {
		aux << " ";
		left->preorder(aux);
	}
	if (right != 0) {
		aux << " ";
		right->preorder(aux);
	}
}
// definición de la función postorder (tercera forma de mostrar el ordenamiento)
template <class T>
void Node<T>::postorder(std::stringstream &aux) const {
	if (left != 0) {
		left->postorder(aux);
	}

	if (right != 0) {
		right->postorder(aux);
	}
	if (aux.tellp() != 1) {
			aux << " ";
	}
	aux << value;
}
// definición de la función printlevel (auxiliar para levelorder)
template <class T>
void Node<T>::printlevel(std::stringstream &aux, int level) const {

	if(level == 0){
		if (aux.tellp() != 1) {
				aux << " ";
		}
		aux << value;
	}
	if (left != 0) {
		left->printlevel(aux, level -1);
	}
	if (right != 0) {
		right->printlevel(aux, level -1);
	}

}
// definición de la función levelorder (cuarta forma de mostrar el ordenamiento)
template <class T>
void Node<T>::levelorder(std::stringstream &aux) const {
	int level = height();
	for(int i = 0; i < level; i++){
			printlevel(aux, i);
	}
}
// definición de la función height (indicará la altura del BST)
template <class T>
int Node<T>::height() const {

	int level_left = 0;
	int level_right = 0;

	if (left != 0) {
		level_left = left->height() + 1;
	}
	if (right != 0) {
		level_right= right->height() +1;
	}
	if (level_left == 0 && level_right == 0)
		return 1;

	return (level_right > level_left) ? level_right : level_left;
}
// creacion de la clase BST (contendrá una serie de nodos para crear el arbol)
template <class T>
class BST {
private:
	Node<T> *root;

public:
	// prototipo de los contructores y destructores
	BST();
	~BST();
	// prototipo de las funciones que puede usar el usuario para manipular el árbol
	bool empty() const;
	void add(T);
	bool find(T) const;
	int  whatlevelamI(T) const;
	void remove(T);
	void removeAll();
	std::string inorder() const;
	std::string preorder() const;
	std::string postorder() const;
	std::string levelorder() const;
	std::string visit();
	std::string ancestors(T) const;
	int height() const;
};
// definición del constructor 
template <class T>
BST<T>::BST() : root(0) {}
// definición del destructor
template <class T>
BST<T>::~BST() {
	removeAll();
}
// definición de la función empty (usada para saber si está limplio el árbol)
template <class T>
bool BST<T>::empty() const {
	return (root == 0);
}
// definición de la función add (añade nodos de elementos tipo T)
template<class T>
void BST<T>::add(T val) {
	if (root != 0) {
		if (!root->find(val)) {
			root->add(val);
		}
	} else {
		root = new Node<T>(val);
	}
}
// definición de la función remove (busca el elemento val y lo borra)
template <class T>
void BST<T>::remove(T val) {
	if (root != 0) {
		if (val == root->value) {
			Node<T> *succ = root->succesor();
			if (succ != 0) {
				succ->left = root->left;
				succ->right = root->right;
			}
			delete root;
			root = succ;
		} else {
			root->remove(val);
		}
	}
}
// definición de la función removeAll (elimina todo lo que contenga el árbol)
template <class T>
void BST<T>::removeAll() {
	if (root != 0) {
		root->removeChilds();
	}
	delete root;
	root = 0;
}
// definición de la función find (busca el elemento introducido)
template <class T>
bool BST<T>::find(T val) const {
	if (root != 0) {
		return root->find(val);
	}
	else {
		return false;
	}
}
// definición de la función whatlevelamI (indica el nivel en que se encuentra un dato, o -1 en caso de que no se encuentre)
template <class T>
int BST<T>::whatlevelamI(T val) const {
	if (root != 0) {
	 	int num = root->whatlevelamI(val);
		if(num < 0) return -1;
		return num;
	}
	else {
		return -1;
	}
}
// definición de la función inorder (primera forma de mostrar el ordenamiento)
template <class T>
std::string BST<T>::inorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->inorder(aux);
	}
	aux << "]";
	return aux.str();
}
// definición de la función preorder (segunda forma de mostrar el ordenamiento)
template <class T>
std::string BST<T>::preorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->preorder(aux);
	}
	aux << "]";
	return aux.str();
}
// definición de la función postorder (tercera forma de mostrar el ordenamiento)
template <class T>
std::string BST<T>::postorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->postorder(aux);
	}
	aux << "]";
	return aux.str();
}
// definición de la función levelorder (cuarta forma de mostrar el ordenamiento)
template <class T>
std::string BST<T>::levelorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->levelorder(aux);
	}
	aux << "]";
	return aux.str();
}
// definición de la función height (devuelve la cantidad de nivel de profundidad del árbol)
template <class T>
int BST<T>::height() const {
	return root->height();
}

// definición de la función ancestors (devuelve todos los nodos arriba de val hasta llegar a la raiz)
template <class T>
std::string BST<T>::ancestors(T val) const {
	std::stringstream aux;
	aux << "[";
	if (!empty()) {
		if(!root->ancestors(val, aux))
			return "[]";
	}
	aux << "]";
	return aux.str();
}
// definición de la función visit (conjunta las cuatro formas de muestreo en un solo return)
template <class T>
std::string BST<T>::visit() {
	std::stringstream aux;
	aux << preorder() << "\n";
	aux << inorder() << "\n";
	aux << postorder() << "\n";
	aux << levelorder();
	return aux.str();
}


#endif /* BST_H_ */
