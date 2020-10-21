/*
 * splay.h
 *
 *  Created on: 19/10/2020
 *      Author: Jesús Misael RC
 */




#ifndef SPLAY_H_
#define SPLAY_H_

#include <string>
#include <sstream>
#include "exception.h"
#include <iostream>
#include "node.h" // node se reusa de las estructuras anteriores

template <class T> class SplayTree;

// se crea la clase SplayTree
template<class T>
class SplayTree{
private:
	// atributos propios de la clase
	Node<T> *root;
	int cant;
	
public:
	// prototipo del constructor y del destructor
	SplayTree();
	~SplayTree();
	// prototipo de los metodos para manipular el arbol (para el usuario)
	bool empty() const;
	void add(T);
	bool find(T);
	void remove(T);
	void removeAll();
	int size();
	std::string inorder() const;
	std::string print_tree() const;
	std::string preorder() const;
};

// definicion del constructor
template <class T>	
SplayTree<T>::SplayTree():root(0), cant(0) {}

// definicion del destructor
template<class T>
SplayTree<T>::~SplayTree() {
	removeAll();
}
	
// definicion del metodo empty (retorna true si está limpia y false cuando esta vacia)
template<class T>
bool SplayTree<T>::empty() const{
	return (root==0);
}

// definicion del metodo add (añade un elemento y lo posiciona en la raiz con una funcion aux)
template<class T>
void SplayTree<T>::add(T val){
	cant++;
	if(root !=0){
		Node<T>* added= root->add(val);
		root=root->splay(root,added);
	}else{
		root=new Node<T>(val);
	}
}
	
// definicion del metodo remove (elimina val y reordena con splay)
template<class T>
void SplayTree<T>::remove(T val){
	cant--;
	if(root!=0){
		if(val==root->value){
			Node<T> *succ=root->succesor();
			if(succ !=0){
				succ->left = root->left;
				succ->right=root->right;
				succ->parent=0;
				if(succ->left)
					succ->left->parent=succ;
				if(succ->right)
					succ->right->parent=succ;
			}
			delete root;
			root=succ;
		}else {
			Node<T>*p = root->remove(val);
			if (p != 0)
				root=root->splay(root,p);
		}
	}
}

// definicion del metodo removeAll (elimina todo los elementos del arbol)
template<class T>
void SplayTree<T>::removeAll(){
	if(root !=0){
		root->removeChilds();
	}
	delete root;
	root=0;
}
	
// definicion del metodo find (true si lo encuentra y false si no, al final aplica splay)
template<class T>
bool SplayTree<T>::find(T val){
	if(root!=0){
		Node<T>* found=root->find(val);
		if (found == 0) return false;
		root=root->splay(root,found);
		return(root->value==val);
	}else{
		return false;
	}
}
// definicion del metodo size (retorna cantidad de elementos del arbol)
template<class T>
int SplayTree<T>::size(){
	return cant;
}

// definicion del metodo inorder (forma de recorrer y mostrar el arbol)
template<class T>
std::string SplayTree<T>::inorder() const{
	std::stringstream aux;
	
	aux<<"[";
	if(!empty()){
		root->inorder(aux);
	}
	aux<<"]";
	return aux.str();
}
	
// definicion del metodo print_tree (segunda forma de recorrer y mostrar el arbol)
template<class T>
std::string SplayTree<T>::print_tree() const{
	std::stringstream aux;
	
	aux<<"\n ====================== ";
	if(!empty()){
		root->print_tree(aux);
	}
	aux<<" ==================== \n";
	return aux.str();
}
	
// definicion del metodo preorder (tercera forma de recorrer y mostrar el arbol)	
template<class T>
std::string SplayTree<T>::preorder() const{
	std::stringstream aux;
	
	aux<<"[";
	if(!empty()){
		root->preorder(aux);
	}
	aux<<"]";
	return aux.str();
}	

#endif 