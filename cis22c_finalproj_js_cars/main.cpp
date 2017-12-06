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
	std::cout << "  [i] Efficiency";
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
			break;
		case 'b':
			break;
		case 'c':
			break;
		case 'd':
			break;
		case 'e':
			break;
		case 'f':
			break;
		case 'g':
			break;
		case 'h':
			break;
		case 'i':
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
		std::cout << "  [i] Efficiency";
		std::cout << "  [q] Quit" << std::endl;
		std::cout << std::endl << "Please enter a letter to select a menu option: ";
		std::cin >> menuInput;
		menuInput = tolower(menuInput);
	}

	////Save name tree to file
	//std::cin.ignore(10, '\n');
	//std::cout << "Where would you like to save the name tree: ";
	//std::getline(std::cin, nameOutputFile);
	//nameOutput.open(nameOutputFile);

	////Save bday tree to file
	//std::cout << "Where would you like to save the birthday tree: ";
	//std::getline(std::cin, bdayOutputFile);
	//bdayOutput.open(bdayOutputFile);

	//nameBst->printBreadthFirst(nameOutput, nameBst->getRoot());
	//bdayBst->printDepthFirst(bdayOutput, bdayBst->getRoot());

	////Close output files
	//bdayOutput.close();
	//nameOutput.close();

	std::cout << std::endl << "Thanks for using this program. Goodbye!" << std::endl;

	inputFile.close(); //Close file now that we are done with it
	system("pause");
	return 0;
}

