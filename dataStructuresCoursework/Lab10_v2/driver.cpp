// Driver program to test above functions
#include<iostream>
#include<climits>
#include "heap.hpp"
using namespace std;
int main()
{
    MinHeap h(11);
    h.pushMinHeap(90);
    h.pushMinHeap(14);
    h.pushMinHeap(87);
    h.pushMinHeap(64);
    h.pushMinHeap(32);
    h.pushMinHeap(53);
    h.pushMinHeap(41);
    h.pushMinHeap(23);
    h.pushMinHeap(50);
    h.pushMinHeap(43);
    h.pushMinHeap(5);

/*

                              5(1)
                           /        \
                        14(2)         41(3)
                      /      \       /    \
                 32(4)       23(5)  87(6)  53(7)
                /    \      /    \
            90(8)   50(9) 64(10) 43(11)

*/
    cout<<"-----------------------"<<endl;
    cout<<"heap after insertion"<<endl;
    h.printMinHeap();
    cout<<"-----------------------"<<endl;
    cout << "Popping the minimum from heap"<<endl ;
    h.popMinHeap();
    cout<<"heap after POP"<<endl;
    h.printMinHeap();
    cout<<"-----------------------"<<endl;
    cout << "min in heap:"<<h.getMin() << " ";

    return 0;
}
