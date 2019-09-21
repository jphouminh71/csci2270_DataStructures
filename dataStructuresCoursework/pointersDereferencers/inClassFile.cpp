#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

void passByValue(int a )
{
  a++;
}
void passByPointer(int* ptr)
{
  cout << "address stored in  ptr: " << ptr << endl;
  *ptr = *ptr + 1;
  (*ptr)++;
}
void passByReference(&array[])
{

}
int main(int argc, char* argv[])
{
  int a = 5;
  int* b = &a;
  // passByValue(a);
  // passByPointer(b);

  int arrayA[5];
  cout << a << endl; // gives 0th index array's ADDRESS



  // Pointer arrays
  // *(argv+1) is equivalent to argg[1]   // this will give you the content of position 1.

  // BELOW THIS IS IMPORTANT, ITS THE EXPLANATION TO HOW THE COMMAND LINE TAKES IN ARGUEMNTS.

  // if (argc < 4)
  // {
  //   cout << "not enough arguments"  << endl;
  //   return -1;
  // }
  // cout << argv[0] << "<<" << endl;
  // cout << "The program is: " << argv[0] << endl;
  // cout << "The filename is: " << argv[1] << endl;
  // cout << "Your name is: " << argv[2] << endl;
  // cout << "your year is: " << argv[3] << endl;
}
