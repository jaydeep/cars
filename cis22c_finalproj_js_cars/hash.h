//
//  hash.h
//  cis22c_final_project_js
//
//  Created by Jaydeep Singh on 11/21/17.
//  Copyright © 2017 DeAnza. All rights reserved.
//
#ifndef hash_h
#define hash_h
#include <iostream>
#include "car.h"
#define A 54059 /* a prime */
#define B 76963 /* another prime */
#define C 86969 /* yet another prime */
#define FIRSTH 37 /* also prime */

class MyHash
{
private:
	MyCar** table;
	MyCar* NULL_record;
	int hashSize;
	int num_collisions; // for add and remove
	int num_operations; // for add and remove
	//int total_operations_performed_on_sort;
	
public:
	MyHash();
	MyHash(int);
	//~MyHash();
	void add(MyCar*);
	bool remove(std::string);
	int find_empty_slot(unsigned);
	bool search(std::string);
	MyCar* find(std::string);
	void printAll();
	unsigned hash_str(const char* s);
	void efficiency_stats();

};

//Default Constructor
MyHash::MyHash()
{
	table = new MyCar*[1];
	NULL_record = new MyCar("X", "Y", "Z", "0000");
	hashSize = 1;
	table[0] = NULL;
	num_collisions = 0; 
	num_operations = 0;
}
//Default Constructor
MyHash::MyHash(int hash_size)
{
	table = new MyCar*[hash_size];
	NULL_record = new MyCar("X", "Y", "Z", "0000");
	hashSize = hash_size;
	num_collisions = 0;
	num_operations = 0;
	int i = 0;
	while (i < hashSize) {
		table[i] = NULL;
		i++;
	}
}

void MyHash::add(MyCar* value)
{
	num_operations += 1;
	std::string  vin = value->getVIN();

	char vin_ptr[20];
	strcpy_s(vin_ptr, vin.c_str());
	unsigned hash_value = hash_str(vin_ptr);
	int myslot = find_empty_slot(hash_value);
	if (myslot > 0) {
	    //std::cout << "slot= " << myslot << " vin= " << vin << "\n";
	    table[myslot] = value; //this may not work now
    }
    else {
		std::cout << "FAILED TO ADD DATA AS NO EMPTY SLOT FOUND\n";
    }
}

int MyHash::find_empty_slot(unsigned hash1) {
	bool done = 0;
	int attempt = 1;
	unsigned next_slot = hash1;
	while (done == 0) {
		if (table[next_slot] == NULL) {
			return next_slot;
		}
		else {
			if (table[next_slot] == NULL_record) {
				return next_slot;
			}
			else {
				next_slot = (hash1 + attempt * attempt) % hashSize;
				attempt++;
				num_collisions++;
			}
		}
	}
	return -1;
}

bool MyHash::remove(std::string vin)
{
	num_operations += 1;
	char vin_ptr[20];
	strcpy_s(vin_ptr, vin.c_str());
	unsigned hash_value = hash_str(vin_ptr);
	//int myslot = locate_slot(hash_value);
	std::string tempvin;
	int done = 0;
	int attempt = 1;
	int next_slot = hash_value;
	while (done == 0) {
		if (table[next_slot] == NULL) {
			// We hit empty slot, so VIN does not exist
			return false;
		}
		else {
			if (table[next_slot] == NULL_record) {
				// We hit a NULL Record, keep searching
				next_slot = (hash_value + attempt * attempt) % hashSize;
				attempt++;
				num_collisions++;
			}
			else {
				tempvin = table[next_slot]->getVIN();
				if (vin == tempvin) {
					// We found the record to be deleted
					delete table[next_slot];
					table[next_slot] = NULL_record;
					return true;
				}
				else {
					// Keep searching
					next_slot = (hash_value + attempt * attempt) % hashSize;
					attempt++;
					num_collisions++;
				}
			}
		}
	}
	return true;
}

bool MyHash::search(std::string vin)
{
	//TODO
}

MyCar* MyHash::find(std::string vin)
{
	num_operations += 1;
	char vin_ptr[20];
	strcpy_s(vin_ptr, vin.c_str());
	int hash_value = hash_str(vin_ptr) % hashSize;
	std::string tempvin;
	int done = 0;
	int attempt = 1;
	int next_slot = hash_value;
	while (done == 0) {
		if (table[next_slot] == NULL) {
			// We hit empty slot, so VIN does not exist
			return NULL;
		}
		else {
			if (table[next_slot] == NULL_record) {
				// We hit a NULL Record, keep searching
				next_slot = (hash_value + attempt * attempt) % hashSize;
				attempt = attempt + 1;
			}
			else {
				tempvin = table[next_slot]->getVIN();
				if (vin == tempvin) {
					return table[next_slot];
				}
				else {
					// Keep searching
					next_slot = (hash_value + attempt * attempt) % hashSize;
					attempt++;
				}
			}
		}
	}
}

void MyHash::printAll()
{
	// We use libary function std::hash to find integer hash value and use modulo operator to restrict to size of table
	int i = 0;
	while (i < hashSize)
	{
		//std::cout << i << "\n";
		if (table[i] == NULL) {
			std::cout << i << " is empty slot\n";
		}
		else if (table[i] == NULL_record){
		std::cout << i << " is deleted record\n";
		}
		else {
			std::cout << "Slot " << i << ": " << table[i]->printCar() << std::endl;
		}
		i++;
	}
}

void MyHash::efficiency_stats() {
	std::cout << "Number of Operations: " << num_operations << "\n";
	std::cout << "Number of Collisions: " << num_collisions << "\n";
	if (num_operations != 0) {
	   std::cout << "Average Number of Collisions as a %: " << 100 * num_collisions / num_operations << "\n";
    }
	else {
		std::cout << "Average Number of Collisions can't be calculated ad num_operations are zero %:\n";
	}

}
unsigned MyHash::hash_str(const char* s)
{
	unsigned h = FIRSTH;
	while (*s) {
		h = (h * A) ^ (s[0] * B);
		s++;
	}
	return h % hashSize;
}
#endif /* hash_h */