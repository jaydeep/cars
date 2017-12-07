//
//  main.cpp
//  cis22c_final_project_js
//
//  Created by Jaydeep Singh on 11/20/17.
//  Copyright © 2017 DeAnza. All rights reserved.
//
#include "headnode.h"

int main() {
	std::string filePath, tempInput;
	std::ifstream inputFile;
	//char menuInput;

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


	int size = 0;
	while (std::getline(inputFile, tempInput))
	{
		size = size + 1;
	}

	inputFile.close();

	MyHash p_hash = MyHash(3*size);
	BinarySearchTree<std::string>* p_tree = new BinarySearchTree<std::string>();
	headNode head = headNode(25, 25, p_hash, p_tree);
	inputFile.open(filePath);

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
		//head.addRecord(mycar1);
		//p_hash.add(mycar1);
		//std::cout << mycar1->printCar() << '\n';
	}
	//Close file now that we are done with it
	inputFile.close();

	

	//std::cout << "Printing ALL\n";
	//p_hash.find("001234567890");
	//p_hash.printAll();
	//p_hash.deleteEven();
	//p_hash.printAll();
	

	//testing addRecord()
    MyCar* tempCar = new MyCar("000000000", "BMW", "M3", "2008");
	MyCar* tempCar1 = new MyCar("000000001", "BMW", "Z4M", "2007");

	head.addRecord(tempCar);
	head.addRecord(tempCar1);

	head.printTable();
	head.printSortedTable();
	//p_hash.printAll();

	//testing search
	std::cout << "Removing Record......\n";
	head.removeRecord(tempCar);
	head.removeRecord(tempCar1);

	head.printTable();
	head.printSortedTable();
	head.efficiency_stats();
	system("pause");
	return 0;
}