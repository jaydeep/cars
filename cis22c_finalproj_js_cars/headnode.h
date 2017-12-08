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
	void add();
	void removeRecord(std::string);
	void remove();
	bool search(std::string);
	void searchByVIN();
	void printTree();
	void printTable();
	void printSortedTable();
	void headNode::efficiency_stats();
	MyCar* getRecord(std::string);
	void writeToFile();
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

void headNode::add()
{
	std::string tempVIN, tempMake, tempModel, tempYear;

	std::cout << "Please enter the 10 digit VIN Number: ";
	std::cin >> tempVIN;

	std::cout << "Please enter the make: ";
	std::cin >> tempMake;

	std::cout << "Please enter the model";
	std::cin >> tempModel;

	std::cout << "Please enter the year of the car: ";
	std::cin >> tempYear;

	MyCar* tempCar = new MyCar(tempVIN, tempMake, tempModel, tempYear);
	addRecord(tempCar);
}

void headNode::removeRecord(std::string vinOfCarToRemove)
{
	// Order of removing is important. Hash remove must be done last as it deletes the memory associated with the record
	MyNode<MyCar*>* save;
	save = pTree->remove(pTree->getRoot(), pHash.find(vinOfCarToRemove)); 
	pTree->setRoot(save);
	pHash.remove(vinOfCarToRemove);
}

void headNode::remove()
{
	std::string keyToRemove;
	std::cout << "What is the VIN of the car you wish to remove: ";
	std::cin >> keyToRemove;

	//search for key, if not found, return, if found, remove it, and tell user successfully deleted
	if (!search(keyToRemove))
	{
		std::cout << "VIN not found. Returning to main menu." << std::endl;
		return;
	}
	else
	{
		//found the VIN
		removeRecord(keyToRemove);
	}
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

void headNode::searchByVIN()
{
	std::string vinToSearch;
	std::cout << "What is the VIN of the car: ";
	std::cin >> vinToSearch;

	if (!search(vinToSearch))
	{
		std::cout << "VIN not found. Returning to main menu." << std::endl;
		return;
	}
	else
	{
		std::cout << "VIN found. Data for car shown below." << std::endl;
		std::cout << (getRecord(vinToSearch))->printCar() << std::endl;
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

void headNode::writeToFile()
{
	std::ofstream output;
	std::string outputFilePath;

	std::cout << "Where would you like to save the file?" << std::endl;
	std::cout << "Please enter the full file path here: ";
	std::getline(std::cin, outputFilePath);
	output.open(outputFilePath);

	while (!output) //file path validation
	{
		std::cout << "Sorry, I could not find that file." << std::endl;
		std::cout << "Please enter the full file path of the data " << std::endl;
		std::cout << "you wish to save: ";
		std::getline(std::cin, outputFilePath);
		output.open(outputFilePath);
	}

	pTree->printBreadthFirst(output, pTree->getRoot());
	std::cout << std::endl << "Successfully saved to file. Returning to main menu." << std::endl << std::endl;
}
#endif