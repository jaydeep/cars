#include <unordered_map>
#include "binarysearchtree.h"
#include "car.h"

class headNode
{
private:
	int count;
	int arySize;
	std::unordered_map<int, MyCar*> *pHash;
	BinarySearchTree<std::string> *pTree;

public:
	headNode(int, int, std::unordered_map<int, MyCar*>, BinarySearchTree<std::string>*);
	headNode(int, int, std::unordered_map<int, MyCar*>);
	headNode(int, int);
	//	int setCount(int);
	//	int setArySize(int);
};

headNode::headNode(int c, int s) {
	// , std::unordered_map<int, MyCar*>* p, BinarySearchTree<std::string>* t) {
	count = c;
	arySize = s;
	//pHash = p;
	//pTree = t;

}
headNode::headNode(int c, int s, std::unordered_map<int, MyCar*> p) {
	// , std::unordered_map<int, MyCar*>* p, BinarySearchTree<std::string>* t) {
	count = c;
	arySize = s;
	//pHash = p;
	//pTree = t;

}
headNode::headNode(int c, int s, std::unordered_map<int, MyCar*> p, BinarySearchTree<std::string>*) {
	// , std::unordered_map<int, MyCar*>* p, BinarySearchTree<std::string>* t) {
	count = c;
	arySize = s;
	//pHash = p;
	//pTree = t;
}
