// file Complex.hpp
#ifndef COMPLEX_HPP
#define COMPLEX_HPP // the reason we do this is because we already included this

class Complex
{
  private:
     double real;
     double imag;
  public:
	   Complex( );
 	   void setData(double _real, double _imag);
 	   void printComplexNumber();
     double getReal();
     double getImag();
     void setReal(double);
     void setImag(double);
     Complex add(Complex &complexOther);
     Complex subtract(Complex &complexOther);

};
#endif
