//
// Created by utkugokce on 14.12.2023.
//

#include <iostream>
#include <string>

// Base class representing coffee
// Component interface
class Coffee {
public:
  virtual std::string orderInfo() const = 0; // Abstract method for order information
  virtual double calculatePrice() const = 0; // Abstract method for price calculation
  virtual ~Coffee() {} // Virtual destructor
};

// Base decorator class extending the base component
// Decorator
class CoffeeDecorator : public Coffee {
protected:
  Coffee* coffee;
public:
  CoffeeDecorator(Coffee* coffee) : coffee(coffee) {} // Constructor with base coffee

  std::string orderInfo() const override {
    return coffee->orderInfo(); // Calls the base coffee's order information
  }

  double calculatePrice() const override {
    return coffee->calculatePrice(); // Calls the base coffee's price calculation
  }
};

// Class representing the base coffee component - Espresso
// Concrete Component
class Espresso : public Coffee {
public:
  std::string orderInfo() const override {
    return "Espresso"; // Information about Espresso
  }

  double calculatePrice() const override {
    return 2.5; // Base price for Espresso
  }
};

// Decorator class adding milk to the coffee
// Concrete Decorator
class Milk : public CoffeeDecorator {
public:
  Milk(Coffee* coffee) : CoffeeDecorator(coffee) {} // Constructor with base coffee

  std::string orderInfo() const override {
    return coffee->orderInfo() + ", Milk"; // Adds milk to the order information
  }

  double calculatePrice() const override {
    return coffee->calculatePrice() + 0.5; // Adds milk price to the total price
  }
};

// Decorator class adding caramel to the coffee
// Concrete Decorator
class Caramel : public CoffeeDecorator {
public:
  Caramel(Coffee* coffee) : CoffeeDecorator(coffee) {} // Constructor with base coffee

  std::string orderInfo() const override {
    return coffee->orderInfo() + ", Caramel"; // Adds caramel to the order information
  }

  double calculatePrice() const override {
    return coffee->calculatePrice() + 0.75; // Adds caramel price to the total price
  }
};