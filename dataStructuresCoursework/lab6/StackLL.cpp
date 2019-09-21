#include <iostream>
#include "StackLL.hpp"

using namespace std;

StackLL::StackLL()  // constructor
{
  stackHead = nullptr;
}

StackLL::~StackLL() // destructor
{
  while(!isEmpty())
  {
    pop();
  }
}

bool StackLL::isEmpty()
{
  return (stackHead == nullptr); // will only return true if the expression is correct.
}

void StackLL::push(int key)
{
  // 1. empty stack
  // 2. not empty stack
  Node* newNode = new Node;
  newNode->key = key;
  newNode->next = stackHead;
  stackHead = newNode;
}

void StackLL::pop()
{
  // stack not empty
  if (!isEmpty())
  {
    Node* tempPtr = stackHead;
    stackHead = stackHead->next;
    delete tempPtr;
  }
  // stack empty
  // if (isEmpty())
  // {
  //   cout << "Stack is empty" << endl;
  // }
}

int StackLL::peek()
{
  if (stackHead == nullptr) // error case
  {

    return 0;
  }
  return stackHead->key;
}
