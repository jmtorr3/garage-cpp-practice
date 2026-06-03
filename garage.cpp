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
	double mpg;

    public:
	Vehicle(std::string make, std::string model, int year, std::string fuelType, double fuel,
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
	void setMpg(double mpg)
	{
		this->mpg = mpg;
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
	void printBasicDesc() const
	{
		std::cout << year << ", " << make << ", " << model << ", Gas: " << fuel << "/"
			  << maxFuel << ", mpg:" << mpg << std::endl;
		std::cout << "--------\n";
	}
	virtual void printInfo() const
	{
		std::cout << "Make: " << make << std::endl;
		std::cout << "Model" << model << std::endl;
		std::cout << "Year" << year << std::endl;
		std::cout << "Fuel Type: " << fuelType << std::endl;
		std::cout << "Max Fuel: " << maxFuel << std::endl;
		std::cout << "Fuel: " << fuel << std::endl;
		std::cout << "MPG: " << mpg << std::endl;
	}
};

class Car : public Vehicle {
    private:
	int doors;

    public:
	Car(std::string make, std::string model, int year, std::string fuelType, double fuel,
	    double maxFuel, double mpg, int doors)
		: Vehicle(make, model, year, fuelType, fuel, maxFuel, mpg)
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
	      double maxFuel, double mpg, int engines)
		: Vehicle(make, model, year, fuelType, fuel, maxFuel, mpg)

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
		/* std::move means to treat this as an
		 * object whose resources (heap allocated car object)
		 * can be transferred elsewhere
		 * so basically...
		 * we're telling the compiler:
		 * vehicle is giving up ownership of this object and transfering
		 * to the vector vehicles[0]*/
		vehicles.push_back(std::move(vehicle));
	}
	void printVehicles()
	{
		for (const auto &vehicle : vehicles) {
			vehicle->printBasicDesc();
		}
	}
};

void drive()
{
}

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
		double mpg;

		std::cout << "1. Add Car\n";
		std::cout << "2. Add Plane\n";
		std::cout << "3. Print Garage\n";
		std::cout << "4. Exit\n";
		std::cout << "Choice: ";
		std::cin >> choice;

		switch (choice) {
		case 1: {
			std::cout << "Make: ";
			std::cin >> make;

			std::cout << "Model: ";
			std::cin >> model;

			std::cout << "Year: ";
			std::cin >> year;

			while (true) {
				std::cout << "Fuel Type:\n";
				std::cout << "1. Regular\n";
				std::cout << "2. Premium\n";
				int choice2;
				std::cin >> choice2;
				switch (choice2) {
				case 1:
					fuelType = "Regular";
					break;

				case 2:
					fuelType = "Premium";
					break;

				default:
					std::cout << "invalid choice";
					continue;
					// goes back to switch statment
				}
				break;
			}

			std::cout << "Fuel Amount: ";
			std::cin >> fuel;

			//keep on forgetting that do while loops are a thing lol
			do {
				std::cout << "Max Fuel Amount: ";
				std::cin >> maxFuel;
				if (maxFuel < fuel) {
					std::cout
						<< "Max fuel cannot be less than actual fuel amount"
						<< std::endl;
				}
			} while (maxFuel < fuel);

			std::cout << "MPG: ";
			std::cin >> mpg;

			int doors;
			std::cout << "Number of doors: ";
			std::cin >> doors;

			garage.addVehicle(std::make_unique<Car>(make, model, year, fuelType, fuel,
								maxFuel, mpg, doors));

			break;
		}

		case 2: {
			std::cout << "Make: ";
			std::cin >> make;

			std::cout << "Model: ";
			std::cin >> model;

			std::cout << "Year: ";
			std::cin >> year;

			while (true) {
				std::cout << "Fuel Type:\n";
				std::cout << "1. Regular\n";
				std::cout << "2. Premium\n";
				int choice2;
				std::cin >> choice2;
				switch (choice2) {
				case 1:
					fuelType = "Regular";
					break;

				case 2:
					fuelType = "Premium";
					break;

				default:
					std::cout << "invalid choice";
					continue;
					// goes back to switch statment
				}
				break;
			}

			std::cout << "Fuel Amount: ";
			std::cin >> fuel;

			//keep on forgetting that do while loops are a thing lol
			do {
				std::cout << "Max Fuel Amount: ";
				std::cin >> maxFuel;
				if (maxFuel < fuel) {
					std::cout
						<< "Max fuel cannot be less than actual fuel amount"
						<< std::endl;
				}
			} while (maxFuel < fuel);

			std::cout << "MPG: ";
			std::cin >> mpg;

			int engines;
			std::cout << "Number of engines: ";
			std::cin >> engines;

			garage.addVehicle(std::make_unique<Plane>(make, model, year, fuelType, fuel,
								  maxFuel, mpg, engines));

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
			std::cout << "!-----------!" << std::endl;
			std::cout << "Invalid input" << std::endl;
			std::cout << "!-----------!" << std::endl;
			continue;
		}
		}
	}
}
