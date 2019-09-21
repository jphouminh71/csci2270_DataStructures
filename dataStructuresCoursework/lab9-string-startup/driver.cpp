// Driver program
#include<iostream>
#include "hash.hpp"
using namespace std;

int main()
{
    string a[] = {"BAT", "DOG", "CAT", "BIRD", "BEAR", "BARE", "TAB"};
    int n = sizeof(a)/sizeof(a[0]);

    // 6 is count of buckets in hash table
    HashTable ht(6);
    // insert the keys into the hash table.
    for (int i = 0; i < n; i++) {
        ht.insertItem(a[i]);
    }

    cout<< "-------after insertion-----"<<endl;
    ht.printTable();
    if(!ht.searchItem("BAT")) {
        cout<<"FAIL: 'BAT' not found"<<endl;
    }

    cout<<"--------deleting DOG-------------"<<endl;
    ht.deleteItem("DOG");
    ht.printTable();
    if(ht.searchItem("DOG")) {
        cout<<"FAIL: found 'DOG'"<<endl;
    }

    cout<<"--------deleting BEAR-------------"<<endl;
    ht.deleteItem("BEAR");
    ht.printTable();
    if(ht.searchItem("BEAR")) {
        cout<<"FAIL: found 'BEAR'"<<endl;
    }

    return 0;
}
