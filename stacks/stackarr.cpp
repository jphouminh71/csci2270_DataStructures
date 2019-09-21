/* PROGRAM WILL BE A SIMPLE INTEGER BASED SYSTEM REVIEWING STACK DATA STRUCTURES USING vector

  Functions that will be used
    push()
      will take in an integer from main and try to push it to the top of the stack
    pop()
      take the top of the stack and return it
    peek()
      just printing out what is on the top of the stack currently
    isEmpty()
      determining is stack is empty
    isFull()
      determining if stack is full
    printStack()
      print the contents of the stack
    loadStackToCapacity()
      will fill the stack until its full



    End Notes:
        The implementation of a stack in array form is finished, small issue is when inputting a value to push onto the stack it triggers the default case for some reason.

        move onto stack implementation with linked list.
*/
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

const int capacity = 10;   // array stack capped at 10 integers.

class arrStackey{
private:
  int currentSize = 0; // current amount of elements in stack
  int stackey [capacity];   // array for the stack
public:
  bool isEmpty();         // done
  bool isFull();         // done
  void peek();       // done
  void push(int);   // done
  void pop();   // done
  void printStack(); //
  void loadStackToCapacity();
  void handleUserInput();
  void displayMenu();
};

bool arrStackey::isEmpty(){
  if (currentSize == 0){
    cout << "STACK EMPTY!" << endl;
    return true;
  }
  return false;
}
bool arrStackey::isFull(){
  if (currentSize == capacity){
    cout << "STACK FULL!" << endl;
    return true;
  }
  return false;
}
void arrStackey::peek(){
  bool nonEmpty = isEmpty();
  if (nonEmpty == false)
  {
    cout << stackey[currentSize-1] << endl;   // returns the top of the stack
  }
  else{
    cout << "nothing to peek." << endl;
  }
}
void arrStackey::push(int value){
  bool full = isFull();
  if (full == true)
  {
    cout << "Cannot push value: " << value << endl;
  }
  else if (full == false)
  {
    //cout << endl <<  "PUSHING: " << value << endl;
    stackey[currentSize] = value;
    currentSize++;  // open a spot up for the next element
  }
}
void arrStackey::pop(){
  bool nonEmpty = isEmpty();
  if (nonEmpty == true)
  {
    cout << "Nothing to pop." << endl;
  }
  else if (nonEmpty == false){
    cout << "POPPING: " << stackey[currentSize-1] << endl;
    currentSize--;
  }
}
void arrStackey::printStack(){
  int i = 0;
  if (currentSize == 0){
    cout << "Nothing to print." << endl;
  }
  else{
    for(i = 0; i < currentSize; i++)
    {
      cout << stackey[i] << ' ';
    }
    cout << endl;
  }
}

void arrStackey::loadStackToCapacity(){
  int i;

    for(i = 0; i < capacity+1; i++)
    {
      push(i);
      //cout <<  "CURRENT STACK SIZE: " << currentSize << ':';
    }
    cout << endl;


}
void arrStackey::displayMenu(){
  cout << endl;
  cout << "MENU: " << endl;
  cout << "1: PRINT STACK" << endl;
  cout << "2: PEEK STACK" << endl;
  cout << "3: PUSH VALUE ONTO STACK" << endl;
  cout << "4: POP STACK" << endl;
  cout << "5: QUIT" << endl;
  cout << ">>"; 
}
void arrStackey::handleUserInput(){
  bool quit = false;
  string s_input;
  int input;

  // loop until the user quits
  while(!quit){
    displayMenu();
    // reading the input in, assuming that they input a number
    getline(cin,s_input);
    try{
      input = stoi(s_input);
    }
    catch(exception& e){            // catch the exception that will be thrown if its a non numeric input and trigger the default case
      input = 6;  // this will send the user that its an invalid input and restart the loop
    }
    switch(input){
      case 1:
        printStack();
        break;
      case 2:
        peek();
        break;
      case 3:
          int inputtedValue;
          cout << "Input a value." << endl;
          cin >> inputtedValue;
          push(inputtedValue);
        break;
      case 4:
        pop();
        break;
      case 5:
        cout << "GOODBYE." << endl;
        quit = true;
        break;
      default:
        cout << "invalid input." << endl;
        break;
    }
  }
}
int main(int argc, char* argv[])
{
  arrStackey stackey;
  stackey.loadStackToCapacity();
  stackey.handleUserInput() ;

  return 0;
}
