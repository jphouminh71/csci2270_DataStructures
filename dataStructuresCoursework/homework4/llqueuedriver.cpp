#include <iostream>
#include "HW4-Todo-QueueLinkedList.hpp"
using namespace std;

TodoQueueLinkedList::TodoQueueLinkedList()
{
  queueFront = nullptr;
  queueEnd = nullptr;
}
TodoQueueLinkedList::~TodoQueueLinkedList()
{
  while (!isEmpty())
  {
    dequeue();
  }
}
bool TodoQueueLinkedList::isEmpty()
{
  if (queueFront == nullptr && queueEnd == nullptr)
  {
    return true;
  }
  return false;
}
void TodoQueueLinkedList::enqueue(std::string todoItem)
{
  TodoItem* newItem = new TodoItem;
  newItem->todo = todoItem;
  newItem->next = nullptr;
  if (isEmpty())		// if theres nothing in the queue, keep the next pointer
  {
    newItem->next = nullptr;
    queueFront = newItem;
    queueEnd = newItem;
  }
  else{
    queueEnd->next = newItem;
    queueEnd = newItem;
  }
}
void TodoQueueLinkedList::dequeue()
{
  if (isEmpty())
  {
    cout << "Queue empty, cannot dequeue an item." << endl;
    return;
  }
  else if(!isEmpty())
  {
    if (queueFront == queueEnd)
    {
      delete queueFront;
      queueFront = nullptr;
      queueEnd = nullptr;
    }
    else{
      TodoItem* tempptr = queueFront;
      queueFront = queueFront->next;
      delete tempptr;
    }
  }
}
TodoItem* TodoQueueLinkedList::peek()
{
  if (!isEmpty())
  {
    return queueFront;
  }
  cout << "Queue empty, cannot peek." << endl;
  return nullptr;
}


int main(int argc, char* argv[])
{
  TodoQueueLinkedList q;
}
