//
//  main.cpp
//  cis22c_final_project_js
//
//  Created by Jaydeep Singh on 11/20/17.
//  Copyright © 2017 DeAnza. All rights reserved.
//
#include "headnode.h"

int main() {
	std::string filePath, tempInput, tempVIN, tempMake, tempModel, tempYear;
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

	//count number of records in file
	int size = 0;
	while (std::getline(inputFile, tempInput))
	{
		size = size + 1;
	}

	//close file now that we are done counting the number of records
	inputFile.close();

	//declare a hashtable with size 3x of numRecords
	MyHash p_hash = MyHash(3*size);

	//open file to read data into hashtable and bst
	inputFile.open(filePath);

	std::cout << std::endl << "Loading file..." << std::endl << std::endl;

	MyCar *tempCar;

	while (inputFile >> tempVIN >> tempMake >> tempModel >> tempYear)
	{
		tempCar = new MyCar(tempVIN, tempMake, tempModel, tempYear);
		p_hash.add(tempCar);
	}

	//Close file now that we are done with it
	inputFile.close();

	std::cout << "Printing ALL\n";
	p_hash.find("001234567890");
	p_hash.printAll();
	p_hash.deleteEven();
	p_hash.printAll();
	p_hash.efficiency_stats();
	//headNode *myHeadNode = new headNode(25, 25, p_hash, carBst);
	system("pause");
	return 0;
}

