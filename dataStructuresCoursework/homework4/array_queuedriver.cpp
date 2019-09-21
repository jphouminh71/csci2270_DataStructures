#include <iostream>
#include "HW4-Todo-QueueArray.hpp"
using namespace std;


TodoQueueArray::TodoQueueArray()
{
  queueFront = -1;
  queueEnd = -1;
}
bool TodoQueueArray::isEmpty()
{
  if (queueFront == -1)
  {
    return true;
  }
  return false;
}

bool TodoQueueArray::isFull()
{
  if ((queueEnd+1)%MAX_QUEUE_SIZE == queueFront)
  {
    return true;
  }
  return false;
}
TodoItem* TodoQueueArray::peek()
{
  if (isEmpty())
  {
    cout << "Queue empty, cannot peek." << endl;
    return nullptr;
  }
  return queue[queueFront];
}
void TodoQueueArray::enqueue(std::string todoItem)
{
    
    TodoItem* newItem = new TodoItem;
    newItem->todo = todoItem;
    // empty queue
    if (isEmpty())
    {
      queueFront = 0;
      queueEnd = 0;
      queue[queueFront] = newItem;
    }
    // if queue is full
    else if (isFull())
    {
      cout << "Queue full, cannot add new todo item." << endl;
    }
    // if we have to loop around
    else if(queueEnd+1 == MAX_QUEUE_SIZE ){  // if the next spot in array is out of range
      queueEnd = 0; // set queue end back to position 0
      queue[queueEnd] = newItem;  // place the newItem in queueEnd spot
    }
    // else, we have more space in the next position
    else{
      queueEnd++;
      queue[queueEnd] = newItem;
    }
}
void TodoQueueArray::dequeue()  // move the front position forwards and then delete the previous positions element
{
  TodoItem* tempptr;
  // empty array
  if(isEmpty())
  {
    cout << "Queue empty, cannot dequeue an item." << endl;

  }
  // if we have only one element in the array
  else if(queueFront == queueEnd){
    tempptr = queue[queueFront];
    queueFront = queueEnd = -1;
    delete tempptr;
  }
  // if we have to loop around
  else{
    tempptr = queue[queueFront];
    queueFront++;
    if (queueFront == 5)
    {
      queueFront = 0;
    }
    delete tempptr;
  }
}

// int main(int argc, char* argv[])
// {
//
//   return 0;
// }
