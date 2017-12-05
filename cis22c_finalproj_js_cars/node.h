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
	MyNode<Data>* left;
	MyNode<Data>* right;

public:
	MyNode();
	MyNode(Data);
	MyNode(Data, MyNode<Data>*, MyNode<Data>*);
	~MyNode();
	Data getValue();
	void setValue(Data);
	MyNode<Data>* getLeft();
	void setLeft(MyNode<Data>*);
	MyNode<Data>* getRight();
	void setRight(MyNode<Data>*);
};

//Default Constructor
template <typename Data> MyNode<Data>::MyNode()
{
	myValue = NULL;
	left = NULL;
	right = NULL;
}

//Constructor that takes one Data parameter
template <typename Data> MyNode<Data>::MyNode(Data value)
{
	myValue = value;
	left = NULL;
	right = NULL;
}

//Constructor that takes a Data and two MyNode pointers for right and left child
template <typename Data> MyNode<Data>::MyNode(Data value,
	MyNode<Data>* left,
	MyNode<Data>* right)
{
	myValue = value;
	left = left;
	right = right;
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

//sets the value stored in node
template <typename Data> void MyNode<Data>::setValue(Data value)
{
	myValue = value;
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
