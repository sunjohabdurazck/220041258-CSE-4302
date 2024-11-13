#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Vehicle {
protected:
    string licensePlate;
    string manufacturer;
    int carriageSizeLimit;

public:
    Vehicle(const string& plate, const string& maker, int sizeLimit)
        : licensePlate(plate), manufacturer(maker), carriageSizeLimit(sizeLimit) {}

    virtual ~Vehicle() {}

    virtual void performMaintenance() = 0;

    string getLicensePlate() const { return licensePlate; }
    string getManufacturer() const { return manufacturer; }
    int getCarriageSizeLimit() const { return carriageSizeLimit; }


     virtual void displayInfo() const {
        cout << "License Plate: " << licensePlate << "\nManufacturer: " << manufacturer
             << "\nCarriage Size Limit: " << carriageSizeLimit << " kg" << endl;
    }

};


class GasolineVehicle : public Vehicle {
protected:
    double fuelTankCapacity;
    string fuelType;

public:
    GasolineVehicle(const string& plate, const string& maker, int sizeLimit,
                    double tankCapacity, const string& fuel)
        : Vehicle(plate, maker, sizeLimit), fuelTankCapacity(tankCapacity), fuelType(fuel) {}

    virtual double calculateFuelConsumption(double distance) {
        const double fuelEfficiency = 10.0;
        return distance / fuelEfficiency;
    }

    virtual void performMaintenance() override {
        cout << "Performing maintenance on gasoline vehicle\n";
    }



     void displayInfo() const override {
        Vehicle::displayInfo();
        cout << "Fuel Tank Capacity: " << fuelTankCapacity << " liters\nFuel Type: " << fuelType << endl;
    }

};

class ElectricVehicle : public Vehicle {
protected:
    double batteryCapacity;
    int chargingTime;

public:
    ElectricVehicle(const string& plate, const string& maker, int sizeLimit,
                    double batteryCap, int chargeTime)
        : Vehicle(plate, maker, sizeLimit), batteryCapacity(batteryCap), chargingTime(chargeTime) {}

    double electricityConsumption(double distance) {
        const double energyEfficiency = 6.0;
        return distance / energyEfficiency;
    }

    virtual void performMaintenance() override {
        cout << "Performing maintenance on electric vehicle\n";
    }
     void displayInfo() const override {
        Vehicle::displayInfo();
        cout << "Battery Capacity: " << batteryCapacity << " KWh, Charging Time: " << chargingTime << " minutes" << endl;
    }
};



class Motorcycle : public GasolineVehicle {
public:
    Motorcycle(const string& plate, const string& maker, int sizeLimit, double tankCapacity, const string& fuel)
        : GasolineVehicle(plate, maker, sizeLimit, tankCapacity, fuel) {}

    double calculateFuelConsumption(double distance) override {
        const double fuelEfficiency = 25.0;
        return distance / fuelEfficiency;
    }

    void performMaintenance() override {
        cout << "Motorcycle - maintenance\n";
    }
};


class Car : public GasolineVehicle {
private:
    int passengerCapacity;

public:
    Car(const string& plate, const string& maker, int sizeLimit, double tankCapacity, const string& fuel, int capacity)
        : GasolineVehicle(plate, maker, sizeLimit, tankCapacity, fuel), passengerCapacity(capacity) {}

    double calculateFuelConsumption(double distance) override {
        const double fuelEfficiency = 12.0;
        return distance / fuelEfficiency;
    }

    void performMaintenance() override {
        cout << "Car - maintenance\n";
    }

    void displayInfo() const override {
        GasolineVehicle::displayInfo();
        cout << "Passenger Capacity: " << passengerCapacity << endl;
    }

};



class Truck : public GasolineVehicle {
private:
    double cargoCapacity;

public:
    Truck(const string& plate, const string& maker, int sizeLimit, double tankCapacity, const string& fuel, double cargo)
        : GasolineVehicle(plate, maker, sizeLimit, tankCapacity, fuel), cargoCapacity(cargo) {}

    double calculateFuelConsumption(double distance) override {
        const double fuelEfficiency = 8.0;
        return distance / fuelEfficiency;
    }

    void performMaintenance() override {
        cout << "Truck - maintenance\n";
    }

     void displayInfo() const override {
        GasolineVehicle::displayInfo();
        cout << "Cargo Capacity: " << cargoCapacity << " kg" << endl;
    }
};


class HybridVehicle : public Vehicle, public GasolineVehicle, public ElectricVehicle {
private:
    double energyRegenerationEfficiency;

public:
    HybridVehicle(string licensePlate, string manufacturer, double carriageSizeLimit, double fuelTankCapacity, string fuelType,
                  double batteryCapacity, int chargingTime, double energyRegenerationEfficiency)
        : Vehicle(licensePlate, manufacturer, carriageSizeLimit),
          GasolineVehicle(licensePlate, manufacturer, carriageSizeLimit, fuelTankCapacity, fuelType),
          ElectricVehicle(licensePlate, manufacturer, carriageSizeLimit, batteryCapacity, chargingTime),
          energyRegenerationEfficiency(energyRegenerationEfficiency) {}

    void performMaintenance() const {
        cout << "Hybrid Vehicle - Maintenance includes both fuel and electric systems check." << endl;
    }

    double calculateFuelConsumption(double distance) const {
        double fuelPart = calculateFuelConsumption(distance * (1 - energyRegenerationEfficiency));
        return fuelPart;
    }

    void displayInfo() const {
        cout << "Fuel Tank Capacity: " << fuelTankCapacity << " liters, Fuel Type: " << fuelType << endl;
        cout << "Battery Capacity: " << batteryCapacity << " KWh, Charging Time: " << chargingTime << " minutes" << endl;
        cout << "Energy Regeneration Efficiency: " << energyRegenerationEfficiency * 100 << "%" << endl;
    }
};

void sort_vehicles_by_capacity(Vehicle** vehicles, int n) {
    sort(vehicles, vehicles + n, [](Vehicle* v1, Vehicle* v2) {
        return v1->getCarriageSizeLimit() > v2->getCarriageSizeLimit();
    });
}

int main() {
  Motorcycle bike("MOTO123", "Yamaha", 2, 15, "Petrol");
  Car sedan("CAR456", "Toyota", 5, 50, "Petrol", 5);
  Truck freight("TRUCK789", "Ford", 3, 120, "Diesel", 2000);

    Vehicle* vehicles[5];

    vehicles[0] = new Motorcycle("MOTO123", "Yamaha", 200, 15, "Petrol");
    vehicles[1] = new Car("CAR456", "Toyota", 1500, 50, "Petrol", 5);
    vehicles[2] = new Truck("TRUCK789", "Volvo", 5000, 200, "Diesel", 10000);
    vehicles[3] = new ElectricVehicle("EV101", "Tesla", 1200, 100, 45);

    sort_vehicles_by_capacity(vehicles, 5);
    cout << "Vehicles sorted by carriage size limit:" << endl;
    for (int i = 0; i < 5; i++) {
        vehicles[i]->displayInfo();
        vehicles[i]->performMaintenance();
        cout << endl;
    }
    for (int i = 0; i < 5; i++) {
        delete vehicles[i];
    }

    return 0;
}

