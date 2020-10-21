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
#include "node.h"

template <class T> class SplayTree;


	
template<class T>
class SplayTree{
private:
	Node<T> *root;
	
public:
	SplayTree();
	~SplayTree();
	bool empty() const;
	void add(T);
	bool find(T);
	void remove(T);
	void removeAll();
	std::string inorder() const;
	std::string print_tree() const;
	std::string preorder() const;
};


template <class T>	
SplayTree<T>::SplayTree():root(0) {}


template<class T>
SplayTree<T>::~SplayTree() {
	removeAll();
}
	

template<class T>
bool SplayTree<T>::empty() const{
	return (root==0);
}


template<class T>
void SplayTree<T>::add(T val){
	
	if(root !=0){
		Node<T>* added= root->add(val);
		root=root->splay(root,added);
	}else{
		root=new Node<T>(val);
	}
}
	

template<class T>
void SplayTree<T>::remove(T val){
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


template<class T>
void SplayTree<T>::removeAll(){
	if(root !=0){
		root->removeChilds();
	}
	delete root;
	root=0;
}
	

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
