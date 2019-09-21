#include "pq.hpp"
#include <string>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;


PriorityQueue::PriorityQueue(int _queueSize)    // this parameter is going to be argv[1]
{
  currentQueueSize = 0;
  maxQueueSize = _queueSize;
  priorityQueue = new PatientNode[maxQueueSize+1]; //indexing for heaps start at 1
}
PriorityQueue::~PriorityQueue()   // this shit is probably wrong
{
    delete [] priorityQueue ;
}
void PriorityQueue::enqueue (string _name, int _injurySeverity, int _treatmentTime)
{
  PatientNode newPatient;
  newPatient.name = _name;
  newPatient.injurySeverity = _injurySeverity;
  newPatient.treatmentTime = _treatmentTime;
  if (currentQueueSize == 0)
  {
    priorityQueue[1] = newPatient;
    currentQueueSize++;
  }
  else if (currentQueueSize < maxQueueSize)
  {
    priorityQueue[currentQueueSize+1] = newPatient;
    currentQueueSize++;
    repairUpward(currentQueueSize);

  }
}
string PriorityQueue::peekName()
{
  if (currentQueueSize != 0 || currentQueueSize < 0)
  {
    return priorityQueue[1].name;
  }
  return "Queue is empty. ";
}
int PriorityQueue::peekInjurySeverity()
{
  if (currentQueueSize != 0 || currentQueueSize < 0)
  {
    return priorityQueue[1].injurySeverity;
  }
  return -111;
}
int PriorityQueue::peekTreatmentTime()
{
  if (currentQueueSize != 0 || currentQueueSize < 0)
  {
    return priorityQueue[1].treatmentTime;
  }
  return -222;
}
void PriorityQueue::dequeue()
{
  if (!isEmpty())
  {
    priorityQueue[1] = priorityQueue[currentQueueSize];
    repairDownward(1);
    currentQueueSize--;  // taking out the last thing in the heap
  }
}
bool PriorityQueue::isFull()
{
  if (currentQueueSize == maxQueueSize)
  {
    return true;
  }
  return false;
}
bool PriorityQueue::isEmpty()
{
  if (currentQueueSize == 0)
  {
    return true;
  }
  return false;
}


// EVERYTHING BELOW IS TO REPAIR UPWARDS------------------------------------------------
/*
    Mainly involving queueing an item up as a leaf then comparing its value with the parent and determining when we want to swap values, higher valued severities should be placed first
    reparing upwards is going to be used for enqueuing
*/

// Return the index of parent of the node at index i
int parent(int i)
{
    return i / 2;
}
void swap(PatientNode *x, PatientNode *y)
{
    PatientNode temp = *x;
    *x = *y;
    *y = temp;
}
void ReverseHeapify(int index, PatientNode queue[])   // instead of parent down to the children, your gonna go from children up to the parent   // these function are going to be used when we add elements to the quueue
{
  int parentIndex = parent(index);
  if (parentIndex != 0 && queue[parentIndex].injurySeverity < queue[index].injurySeverity)
  {
      swap(&queue[index],& queue[parentIndex]);
      ReverseHeapify(parentIndex,queue);

  }
  else if (queue[parentIndex].injurySeverity == queue[index].injurySeverity)
  {
    if (queue[parentIndex].treatmentTime > queue[index].treatmentTime)    // want to swap the smaller item
    {
      swap(&queue[index],& queue[parentIndex]);
    }
    else{
      swap(&queue[parentIndex],& queue[index]);
    }
    ReverseHeapify(parentIndex,queue);
  }
}
void PriorityQueue::repairUpward(int nodeIndex)
{
  ReverseHeapify(nodeIndex,priorityQueue); // passing the index we working with and then giving the queue as reference
}

// EVERYTHING BELOW IS TO REPAIR DOWNWARDS ----------------------------------------------------
/*
  need to know the values of the children to know where to swap things , not as easy as working upwards
  going to have to use this when dequeing so we know which child to set as the root and then where to repair
*/

int left(int i)
{
    return 2*i;
}
// Return index of right child of node at index i
int right(int i)
{
    return (2*i) + 1;
}
void MaxHeapify(int i, PatientNode queue[], int currentQueueSize)         // still need to handle the case of having the same injury rating
{
    // left and right children
    int li, ri;
    //PatientNode max = queue[i];
    int max = i;
    li = left(i);
    ri = right(i);

    //int root = i;     // root is the index that we are working shifting down the 'tree'

      if(li < currentQueueSize && (queue[li].injurySeverity > queue[max].injurySeverity || (queue[li].injurySeverity == queue[max].injurySeverity && queue[li].treatmentTime < queue[max].treatmentTime)))
      {
        max = li;
      }
      if (ri < currentQueueSize && (queue[ri].injurySeverity > queue[max].injurySeverity || (queue[ri].injurySeverity == queue[max].injurySeverity && queue[ri].treatmentTime < queue[max].treatmentTime)))
      {
        max = ri;
      }

      if (max != i)
      {
        swap(&queue[i], &queue[max]);
        MaxHeapify(max, queue, currentQueueSize);
      }
}
void PriorityQueue::repairDownward(int nodeIndex)
{
  MaxHeapify(nodeIndex, priorityQueue, currentQueueSize);
}
