//
//  main.cpp
//  cis22c_finalproj_js_cars
//
//  Created by Jaydeep Singh on 11/20/17.
//  Copyright © 2017 DeAnza. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "binarysearchtree.h"
#include "headnode.h"
#include "car.h"
#include <unordered_map>

//helper functions
void addNode(BinarySearchTree<std::string>*, BinarySearchTree<std::string>*);
void removeNode(BinarySearchTree<std::string>*, BinarySearchTree<std::string>*);
void searchByName(BinarySearchTree<std::string>*);
void searchByBirthday(BinarySearchTree<std::string>*);

//main
int main() {
	std::string filePath, tempVIN, tempMake, tempModel, tempYear;
	std::ifstream inputFile;
	std::ofstream nameOutput, bdayOutput;
	int counter = 0;

	// Hashtable on vin number stores the pointer to car record
	std::unordered_map<int, MyCar*> hashtable;
	char menuInput;

	//create the tree
	BinarySearchTree<std::string>* carBst = new BinarySearchTree<std::string>();

	std::cout << "Welcome to the BMW of Denver Downtown!" << std::endl;
	std::cout << "Please enter the full file path that contains the car inventory." << std::endl;
	std::cout << "(File should have one record per line and each line should have" << std::endl;
	std::cout << "VIN, make, model and year of the car.) : " << std::endl;

	std::getline(std::cin, filePath);

	inputFile.open(filePath);

	while (!inputFile) //file input validation
	{
		std::cout << "Sorry, I could not find that file." << std::endl;
		std::cout << "Please enter the full file path of the data " << std::endl;
		std::cout << "you wish to load: ";

		std::getline(std::cin, filePath);
		inputFile.open(filePath);
	}

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



	inputFile.close(); //Close file now that we are done with it
	system("pause");
	return 0;
}

