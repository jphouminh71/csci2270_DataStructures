#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int sum(int num)
{
  if (num!=0)
  {
    return (num + sum(num-1));
  }
  else{
    return num;
  }
}

int main(int argc, char* argv[])
{
  int n;
  cout << "Enter number for which you want the sum of natural numbers to be calculated: ";
  cin >> n;
  int total = sum(n);
  cout << endl << "Sum of natural numbers from 1 to " << n << " are: " << total << endl;
  return 0; 
}
