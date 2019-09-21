/*
  Array implementation of queue
  Functions:
    isFull()
      - will check number of elements in the array and return a boolean
    isEmpty()
      - will return a boolean if any elements are in the queue
    Dequeue()
      - will check if queue is empty and then will pop the next item in the queue
        instead of popping and shifting all remaining elements to the left, we will handle this a different way to improve efficiency
    Enqueue()
      - function will take in objection
          first determine if queue is full
          if not, then append the object to the end of the queue in the next open spot in the array
    peek()
      - return what is next in the queue

    notes:
      since this is an implementation in the array and we are not shifting all elements in the array when dequeueing, we must keep track of the queue front and the queue tail.
      essentially manually keeping track of the head and tail like in a linked list. The problem with this implementation is that it makes it difficult to traverse and print the contents of the queue.

      -when initializing the array, we have a * in front of the array declaration because we are pointing to a spot in memory.
      - if qFront = -1 then we know that the queue is empty.

      picture of how the looping around should working when enqueing
        [1][2][3]
        [][2][3]      , when trying to enque we we should have to loop back around to position 0 when qEnd is incremented and hits
        [4][2][3]


      . . . move onto prioritiy queues 
*/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int MAX_QUEUE_SIZE = 3;  // [0][1][2], will only hold 3 elements at most.

struct toDoItem{
  string task;
};

class queuearr{
private:
  int qFront = -1;   // this is the index of the array that represents the next object that will be dequeued
  int qEnd = -1;  // need to keep track of this so we don't accidentally overwrite other objects, it is the most recently queued object
  toDoItem*  queue[MAX_QUEUE_SIZE];  // pointer to initialized array in memory.
public:
  bool isEmpty();   // done
  bool isFull();    // done
  void enqueue(string newItem);
  void dequeue();
  toDoItem* peek();                     // returns a pointer to an object in the array
};

bool queuearr::isEmpty(){
  if (qFront == -1){
    return true;
  }
  return false;
}

bool queuearr::isFull(){    // [1][2][3][4]      , qEnd = 3 q front = 0   , equation to determine if full is (qEnd+1)%MAX_QUEUE_SIZE == front   4%4 = 0
  if((qEnd+1)%MAX_QUEUE_SIZE == qFront){    // queue is full
    return true;
  }
  return false;   // queue is not full.
}
/*
  First we need to check if the queue is full,
  otherwise we need to make a new object and then append it the next spot in the array, we need to handle the case if we need to move adjust qEnd to loop back around and thats if
  qEnd is equal to MAX_QUEUE_SIZE then just make qEnd = to index 0.

  need an edge case if its the first item in the queue
*/
void queuearr::enqueue(string newTask){
  if(isFull()){
    cout << "Cannot perform operation (ENQUEUE), queue is full." << endl;
  }

  else if(isEmpty()){
    toDoItem* newItem = new toDoItem;
    newItem->task = newTask;
    qFront = qEnd = 0;
    queue[qFront] = newItem;
    cout << "TASK: " << queue[qEnd]->task << " ,appended at index, " << qEnd << endl;
  }
  // edge case if we have to loop around.
  else if (qEnd == MAX_QUEUE_SIZE){
    cout << endl << "LOOPING AROUND!" << endl;
    toDoItem* newItem = new toDoItem;
    newItem->task = newTask;
    qEnd = 0;
    queue[qEnd] = newItem;
  }
  // if we dont need to loop around just get the next index in the array and put the object in that spot.
  else{
    toDoItem* newItem = new toDoItem;
    newItem->task = newTask;
    qEnd++;
    queue[qEnd] = newItem;
    cout << "TASK: " << queue[qEnd]->task << " ,appended at index, " << qEnd << endl;
  }
}
/*
  first check if the queue is empty.
    if its empty , print out nothing can be performed
    things to think about in this function,
      if there is only one element in the queue, that is when qFront = qEnd, then we must delete that element then reset the values of qFront and qEnd back to -1
      otherwise we just increment the qFront index and if we must loop around we need a conditional that pushings the
*/
void queuearr::dequeue(){
  toDoItem* tempptr = queue[qFront];
  bool empty = isEmpty();
  if (empty == true)
  {
    cout << "Cannot perform operation (DEQUEUE), queue empty." << endl;
  }
  // edge case for when there is only one object in the array. if index of qFront == index of qEnd then we know there is only one element in the queue.
  else if ( qFront == qEnd ){
    cout << "DEQUEUING THE ONLY ITEM IN THE QUEUE, " << queue[qFront]->task << endl;
    qFront = qEnd = -1;  // resetting the index to -1 to indicate empty queue.
    delete tempptr;
  }
  // normal dequeuing with conditional if we have to loop back around to the 0 index of the array. increment the qFront, and then delete the tempptr to the previous front.
  else{
    cout << "Dequeuing " << tempptr->task << endl;
    qFront++;
    if (qFront == MAX_QUEUE_SIZE){      // loop the next spot to the front of the array.
      qFront = 0;
    }
    delete tempptr;
  }
}

toDoItem* queuearr::peek(){   // return the next element in the queue
  if (isEmpty()){
    cout << "Cannot perform operation (PEEK), queue is empty," << endl;
    return nullptr;
  }
  cout << "Next task in queue, " << queue[qFront]->task << "." << endl;
  return queue[qFront];
}

int main(int argc, char* argv[]){
  queuearr q;
  cout << "SIZE OF ARRAY IS: " << MAX_QUEUE_SIZE << endl;
// first test if we are queueing correctly without issues
  // q.enqueue("buy eggs");
  // q.enqueue("buy milk");
  // q.enqueue("buy chicken");
  //q.enqueue("this should not be added to the queue");   // yes it does work.

// see if dequeue function is working properly
  // q.dequeue();
  // q.dequeue();
  // q.dequeue();

// go through and make sure that items are queued correctly after being dequeued
  // q.enqueue("buy eggs");
  // q.enqueue("buy milk");
  // q.enqueue("buy chicken");
  // q.dequeue();  // should dequeue , buy eggs.
  // q.enqueue("Buy batteries");
  // q.dequeue();
  // q.dequeue();
  // q.dequeue();  // this should be dequeing, buy batteries


// check to make sure the looping is working properly.
  // q.enqueue("buy eggs");
  // q.enqueue("buy milk");
  // q.enqueue("buy chicken");
  // q.dequeue();
  // q.enqueue("buy alcohol");  // should cause the looping.
  // q.enqueue("buy drinks");
  // q.enqueue("buy chips");
  // q.enqueue("buy snaccs");
  // q.enqueue("buy eggs");
  // q.enqueue("buy milk");
  // q.enqueue("buy chicken");
  // q.dequeue();
  // q.enqueue("buy alcohol");  // should cause the looping.
  // q.enqueue("buy drinks");
  // q.enqueue("buy chips");
  // q.enqueue("buy snaccs");
  // q.enqueue("buy alcohol");  // should cause the looping.
  // q.enqueue("buy drinks");
  // q.enqueue("buy chips");
  // q.enqueue("buy snaccs");

  return 0;
}
