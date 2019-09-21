/*
      Queues
      examples of queues: lines at bank, store, DMV
      - batch jobs
      - Scheduling
      Operations of Queues:
      isEmpty
      isFull (array)
      enqueue
      dequeue , removing the next item from the top of the stack
      peek

      This will be the implementation of the linked list version.
*/
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct node{
  string task;
  node* next;
  node* previous;
};
class queue{
public:
  bool isEmpty();      // checks to see if the queue is empty
  void enqueue(string task);  // take in a node and append it to the list;
  void dequeue();    // pop the head of the list and move the head to the next item in the list
  void peek();  // print the next item in the queue
  void findPosition(node* task);   // take in and item and determine if its in the queue and then determine the position in the queue if its in it.
  void printQueue();  // print the contents of the queue

private:
  node* head;
};

/*
  function takes no parameters
  return true if head pointer is null
  return false if head pointer is not null
*/
bool queue::isEmpty(){
  if ( head == nullptr ){   // nothing in the linked list
    return true;
  }
  return false;
}
/*
  create a new task passed in a parameter then its just constructing a singly linked list.
  need to check if its the first item in the list
    if it is, make it the head
  otherwise
    traverse the linked list and append the new node to the end of the linked list
*/
void queue::enqueue(string g_task){
  node* newTask = new node;
  newTask->task = g_task;
  newTask->next = nullptr;
  if (head == nullptr){
    head = newTask;
  }
  else if (head != nullptr){         // 1 -- > 2 --> 3 --> nullptr
    node* tempptr = head;
    while (tempptr->next != nullptr)
    {
      tempptr = tempptr->next;    // this finds the last position in the linked list
    }
    tempptr->next = newTask;  // appending the new node into the linked list
  }

}
/*
  this function will pop the head of of the linked list off and print out the task that was just dequeued
  edge cases to handle for this function
    if the linked list is empty
    only one item to dequeue

*/
void queue::dequeue(){
  bool empty = isEmpty();
  if (empty == true){
    cout << "Queue is empty, nothing to dequeue." << endl;
  }
  else if ( empty == false ){
    node* tempptr = head;
    head = head->next;      // might throw error here,
    cout << "Dequeuing task: " << tempptr->task << endl;
    delete tempptr;

  }

}

/*
  function must check if the queue is empty
    if its not empty print out the next item in the queue
*/
void queue::peek(){
  bool empty = isEmpty();
  if ( empty == true ){
    cout << "Queue is empty, nothing to peek." << endl;
  }
  else if ( empty == false ){
    cout << "Next thing to do is, " << head->task << "." << endl;
  }
}
/*
  This function will perform similarly as the peek function does but instead of printing the head of the list, we need to traverse the lsit and find its position
    the only thing we would have to worry about is if the linked list is empty.
*/
void queue::findPosition(node* task){
  bool empty = isEmpty();
  if ( empty == true ){
    cout << "Queue is empty, nothing to find." << endl;
  }
  else if ( empty == false ){       // traverse the linked list and count how many steps you needed to take to the node if you end up finding it.
    int position = 0;
    node* tempptr = head;
    while (tempptr != nullptr){
      if (tempptr->task == task->task){
        cout << "Task: " << tempptr->task << " , found at position " << position << " in the queue." << endl;
      }
      position++;
      tempptr = tempptr->next;
    }
  }
}
/*
  traverse the linked list and print the contents of the queue
    just have to check to make sure the queue isnt empty
*/
void queue::printQueue(){
  int taskCounter = 0;
  node* tempptr = head;
  if ( tempptr == nullptr ){
    cout << "Queue is empty, nothing to print." << endl;
  }
  else if ( tempptr != nullptr ){
    cout << "QUEUE CONTENTS" << endl;
    while ( tempptr != nullptr ){
      cout << taskCounter << ": " << tempptr->task << endl;
      taskCounter++;
      tempptr=tempptr->next;
    }
  }
}
int main(int argc, char* argv[]){
  queue q;
  q.enqueue("do laundry");
  q.enqueue("get groceries");
  q.enqueue("eat food");
  q.printQueue();
  q.dequeue();
  q.printQueue();
  q.dequeue();
  q.printQueue();
  q.dequeue();
  q.dequeue();
  q.printQueue();
}
