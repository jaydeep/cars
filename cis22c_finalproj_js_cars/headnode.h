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
	void headNode::efficiency_stats();
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
	// Order of removing is important. Hash remove must be done last as it deletes the memory associated with the record
	MyNode<std::string>* save;
	save = pTree->remove(pTree->getRoot(), carToRemove->getVIN()); 
	pTree->setRoot(save);
	pHash.remove(carToRemove->getVIN());
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
void headNode::efficiency_stats() {
	pHash.efficiency_stats();
}
void headNode::printSortedTable()
{
	std::cout << "Printing Sorted Table\n";
	pTree->printDepthFirstStdOut(pTree->getRoot());
}
#endif