#pragma once

#include <string>

class Vehicle {
    protected:
	std::string make;
	std::string model;
	int year;

	std::string fuelType;
	double fuel;
	double maxFuel;
	double mpg;

    public:
	// constructor
	Vehicle(std::string make, std::string model, int year, std::string fuelType, double fuel,
		double maxFuel, double mpg);

	// creating a destructor
	// and also making polymorphic deletion safe (virtual)
	virtual ~Vehicle() = default;

	// setters
	void setMake(std::string &make);
	void setModel(std::string &model);
	void setYear(int year);
	void setFuelType(std::string &fuelType);
	void setFuel(double fuel);
	void setMaxFuel(double maxFuel);
	void setMpg(double mpg);

	// getters
	std::string getMake() const;
	std::string getModel() const;
	int getYear() const;
	std::string getFuelType() const;
	double getFuel() const;
	double getMaxFuel() const;
	double setMpg() const;

	// functions
	void printBasicDesc() const;
	virtual void printInfo() const;
};
