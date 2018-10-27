
#include "binarytree.h"
#include <algorithm>
#include <iostream>

binarytree::binarytree()
{
	_size = tree.size();
}

binarytree::~binarytree()
{
	//dtor
}
int binarytree::lleaf(int pos_parent) {
	return (2 * pos_parent) + 1;
}

int binarytree::rleaf(int pos_parent) {
	return (2 * pos_parent) + 2;
}
int binarytree::parent(int pos_leaf) {
	return (pos_leaf - 1) / 2;

}
void binarytree::down(int x) {
	//temporal que guarda la posicion
	int temp;
	//Revisa si el nodo solo tiene una hoja
	if (rleaf(x) <= _size) {
		//Compara las hojas y elije el mayor
		if (tree[lleaf(x)] > tree[rleaf(x)]) {
			//Si el padre es mayor se intercambian
			if (tree[x] < tree[lleaf(x)]) {
				//guarda la posicion de la hoja
				temp = lleaf(x);
				//intercambia la hoja por el nodo
				std::swap(tree[x], tree[lleaf(x)]);
				//llama a la funcion con la nueva posicion del nodo
				down(tree[temp]);
			}
			else return;
		}
		if (tree[lleaf(x)] < tree[rleaf(x)]) {
			if (tree[x] < tree[rleaf(x)]) {
				temp = rleaf(x);
				std::swap(tree[x], tree[rleaf(x)]);
				down(tree[temp]);
			}
			else return;
		}	
	}
	else {
		if (tree[x] < tree[lleaf(x)]) {
			//guarda la posicion de la hoja
			temp = lleaf(x);
			//intercambia la hoja por el nodo
			std::swap(tree[x], tree[lleaf(x)]);
			//llama a la funcion con la nueva posicion del nodo
			return;
		}
		else return; 
	}
}
void binarytree::up(int x) {
	int temp;
	if (tree[x] > tree[parent(x)]) {
		temp = tree[parent(x)];
		std::swap(tree[x], tree[parent(x)]);
		up(tree[temp]);
		return;
	}
	else return;
}
void binarytree::push(int x) {
	tree.push_back(x);
	up(tree.size() - 1);
}
void binarytree::_delete(int x) {
	if (_size = 0)
		return;
	std::swap(tree[0], tree[_size - 1]);
	tree.resize(_size - 1);
	_size -= 1;
	down(0);
	
	return;
}