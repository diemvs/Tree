// BTree.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "Tree.h"
#include <iostream>


using namespace std;

template <typename T>
void rotate(BTree<T> tree) {
	int operation;
	cout << "1. Rotate left\n" << "2. Rotate right\n" << endl;
	cin >> operation;
	switch (operation) {
	case 1:
		tree.rotateLeft();
		break;
	case 2:
		tree.rotateRight();
		break;
	}
}


template <typename T>
void start(BTree<T> tree) {
	int operation, data;
	cout << "Choose the operation : \n" << "1. Add node\n" << "2. Find max\n" << "3. Find min\n" << "4. Delete node\n" << "5. Print\n" << "6. Print tree\n" << "7. Rotate\n"<< endl;
	cin >> operation;
	cout << endl;
	switch (operation) {
	case 1:
		cout << "Enter the element :\n";
		cin >> data;
		tree.add(data);
		cout << endl;
		break;
	case 2:
		cout << "Max is :";
		tree.findMax(tree.getRoot());
		cout << endl;
		break;
	case 3:
		cout << "Min is :";
		tree.findMin(tree.getRoot());
		cout << endl;
		break;
	case 4:

		cout << endl;
		break;
	case 5:
		tree.print();
		cout << endl;
		break;
	case 6:
		tree.printTree();
		cout << endl;
		break;
	case 7:
		rotate(tree);
		cout << endl;
		break;
	}
	start(tree);
}

int main()
{
	/*BTree<int> a;
	
	
	
	a.add(7);
	a.add(8);
	a.add(5);
	a.add(6);
	a.add(9);
	a.add(10);
	a.add(4);
	a.add(3);

	cout << "Tree = ";
	a.print();
	cout << endl;

	cout << "Max is :"<< a.findMax(a.getRoot()) << endl;
	cout << "Min is :" << a.findMin(a.getRoot()) << endl;

	cout << "Print tree :" << endl;

	a.printTree();
	cout << endl;

	a.rotateRight();
	a.printTree();

	a.rotateLeft();
	a.printTree();
	cout << endl;
	
	

	cout << endl;*/

	BTree<int> tree;
	//start(tree);
	tree.add(5);
	tree.add(3);
	tree.add(4);
	tree.add(10);
	tree.add(7);
	tree.add(2);
	tree.add(12);
	tree.add(8);
	
	cout << "NODES :";

	tree.print(); 
	cout << "\n========TREE PRINT=========" << endl;
	tree.printTree();

	

	cout << "========ROTATE LEFT=========" << endl;

	tree.rotateLeft();
	tree.printTree();

	cout << "========ROTATE LEFT=========" << endl;

	tree.rotateLeft();
	tree.printTree();
	cout << "========ROTATE RIGHT=========" << endl;
	tree.rotateRight();
	tree.print();
	tree.printTree();


	system("pause");
    return 0;
	
}