#include "minheap.cpp"

int main(int argc, char* argv[]){
  minIntHeap heapy;
  //
  // //cout << "adding 10" << endl;
  // heapy.add(10);
  // heapy.printHeap();
  // //cout << "adding 15" << endl;
  // heapy.add(15);
  // heapy.printHeap();
  // //cout << "adding 20" << endl;
  // heapy.add(20);
  // heapy.printHeap();
  // //cout << "adding 17" << endl;
  // heapy.add(17);
  // heapy.printHeap();
  // //cout << "adding 1" << endl;
  // heapy.add(1);
  // heapy.peek();
  // heapy.printHeap();
  // cout << "POLLING!" << endl;
  // heapy.poll();
  // cout << "HEAP AFTER HEAPIFYING: " << endl;
  // heapy.printHeap();
  // heapy.peek();

  // everything seems to be working, but lets test it by adding a bunch of random numbers and seeing if the heap holds after doubling and such.
  int array10[] = {482 , 41, 5, 6, 65, 98, 33, 12, 11, 71};
  int array20[] = {482, 67, 2, 1, 165, 198, 133, 189, 13, 74, 66, 88 ,47 , 43 ,42 ,45 ,76 ,72, 63, 22};

  for(int i  = 0; i < 10; i++){
    heapy.add(array10[i]);
  }
  cout << "Heap after adding all 20 items: " << endl;
  // heapy.printHeap();
  // cout << "=====================" << endl;
  // for(int i = 0; i < 4; i++){
  //   heapy.poll();
  // }
  // cout << "Heap after remvoving 4 items" << endl;
  // heapy.printHeap();

  return 0;
}


/*    NOTES
  This will be a min heap implementation of strictly integer values followed along by youtube video provided by Hacker rank.
    link: https://www.youtube.com/watch?v=t0Cq6tVNRBA

  Source code originally written in java 7 but will be translated to c++
*/
