#ifndef HASH_HPP
#define HASH_HPP

#include <string>


using namespace std;

struct node
{
    string key;
    struct node* next;
};

class HashTable
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    node* *table;

    node* createNode(string key, node* next);
public:
    HashTable(int bsize);  // Constructor

    // inserts a key into hash table
    bool insertItem(string key);

    // deletes a key from hash table
    bool deleteItem(string key);

    // hash function to map values to key
    unsigned int hashFunction(string key);

    void printTable();

    node* searchItem(string key);
};

#endif
