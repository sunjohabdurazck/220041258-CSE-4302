#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string licensePlate;
    string manufacturer;
    double carriageSizeLimit;

public:
    Vehicle(string lp, string manu, double csl)
        : licensePlate(lp), manufacturer(manu), carriageSizeLimit(csl) {}

    virtual void maintenance() = 0;
};

class GasolineVehicle : public Vehicle {
protected:
    double fuelTankCapacity;
    string fuelType;

public:
    GasolineVehicle(string lp, string manu, double csl, double ftc, string ft)
        : Vehicle(lp, manu, csl), fuelTankCapacity(ftc), fuelType(ft) {}
};

class Motorcycle : public GasolineVehicle {
public:
    Motorcycle(string lp, string manu, double csl, double ftc, string ft)
        : GasolineVehicle(lp, manu, csl, ftc, ft) {}

    void maintenance() override {
        cout << "Motorcycle - maintenance" << endl;
    }
};

class Car : public GasolineVehicle {
    int passengerCapacity;

public:
    Car(string lp, string manu, double csl, double ftc, string ft, int pc)
        : GasolineVehicle(lp, manu, csl, ftc, ft), passengerCapacity(pc) {}

    void maintenance() override {
        cout << "Car - maintenance" << endl;
    }
};

class Truck : public GasolineVehicle {
    double cargoCapacity;

public:
    Truck(string lp, string manu, double csl, double ftc, string ft, double cc)
        : GasolineVehicle(lp, manu, csl, ftc, ft), cargoCapacity(cc) {}

    void maintenance() override {
        cout << "Truck - maintenance" << endl;
    }
};

class ElectricVehicle : public Vehicle {
protected:
    double batteryCapacity;
    int chargingTime;

public:
    ElectricVehicle(string lp, string manu, double csl, double bc, int ct)
        : Vehicle(lp, manu, csl), batteryCapacity(bc), chargingTime(ct) {}

    void maintenance() override {
        cout << "Electric Vehicle - maintenance" << endl;
    }
};

class HybridVehicle : public GasolineVehicle, public ElectricVehicle {
    double energyRegenEfficiency;

public:
    HybridVehicle(string lp, string manu, double csl, double ftc, string ft,
                  double bc, int ct, double ere)
        : GasolineVehicle(lp, manu, csl, ftc, ft), ElectricVehicle(lp, manu, csl, bc, ct),
          energyRegenEfficiency(ere) {}

    void maintenance() override {
        cout << "Hybrid Vehicle - maintenance" << endl;
    }
};

class Employee {
protected:
    string name;
    int id;

public:
    Employee(string n, int i) : name(n), id(i) {}
    virtual void introduce() = 0;  // Pure virtual function
};

class Manager : public Employee {
public:
    Manager(string n, int i) : Employee(n, i) {}

    void introduce() override {
        cout << "Mr. " << name << endl;
    }
};

class Driver : public Employee {
public:
    Driver(string n, int i) : Employee(n, i) {}

    void introduce() override {
        cout << name << endl;
    }
};

class Branch {
    Motorcycle motorcycles[10];
    Car cars[10];
    Truck trucks[10];
    ElectricVehicle electricVehicles[10];
    HybridVehicle hybridVehicles[10];
    Manager managers[10];
    Driver drivers[10];
class Motorcycle {
public:
    Motorcycle() = default; // Default constructor
    Motorcycle(string lp, string manu, double csl, double ftc, string ft)
        : licensePlate(lp), manufacturer(manu), carriageSizeLimit(csl), fuelTankCapacity(ftc), fuelType(ft) {}

    void maintenance() override {
        cout << "Motorcycle - maintenance" << endl;
    }
};

// Similarly define default constructors for other classes as needed

public:
    Branch() {
        for (int i = 0; i < 10; ++i) {
            motorcycles[i] = Motorcycle("LP" + to_string(i), "Yamaha", 150, 10, "Petrol");
            cars[i] = Car("LP" + to_string(i + 10), "Toyota", 1000, 50, "Petrol", 5);
            trucks[i] = Truck("LP" + to_string(i + 20), "Ford", 5000, 100, "Diesel", 2000);
            electricVehicles[i] = ElectricVehicle("LP" + to_string(i + 30), "Tesla", 1000, 75, 60);
            hybridVehicles[i] = HybridVehicle("LP" + to_string(i + 40), "Toyota", 1200, 40, "Petrol", 50, 45, 85.0);
            managers[i] = Manager("Manager" + to_string(i), i);
            drivers[i] = Driver("Driver" + to_string(i), i + 10);
        }
    }

    void introduceEmployees() {
        cout << "Managers:" << endl;
        for (int i = 0; i < 10; ++i) {
            managers[i].introduce();
        }
        cout << "Drivers:" << endl;
        for (int i = 0; i < 10; ++i) {
            drivers[i].introduce();
        }
    }

    void performMaintenance() {
        cout << "Performing maintenance on all vehicles:" << endl;
        for (int i = 0; i < 10; ++i) {
            motorcycles[i].maintenance();
            cars[i].maintenance();
            trucks[i].maintenance();
            electricVehicles[i].maintenance();
            hybridVehicles[i].maintenance();
        }
    }
};
no

int main() {
    Branch branch;
    branch.introduceEmployees();
    branch.performMaintenance();
    return 0;
}
