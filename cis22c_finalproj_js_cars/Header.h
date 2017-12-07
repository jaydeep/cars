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
};

headNode::headNode(int c, int s, MyHash p, BinarySearchTree<std::string>* t)
{
	count = c;
	arySize = s;
	pHash = p;
	pTree = t;
}
#endif