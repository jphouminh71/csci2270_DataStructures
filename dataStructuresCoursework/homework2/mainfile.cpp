// ==========================================
// Created: August 23, 2018
// @Jonathan Phouminh
//
// Description: Counts unique words in a file
// outputs the top N most common words
// ==========================================

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// struct to store word + count combinations
struct wordItem
{
    string word;
    int count;
};

/*
* Function name: getStopWords
* Purpose: read stop word list from file and store into vector
* @param ignoreWordFile - filename (the file storing ignore/stop words)
* @param _vecIgnoreWords - store ignore words from the file (pass by reference)
* @return - none
* Note: The number of words is fixed to 50
*/

// function read in the file containing the ignore words and pushed them into the vector
void getStopWords(const char* ignoreWordFileName, vector<string> &_vecIgnoreWords)
{
  ifstream infile;
  infile.open(ignoreWordFileName);
  if (infile.is_open())
  {
    cout << "NOW READING IN: " << ignoreWordFileName << endl;
    string line;
    int count = 0;
    while(getline(infile,line))
    {
      _vecIgnoreWords.push_back(line);
    }

  }
  else if(!infile.is_open())
  {
    cout << "File failed to open" << endl;
  }
}
/*
* Function name: isStopWord
* Purpose: to see if a word is a stop word
* @param word - a word (which you want to check if it is a stop word)
* @param _vecIgnoreWords - the vector type of string storing ignore/stop words
* @return - true (if word is a stop word), or false (otherwise)
*/

bool isStopWord(string word, vector<string> &_vecIgnoreWords)
{
  bool isStopWord = false;
  for (int i = 0; i < _vecIgnoreWords.size(); i++)
  {
    if (word == _vecIgnoreWords[i])
    {
      isStopWord = true;
    }
    else
    {
      return isStopWord;
    }
  }
}
/*
* Function name: getTotalNumberNonStopWords
* Purpose: compute the total number of words saved in the words array (including repeated words)
* @param list - an array of wordItems containing non-stopwords
* @param length - the length of the words array
* @return - the total number of words in the words array (including repeated words multiple times)
*/
int getTotalNumberNonStopWords(wordItem list[], int length)
{

}

// ./a.out 10 HW2-HungerGames_edit.txt HW2-ignoreWords.txt
int main(int argc, char *argv[])
{
    vector<string> vecIgnoreWords;

    // verify we have the correct # of parameters, else throw error msg & return
    if (argc != 4)
    {
      cout << "not enough parameters" << endl;
    }
    else if (argc == 4)
    {
        cout << "Usage: ";
        cout << argv[0] << "Number of words: " << argv[1] << "Filename: " << argv[2] << "Ignore Filename: " << argv[3] << endl;
        getStopWords(argv[2],vecIgnoreWords);
        cout << "NEW VECTOR SIZE: " << vecIgnoreWords.size() << endl;
        return 0;
    }

    /* **********************************
    1. Implement your code here.

    Read words from the file passed in on the command line, store and
    count the words.

    2. Implement the six functions after the main() function separately.
    ********************************** */

    return 0;
}
