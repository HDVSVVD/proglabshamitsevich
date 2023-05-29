#include <iostream>

class Square {
protected: double side;

public: Square(double s = 0) : side(s) {}

      double getPerimeter() {
          return 4 * side;
      }

      virtual void printInfo() {
          std::cout << "Square with side " << side << " has a perimeter of " << getPerimeter() << std::endl;
      }
};

class Rectangle : public Square {
private: double other_side;

public: Rectangle(double s = 0, double other = 0) : Square(s), other_side(other) {}

      double getPerimeter() {
          return 2 * side + 2 * other_side;
      }

      virtual void printInfo() {
          std::cout << "Rectangle with sides " << side << " and " << other_side << " has a perimeter of " << getPerimeter() << std::endl;
      }
};

int main() {
    Square s(5.5); Rectangle r(3.2, 7.8);

    s.printInfo();
    r.printInfo();

    Square* ptr1 = &s;
    ptr1->printInfo();

    Square* ptr2 = &r;
    ptr2->printInfo();

    return 0;
}