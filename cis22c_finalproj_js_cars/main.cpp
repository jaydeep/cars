//
//  main.cpp
//  cis22c_final_project_js
//
//  Created by Jaydeep Singh on 11/20/17.
//  Copyright © 2017 DeAnza. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "binarysearchtree.h"
#include "car.h"
#include <unordered_map>

//helper functions
void addNode(BinarySearchTree<std::string>*, BinarySearchTree<std::string>*);
void removeNode(BinarySearchTree<std::string>*, BinarySearchTree<std::string>*);
void searchByName(BinarySearchTree<std::string>*);
void searchByBirthday(BinarySearchTree<std::string>*);


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

int main() {
	std::string filePath, tempInput, tempInput1, nameOutputFile, bdayOutputFile;
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
	std::string VIN;
	std::string make;
	std::string model;
	std::string year;
	std::size_t found;
	int counter = 0;
	MyCar *mycar1;
	while (std::getline(inputFile, tempInput))
	{
		found = tempInput.find(" ");
		if (found != std::string::npos) {
			VIN = tempInput.substr(0, found);
			tempInput = tempInput.substr(found + 1);
			std::cout << "VIN= " << VIN << '\n';
			std::cout << "space found at= " << found << '\n';
			std::cout << "rest of the string " << tempInput << '\n';
		}
		else {
			std::cout << "Malformed record would be ignored:" << tempInput << "\n";
		}
		found = tempInput.find(" ");
		if (found != std::string::npos) {
			make = tempInput.substr(0, found);
			tempInput = tempInput.substr(found + 1);
			std::cout << "make= " << make << '\n';
			std::cout << "space found at= " << found << '\n';
			std::cout << "rest of the string " << tempInput << '\n';
		}
		else {
			std::cout << "Malformed record would be ignored:" << tempInput << "\n";
		}
		found = tempInput.find(" ");
		if (found != std::string::npos) {
			model = tempInput.substr(0, found);
			year = tempInput.substr(found + 1);
			std::cout << "model= " << model << '\n';
			std::cout << "year= " << year << '\n';
			std::cout << "space found at= " << found << '\n';
		}
		else {
			std::cout << "Malformed record would be ignored:" << tempInput << "\n";
		}
		mycar1 = new MyCar(VIN, make, model, year);
		counter = counter + 1;
		hashtable[counter] = mycar1;
		std::cout << mycar1->printCar() << '\n';
	}
	headNode *myHeadNode = new headNode(25, 25);
	headNode *myHeadNode1 = new headNode(25, 25, hashtable);
	headNode *myHeadNode2 = new headNode(25, 25, hashtable, carBst);

	inputFile.close(); //Close file now that we are done with it
	system("pause");
	return 0;
}

