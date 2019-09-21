#include <iostream>
#include "HW4-Todo-StackArray.hpp"
using namespace std;

TodoStackArray::TodoStackArray()
{
  stackTop = 0;
  stack[MAX_STACK_SIZE];
}
bool TodoStackArray::isEmpty()
{
  if (stackTop == 0)
  {
    return true;
  }
  return false;
}
bool TodoStackArray::isFull()
{
  if (stackTop == MAX_STACK_SIZE)
  {
    return true;
  }
  return false;
}
TodoItem* TodoStackArray::peek()
{
  if (!isEmpty())
  {
    return stack[stackTop-1];
  }
  return nullptr;
}
void TodoStackArray::push(std::string todoItem)
{
  if(isFull())
  {
    cout << "Stack full, cannot push item." << endl;
  }
  else{
    TodoItem* newItem = new TodoItem;
    newItem->todo = todoItem;
    stack[stackTop] = newItem;
    stackTop++;
  }
}
void TodoStackArray::pop()
{
  if (isEmpty())
  {
    cout << "Stack empty, cannot pop an item" << endl;
  }
  else{
    delete stack[stackTop-1];
    stackTop--;
  }
}
int main(int argc, char* argv[])
{
  cout << "here" << endl;
}
