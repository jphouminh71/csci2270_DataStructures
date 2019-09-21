//file Main.cpp
#include "Complex.hpp"
#include <iostream>

using namespace std;
int main()
{
  Complex c1,c2; // Objects of “complex” class
  c1.setData(2, 3);
  c2.setData(14.3, 22.1);

  cout << "First complex: "; c1.printComplexNumber();
  cout << "Second complex: ";c2.printComplexNumber();
  return 0;
}
