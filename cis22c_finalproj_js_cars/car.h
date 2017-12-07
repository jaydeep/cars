//
//  car.h
//  cis22c_final_project_js
//
//  Created by Jaydeep Singh on 11/21/17.
//  Copyright © 2017 DeAnza. All rights reserved.
//
#ifndef car_h
#define car_h
#include <string>

class MyCar
{
private:
	std::string VIN;
	std::string make;
	std::string model;
	std::string year;

public:
	MyCar(std::string, std::string, std::string, std::string);

	~MyCar();
	std::string getVIN();
	std::string getMake();
	std::string getModel();
	std::string getYear();
	std::string printCar();

};

//Default Constructor
MyCar::MyCar(std::string myVIN, std::string mymake, std::string mymodel, std::string myyear)
{
	VIN = myVIN;
	make = mymake;
	model = mymodel;
	year = myyear;

}



//get VIN
std::string MyCar::getVIN()
{
	return VIN;
}

//get year
std::string MyCar::getYear()
{
	return year;
}

//get make
std::string MyCar::getMake()
{
	return make;
}
//get Model
std::string MyCar::getModel()
{
	return model;
}

std::string MyCar::printCar()
{
	return  VIN + " " + make + " " + model + " " + year;
}

MyCar::~MyCar(){
	delete this;
}
#endif /* car_h */

#pragma once
