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
    int uniqueNonStopWords = 0;
    int totalNonStopWords = 0;
    string word;
    while(infile >> word)
    {
      if (stopWordTable.isInTable(word) == false && uniqueWordsTable.isInTable(word) == false)
      {
        totalNonStopWords++;
        uniqueNonStopWords++;
        uniqueWordsTable.addWord(word);
      }
      else if (stopWordTable.isInTable(word) == false && uniqueWordsTable.isInTable(word) == true)
      {
        totalNonStopWords++;
        uniqueWordsTable.incrementCount(word);
      }
    }

    uniqueWordsTable.printTopN(stoi(argv[1]));
    cout << "#\n";
    cout << "Number of collisions: " << uniqueWordsTable.getNumCollisions() << endl;
    cout << "#\n";
    cout << "Unique non-stop words: " << uniqueNonStopWords << endl;
    cout << "#\n";
    cout << "Total non-stop words: " << totalNonStopWords << endl;

  }
}


// // find total nonstop words;
// wordItem* tempptr = stopWordTable;
// while(tempptr != nullptr)
// {
//   if(tempptr->next != nullptr)    // go through the bucket if theres more than one thing
//   {
//     while(tempptr != nullptr)
//     {
//       totalNonStopWords = totalNonStopWords + tempptr->count;
//       tempptr = tempptr->next;
//     }
//   }
//   else{
//     totalNonStopWords = totalNonStopWords + tempptr->count;
//   }
//   tempptr = tempptr->next;
// }
