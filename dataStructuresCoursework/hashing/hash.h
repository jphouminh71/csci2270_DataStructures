#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class HASH{
private:
  static const int tableSize = 10;   // size of our hash table

  struct item{        // this is the kind of objects that will be in the has tables
    string name;
    string favoriteDrink;
    item* next;           // have this pointer here for chaining for when we have collisions
  };

  item* hashTable[tableSize];   // casting a array of pointers that will serve as the hash table
public:
  HASH(); // constructor
  ~HASH();  // destructor 
  int hash(string key);   // think about the phonebook example, your passing the name of the person to the hash function
  void addItem(string name, string favoriteDrink);
  int numItemsInIndex(int index);
  void printTable();
  void printItemsinIndex(int index);
  void findDrink(string name);
  void removeItem(string name);
  void destroyTable();
};
