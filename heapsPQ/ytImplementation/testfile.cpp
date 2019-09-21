#include <iostream>
#include <cstdlib>
using namespace std;

void swap(int (&myArray)[2], int size){
  int temp = myArray[0];
  myArray[0] = myArray[1];
  myArray[1] = temp;

}
void print(int myArray[], int size){
  for(int i = 0; i < size; i++){
    cout << myArray[i] << ' ';
  }
  cout << endl;
}

int main(int argc, char* argv[]){
  int array[] = {1, 2};
  int size = 2;
  swap(array, size);
  print(array, size);
  return 0;
}
