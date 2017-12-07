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

public:
	headNode(int, int, MyHash, BinarySearchTree<std::string>*);
	void addRecord(MyCar*);
	void removeRecord(MyCar*);
	void search(std::string);
	void printTree();
	void printTable();
	void printSortedTable();
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

void headNode::removeRecord(MyCar* carToRemove)
{
	pHash.remove(carToRemove->getVIN());
	//pTree->remove(pTree->getRoot(), carToRemove->getVIN()); //TODO
}

void headNode::search(std::string searchKey)
{
	std::cout << pTree->search(pTree->getRoot(), searchKey); //TODO
}

void headNode::printTree()
{

}

void headNode::printTable()
{
	std::cout << "Printing the entire hash table: " << std::endl << std::endl;
	pHash.printAll();
}

void headNode::printSortedTable()
{

}
#endif