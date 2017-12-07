//
//  main.cpp
//  cis22c_final_project_js
//
//  Created by Jaydeep Singh on 11/20/17.
//  Copyright © 2017 DeAnza. All rights reserved.
//
#include "headnode.h"

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
	BinarySearchTree<std::string>* p_tree = new BinarySearchTree<std::string>();
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
	std::cout << "  [a] Print Name Tree (breadth first traversal)" << std::endl;
	std::cout << "  [b] Print Birthday Tree (depth first traversal)  " << std::endl;
	std::cout << "  [c] Add Node" << std::endl;
	std::cout << "  [d] Search by name" << std::endl;
	std::cout << "  [e] Search by birth date" << std::endl;
	std::cout << "  [f] Remove Node" << std::endl;
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
				//std::cout << std::endl << "Printing the name tree..." << std::endl;
				//nameBst->printBreadthFirstStdOut(nameBst->getRoot());
				break;
			case 'b':
				//std::cout << std::endl << "Printing the birthday tree..." << std::endl;
				break;
			case 'c':
				//addNode(nameBst, bdayBst);
				break;
			case 'd':
				//searchByName(nameBst);
				break;
			case 'e':
				//searchByBirthday(bdayBst);
				break;
			case 'f':
				//removeNode(nameBst, bdayBst);
				break;
			default:
				std::cout << "That was an invalid input. ";
				break;
		}

		std::cout << std::endl << std::endl << "Menu: " << std::endl;
		std::cout << "  [a] Print Name Tree (breadth first traversal)" << std::endl;
		std::cout << "  [b] Print Birthday Tree (depth first traversal)  " << std::endl;
		std::cout << "  [c] Add Node" << std::endl;
		std::cout << "  [d] Search by name" << std::endl;
		std::cout << "  [e] Search by birth date" << std::endl;
		std::cout << "  [f] Remove Node" << std::endl;
		std::cout << "  [q] Quit" << std::endl;
		std::cout << std::endl << "Please enter a letter to select a menu option: ";
		std::cin >> menuInput;
		menuInput = tolower(menuInput);
	}


	system("pause");
	return 0;
}