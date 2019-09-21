#include <iostream>
#include <cmath>
#include <string>
using namespace std;
void printList(int myArray[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << myArray[i] << ' ' << endl;
  }
}
int main(int argc, char* argv[])
{
  int size = 7;
  int myArray[size] = {9,4,7,2,8,3,5};
  printList(myArray,size);
}
