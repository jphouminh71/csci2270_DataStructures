// implementing a queue through an Array
#include <iostream>
using namespace std;
const int MAX_SIZE = 2; // max size of our array queue is going to be set to 2

// creating a class named queue

class Queue{
private:
  int A[MAX_SIZE];    // declaring array with size 2
  int rear; // keeping track of front and rear parts of the queue
  int front;
public:
  // notice that all the functions for this queue are inlined
  // we are goint to set the intial values of rear and front to -1, we are assuming its empty
  Queue(){
    front = -1;     // these are indeces of the array
    rear = -1;
  }
  // function to check whether the queue is empty or not
  bool isEmpty()
  {
    if (front == -1 && rear == -1)
    {
      return true;
    }
    else{
      return false;
    }
  }
  // checking if the queue is full, if the rear+1 % max elements = 0, then you know you have an empty queue
  bool isFull()
  {
    if ((rear+1)%MAX_SIZE == front)
    {
      return true;    // if the value == 0, then its full,
    }
    else{   // otherwise its not full
      return false;
    }
  }
  // adding an element to the queue to the rear, think like getting in line.
  void enqueue(int x)
  {
    if (isFull() == true)
    {
      cout << "Error, the Queue is full" << endl;
      return;
    }
    if (isEmpty() == true)
    {
      front = rear = 0;
    }
    else{                           // essentially looking for the spot where the rear is
      rear = (rear+1)%MAX_SIZE;
    }
    A[rear] = x;    // setting the rear of the queue equal to our value
  }
  // Remove an element from the queue in the front
  void dequeue()
  {
    cout << "Dequeuing: " << endl;
    if (isEmpty() == true)
    {
      cout << "Error, Queue is empty" << endl;
      return;
    }
    else if (front == rear){
      rear = front = -1;
    }
    else{
      front = (front+1)%MAX_SIZE;
    }
  }
  // returning the front element of the Queue
  int peek()    // remember that peek is a function that checks what is on the top of the stack
  {
    if (front == -1)  // nothing in the stack
    {
      cout << "Stack is empty. Cannot peek" << endl;
      return -1;
    }
    return A[front];
  }
  // print function is just too see what is going on
  void print()
  {
    if (isEmpty() == true)
    {
      cout << "Nothing to print. Queue is empty" << endl;
    }
    else{
      // first find how many elements are in the queue, shouldn't this just be the value of rear?
      int count = (rear+MAX_SIZE-front)%MAX_SIZE + 1;
      for (int i = 0; i < count; i++)
      {
        int index = (front + i) % MAX_SIZE;   // indexing through the array circularly from the front
        cout << A[index] << " ";
      }
      cout << "\n\n";
    }
  }
};

int main(int argc, char* argv[])
{
  Queue Q;  // creating instance of a Queue
  Q.enqueue(2); Q.print();
  Q.enqueue(4); Q.print();
  Q.enqueue(6); Q.print();
  Q.dequeue(); Q.print();
  
}
