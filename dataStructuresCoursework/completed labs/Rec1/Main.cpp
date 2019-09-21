//file Main.cpp
#include "Complex.hpp"
#include <iostream>

using namespace std;
int main(int argc, char* argv[])  // argc = number other one is array of argc
{

  Complex c1,c2; // Objects of “complex” class
  c1.setData(2, 3);
  c2.setData(14.3, 22.1);

  // command line arguments
  Complex c3;
  c3.setReal(stod(argv[1]));
  c3.setImag(stod(argv[2]));
  c3.printComplexNumber();
  cout << "^^^^^^^" << endl;


  cout << "First complex: "; c1.printComplexNumber();
  cout << "Second complex: ";c2.printComplexNumber();

  cout << "C1 Real: " << c1.getReal() << endl;
  cout << "C1. Imag: " << c1.getImag() << endl;

  //testSetters
  c1.setReal(3);
  c1.setImag(5);
  c1.printComplexNumber();

  //additem
  Complex sum = c1.add(c2);
  sum.printComplexNumber();

  // subtract additem
  Complex diff = c1.subtract(c2);
  diff.printComplexNumber();

  return 0;
}
