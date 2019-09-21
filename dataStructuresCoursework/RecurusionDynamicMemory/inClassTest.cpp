#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void calculateCost(int count, float& subTotal, float& taxCost)
{
  if (count < 10)
  {
    subTotal = count * 0.50;
  }
  else
  {
    subTotal = count * 0.20;
  }
  taxCost = 0.1 * subTotal;
}
int main()
{
  // float tax = 0.0,
  //   subTotal = 0.0;
  //
  // calculateCost(15,subTotal,tax);
  // cout << "The cost for 15 items is " << subTotal << ",and the tax for" << subTotal << "is " << tax << endl;

  double var = 3.79887080535;

  double* address = &var;

  cout << * address << endl;
}
// int factorial(int x)
// {
//   if ( x == 0)
//   {
//     return 1;
//   }
//   else
//   {
//     return x * factorial(x-1);
//   }
// }
//
//
//
// int main(int argc, char* argv[])
// {
//   int y = factorial(3);
//   //cout << y << "<<" << endl;
//
// }
