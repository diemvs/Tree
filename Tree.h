#pragma once
#include "Node.h"
template <typename T>
class BTree {
	
public:
	BTree();
	void add(const T &);
	void print();
	void printTree();
	void rotateLeft();
	void rotateRight();
	T findMax(Node<T> *);
	T findMin(Node<T> *);
	Node<T>* getRoot();
private:
	Node<T> *root;
};


template <typename T>
BTree<T>::BTree(){
	root = nullptr;
}

template <typename T>
void BTree<T>::add(const T &x) {
	Node<T>* treeNode = new Node<T>(x);
	Node<T>* ptr1;
	Node<T>* ptr2 = nullptr;

	treeNode->parent = treeNode->left = treeNode->right = nullptr;
	ptr1 = root;
	while (ptr1 != 0) {
		ptr2 = ptr1;
		if (x < ptr1->getData()) {
			ptr1 = ptr1->left;
		}
		else {
			ptr1 = ptr1->right;
		}
	}
	treeNode->parent = ptr2;
	if (ptr2 == 0) {
		root = treeNode;
	}
	else {
		if (x < ptr2->getData()) {
			ptr2->left = treeNode;
		}
		else {
			ptr2->right = treeNode;
		}
	}
}

template <typename T>
void BTree<T>::print() {
	show(root);
}

template <typename T>
Node<T>* BTree<T>::getRoot() {
	return root;
}

template <typename T>
T BTree<T>::findMax(Node<T> *node) {
	while (node->right != 0)
		node = node->right;
	return node->data;
}

template <typename T>
T BTree<T>::findMin(Node<T> *node){
	while (node->left != 0)
		node = node->left;
	return node->data;
}

template <typename T>
void BTree<T>::printTree() {
	int lvl = 0;
	showTree(root, lvl);
}

template <typename T>
void BTree<T>::rotateLeft() {
	root = newRootRotateLeft(root);
}

template <typename T>
void BTree<T>::rotateRight() {
	root = newRootRotateRight(root);
}