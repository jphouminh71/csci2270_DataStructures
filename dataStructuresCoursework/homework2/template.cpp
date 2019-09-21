// where you left off, figuring out how to use a dynamic array, you initialized a ptr of of 100 but then you got stuck with passing it too a doubleing function

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;

// struct to store word + count combinations
struct wordItem
{
public:
    string word;
    int count;
    wordItem(){     // constructor DEFAULT

    }
    wordItem(string givenWord, int givenCount){   // constructor
      word = givenWord;
      count = givenCount;
    }
};


// Purpose: read stop word list from file and store into vector
void getStopWords(const char *ignoreWordFileName, vector<string> &_vecIgnoreWords)
{
  ifstream infile;
  infile.open(ignoreWordFileName);
  if (infile.is_open())
  {
    //cout << "NOW READING IN: " << ignoreWordFileName << endl;           // COMMENT THIS OUT
    string line;
    int i = 0;
    while(getline(infile,line))
    {
      _vecIgnoreWords[i] = line;         // loading the vector with the words to ignore
      i++;

    }
  }
  else if(!infile.is_open())
  {
    cout << "File failed to open" << endl;
  }
}

// Purpose: to see if a word is a stop word
bool isStopWord(string word, vector<string> &_vecIgnoreWords)
{
  bool isStopWord = false;
  for (int i = 0; (unsigned)i < _vecIgnoreWords.size(); i++)
  {
    if (word == _vecIgnoreWords[i])
    {
      isStopWord = true;
      return isStopWord;
    }
  }
  return false;
}

// Purpose: compute the total number of words saved in the words array (including repeated words)
int getTotalNumberNonStopWords(wordItem list[], int numberOfUniqueWords)
{
  int totalWords = 0;
  for (int i = 0; i < numberOfUniqueWords; i++)
  {
    totalWords+= list[i].count;
  }
  return totalWords;
}

// Purpose: sort an array of wordItems, decreasing, by their count fields
void arraySort(wordItem list[], int length)     // list array was sorted through bubble sorting
{
    bool is_sorted = false;
    int i = 0;
    while (is_sorted == false)
    {
        is_sorted = true;
        for (int j = 0; j < length - 1 - i ; j++)
        {
            if (list[j].count < list[j + 1].count)
            {
                wordItem previous_value = list[j];
                list[j] = list[j + 1];
                list[j + 1] = previous_value;
                is_sorted = false;
            }
        }
     i++;
    }
}

//Purpose: to print the top N high frequency words
void printTopN(wordItem wordItemList[], int topN)
{
  for (int i = 0; i < topN; i++)
  {
      cout << wordItemList[i].count << " - " << wordItemList[i].word << endl;
  }
}
bool isInArray(string word, wordItem *uniqueWordArray, int currentWordCount)    // function serves to see if the word is already in the array
{
  for (int i = 0; i < currentWordCount; i++)
  {
    if (word == uniqueWordArray[i].word)
    {
      return true;
    }
  }
  return false;
}

// ./a.out 10 HW2-HungerGames_edit.txt HW2-ignoreWords.txt
int main(int argc, char *argv[])
{
    if (argc != 4)      // conditional checking for valid number of arguments via command line
    {
      cout << "not enough parameters" << endl;
      return -1;    // failed to provide enough arguments
    }
    else if (argc == 4)       // conditional that will carry out the program
    {
      const int STOPWORD_LIST_SIZE = 50;
      const int INITIAL_ARRAY_SIZE = 100;
      int capDoubleCounter = 0;     // counts how many times new memory needed to be allocated
      int uniqueWordCap = 0;    // the current max memory allocation currently

      vector<string> vecIgnoreWords(STOPWORD_LIST_SIZE);
      wordItem *uniqueWords = new wordItem[INITIAL_ARRAY_SIZE];   // allocating an space for an array of unique words.
      uniqueWordCap = INITIAL_ARRAY_SIZE;


        cout << "Usage: ";
        cout << argv[0] << "Number of words: " << argv[1] << "Filename: " << argv[2] << "Ignore Filename: " << argv[3] << endl;
        getStopWords(argv[2],vecIgnoreWords);   // vector is now loaded with all the stop words
        ifstream infile;    // here we will begin proccessing the hunger games text
        infile.open(argv[3]);

        if (!infile.is_open())    // checking if the file opened
        {
          cout << "FILE FAILED TO OPEN. TERMINATING"  << endl;
          return -1;
        }
        int currentWordCount = 0;   // counter for how many words are currently in the current array
        string line;
        while(getline(infile,line)){      // parsing through each line
          stringstream ss;
          ss << line;
          string word;
          while(getline(ss,word,' '))   // parsing throught the current line
          {
              if (currentWordCount == 0)
              {
                wordItem newWord = wordItem(word,1);  // initializing object for the very first word;
                uniqueWords[currentWordCount] = newWord;
                currentWordCount++;
              }
              else if (currentWordCount != 0) // check if word is in the ignore word then check if it is already in the array
              {
                if (currentWordCount < uniqueWordCap) // if there is still space in the array for more memory
                {
                  bool foundIgnore = false;
                  bool foundInArray = false;
                  foundIgnore = isStopWord(word, vecIgnoreWords);
                  foundInArray = isInArray(word, uniqueWords, currentWordCount);
                  if (foundIgnore == false && foundInArray == true && word != "")  // if it's not an ignore word but it's already in the array, take the word and update it's object counts
                  {
                    for(int i = 0; i < currentWordCount; i++)   // now looping through to find the actual word and updating it's count
                    {
                      if (word == uniqueWords[i].word)
                      {
                        uniqueWords[i].count+=1;
                      }
                    }
                  }
                  else if (foundIgnore == false && foundInArray == false && word != "") // if it's not in the ignore words and if it's not already in the array, put the new word in
                  {
                    wordItem newWord = wordItem(word,1);  // creating a word object and initalizing it's word count to 1;
                    uniqueWords[currentWordCount] = newWord;  // putting in the new word
                    currentWordCount++;
                  }

                }
                else if (currentWordCount == uniqueWordCap)   // we need to double the capsize, then add the new word.
                {
                  capDoubleCounter++;   // adding one to the double encounter
                  uniqueWordCap = uniqueWordCap * 2;  // doubling the capsize
                  wordItem *tempPtrArray = new wordItem[uniqueWordCap];  // allocating more memory for object array with double the size;
                  for (int i = 0; i < currentWordCount; i++)    // copying all the values of the old ptr array into a new one with double the cap size
                  {
                    tempPtrArray[i] = uniqueWords[i];
                  }
                  delete[] uniqueWords; // cleared the memory of the old array
                  uniqueWords = tempPtrArray; // putting the new ptr array you just created into the orinal place holder of the main array
                  bool foundIgnore = false;
                  bool foundInArray = false;
                  foundIgnore = isStopWord(word, vecIgnoreWords);
                  foundInArray = isInArray(word, uniqueWords, currentWordCount);
                  if (foundIgnore == false && foundInArray == true && word != "")  // if it's not an ignore word but it's already in the array, take the word and update it's object counts
                  {
                    for(int i = 0; i < currentWordCount; i++)   // now looping through to find the actual word and updating it's count
                    {
                      if (word == uniqueWords[i].word)
                      {
                        uniqueWords[i].count+=1;
                      }
                    }
                  }
                  else if (foundIgnore == false && foundInArray == false && word != "") // if it's not in the ignore words and if it's not already in the array, put the new word in
                  {
                    wordItem newWord = wordItem(word,1);  // creating a word object and initalizing it's word count to 1;
                    uniqueWords[currentWordCount] = newWord;  // putting in the new word
                    currentWordCount++;
                  }
                  // tempPtrArray[currentWordCount] = newWord;   // after doubling the array size, finally add the newWord
                  // currentWordCount++;
                  // delete[] uniqueWords; // cleared the memory of the old array
                  // uniqueWords = tempPtrArray; // putting the new ptr array you just created into the orinal place holder of the main array

                }
              }

          }
        }
        //currentWordCount--; // accounting for the last word in the entire file

        int totalWords;
        totalWords = getTotalNumberNonStopWords(uniqueWords,currentWordCount);
        arraySort(uniqueWords,currentWordCount);
        printTopN(uniqueWords,stoi(argv[1]));
        cout << "#" << endl;
        cout << "Array Doubled: " << capDoubleCounter << endl;
        cout << "#" << endl;
        cout << "Unique non-stop words: " << currentWordCount << endl;
        cout << "#" << endl;
        cout << "Total non-stop words: " << totalWords << endl;
        //
        //for (int i = 0; i < vecIgnoreWords.size(); i++)
        //{
          //cout << vecIgnoreWords[i] << endl;
        //}

        // cout << capDoubleCounter << "<<<<<<< DOUBLE" << endl;
        // cout << currentWordCount << "<<< Number of unique words" << endl;
        // cout << INITIAL_ARRAY_SIZE << "<<< INITIAL" << endl;
        // cout << currentWordCount << "<<< CURRENT W COUNT" << endl;
        // cout << uniqueWordCap << "<<<< UNIQUE W CAPSIZE" << endl;
        return 0;
    }
/*
    Read words from the file passed in on the command line, store and
    count the words.
*/


}



/*  THIS HAS THE METHODS TO COMPLETE ARRAY DOUBLING
for (int i = 0; i < vecIgnoreWords.size(); i++) // looping through the vector to see if the word was in there or not
{
  if (word == "")   // disregarding space marks;
  {
    break;
  }
  if (word == vecIgnoreWords[i]) // if the word isn't in the list
  {
    wordItem newWord = wordItem(word, i); // making an object for the words
    if (currentWordCount != uniqueWordCap)    // if the current count of words < capsize, put the word into the array
    {
      uniqueWords[currentWordCount] = newWord;    // setting the new word of the last position into the array of unique words
      currentWordCount++;
      break;
    }
    else if (currentWordCount == uniqueWordCap)   // double the cap size, copy into a NEW ptr array, then delete the old array
    {
      uniqueWordCap = uniqueWordCap * 2;  // doubling the capsize
      capDoubleCounter++;
      wordItem *tempPtrArray = new wordItem[uniqueWordCap];  // allocating more memory for object array with double the size;
      for (int i = 0; i < currentWordCount; i++)    // copying all the values of the old ptr array into a new one with double the cap size
      {
        tempPtrArray[i] = uniqueWords[i];
      }
      tempPtrArray[currentWordCount] = newWord;   // after doubling the array size, finally add the newWord
      currentWordCount++;
      delete[] uniqueWords; // cleared the memory of the old array
      uniqueWords = tempPtrArray; // putting the new ptr array you just created into the orinal place holder of the main array
      break;
      //delete[] tempPtrArray;
    }

  }
}
*/
