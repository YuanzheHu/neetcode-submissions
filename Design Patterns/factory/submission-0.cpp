#include <iostream>
#include <string>
using namespace std;

// 抽象产品
class Vehicle {
public:
    virtual string getType() = 0;
    virtual ~Vehicle() = default;  // 注意加虚析构函数
};

// 具体产品
class Car : public Vehicle {
public:
    string getType() override {
        return "Car";
    }
};

class Bike : public Vehicle {
public:
    string getType() override {
        return "Bike";
    }
};

class Truck : public Vehicle {
public:
    string getType() override {
        return "Truck";
    }
};

// 抽象工厂
class VehicleFactory {
public:
    virtual Vehicle* createVehicle() = 0;
    virtual ~VehicleFactory() = default;
};

// 具体工厂
class CarFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        return new Car();  // 返回具体产品
    }
};

class BikeFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        return new Bike();
    }
};

class TruckFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        return new Truck();
    }
};
