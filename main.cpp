#include "DecoratorDesignPattern1.cpp"


int main()
{
  ///Decorator Coffee Example
  Coffee* espresso = new Espresso(); // Create a base Espresso
  espresso = new Milk(espresso); // Added milk to the espresso
  espresso = new Caramel(espresso); // Added caramel on top

  std::cout << "Order: " << espresso->orderInfo() << std::endl; // Display the order information
  std::cout << "Total Price: " << espresso->calculatePrice() << " $" << std::endl; // Display the total price

  delete espresso; // Free allocated memory

  return 0;
}
