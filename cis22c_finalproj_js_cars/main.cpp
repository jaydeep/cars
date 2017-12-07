//
//  main.cpp
//  cis22c_final_project_js
//
//  Created by Jaydeep Singh on 11/20/17.
//  Copyright � 2017 DeAnza. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "binarysearchtree.h"
#include "car.h"
#include <unordered_map>

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
	int setCount(int);
	int setArySize(int);
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
//helper functions
void addRecord();
void removeRecord();
void searchByVIN();
void searchByYear();
void searchByMake();
void searchByModel();
void listDataInHashTableSeq();
void listDataInSortedKeySeq();
void printIndentedTree();
void printEfficiency();

int main() {
	std::string filePath, tempInput, tempInput1, nameOutputFile, bdayOutputFile, tempVIN, tempMake, tempModel, tempYear;
	int counter = 0;
	std::ifstream inputFile;
	std::ofstream nameOutput, bdayOutput;
	// Hashtable on vin number stores the pointer to car record
	std::unordered_map<int, MyCar*> hashtable;
	char menuInput;

	//create the two trees
	BinarySearchTree<std::string>* carBst = new BinarySearchTree<std::string>();

	std::cout << "Welcome the BMW of Denver Downtown!" << std::endl;
	std::cout << "Please enter the full file path that contains the 25+ records of cars." << std::endl;
	std::cout << "One record per line and each line would have VIN, make, model and year of the car." << std::endl;

	//std::getline(std::cin, filePath);
	filePath = "car.txt";
	inputFile.open(filePath);

	while (!inputFile) //file input validation
	{
		std::cout << "Sorry, I could not find that file." << std::endl;
		std::cout << "Please enter the full file path of the data " << std::endl;
		std::cout << "you wish to save: ";
		std::getline(std::cin, filePath);
		inputFile.open(filePath);
	}

	std::cout << std::endl << "Loading file..." << std::endl << std::endl;

	//get data from file and add them to tree
	std::cout << std::endl << "Loading file..." << std::endl << std::endl;

	//get data from file and add them to tree
	MyCar *myCar1;
	while (inputFile >> tempVIN >> tempMake >> tempModel >> tempYear) //read records line by line
	{
		myCar1 = new MyCar(tempVIN, tempMake, tempModel, tempYear);
		counter += 1;
		hashtable[counter] = myCar1;
		std::cout << myCar1->printCar() << std::endl;
	}

	//Menu
	std::cout << std::endl << std::endl << "Menu: " << std::endl;
	std::cout << "  [a] Add new data" << std::endl;
	std::cout << "  [b] Delete data " << std::endl;
	std::cout << "  [c] Search by primary key/VIN" << std::endl;
	std::cout << "  [d] Search by year" << std::endl;
	std::cout << "  [e] Search by make" << std::endl;
	std::cout << "  [f] List data in hash table sequence" << std::endl;
	std::cout << "  [g] List data in sorted key sequence" << std::endl;
	std::cout << "  [h] Print Indented Tree" << std::endl;
	std::cout << "  [i] Efficiency" << std::endl;
	std::cout << "  [q] Quit" << std::endl;
	std::cout << std::endl << "Please enter a letter to select a menu option: ";
	std::cin >> menuInput;
	menuInput = tolower(menuInput);

	//Menu handling
	while (menuInput != 'q')
	{
		switch (menuInput)
		{
		case 'a':
			addRecord();
			break;
		case 'b':
			removeRecord();
			break;
		case 'c':
			searchByVIN();
			break;
		case 'd':
			searchByYear();
			break;
		case 'e':
			searchByMake();
			break;
		case 'f':
			listDataInHashTableSeq();
			break;
		case 'g':
			listDataInSortedKeySeq();
			break;
		case 'h':
			printIndentedTree();
			break;
		case 'i':
			printEfficiency();
			break;
		default:
			std::cout << "That was an invalid input. ";
			break;
		}

		std::cout << std::endl << std::endl << "Menu: " << std::endl;
		std::cout << "  [a] Add new data" << std::endl;
		std::cout << "  [b] Delete data " << std::endl;
		std::cout << "  [c] Search by primary key/VIN" << std::endl;
		std::cout << "  [d] Search by year [team choice]" << std::endl;
		std::cout << "  [e] Search by make [team choice]" << std::endl;
		std::cout << "  [f] List data in hash table sequence" << std::endl;
		std::cout << "  [g] List data in sorted key sequence" << std::endl;
		std::cout << "  [h] Print Indented Tree" << std::endl;
		std::cout << "  [i] Efficiency" << std::endl;
		std::cout << "  [q] Quit" << std::endl;
		std::cout << std::endl << "Please enter a letter to select a menu option: ";
		std::cin >> menuInput;
		menuInput = tolower(menuInput);
	}
}

void addRecord()
{
}

void removeRecord()
{
}

void searchByVIN()
{
}

void searchByYear()
{
}

void searchByMake()
{
}

void searchByModel()
{
}

void listDataInHashTableSeq()
{
}

void listDataInSortedKeySeq()
{
}

void printIndentedTree()
{
}

void printEfficiency()
{
}
