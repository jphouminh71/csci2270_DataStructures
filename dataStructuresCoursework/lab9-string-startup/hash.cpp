// CPP program to implement hashing with chaining
#include<iostream>
#include "hash.hpp"

using namespace std;

node* HashTable::createNode(string key, node* next)
{
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize)
{
  tableSize = bsize;
  table = new node*[tableSize]; // allocating new memory for array of pointers to the nodes
  for(int i = 0; i < tableSize; i++)
  {
    table[i] = nullptr;
  }
}

//function to calculate hash function
unsigned int HashTable::hashFunction(string key)
{
    unsigned int hash = 0;
    for(int i = 0; i < key.length(); i++){
      hash+=key[i];
    }
    hash = hash%tableSize;

    return hash ;
}

//function to search
node* HashTable::searchItem(string key)
{
    int index = hashFunction(key);
    node* temp = table[index];
    while(temp != nullptr){
      if(temp->key == key){
        return temp;
      }
      temp = temp->next;
    }
    return nullptr;
}

//function to insert
bool HashTable::insertItem(string key)
{
  if (!searchItem(key))
  {
    int index = hashFunction(key);
    node* n = createNode(key,nullptr);
    n->next = table[index];
    table[index] = n;
    return true;
  }
  else{
    return false;
  }
}

// function to delete
bool HashTable::deleteItem(string key)
{
    int index = hashFunction(key);
    node* temp = table[index];
    bool found = false;
    if (temp == nullptr)
    {
      return found;
    }
    else if (temp->key == key){
      // found key at head
      table[index] = temp->next;
      delete temp;
      found = true;
    }
    else{
      // case where the item is somewhere in the bucket
      while(temp->next && !found)
      {
        if(temp->next->key == key)
        {
          found = true;
          node* delptr = temp->next;
          temp->next = temp->next->next;
          delete delptr;
        }
        else{
          temp = temp->next;
        }
      }
    }
    return false;
}

// function to display hash table
void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++) {
        cout << i <<"|| ";
        node* temp = table[i];
        while(temp)
        {
            cout<< temp->key;
            if(temp->next!=nullptr)
            {
                cout<<"-->";
            }
            temp = temp->next;
        }
        cout<<endl;

    }
}
