#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Vehicle {
	// using protected so that members can access these variables
	// use private only when you want the class to access it
    protected:
	std::string make;
	std::string model;
	int year;

	std::string fuelType;
	double fuel;
	double maxFuel;

    public:
	Vehicle(std::string make, std::string model, int year, std::string fuelType, double fuel,
		double maxFuel)
		: make(make)
		, model(model)
		, year(year)
		, fuelType(fuelType)
		, fuel(fuel)
		, maxFuel(maxFuel)
	{
	}
	// const inside the function means that it promises not to change the value passed in
	void setMake(const std::string &make)
	{
		this->make = make;
	}
	void setModel(const std::string &model)
	{
		this->model = model;
	}
	void setYear(int year)
	{
		this->year = year;
	}
	void setFuelType(const std::string &fuelType)
	{
		this->fuelType = fuelType;
	}
	void setFuel(double fuel)
	{
		this->fuel = fuel;
	}
	void setMaxFuel(double maxFuel)
	{
		this->maxFuel = maxFuel;
	}

	// const next to a function means that the function promises not to modify the object
	std::string getMake() const
	{
		return make;
	}
	std::string getModel() const
	{
		return model;
	}
	int getYear() const
	{
		return year;
	}
	std::string getFuelType() const
	{
		return fuelType;
	}
	int getFuel() const
	{
		return fuel;
	}
	int getMaxFuel() const
	{
		return maxFuel;
	}
	virtual void printInfo() const
	{
		std::cout << "Make: " << make << std::endl;
		std::cout << "Model" << model << std::endl;
		std::cout << "Year" << year << std::endl;
		std::cout << "Fuel Type: " << fuelType << std::endl;
		std::cout << "Max Fuel: " << maxFuel << std::endl;
		std::cout << "Fuel: " << fuel << std::endl;
	}
};

class Car : public Vehicle {
    private:
	int doors;

    public:
	Car(std::string make, std::string model, int year, std::string fuelType, double fuel,
	    double maxFuel, int doors)
		: Vehicle(make, model, year, fuelType, fuel, maxFuel)
		, doors(doors)
	{
	}
	void setDoors(int doors)
	{
		this->doors = doors;
	}
	int getDoors()
	{
		return doors;
	}

	void printInfo() const override
	{
		std::cout << "Make: " << make << std::endl;
		std::cout << "Model: " << model << std::endl;
		std::cout << "Year: " << year << std::endl;
		std::cout << "Fuel Type: " << fuelType << std::endl;
		std::cout << "Fuel: " << fuel << std::endl;
		std::cout << "Max Fuel: " << maxFuel << std::endl;
		std::cout << "Doors: " << doors << std::endl;
	}
};

class Plane : public Vehicle {
    private:
	int engines;

    public:
	Plane(std::string make, std::string model, int year, std::string fuelType, double fuel,
	      double maxFuel, int engines)
		: Vehicle(make, model, year, fuelType, fuel, maxFuel)

		, engines(engines)
	{
	}
	void setEngines(int engines)
	{
		this->engines = engines;
	}
};

class Garage {
    private:
	std::vector<std::unique_ptr<Vehicle> > vehicles;

    public:
	void addVehicle(std::unique_ptr<Vehicle> vehicle)
	{
		vehicles.push_back(std::move(vehicle));
	}
	void printVehicles()
	{
		for (const auto &vehicle : vehicles) {
			vehicle->printInfo();
		}
	}
};

int main()
{
	Garage garage;
	int choice;
	while (true) {
		std::string make;
		std::string model;
		int year;

		std::string fuelType;
		double fuel;
		double maxFuel;

		std::cout << "1. Add Car\n";
		std::cout << "2. Add Plane\n";
		std::cout << "3. Print Garage\n";
		std::cout << "Choice:";
		std::cin >> choice;

		switch (choice) {
		case 1: {
			std::cout << "Make: ";
			std::cin >> make;

			std::cout << "Model: ";
			std::cin >> model;

			std::cout << "Year: ";
			std::cin >> year;

			std::cout << "Fuel Type: ";
			std::cin >> fuelType;

			std::cout << "Fuel Amount: ";
			std::cin >> fuel;

			std::cout << "Max Fuel Amount: ";
			std::cin >> maxFuel;

			int doors;
			std::cout << "Number of doors: ";
			std::cin >> doors;

			garage.addVehicle(std::make_unique<Car>(make, model, year, fuelType, fuel,
								maxFuel, doors));

			break;
		}

		case 2: {
			garage.printVehicles();
			break;
		}
		case 3: {
			garage.printVehicles();
			break;
		}
		case 4: {
			return 0;
		}
		default: {
			std::cout << "Invalid input" << std::endl;
		}
		}
	}
}
