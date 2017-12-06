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

class MyHash
{
private:
	MyCar** table;
	int hashSize;
	
public:
	MyHash(int);
	//~MyHash();
	void add(std::string, MyCar*);
	//void remove(MyCar*);
};

//Default Constructor
MyHash::MyHash(int n)
{
	table = new MyCar*[n];
	hashSize = n;
}

void MyHash::add(std::string key, MyCar* value)
{
	// We use libary function std::hash to find integer hash value and use modulo operator to restrict to size of table
	std::hash<char*> ptr_hash;
	char key_ptr[1024];
	strcpy_s(key_ptr, key.c_str());
	int hash_value = ptr_hash(key_ptr) % hashSize;
	table[hash_value] = value;
}

#endif /* hash_h */

