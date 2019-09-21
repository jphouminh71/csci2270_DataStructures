#include "HashTable.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

HashTable::HashTable(int newhashTableSize)    // something wrong here.
{
  hashTableSize = newhashTableSize;
  hashTable = new wordItem*[hashTableSize]; // allocating memory for array of pointers to word items
  for(int i = 0; i < hashTableSize; i++)
  {
    hashTable[i] = nullptr;
  }
  numItems = 0;
  numCollisions = 0;

}
HashTable::~HashTable()
{
  for(int i = 0; i < hashTableSize; i++)
  {
      wordItem* tempptr = hashTable[i];

      while (tempptr != nullptr)
      {
        wordItem * delptr = tempptr->next;
        delete tempptr;
        tempptr = delptr;
      }

  }
  delete [] hashTable;
}
unsigned int HashTable::getHash(string word)   // DJb2 Hashing method
{
  unsigned int hash = 5381;
  for(unsigned int i = 0; i < word.length(); i++)
  {
    hash = hash*33 + int(word[i]);
  }
  hash = hash % hashTableSize;
  return hash;
}
void HashTable::addWord(string word)
{
    bool found = isInTable(word);
    int index = getHash(word);
    if (hashTable[index] == nullptr)  // empty bucket
    {
      wordItem* newWord = new wordItem;
      newWord->word = word;
      newWord->count = 1;
      newWord->next = nullptr;  // points to null because its the only thing in the bucket
      hashTable[index] = newWord;
    }
    else if(found == false) {   // handle the case of chaining
      numCollisions++;
      wordItem* newWord = new wordItem;
      newWord->word = word;
      newWord->count = 1;
      newWord->next = nullptr;

      wordItem* p = hashTable[index];
      //wordItem* tempptr = nullptr;

      while(p->next != nullptr)
      {
        p = p->next;
      }
      p->next = newWord;
      // hashTable[index]->next = newWord;
    }
    numItems++;
}
bool HashTable::isInTable(string word)      // possible warning coming from here for no return;
{
  int index = getHash(word);  // if the word exists in the hash table then it must be in this index
  if (hashTable[index] == nullptr)  // the bucket is empty
  {
    return false;
  }
  else{
    bool found = false;
    wordItem* tempptr = hashTable[index];
    while(tempptr != nullptr)
    {
      if (tempptr->word == word)
      {
        found = true;
        return true;
      }
      tempptr = tempptr->next;
    }

    return found;
  }

}
wordItem* HashTable::searchTable(string word)
{
  int index = getHash(word);
  if (hashTable[index] == nullptr)  // empty bucket;
  {
    return nullptr;
  }
  else{
    wordItem* tempptr = hashTable[index];   // pointing to the top of the bucket
    while(tempptr->next != nullptr)
    {
      if (tempptr->word == word)
      {
        return tempptr;   // we found the word
      }
      tempptr = tempptr->next;
    }

    return nullptr; // the word wasn't found

  }
}
int HashTable::getTotalNumWords()
{
  int count = 0;
  for(int i = 0; i < hashTableSize; i++)
  {
    if (hashTable[i] != nullptr && hashTable[i]->word != "")
    {
      wordItem* tempptr = hashTable[i];
      count = count + tempptr->count;
      while(tempptr->next != nullptr) // going through the linked list to count more of the words
      {
        tempptr = tempptr->next;
        count = count + tempptr->count;
      }
    }

  }
  return count;
}
void HashTable::incrementCount(std::string word)  // lets assume that we only call this function when the word exits to keep the function short
{
  int index = getHash(word);
  hashTable[index]->count+=1;
}

/* load stopwords into the stopwords hash table */    // NOT DONE
void getStopWords(char *ignoreWordFileName, HashTable &stopWordsTable)  // this function will be called when you are loading in the hash table
{
    ifstream infile;
    infile.open(ignoreWordFileName);
    if (!infile.is_open())
    {
      cout << ignoreWordFileName << " FAILED TO OPEN.\n";
    }
    else{
      string line;
      while(getline(infile,line))
      {
        stopWordsTable.addWord(line);
      }
    }
}     // stop words should have now been added to the hash table;
int insertIntoSortedArray(wordItem* myArray[], int wordCount, wordItem* newValue){   // sorts and keeps everything in
  if (wordCount == 0){         // this is to handle the first value
    myArray[0] = newValue;
    wordCount++;
  }
  else{
    int index = -1;
    for (int i = 0; i < wordCount; i++)
    {
      if(newValue->count > myArray[i]->count)
      {
          index = i;
          break;
      }
    }
    if(index == -1)
    {
      myArray[wordCount] = newValue;
      wordCount++;
    }
    else{
      for(int j=wordCount-1; j>= index;j--)
      {
          myArray[j+1] = myArray[j];
      }
      myArray[index] = newValue;
      wordCount++;
    }
  }
  return wordCount;
}
void HashTable::printTopN(int n)  // NOT DONE
{
    int wordCount = 0;
    wordItem* sortedArray[n];
    //wordItem* tempptr = hashTable[0];
    for (int i = 0; i < hashTableSize; i++)
    {
      wordItem* tempptr = hashTable[i];
      while (tempptr!=nullptr)
      {
        if (wordCount != n)
        {
          wordCount = insertIntoSortedArray(sortedArray,wordCount,tempptr);
          //tempptr = tempptr->next;
        }
        else if (sortedArray[n-1]->count < tempptr->count && wordCount == n){
          sortedArray[n-1] = nullptr;
          wordCount = insertIntoSortedArray(sortedArray,wordCount-1, tempptr);
        }
        tempptr = tempptr->next;
      }
    }
    for (int i = 0; i < n; i++)
    {
      cout << sortedArray[i]->count << " - " << sortedArray[i]->word << endl;
    }
}
int HashTable::getNumCollisions()
{
  return numCollisions;
}
int HashTable::getNumItems()
{
  return numItems;
}
bool isStopWord(string word, HashTable& stopWordsTable)
{
  bool found = false;
  if (stopWordsTable.isInTable(word))
  {
    found = true;
  }
  return found;
}
