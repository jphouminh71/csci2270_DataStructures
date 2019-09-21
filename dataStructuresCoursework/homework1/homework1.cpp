// still have to figure out sorting after you put it in
// first worry about implementing more user input
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;
void printArray(int myArray[], int size){
  cout << "ARRAY SIZE: " << size << endl;
  for (int i = 0; i < size; i++){
    if (i == size-1){
      cout << myArray[i];
    }
    else if (i < size-1){
      cout << myArray[i] << ',';
    }
  }
  cout << endl;
}
int insertIntoSortedArray(int myArray[], int size, int newValue){   // sorts and keeps everything in
//cout<< "inserting:"<< newValue<<endl;
  if (size == 0){         // this is to handle the first value
    myArray[0] = newValue;
    size++;
  }
  else{
    int index=-1;
    for (int i = 0; i < size; i++)
    {
      //cout<< "a["<<i<<"]=="<< myArray[i]<<endl;

      if(newValue < myArray[i])
      {
          index = i;
          //cout<< "stoping at :"<< index;
          break;
      }
    }
    if(index == -1)
    {
      myArray[size] = newValue;
    }
    else{
      for(int j=size-1; j>= index;j--)
      {
          myArray[j+1] = myArray[j];
      }
      myArray[index] = newValue;
    }

    size++;
  }

  return size;
}

void openFile(string filename){
  ifstream infile;
  infile.open(filename);
  if (infile.is_open()){
    cout << "File name: " << filename << endl;
    int entryArray[100];
    int numOfEntries = 0;
    string line;
    while (getline(infile,line))
    {
      int value = stoi(line);
      numOfEntries = insertIntoSortedArray(entryArray,numOfEntries,value);
    }
    printArray(entryArray,numOfEntries);
    cout << "Enter a number: " << endl;
    int input;
    bool found = false;
    cin >> input;
    for (int i = 0; i < numOfEntries; i++){
      if (entryArray[i] == input){
        cout << "POSITION: " << i << endl;
        found = true;
      }
    }
    if (found == false){
      cout << "Number not found." << endl;
    }
  }
  infile.close();

}
int main(int argc, char* argv[]){
  openFile(argv[1]);

  return 0;
}
