//
//  node.h
//
//  Created by Jaydeep Singh on 11/21/17.
//  Copyright © 2017 DeAnza. All rights reserved.
//

#ifndef node_h
#define node_h

template <typename Data> class MyNode
{
private:
	Data myValue;
	std::string key;
	MyNode<Data>* left;
	MyNode<Data>* right;

public:
	MyNode();
	MyNode(Data, std::string);
	MyNode(Data, std::string, MyNode<Data>*, MyNode<Data>*);
	~MyNode();
	Data getValue();
	void setValue(Data, std::string);
	MyNode<Data>* getLeft();
	std::string getKey();
	void setLeft(MyNode<Data>*);
	MyNode<Data>* getRight();
	void setRight(MyNode<Data>*);
};

//Default Constructor
template <typename Data> MyNode<Data>::MyNode()
{
	myValue = NULL;
	key = "";
	left = NULL;
	right = NULL;
}

//Constructor that takes one Data parameter
template <typename Data> MyNode<Data>::MyNode(Data value, std::string key1)
{
	myValue = value;
	left = NULL;
	right = NULL;
	key = key1;
}

//Constructor that takes a Data and two MyNode pointers for right and left child
template <typename Data> MyNode<Data>::MyNode(Data value, std::string key1,
	MyNode<Data>* left,
	MyNode<Data>* right)
{
	myValue = value;
	left = left;
	right = right;
	key = key1;
}

//Destructor - deallocates the memory pointing to left and right child
template <typename Data> MyNode<Data>::~MyNode()
{
	delete left;
	delete right;
}

//returns the value stored in node
template <typename Data> Data MyNode<Data>::getValue()
{
	return myValue;
}

template <typename Data> std::string MyNode<Data>::getKey()
{
	return key;
}

//sets the value stored in node
template <typename Data> void MyNode<Data>::setValue(Data value, std::string key1)
{
	myValue = value;
	key = key1;
}

//gets left child
template <typename Data> MyNode<Data>* MyNode<Data>::getLeft()
{
	return left;
}

//set pointer of left child
template <typename Data> void MyNode<Data>::setLeft(MyNode<Data>* newLeft)
{
	left = newLeft;
}

//get right child
template <typename Data> MyNode<Data>* MyNode<Data>::getRight()
{
	return right;
}

//set pointer of right child
template <typename Data> void MyNode<Data>::setRight(MyNode<Data>* newRight)
{
	right = newRight;
}

#endif /* node_h */
