#pragma once
template <typename T>
class Node {
	template <typename T>
	friend class BTree;
	friend void show(Node<T> *root) {
		if (root != 0) {
			show(root->left);
			cout << root->data << " ";
			show(root->right);
		}
	}

	friend void showTree(Node<T> *root, int lvl) {
		if (root) {
			showTree(root->left, lvl + 1);
			for (int i = 0; i< lvl; i++) cout << "   ";
			cout << root->data << endl;
			showTree(root->right, lvl + 1);
		}
	}

	friend Node<T>* newRootRotateLeft(Node<T>* root) {
		Node<T>* newRoot;
		newRoot = root->right;
		root->right = newRoot->left;
		newRoot->left = root;
		return newRoot;
	}

	friend Node<T>* newRootRotateRight(Node<T>* root) {
		Node<T>* newRoot;
		newRoot = root->left;
		root->left = newRoot->left;
		newRoot->right = root;
		return newRoot;
	}

public:
	T getData() {
		return data;
	}
	Node(const T &data) {
		this->data = data;
		left = right = nullptr;
	}
private:
	T data;
	Node *left, *right, *parent;
};