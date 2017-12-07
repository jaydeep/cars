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
	BinarySearchTree<MyCar*> *pTree;

public:
	headNode(int, int, MyHash, BinarySearchTree<MyCar*>*);
	void addRecord(MyCar*);
	void removeRecord(std::string);
	bool search(std::string);
	void printTree();
	void printTable();
	void printSortedTable();
	void headNode::efficiency_stats();
	MyCar* getRecord(std::string);
};

headNode::headNode(int c, int s, MyHash p, BinarySearchTree<MyCar*>* t)
{
	count = c;
	arySize = s;
	pHash = p;
	pTree = t;
}

void headNode::addRecord(MyCar* carToAdd)
{
	pHash.add(carToAdd);
	pTree->add(pTree->getRoot(), carToAdd);
}

void headNode::removeRecord(std::string vinOfCarToRemove)
{
	// Order of removing is important. Hash remove must be done last as it deletes the memory associated with the record
	MyNode<MyCar*>* save;
	save = pTree->remove(pTree->getRoot(), pHash.find(vinOfCarToRemove)); 
	pTree->setRoot(save);
	pHash.remove(vinOfCarToRemove);
}

bool headNode::search(std::string searchKey)
{
	if (pHash.find(searchKey))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void headNode::printTree()
{
	std::cout << "Printing the tree: " << std::endl;
	pTree->printBreadthFirstStdOut(pTree->getRoot());
}

void headNode::printTable()
{
	std::cout << "Printing the entire hash table: " << std::endl << std::endl;
	pHash.printAll();
}
void headNode::efficiency_stats() {
	pHash.efficiency_stats();
}
void headNode::printSortedTable()
{
	std::cout << "Printing Sorted Table\n";
	pTree->printDepthFirstStdOut(pTree->getRoot());
}

MyCar* headNode::getRecord(std::string VIN)
{
	return pHash.find(VIN);
}
#endif