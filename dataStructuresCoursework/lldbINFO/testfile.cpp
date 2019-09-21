#include <iostream>

using namespace std;

int add(int x, int y)
{
  int sum = x + y;
  return sum;
}
int main()
{
  int x, y;
  cout << "Enter values" << endl;
  x = 2;
  x = 3;
  int sum = add(x,y);
  if (sum == 5)
  {
    cout << "function works" << endl;
  }
  else if (sum != 5)
  {
    cout << "function doesn't work" << endl;
  }
}
