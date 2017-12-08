//
//  main.cpp
//  cis22c_final_project_js
//
//  Created by Jaydeep Singh on 11/20/17.
//  Copyright © 2017 DeAnza. All rights reserved.
//
#include "headnode.h"

void add(headNode);
void remove(headNode);
void searchByVIN(headNode);

int main() {
	std::string filePath, tempInput, VIN, make, model, year;
	std::size_t found;
	MyCar *mycar1;
	int size = 0;
	std::ifstream inputFile;
	char menuInput;

	std::cout << "Welcome to the BMW of Denver Downtown!" << std::endl;
	std::cout << "Please enter the full file path that contains the 25+ records of cars." << std::endl;
	std::cout << "One record per line and each line would have VIN, make, model and year of the car." << std::endl;
	std::cout << "Enter file path here: ";

	std::getline(std::cin, filePath);
	inputFile.open(filePath);

	while (!inputFile) //file input validation
	{
		std::cout << "Sorry, I could not find that file." << std::endl;
		std::cout << "Please enter the full file path of the data " << std::endl;
		std::cout << "you wish to save: ";
		std::getline(std::cin, filePath);
		inputFile.open(filePath);
	}

	//read file to get size of hashtable
	while (std::getline(inputFile, tempInput))
	{
		size = size + 1;
	}

	inputFile.close();

	MyHash p_hash = MyHash(3*size); //use 3*size for better efficiency
	BinarySearchTree<MyCar*>* p_tree = new BinarySearchTree<MyCar*>();
	headNode head = headNode(25, 25, p_hash, p_tree);
	inputFile.open(filePath);

	std::cout << std::endl << "Loading file..." << std::endl << std::endl;

	//get data from file and add them to tree/hash
	while (std::getline(inputFile, tempInput))
	{
		found = tempInput.find(" ");
		if (found != std::string::npos) {
			VIN = tempInput.substr(0, found);
			tempInput = tempInput.substr(found + 1);
		}
		else {
			std::cout << "Malformed record would be ignored:" << tempInput << "\n";
		}

		found = tempInput.find(" ");

		if (found != std::string::npos) {
			make = tempInput.substr(0, found);
			tempInput = tempInput.substr(found + 1);
		}
		else {
			std::cout << "Malformed record would be ignored:" << tempInput << "\n";
		}

		found = tempInput.find(" ");
		if (found != std::string::npos) {
			model = tempInput.substr(0, found);
			year = tempInput.substr(found + 1);
		}
		else {
			std::cout << "Malformed record would be ignored:" << tempInput << "\n";
		}

		mycar1 = new MyCar(VIN, make, model, year);
		head.addRecord(mycar1);
	}
	//Close file now that we are done with it
	inputFile.close();

	//Menu
	std::cout << std::endl << std::endl << "Menu: " << std::endl;
	std::cout << "  [a] Add record" << std::endl;
	std::cout << "  [b] Remove record" << std::endl;
	std::cout << "  [c] Search by VIN" << std::endl;
	std::cout << "  [d] Print Table" << std::endl;
	std::cout << "  [e] Print Table (sorted by key value)" << std::endl;
	std::cout << "  [f] Print Indented Tree" << std::endl;
	std::cout << "  [g] Print Efficiency of Table" << std::endl;
	std::cout << "  [h] TODO OPTION" << std::endl;
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
				//Add Record
				head.add();
				break;
			case 'b':
				//Remove record
				head.remove();
				break;
			case 'c':
				//Search By VIN
				head.searchByVIN();
				break;
			case 'd':
				//Print Table
				head.printTable();
				break;
			case 'e':
				//Print Sorted Table
				head.printSortedTable();
				break;
			case 'f':
				//Print Indented Tree
				head.printTree();
				break;
			case 'g':
				//Print Efficiency of Table
				head.efficiency_stats();
				break;
			case 'h':
				//TODO Option
				break;
			default:
				std::cout << "That was an invalid input. ";
				break;
		}

		std::cout << std::endl << std::endl << "Menu: " << std::endl;
		std::cout << "  [a] Add record" << std::endl;
		std::cout << "  [b] Remove record" << std::endl;
		std::cout << "  [c] Search by VIN" << std::endl;
		std::cout << "  [d] Print Table" << std::endl;
		std::cout << "  [e] Print Table (sorted by key value)" << std::endl;
		std::cout << "  [f] Print Indented Tree" << std::endl;
		std::cout << "  [g] Print Efficiency of Table" << std::endl;
		std::cout << "  [h] TODO OPTION" << std::endl;
		std::cout << "  [q] Quit" << std::endl;
		std::cout << std::endl << "Please enter a letter to select a menu option: ";
		std::cin >> menuInput;
		menuInput = tolower(menuInput);
	}

	std::cout << std::endl << std::endl << "Thank you for using this program! We hope to see you again soon!" << std::endl;

	system("pause");
	return 0;
}

//void add(headNode head)
//{
//	std::string tempVIN, tempMake, tempModel, tempYear;
//
//	std::cout << "Please enter the 10 digit VIN Number: ";
//	std::cin >> tempVIN;
//
//	std::cout << "Please enter the make: ";
//	std::cin >> tempMake;
//
//	std::cout << "Please enter the model";
//	std::cin >> tempModel;
//
//	std::cout << "Please enter the year of the car: ";
//	std::cin >> tempYear;
//
//	MyCar* tempCar = new MyCar(tempVIN, tempMake, tempModel, tempYear);
//	head.addRecord(tempCar);
//}
//
//void remove(headNode head)
//{
//	std::string keyToRemove;
//	std::cout << "What is the VIN of the car you wish to remove: ";
//	std::cin >> keyToRemove;
//
//	//search for key, if not found, return, if found, remove it, and tell user successfully deleted
//	if (!head.search(keyToRemove))
//	{
//		std::cout << "VIN not found. Returning to main menu." << std::endl;
//		return;
//	}
//	else
//	{
//		//found the VIN
//		head.removeRecord(keyToRemove);
//	}
//}

void searchByVIN(headNode head)
{
	std::string vinToSearch;
	std::cout << "What is the VIN of the car: ";
	std::cin >> vinToSearch;

	if (!head.search(vinToSearch))
	{
		std::cout << "VIN not found. Returning to main menu." << std::endl;
		return;
	}
	else
	{
		std::cout << "VIN found. Data for car shown below." << std::endl;
		std::cout << (head.getRecord(vinToSearch))->printCar() << std::endl;
	}
}