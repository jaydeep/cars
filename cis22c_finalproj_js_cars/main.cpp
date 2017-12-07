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

	inputFile.open(filePath);

	std::cout << std::endl << "Loading file..." << std::endl << std::endl;

	//get data from file and add them to tree
	std::string VIN;
	std::string make;
	std::string model;
	std::string year;

	BinarySearchTree<std::string>* carBst = new BinarySearchTree<std::string>();
	headNode *myHeadNode = new headNode(25, 25, p_hash, carBst);
	MyCar *mycar1;

	while (inputFile >> VIN >> make >> model >> year)
	{
		mycar1 = new MyCar(VIN, make, model, year);
		myHeadNode->addRecord(mycar1);
	}
	//Close file now that we are done with it
	inputFile.close();

	std::cout << "Printing ALL\n";
	p_hash.find("001234567890");
	p_hash.printAll();
	p_hash.deleteEven();
	p_hash.printAll();
	p_hash.efficiency_stats();



	//testing addRecord()
	MyCar* tempCar = new MyCar("000000000", "BMW", "M3", "2008");
	myHeadNode->addRecord(tempCar);
	myHeadNode->printTable();
	myHeadNode->printTree();

	//testing search
	std::cout << "Searching......";
	myHeadNode->search("000000000");
	p_hash.find("000000000");

	//testing remove
	myHeadNode->removeRecord(tempCar);

	myHeadNode->printTable();

	system("pause");
	return 0;
}