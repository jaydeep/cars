//
//  hash.h
//  cis22c_final_project_js
//
//  Created by Jaydeep Singh on 11/21/17.
//  Copyright © 2017 DeAnza. All rights reserved.
//
#ifndef hash_h
#define hash_h
#include <string>
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
	
public:
	MyHash();
	MyHash(int);
	//~MyHash();
	void add(MyCar*);
	bool remove(std::string);
	int find_empty_slot(unsigned);
	void print(std::string);
	void printAll();
	unsigned hash_str(const char* s);

};

//Default Constructor
MyHash::MyHash()
{
	table = new MyCar*[1];
	NULL_record = new MyCar("X", "Y", "Z", "0000");
	hashSize = 1;
	table[0] = NULL;
}
//Default Constructor
MyHash::MyHash(int hash_size)
{
	table = new MyCar*[hash_size];
	NULL_record = new MyCar("X", "Y", "Z", "0000");
	hashSize = hash_size;
	int i = 0;
	while (i < hashSize) {
		//std::cout << i << "\n";
		table[i] = NULL;
		i++;
	}
}

void MyHash::add(MyCar* value)
{
	std::string  vin = value->getVIN();
	std::hash<char*> ptr_hash;
	char vin_ptr[20];
	strcpy_s(vin_ptr, vin.c_str());
	unsigned hash_value = hash_str(vin_ptr);
	int myslot = find_empty_slot(hash_value);
	if (myslot > 0) {
	    std::cout << "slot= " << myslot << " vin= " << vin << "\n";
	    table[myslot] = value;
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
			}
		}
	}
	return -1;
}

bool MyHash::remove(std::string vin)
{
	std::hash<char*> ptr_hash;
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
				}
			}
		}
	}
	return true;
}

void MyHash::print(std::string vin)
{
	std::hash<char*> ptr_hash;
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
			std::cout << "VIN does not exist " << vin << "slot = " << next_slot;
			return;
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
					// We found the record to be printed
					std::cout << "VIN exists in " << vin << "slot = " << next_slot << "\n";
					table[next_slot]->printCar();
					return;
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
		if (table[i] != NULL && table[i] != NULL_record)
		{
			table[i]->printCar();
		}

		i++;
	}
}
unsigned MyHash::hash_str(const char* s)
{
	unsigned h = FIRSTH;
	while (*s) {
		h = (h * A) ^ (s[0] * B);
		s++;
	}
	return h % hashSize; // or return h % C;
}
#endif /* hash_h */