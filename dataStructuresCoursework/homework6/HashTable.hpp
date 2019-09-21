#ifndef HW_7_HASH_TABLE
#define HW_7_HASH_TABLE

#include <string>

// struct to store word + count combinations
struct wordItem
{
    std::string word;
    int count;
    wordItem* next;
};

/* class HashTable for storing words.
 *   You will create two hash tables in your driver:
 *      - one for storing stop words
 *      - one for storing unique non-stop words
 *   Why? We can load all the stopwords into the first table.
 *   Then, we can quickly check that first hash table to see if
 *   a word is a stopword before adding it to the second.
 */
class HashTable {
  public:
    HashTable(int hashTableSize); // done
    ~HashTable();       // done but get checked 
    void addWord(std::string word);   // done
    bool isInTable(std::string word); // done
    void incrementCount(std::string word);  // done
    void printTopN(int n);
    int getNumCollisions(); // done
    int getNumItems();    // done
    int getTotalNumWords();   // done

  private:
    /* member functions */
    unsigned int getHash(std::string word);   // done
    wordItem* searchTable(std::string word);  // done

    /* instance variables */
    wordItem* *hashTable;
    int hashTableSize;
    int numItems;
    int numCollisions;
};


/* size to make your stopwords hash table */
const int STOPWORD_TABLE_SIZE = 50;

/* Required functions for use in main.
 *   you are free to also define your own helper functions
 *   for your driver in your .cpp files if you wish.
 * These are the same functions from hw2, but use a
 *   hashtable instead of a vector. */

/* load stopwords into the stopwords hash table */
void getStopWords(char *ignoreWordFileName, HashTable &stopWordsTable); // done
/* check table to see if a word is a stopword or not */
bool isStopWord(std::string word, HashTable &stopWordsTable);

#endif
