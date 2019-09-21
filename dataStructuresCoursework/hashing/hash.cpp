#include "hash.h"

HASH::HASH()
{
  // tableSize = 100;  // the size of our hashtable is set by default to 100;
  for(int i = 0; i < tableSize; i++)    // filling all the buckets for the hash table
  {
    hashTable[i] = new item;    // casting a new object of item into the buckey
    hashTable[i]->name = "empty";
    hashTable[i]->favoriteDrink = "empty";
    hashTable[i]->next = nullptr;
  }
}
void HASH::destroyTable()
{
  ~HASH();
  cout << "Table destroyed." << endl;
}
HASH::~HASH()
{
   item* Ptr;
   for(int i=0;i<tableSize;i++)
   {
      while(hashTable[i] != NULL)
      {
         Ptr = hashTable[i];
         hashTable[i] = hashTable[i]->next;
         delete Ptr;
      }
   }
}

int HASH::hash(string key)    // getting the unique hash value for the string
{
  int hash = 0;
  int index;

  for(int i = 0; i < key.length();i++)
  {
    hash += int(key[i]);    // converting all the letters into there ascii integer values, then getting the unique hash value for the string
    //cout << hash << "<<" << endl;
  }


  index = hash%tableSize; // giving the remainder of the division to use it as the index variable for the hash table, index for the 'array'
  //cout << index << "   INDEX:" << endl;
  return index;
}
// so far the two functions above is how we find the spot of the array to place whatever key we are working with

void HASH::addItem(string name, string favoriteDrink) // adding nodes into hash table
{
  int index = hash(name);     // holds the index for where the new information should be placed in the hash table
  // now we should inspect what is currently in or not is in the current bucket
  if (hashTable[index]->name == "empty")
  {
    hashTable[index]->name = name;
    hashTable[index]->favoriteDrink = favoriteDrink;
    hashTable[index]->next = nullptr;
  }
  else{   // we have a collision
    item* ptr = hashTable[index]; // pointing the the bucket that has something already in it
    item* n = new item; // pointing to a new object with the given parameters
    n->name = name;
    n->favoriteDrink = favoriteDrink;
    n->next = nullptr;
    // now we traverse through the linked list to find the next available spot
    while(ptr->next != nullptr)
    {
      ptr = ptr->next;
    }   // now the current object that is being pointed to has a next value of NULL
    ptr->next = n;
  }
}
// this next function will let us see how many items we have in the a bucket.
int HASH::numItemsInIndex(int index)
{
  int count = 0;
  if (hashTable[index]->name == "empty")
  {
    return count;
  }
  else{
    count++;    // one
    item* tempptr = hashTable[index];
    while(tempptr->next != nullptr)
    {
      count++;
      tempptr = tempptr->next;
    }
  }
  return count;
}
void HASH::printTable()     // print ever item in each bucket and also tell us how many items were in each bucket
{
  int numberOfItems;
  for(int i = 0; i < tableSize; i++)
  {
    numberOfItems = numItemsInIndex(i);
    cout << "----------------------\n";
    cout << "index = " << i << endl;
    cout << hashTable[i]->name << endl;
    cout << hashTable[i]->favoriteDrink << endl;
    cout << "# of items = " << numberOfItems << endl;
    cout << "----------------------\n";
  }
}

void HASH::printItemsinIndex(int index)   // print every item in the bucket
{
  item* tempptr = hashTable[index];
  if (tempptr->name == "empty")
  {
    // nothing in the bucket
    cout << "Index " << index << " is empty." << endl;
  }
  else{
    cout << "index " << index << " contains the following items:\n";
    while (tempptr != nullptr)
    {
      cout << "----------------------\n";
      cout << tempptr->name << endl;
      cout << tempptr->favoriteDrink << endl;
      cout << "----------------------\n";
      tempptr = tempptr->next;

    }
  }
}

void HASH::findDrink(string name)
{
  int index = hash(name);   // hashing the name find the index
  bool foundName = false;
  string drink;
  item* tempptr = hashTable[index]; // giving us the bucket to start looking for the item
  while(tempptr != nullptr)
  {
    if (tempptr->name == name)
    {
      drink = tempptr->favoriteDrink;
      foundName = true;
    //  cout << "HERE" << endl;
    }
    tempptr = tempptr->next;
  }
  if (foundName == true)
  {
    cout << name << " found, their favorte drink is: " << drink << endl;
  }
  else{
    cout << name << " 's information was not found int hashtable.\n";
  }
}
void HASH::removeItem(string name)
{
  int index = hash(name);
  item* delptr;
  item* p1;
  item* p2;

  // empty bucket
  if (hashTable[index]->name == "empty")
  {
    cout << name << " was not found in the hashTable.\n";
  }
  // only one item in the bucket and that one item is a match
  else if (hashTable[index]->name == name && hashTable[index]->next == nullptr)
  {
    hashTable[index]->name = "empty";
    hashTable[index]->favoriteDrink = "empty";
    //delete hashTable[index];                            // if something goes wrong look at this line
    cout << name << " was removed from the hash table.\n";
  }
  // match is found but there are more items in the bucket
  else if (hashTable[index]->name == name)
  {
    delptr = hashTable[index];
    hashTable[index] = hashTable[index]->next;
    delete delptr;
    cout << name << " was removed from the hash table.\n";
  }
  // match is found, but is somewhere in the middle
  else{
    p1 = hashTable[index]->next;
    p2 = hashTable[index];        // have p2 trail so we dont lose pointer to relink
    while(p1->name != name && p1 != nullptr)
    {
      p2 = p1;
      p1 = p1->next;
    }
    if(p1 == nullptr)
    {
      cout << name << " wasn't removed from the hash table.\n";
    }
    else{
      delptr = p1;
      p1 = p1->next;  // unlinking the node to be deleted
      p2->next = p1;    // relinking
      delete delptr;
      cout << name << " was removed from the hash table.\n";
    }
  }
}
