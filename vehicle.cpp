#include "vehicle.h"
#include <iostream>

Vehicle::Vehicle(std::string make, std::string model, int year, std::string fuelType, double fuel,
		 double maxFuel, double mpg)
	: make(make)
	, model(model)
	, year(year)
	, fuelType(fuelType)
	, fuel(fuel)
	, maxFuel(maxFuel)
	, mpg(mpg)
{
}

// setters
void Vehicle::setMake(std::string &make)
{
	this->make = make;
}
void Vehicle::setModel(std::string &model)
{
	this->model = model;
}
void Vehicle::setYear(int year)
{
	this->year = year;
}
void Vehicle::setFuelType(std::string &fuelType)
{
	this->fuelType = fuelType;
}
void Vehicle::setFuel(double fuel)
{
	this->fuel = fuel;
}
void Vehicle::setMaxFuel(double maxFuel)
{
	this->maxFuel = maxFuel;
}
void Vehicle::setMpg(double mpg)
{
	this->mpg = mpg;
}

// getters
std::string Vehicle::getMake() const
{
	return make;
}
std::string Vehicle::getModel() const
{
	return model;
}
int Vehicle::getYear() const
{
	return year;
}
std::string Vehicle::getFuelType() const
{
	return fuelType;
}
double Vehicle::getFuel() const
{
	return fuel;
}
double Vehicle::getMaxFuel() const
{
	return maxFuel;
}
double Vehicle::setMpg() const
{
	return mpg;
}

// functions
void Vehicle::printBasicDesc() const
{
	std::cout << year << ", " << make << ", " << model << ", Gas: " << fuel << "/" << maxFuel
		  << ", mpg:" << mpg << std::endl;
	std::cout << "--------\n";
}

// virtual only goes in declaration in the class, should be the same for override
void Vehicle::printInfo() const
{
	std::cout << "Make: " << make << std::endl;
	std::cout << "Model" << model << std::endl;
	std::cout << "Year" << year << std::endl;
	std::cout << "Fuel Type: " << fuelType << std::endl;
	std::cout << "Max Fuel: " << maxFuel << std::endl;
	std::cout << "Fuel: " << fuel << std::endl;
	std::cout << "MPG: " << mpg << std::endl;
}
