// Array Implementation of Stacks
#include <iostream>
using namespace std;

const int MAX_SIZE = 6;

class arrStack{
public:
  arrStack();   // constructor
  ~arrStack();  // destructor
  bool isEmpty(); //
  bool isFull();

  int peek();
  int pop();
  bool push(int);
private:
  int stackOInts[MAX_SIZE]; // if we wanted to make more space for this we would have to dynamically allocate new memory for it
  int currentSize;
};
arrStack::arrStack()
{
  currentSize = 0;
}
arrStack::~arrStack()
{

}
bool arrStack::isEmpty()
{
  if (currentSize == 0){    // checking amount of elements in array using the size;
    return true;
  }
  else{
    return false;
  }
}
bool arrStack::isFull()
{
  if (currentSize == MAX_SIZE){
    return true;
  }
  else{
    return false;
  }
}
int arrStack::peek()
{
  if (!isEmpty())
  {
    return stackOInts[currentSize-1];
  }
  else
  {
    cout << "Stack is empty, cannot peek" << endl;
    return -99999999;
  }

}
bool arrStack::push(int givenNumber)
{
  if (isFull())
  {
    return false;
  }
  else{
    stackOInts[currentSize] = givenNumber;
    currentSize++;
    return true;
  }
}
int arrStack::pop()   // function deletes the top of the current stack by decrementing the size of array and then just returning the current top of stack to nothing?
{
  if (!isEmpty())
  {
    int valueToReturn = stackOInts[currentSize-1];
    currentSize = currentSize - 1;    // just makes the top of the stack equal to the previous element?
    return valueToReturn;           // returns this value somewhere else?
  }
  else{
    cout << "Stack is empty! Cannot Pop. " << endl;
    return -999999;
  }

}

int main(int argc, char* argv[])
{
  arrStack stackey;
  if (stackey.isEmpty() == true)
  {
    cout << "Stack is empty" << endl;
  }
  if (stackey.push(33) == true)     // conditionals to see if we added to the stack if there was room
  {
    cout << "33 added to the stack" << endl;
  }
  if (stackey.push(44) == true)
  {
    cout << "44 added to the stack" << endl;
  }
  if (stackey.push(55) == true)
  {
    cout << "55 added to the stack" << endl;
  }
  if (stackey.push(66) == true)
  {
    cout << "66 added to the stack" << endl;
  }
  if (stackey.push(77) == true)
  {
    cout << "77 added to the stack" << endl;
  }
  if (stackey.push(88) == true)
  {
    cout << "88 added to the stack" << endl;
  }
  if (stackey.push(99) == true)     // this is going to return false because there was no more room in the stack
  {
    cout << "99 added to the stack" << endl;
  }
  else{
    cout << "99 Not added to the stack" << endl;
  }

  cout << "Top of stack: " << stackey.peek() << endl;

  stackey.pop();
  cout << "Top of stack: " << stackey.peek() << endl;
  stackey.pop();
  cout << "Top of stack: " << stackey.peek() << endl;
  stackey.push(100);      // this just overrided the previous element that was there before we decremented when we popped 
  cout << "Top of stack: " << stackey.peek() << endl;

  return 0;
}
