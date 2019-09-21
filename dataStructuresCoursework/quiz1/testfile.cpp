#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int insertInArray(int list[], int size, int* numItems, int index, int newVal)
{
    for (int i = 0; i<size;i++)
    {
      cout << list[i] << endl;
    }
    cout << "ABOVE IS JUST THE ARRAY ELEMENTS" << endl;


    // if(numItems == size)
    // {
    //     return -1;
    // }
    // for(int i = size; i > index; i--)
    // {
    //     list[i] = list[i-i];
    // }
    // list[index] = newVal;
    // numItems++;
    return 0;
}

int main(int argc, char* argv[])
{
  int size = 10;
  int sampleArray[size];
  int index = 4;
  int newVal = 0;

  for (int i = 0; i < 4; i++)
  {
    sampleArray[i] = i+1;
  }
  for (int i = 0; i < 4; i++)
  {
    cout << sampleArray[i] << endl;
    cout << &sampleArray[i] << endl;
  }
  //insertInArray(sampleArray, size, ptr,index, newVal);
  return 0;
}
