// file Complex.cpp
#include "Complex.hpp"
#include <iostream>

Complex::Complex()
{

}

void Complex::setData(double _real, double _imag)
{
  real = _real;
  imag = _imag;
}
void Complex::printComplexNumber()
{
   std::cout << "(" << real << "," << imag << "i)" << std::endl;
}
