#ifndef headnode_h
#define headnode_h
#include "hash.h"
#include "binarysearchtree.h"

class headNode
{
private:
	int count;
	int arySize;
	MyHash pHash;
	BinarySearchTree<std::string> *pTree;
	void addRecord(MyCar*);
	void removeRecord();
	void search(std::string);
	void printTree();
	void printTable();
	void printSortedTable();

public:
	headNode(int, int, MyHash, BinarySearchTree<std::string>*);
};

headNode::headNode(int c, int s, MyHash p, BinarySearchTree<std::string>* t)
{
	count = c;
	arySize = s;
	pHash = p;
	pTree = t;
}

void headNode::addRecord(MyCar* carToAdd)
{
	pHash.add(carToAdd);
	pTree->add(pTree->getRoot(), carToAdd->getVIN());
}

void headNode::removeRecord()
{

}

void headNode::search(std::string searchKey)
{

}

void headNode::printTree()
{

}

void headNode::printTable()
{

}

void headNode::printSortedTable()
{

}
#endif