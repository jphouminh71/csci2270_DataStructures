#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class Complex
{
  private:
     double real;
     double imag;
  public:
	Complex( );
 	void setData(double _real, double _imag);
 	void printComplexNumber();
};
#endif
