#include "minheap.hpp"

/*
  Helper function that will return the index of a childs parent index.
    [parentIndex] = (childIndex - 2) / 2;
*/
int minIntHeap::getParentIndex(int childIndex){
  //return (childIndex - 2) / 2;
  return childIndex/2;
}

/*
  Helper function that will get the index of a leftChild for a parent "node"
    [leftChildIndex] = (parentIndex*2)+1
*/
int minIntHeap::getLeftChildIndex(int parentIndex){
  //return (parentIndex*2)+1;
  return 2*parentIndex;
}

/*
  Helper function that will get the index of the rightChild for a parent "node"
    [getRightChildIndex] = (parentIndex*2)+2
*/
int minIntHeap::getRightChildIndex(int parentIndex){
  //return (parentIndex*2)+2;
  return (2*parentIndex) + 1;
}

/*
  Helper function that will return a boolean if a leftChild exists,
    we know that the left child exists if we find the index and find that the index is in the range of the current size of the heap;

    will return true if left child exists or false otherwise. . .
*/
bool minIntHeap::hasLeftChild(int parentIndex){
  int index = getLeftChildIndex(parentIndex);
  return index < currentSize;
}

/*
  Helper function that will return a boolean if a rightChild exists,
    we know that the right child exists if we find the index and find that the index is in the range of the current size of the heap;

    will return true if right child exists or false otherwise. . .
*/
bool minIntHeap::hasRightChild(int parentIndex){
  int index = getRightChildIndex(parentIndex);
  return index < currentSize;
}

bool minIntHeap::hasParent(int childIndex){
  int index = getParentIndex(childIndex);
  return index >= 0;
}

/*
  Following functions will return the actual elements at the index passed as parameters
*/
int minIntHeap::leftChild(int index){
  return items[getLeftChildIndex(index)];
}
int minIntHeap::rightChild(int index){
  return items[getRightChildIndex(index)];
}
int minIntHeap::parent(int index){
  return items[getParentIndex(index)];
}

/*
  Function will take in two index's that must be swapped and swap them in the array.
*/
void minIntHeap::swap(int indexOne, int indexTwo){
  int temp = items[indexOne];
  items[indexOne] = items[indexTwo];
  items[indexTwo] = temp;
}

/*
  When heap hits capacity array will need to increase in size so function will create an array the size of twice the previous capacity and copy elements in
  and increase the total capacity.
*/
void minIntHeap::doubleArray(){
  // cout << "ARRAY BEFORE DOUBLING: " << endl;
  // printHeap();
  int i;
  if (currentSize == capacity){
    cout << "DOUBLING SIZE OF ARRAY!" << endl;
    int *tempArray = new int[capacity*2];               // initialize new array of double the size
    for(i = 0; i < capacity*2; i++){                   // copying the contents of the old array into the new one
      if (i >= currentSize){
        tempArray[i] = 0;
      }
      else
        tempArray[i] = items[i];
    }
                                                        // at this point everything should be copied
    items = tempArray;
    capacity = capacity *2;

    cout << "====================================================" << endl;
    cout << "ARRAY AFTER DOUBLING." << endl;
    int i;
    cout << '[';
    for(i = 0; i < capacity; i++){
      cout << items[i] << "] [";
    }
    cout << "fill]" << endl;
    cout << "CURRENT SIZE IN DOUBLE ARRAY FUNC: " << currentSize << endl;
    cout << "===================================================" << endl;
    delete[] tempArray;
  }
}

/*
  Function returns the next element in the min heap
*/
int minIntHeap::peek(){
  if (currentSize == 0){                                // checking if the heap is empty.
    cout << "Cannot perform operation(PEEK), minheap is empty." << endl;
    return -1;
  }
  cout << "THE TOP ITEM IS: " << items[0] << endl;
  return items[0];
}

/*
  Function extracts the minimum element then makes sure that the min heap is restored to its orginal properties by calling the heapifyDown function
*/

int minIntHeap::poll(){
  if (currentSize == 0){                              // checking if the heap is empty
    cout << "Cannot perform operation(POLL), heap is empty." << endl;
    return -1;
  }

  int returnItem = items[0];                          // extracting the minimum element

  items[0] = items[currentSize-1];                    // making the most recent item added the root
  currentSize--;                                      // "erasing" the last item
  heapifyDown();

  return returnItem;
}

/*
  Function does the opposite of poll function, instead of removing an element we will add in element into the heap at the next spot
*/
int minIntHeap::add(int item){
  doubleArray();                // first check if heap must be increased in size
  currentSize++;                // increase the current size
  items[currentSize] = item;           // add the item into the last spot
  heapifyUp();                  //  restore minheap properties
  cout << "HEAP AFTER HEAPIFYING." << endl;
  printHeap();
}

/*
  Function will be called when restoring properties of minheap after removing top node.
    1. At this point the tree will be ready to be sorted so we just take the first value and start comparing it with its children and swapping it
    until its in the correct position.
      - we know its in the correct position if its smaller than both of its children or if it has no children.

    2. need to compare to check in the cases
      - if it has two children
        -  find the smaller between the two children and swap
        -  change the index to whichever child you ended up swapping with
      - has only the left child
        - check to see if its smaller , if it is, swap
        - change the index to be the index of the leftChild
      - has only the right child
        - check to see if its smaller, if it is, swap
        - change the index to be the index of the rightChild
      - has no childen
        - return because there is nothing to swap.
*/
void minIntHeap::heapifyDown(){
  int index = 0;
  while (hasLeftChild(index) || hasRightChild(index)){
    // first compare assuming we have two children
    if ((hasLeftChild(index) && hasRightChild(index)) && (leftChild(index) < rightChild(index)) && (leftChild(index) < items[index])){      // the case where we swap with the left child
      swap(getLeftChildIndex(index), index);
      index = getLeftChildIndex(index);
    }
    else if ((hasLeftChild(index) && hasRightChild(index)) && (leftChild(index) > rightChild(index)) && (rightChild(index) < items[index])){      // the case where we swap with the left child
      swap(getRightChildIndex(index), index);
      index = getRightChildIndex(index);
    }
    // comparing if it only has one child
    else if ((!hasLeftChild(index) && hasRightChild(index) && rightChild(index) < items[index])){   // has a right child and it is less than the current value , swap
      swap(getRightChildIndex(index), index);
      index = getRightChildIndex(index);
    }
    else if ((hasLeftChild(index) && !hasRightChild(index) && leftChild(index) < items[index])){   // has a right child and it is less than the current value , swap
      swap(getLeftChildIndex(index), index);
      index = getLeftChildIndex(index);
    }
    // last ase if it doesn't have children, just dont do anything
    else{
      break;
    }
  }
}

/*
  Function will be called after a value has been added to the heap and the heap must be restored to its properties of roots being lesser than
  their children.
    1. take the last element added and start comparing it against its children walking up the tree swapping as needed.
*/
void minIntHeap::heapifyUp(){
  int index = currentSize;
  while(hasParent(index) && (parent(index) > items[index])){      // while there is a parent above the index we are looking at and as long as that key value is greater than the index we are looking at
    swap(getParentIndex(index),index);             // swapping the two values
    index = getParentIndex(index);                // walking up the tree ..
  }
}


/*
    print function to look through the heap to make sure it is functioning correctly
*/
void minIntHeap::printHeap(){
  if (currentSize == 0){
    cout << "Cannot perform operation(PRINT HEAP), array is empty.\n";
    return;
  }
  int i;
  cout << '[';
  for(i = 0; i < currentSize; i++){
    cout << items[i] << "] [";
  }
  cout << "fill]" << endl;
}
