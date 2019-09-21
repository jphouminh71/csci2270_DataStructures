#include <iostream>
#include "HW4-Todo-StackLinkedList.hpp"
using namespace std;

TodoStackLinkedList::TodoStackLinkedList()
{
  stackHead = nullptr;
}
TodoStackLinkedList::~TodoStackLinkedList()
{
  while (!isEmpty())
  {
    pop();
  }
}
bool TodoStackLinkedList::isEmpty()
{
  if (stackHead == nullptr)
  {
    return true;
  }
  return false;
}
void TodoStackLinkedList::push(std::string todoItem)
{
  TodoItem* newItem = new TodoItem;
  newItem->todo = todoItem;
  newItem->next = nullptr;
  if (isEmpty())
  {
    stackHead = newItem;
  }
  else
  {
    newItem->next = stackHead;
    stackHead = newItem;
  }
}
void TodoStackLinkedList::pop()
{
  if (isEmpty())
  {
    cout << "Stack empty, cannot pop an item." << endl;
  }
  else
  {

    if (stackHead->next == nullptr)
    {
      delete stackHead;
      stackHead = nullptr;
    }
    else{
      TodoItem* tempptr = stackHead;
      stackHead = stackHead->next;
      delete tempptr;
    }
  }
}
TodoItem* TodoStackLinkedList::peek()
{
  if (isEmpty())
  {
    cout << "Stack empty, cannot peek." << endl;
    return nullptr;
  }
  return stackHead;
}
int main(int argc, char* argv[])
{
  
}
