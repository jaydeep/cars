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
#include "hash.h"
//#include <unordered_map>

class headNode
{
private:
	int count;
	int arySize;
	MyHash pHash;
	BinarySearchTree<std::string> *pTree;

public:
	headNode(int, int, MyHash, BinarySearchTree<std::string>*);
};


headNode::headNode(int c, int s, MyHash p, BinarySearchTree<std::string>* t) {
	count = c;
	arySize = s;
	pHash = p;
	pTree = t;
}
//helper functions
void addNode(BinarySearchTree<std::string>*, BinarySearchTree<std::string>*);
void removeNode(BinarySearchTree<std::string>*, BinarySearchTree<std::string>*);
void searchByName(BinarySearchTree<std::string>*);
void searchByBirthday(BinarySearchTree<std::string>*);

int main() {
	std::string filePath, tempInput, tempInput1, nameOutputFile, bdayOutputFile;
	std::ifstream inputFile;
	std::ofstream nameOutput, bdayOutput;
	// Hashtable on vin number stores the pointer to car record
	//std::hash<char*> ptr_hash;
	//std::unordered_map<int, MyCar*> hashtable;
	//char menuInput;

	//create the two trees
	BinarySearchTree<std::string>* carBst = new BinarySearchTree<std::string>();

	std::cout << "Welcome the BMW of Denver Downtown!" << std::endl;
	std::cout << "Please enter the full file path that contains the 25+ records of cars." << std::endl;
	std::cout << "One record per line and each line would have VIN, make, model and year of the car." << std::endl;

	//std::getline(std::cin, filePath);
	filePath = "car5.txt";
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
	MyHash p_hash = MyHash(size);
	inputFile.open(filePath); 
	std::cout << std::endl << "Loading file..." << std::endl << std::endl;

	//get data from file and add them to tree
	std::string VIN;
	std::string make;
	std::string model;
	std::string year;
	std::size_t found;
	//char temp_VIN[1024];
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
		p_hash.add(mycar1);
		//strcpy(temp_VIN, VIN.c_str());	
		//hashtable[ptr_hash(temp_VIN)] = mycar1;
		std::cout << mycar1->printCar() << '\n';
	}
	p_hash.printAll();
	headNode *myHeadNode = new headNode(25, 25, p_hash, carBst);
	system("pause");
	return 0;
	inputFile.close(); //Close file now that we are done with it

					   /*
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
					   std::cout << std::endl << "Printing the name tree..." << std::endl;
					   nameBst->printBreadthFirstStdOut(nameBst->getRoot());
					   break;
					   case 'b':
					   std::cout << std::endl << "Printing the birthday tree..." << std::endl;
					   bdayBst->printBreadthFirstStdOut(bdayBst->getRoot());
					   break;
					   case 'c':
					   addNode(nameBst, bdayBst);
					   break;
					   case 'd':
					   searchByName(nameBst);
					   break;
					   case 'e':
					   searchByBirthday(bdayBst);
					   break;
					   case 'f':
					   removeNode(nameBst, bdayBst);
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

					   //Save name tree to file
					   std::cin.ignore(10, '\n');
					   std::cout << "Where would you like to save the name tree: ";
					   std::getline(std::cin, nameOutputFile);
					   nameOutput.open(nameOutputFile);

					   //Save bday tree to file
					   std::cout << "Where would you like to save the birthday tree: ";
					   std::getline(std::cin, bdayOutputFile);
					   bdayOutput.open(bdayOutputFile);

					   nameBst->printBreadthFirst(nameOutput, nameBst->getRoot());
					   bdayBst->printDepthFirst(bdayOutput, bdayBst->getRoot());

					   //Close output files
					   bdayOutput.close();
					   nameOutput.close();

					   std::cout << std::endl << "Thanks for using this program. Goodbye!" << std::endl;
					   system("pause");
					   return 0;
					   }


					   // *********** addNode(BinarySearchTree<std::string>*, BinarySearchTree<std::string>*)
					   //	params: nameBst - pointer to name tree
					   //			bdayBst - pointer to bday tree
					   //  helper function to add a node to name and bday tree
					   void addNode(BinarySearchTree<std::string>* nameBst, BinarySearchTree<std::string>* bdayBst)
					   {
					   std::string tempName, tempBirthday;

					   std::cin.ignore(10, '\n');
					   std::cout << "Please enter the name(fname lname): ";
					   std::getline(std::cin, tempName);

					   //Insert Node in Name Tree
					   nameBst->add(nameBst->getRoot(), tempName);


					   std::cout << "Please enter the birthday(YYYY/MM/DD): ";
					   std::getline(std::cin, tempBirthday);

					   //Insert Node in Birthday Tree
					   bdayBst->add(bdayBst->getRoot(), tempBirthday);
					   }

					   // *********** removeNode(BinarySearchTree<std::string>*, BinarySearchTree<std::string>*)
					   //	params: nameBst - pointer to name tree
					   //			bdayBst - pointer to bday tree
					   //  helper function to remove a node from name and bday tree
					   void removeNode(BinarySearchTree<std::string>* nameBst, BinarySearchTree<std::string>* bdayBst)
					   {
					   std::string nameToRemove, birthdayToRemove;

					   std::cout << std::endl << "Please enter the first name and last name of the" << std::endl;
					   std::cout << std::endl << "person you would like to remove (fname lname): ";
					   std::cin.ignore(10, '\n');
					   std::getline(std::cin, nameToRemove);

					   std::cout << std::endl << "Please enter the birthday of the" << std::endl;
					   std::cout << std::endl << "person you would like to remove (YYYY/MM/DD): ";

					   std::cin >> birthdayToRemove;

					   nameBst->remove(nameBst->getRoot(), nameToRemove);
					   bdayBst->remove(bdayBst->getRoot(), birthdayToRemove);
					   }

					   // *********** searchByName(BinarySearchTree<std::string>*)
					   //	params: nameBst - pointer to name tree
					   //  helper function to search name tree
					   void searchByName(BinarySearchTree<std::string>* nameBst)
					   {
					   std::string userSearchValue;

					   std::cin.ignore(10, '\n');

					   std::cout << "Please enter the first name and last name of the person you would like to find (fname lname): ";
					   std::getline(std::cin, userSearchValue);

					   bool searchResult = nameBst->search(nameBst->getRoot(), userSearchValue);

					   if (searchResult)
					   std::cout << std::endl << userSearchValue << " was found!" << std::endl;
					   else
					   std::cout << std::endl << userSearchValue << " was not found!" << std::endl;
					   }

					   // *********** searchByBirthday(BinarySearchTree<std::string>*)
					   //	params: bdayBst - pointer to bday tree
					   //  helper function to search birthday tree
					   void searchByBirthday(BinarySearchTree<std::string>* bdayBst)
					   {
					   std::string userSearchValue;

					   std::cin.ignore(10, '\n');
					   std::cout << "Please enter the birthday of the person you would like to find (YYYY/MM/DD) : ";
					   std::getline(std::cin, userSearchValue);

					   bool searchResult = bdayBst->search(bdayBst->getRoot(), userSearchValue);

					   if (searchResult)
					   std::cout << std::endl << userSearchValue << " was found!" << std::endl;
					   else
					   std::cout << std::endl << userSearchValue << " was not found!" << std::endl;

					   */
}

