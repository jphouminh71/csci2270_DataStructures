#include "HashTable.cpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{
  //int numMostCommonWords = stoi(argv[1]);   // this should be passed into the printTopN function
  //string hungerGamesText = argv[2];
  //string stopwordText = argv[3];
  //int uniqueWordHashSize = stoi(argv[4]);

  HashTable stopWordTable(STOPWORD_TABLE_SIZE);   // creating instances of the hash tables
  HashTable uniqueWordsTable(stoi(argv[4]));
  getStopWords(argv[3],stopWordTable);    // populating the stopword hash table

  /* populate the getstopword table
    then start reading in the hunger games text, if it isn't a ignore word
    put it into the other hash table for unique words, by just calling the addWord function
    for each word
  */
  ifstream infile;
  infile.open(argv[2]);
  if (infile.fail())
  {
    cout << "FILE FAILED TO OPEN." << endl;
    return -1;
  }
  else{
    bool emptyBucket = false;
    bool alreadyExists = false;
    string word;
    while(infile >> word)
    {
      if (stopWordTable.isInTable(word) == false && uniqueWordsTable.isInTable(word) == false))
      {
        uniqueWordsTable.addWord(word);
      }
      else if (stopWordTable.isInTable == false && uniqueWordsTable.isInTable == true)
      {
        wordItem* tempptr = hashTable[index];   // go through the bucket. find the word and incrememnt its count
        while(tempptr != nullptr)
        {
          if(tempptr->word == word)
          {
            incrementCount(tempptr->word);
          }
          tempptr = tempptr->next;
        }
      }
    }
    uniqueWordsTable.printTopN(stoi(argv[1]));
    cout << "#\n";
    cout << "Number of Collisions: " << uniqueWordsTable.getNumCollisions() << endl;
    cout << "#\n";
    cout << "Unique non-stop words: " << "10" << endl;
    cout << "#\n";
    cout << "Total non-stop words: " << "11" << endl;

  }
}
