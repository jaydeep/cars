//
//  binary_search_tree.h
//  cis22c_lab5_js
//
//  Created by Jaydeep Singh on 11/21/17.
//  Copyright © 2017 DeAnza. All rights reserved.
//

#ifndef binary_search_tree_h
#define binary_search_tree_h
#include "node.h"
#include <fstream>

template <typename Data> class BinarySearchTree
{
private:
	MyNode<Data> *root;
	MyNode<Data>* findMinNode(MyNode<Data>*);

public:
	BinarySearchTree();
	~BinarySearchTree();
	void deleteTree(MyNode<Data>*);
	MyNode<Data>* getRoot();
	void setRoot(MyNode<Data>*);
	void add(MyNode<Data>*, Data);
	bool edit(MyNode<Data>*, Data, Data);
	MyNode<Data>* remove(MyNode<Data>*, Data);
	MyNode<Data>* search(MyNode<Data>*, Data);
	void printBreadthFirst(std::ofstream &, MyNode<Data>*);
	void printBreadthFirstStdOut(MyNode<Data>*);
	void printDepthFirst(std::ofstream &, MyNode<Data>*);
	void printDepthFirstStdOut(MyNode<Data>*);
};

//Default Constructor
template <typename Data> BinarySearchTree<Data>::BinarySearchTree()
{
	root = NULL;
}

//Destructor
template <typename Data> BinarySearchTree<Data>::~BinarySearchTree()
{
	if (root == NULL) {
		delete this;
	}
	else {
		deleteTree(root);
		delete root;
	}
}

template <typename Data> void BinarySearchTree<Data>::deleteTree(MyNode<Data>* node)
{
	if (node == NULL) {
	}
	else {
		deleteTree(node->getLeft());
		deleteTree(node->getRight());
		delete node;
	}
}
//returns the root
template <typename Data> MyNode<Data>* BinarySearchTree<Data>::getRoot()
{
	return root;
}

//********* setRoot(MyNode<Data>*)
// sets the root pointer of the BST
// param - newRoot - new value of root
template <typename Data> void BinarySearchTree<Data>::setRoot(MyNode<Data>* newRoot)
{
	root = newRoot;
}

//********** add(MyNode<Data>*, Data)
// params - node - node to walk to add Data to to
//			newData - new data to be added to tree
// adds a node to the tree
template <typename Data> void BinarySearchTree<Data>::add(MyNode<Data>* node, Data newData)
{
	if (node == NULL) {
		node = new MyNode<Data>(newData);
		root = node;
	}
	else {
		if (node->getValue() > newData) {
			if (node->getLeft() == NULL) {
				node->setLeft(new MyNode<Data>(newData));
			}
			else {
				this->add(node->getLeft(), newData);
			}
		}
		else {
			if (node->getRight() == NULL) {
				node->setRight(new MyNode<Data>(newData));
			}
			else {
				this->add(node->getRight(), newData);
			}
		}
	}
}

//*********** edit(MyNode<Data>*, Data, Data)
// params - node - node to walk to find node to edit
//			oldData - old value of data to edit
//			newData - new value of data
// finds node with value of oldData and then replaces it with value of newData
template <typename Data> bool BinarySearchTree<Data>::edit(MyNode<Data>* node, Data oldData, Data newData)
{
	if (node == NULL) {
		return false;
	}
	else {
		if (node->getValue() == oldData) {
			node->setValue(newData);
			return true;
		}
		else if (node->getValue() < oldData) {
			edit(node->getRight(), oldData, newData);
		}
		else {
			edit(node->getLeft(), oldData, newData);

		}
	}
}

//********* findMinNode(MyNode<Data>*)
// params - node - node to walk to find min node in tree
// finds the minimum node of the tree
template <class Data> MyNode<Data>* BinarySearchTree<Data>::findMinNode(MyNode<Data>* node)
{
	while (node->getLeft() != NULL)
		node = node->getLeft();
	return node;
}

//********** remove(MyNode<Data>*, Data)
// params - node - node to walk to find node to delete
// finds ValueToDelete and then removes that node from the tree
template <typename Data> MyNode<Data>* BinarySearchTree<Data>::remove(MyNode<Data>* node, Data valueToDelete)
{
	if (node == NULL)
		return node;
	if (valueToDelete < node->getValue())
	{
		node->setLeft(remove(node->getLeft(), valueToDelete));
	}
	else if (valueToDelete > node->getValue())
	{
		node->setRight(remove(node->getRight(), valueToDelete));
	}
	else
	{
		// rootNode->getValue() == value
		if (node->getLeft() == NULL && node->getRight() == NULL)
		{
			delete node;
			node = NULL;
		}
		else if (node->getLeft() == NULL)
		{
			MyNode<Data> *tempNode = new MyNode<Data>(node->getValue());
			node = node->getRight();
			delete tempNode;
		}
		else if (node->getRight() == NULL) {
			MyNode<Data> *tempNode = new MyNode<Data>(node->getValue());
			node = node->getLeft();
			delete tempNode;
		}
		else {
			// call min node function to get the minimum node
			MyNode<Data> *minNode = new MyNode<Data>(findMinNode(node->getRight())->getValue());
			node->setValue(minNode->getValue());
			node->setRight(remove(node->getRight(), node->getValue()));
			delete minNode;
		}
	}
	return node;
}

//******** search(MyNode<Data>*, Data)
// params - node - node to walk to find valueToFind
//			valueToFind - value to search tree for
// walks the tree to find valueToFind in tree, else returns NULL
template <typename Data> MyNode<Data>* BinarySearchTree<Data>::search(MyNode<Data>* node, Data valueToFind)
{
	if (node != NULL || node->getValue() == valueToFind)
		return node;
	if (valueToFind < node->getValue())
		return search(node->getLeft(), valueToFind);
	else
		return search(node->getRight(), valueToFind);
}

//********* printBreadthFirst(std::ofstream&, MyNode<Data>*)
// params - output - output file to print tree to
//			node - node to walk to print tree
// prints the tree in a breadth first fashion
template <typename Data> void BinarySearchTree<Data>::printBreadthFirst(std::ofstream &output, MyNode<Data>* node)
{
	if (node != NULL) {
		output << node->getValue() << "\n";
		printBreadthFirst(output, node->getLeft());
		printBreadthFirst(output, node->getRight());
	}
}

//********* printDepthFirst(std::ofstream&, MyNode<Data>*)
// params - output - output file to print tree to
//			node - node to walk to print tree
// prints the tree in a depth first fashion
template <typename Data> void BinarySearchTree<Data>::printDepthFirst(std::ofstream &output, MyNode<Data>* node)
{
	if (node != NULL) {
		printDepthFirst(output, node->getLeft());
		output << node->getValue() << "\n";
		printDepthFirst(output, node->getRight());
	}

}

//********* printBreadthFirstStdOut(MyNode<Data>*)
// params - node - node to walk to print tree
// prints the tree to std out in a breadth first fashion
template <typename Data> void BinarySearchTree<Data>::printBreadthFirstStdOut(MyNode<Data>* node)
{
	if (node != NULL) {
		std::cout << node->getValue() << "\n";
		printBreadthFirstStdOut(node->getLeft());
		printBreadthFirstStdOut(node->getRight());
	}
}

//********* printDepthFirstStdOut(MyNode<Data>*)
// params - node - node to walk to print tree
// prints the tree to std out in a depth first fashion
template <typename Data> void BinarySearchTree<Data>::printDepthFirstStdOut(MyNode<Data>* node)
{
	if (node != NULL) {
		printDepthFirstStdOut(node->getLeft());
		std::cout << node->getValue() << "\n";
		printDepthFirstStdOut(node->getRight());
	}

}

#endif /* binary_search_tree_h */