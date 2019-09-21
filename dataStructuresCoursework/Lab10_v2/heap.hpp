#ifndef HEAP_HPP
#define HEAP_HPP

// A class for Min Heap
class MinHeap
{
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
    MinHeap(int capacity);


    void ReverseHeapify(int );    // sift elemenents up the heap

    // to heapify a subtree with the root at given index
    void MinHeapify(int );  // sift elements down the heap 

    int parent(int ) ;

    // to get index of left child of node at index i
    int left(int );

    // to get index of right child of node at index i
    int right(int );

    // to extract the root which is the minimum element
    void popMinHeap();

    // Returns the minimum key (key at root) from min heap
    int getMin();

    // Inserts a new key 'k'
    void pushMinHeap(int );

    // printing the heap
    void printMinHeap();
};

#endif
