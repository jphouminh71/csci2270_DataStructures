#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class minIntHeap{
private:
  int capacity = 10;              // heap will only be able to store 10 values
  int currentSize = 0;                  // keep track of how many items are in the heap
  int* items = new int[capacity+1];
  void swap(int indexOne, int indexTwo);      // function will be utilized when heapifying the minheap
  void doubleArray();
  void heapifyDown();
  void heapifyUp();
public:
  // declaring helper functions to get the indexs of parent and child indexs of a current node;
  int getParentIndex(int childIndex);
  int getLeftChildIndex(int parentIndex);
  int getRightChildIndex(int parentIndex);

  // declaring helper functions to check if left and right childs or parent exists
  bool hasLeftChild(int parentIndex);
  bool hasRightChild(int parentIndex);
  bool hasParent(int childIndex);

  // declaring helper functions that will return to us the left and right childs
  int leftChild(int index);
  int rightChild(int index);
  int parent(int index);

  // now declaring main functions of the min heap;
  int peek();
  int poll();
  int add(int item);

  void printHeap();






};
