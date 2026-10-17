class Coffee {
public:
    virtual double getCost() = 0; // Pure virtual function makes this class abstract
};

class SimpleCoffee : public Coffee {
public:
    double getCost() override {
        return 1.1;
    }
};

class CoffeeDecorator : public Coffee {
protected:
    Coffee* decoratedCoffee;

public:
    CoffeeDecorator(Coffee* coffee) : decoratedCoffee(coffee) {}

    double getCost() override {
        return decoratedCoffee->getCost();
    }
};

class MilkDecorator : public CoffeeDecorator {
public:
    // Implement the Milk decorator
    MilkDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}

    double getCost() override {
        return CoffeeDecorator::getCost() + 0.5;
    }
};

class SugarDecorator : public CoffeeDecorator {
public:
    // Implement the Sugar decorator
    SugarDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}

    double getCost() override {
        return CoffeeDecorator::getCost() + 0.2;
    }
};

class CreamDecorator : public CoffeeDecorator {
public:
    // Implement the Cream decorator
    CreamDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}

    double getCost() override {
        return CoffeeDecorator::getCost() + 0.7;
    }
};

// Coffee coffee = new SimpleCoffee();
// coffee.getCost();    // 1.1

// coffee = new MilkDecorator(coffee);
// coffee.getCost();    // 1.6

// coffee = new SugarDecorator(coffee);
// coffee.getCost();    // 1.8

// coffee = new CreamDecorator(coffee);
// coffee.getCost();    // 2.5