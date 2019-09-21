#include <iostream>
#include "QueueLL.hpp"

using namespace std;

QueueLL::QueueLL()
{
  queueFront = nullptr;
  queueEnd = nullptr;
}

QueueLL::~QueueLL()
{
  while(!isEmpty())
  {
    dequeue();
  }
}

bool QueueLL::isEmpty()
{
    return (queueFront == nullptr && queueEnd == nullptr); // they should both be equal to null
}

void QueueLL::enqueue(int key)  // appending to the end of the list
{
  // 1. Empty
  // 2. Not empty
  Node* newNode = new Node;
  newNode->key = key;
  newNode->next = nullptr;
  if (isEmpty())
  {
    queueFront = newNode;
    queueEnd = newNode;
  }
  else{
    queueEnd->next = newNode; // pointing the last known node to the new node
    queueEnd = newNode; // repointing the tail pointer
  }
}

void QueueLL::dequeue() // removing from the front of the list
{
  // case 1: Q is empty
  if (isEmpty())
  {
    // error
    return;
  }
  // case 2: only one thing in the q
  else if (queueEnd == queueFront)
  {
    delete queueEnd;  // delete the one value
    queueFront = queueEnd = nullptr;  // reset the pointers to null
  }
  // case 3: more than on thing in the queue
  else{
    Node* tempPtr = queueFront;
    queueFront = queueFront->next;
    delete tempPtr;
  }

}

int QueueLL::peek()
{
    if (isEmpty())
    {
      return 0;
    }
    return queueFront->key;
}
