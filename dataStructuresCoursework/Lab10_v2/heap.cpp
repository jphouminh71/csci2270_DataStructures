// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include<climits>
#include "heap.hpp"
using namespace std;

// Prototype of a utility function to swap two integers
void swap(int *x, int *y);


// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
  capacity = cap;
  heap_size = 0;  // heap is initially is empty
  harr = new int[capacity+1]; // allocating array with + 1 because we dont use index 0 to make the math easier;
}

// Return the index of parent of the node at index i
int MinHeap::parent(int i)
{
    return i / 2;
}

// Return index of left child of node at index i
int MinHeap::left(int i)
{
    return 2*i;
}

// Return index of right child of node at index i
int MinHeap::right(int i)
{
    return (2*i) + 1;
}

// Return the minimum value in the heap
int MinHeap::getMin()   // like the peak function, its at the root, index 1
{
    if (heap_size > 0)
    {
      return harr[1];
    }
    cout << "Heap Empty." << endl;
    return -1;
}

// Inserts a new key 'k'
void MinHeap::pushMinHeap(int k)    // pushing  a value up the 'tree', so we have to use reverse heapify
{
    if(heap_size == capacity)
    {
      cout << "heap is full, can't push." << endl;
      return;
    }
    heap_size++;
    int i = heap_size;
    harr[i] = k;

    ReverseHeapify(i);
}

// Heapify after inserting an element to the heap
void MinHeap::ReverseHeapify(int i)   // instead of parent down to the children, your gonna go from children up to the parent   // these function are going to be used when we add elements to the quueue
{
  int pi = parent(i);
  if (pi != 0 && harr[pi] > harr[i])
  {
    swap(&harr[i], &harr[pi]);
    ReverseHeapify(pi);
  }
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    // left and right children
    int li, ri;
    li = left(i);
    ri = right(i);

    int smallest = i;

    if (li < heap_size && harr[li] <= harr[smallest])
    {
      smallest = li;
    }
    if(ri <= heap_size && harr[ri] <= harr[smallest])
    {
      smallest = ri;
    }
    if (smallest != i)
    {
      swap(&harr[i], &harr[smallest]);
      MinHeapify(smallest); // fixing making sure the tree is balanced
    }
}

// Method to remove minimum element (or root) from min heap
void MinHeap::popMinHeap()
{
    if (heap_size <= 0)
    {
      cout << "Nothing in the heap." << endl;
      return;
    }
    if (heap_size == 1)
    {
      heap_size--;  // taking the heap size back down to zero
    }
    // take the thing at the end of the array adn putting it to the root and then heapifying it down to where it should be.
    else
    {
      harr[1] = harr[heap_size];
      heap_size--;  // taking out the last thing in the heap
      MinHeapify(1);
    }
}

void MinHeap::printMinHeap()
{
    for(int i=1;i<=heap_size;i++)
        cout<<i<<":"<<harr[i]<<endl;
}
// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
