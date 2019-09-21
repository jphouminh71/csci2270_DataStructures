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
double Complex::getReal()
{
  return real;
}
double Complex::getImag()
{
  return imag;
}
void Complex::setReal(double givenReal)
{
  real = givenReal;
}
void Complex::setImag(double givenImag)
{
  imag = givenImag;
}
Complex Complex::add(Complex &complexOther)
{
  Complex complexSum;
  complexSum.real = real + complexOther.getReal();
  complexSum.imag = imag + complexOther.getImag();
  return complexSum;
}
Complex Complex::subtract(Complex &complexOther)
{
  Complex complexDifference;
  complexDifference.real = real - complexOther.getReal();
  complexDifference.imag = imag - complexOther.getImag();
  return complexDifference;
}
