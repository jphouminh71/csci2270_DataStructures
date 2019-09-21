#include <iostream>
#include <fstream>
#include "MovieTree.hpp"

using namespace std;

void Split(string words, char seperate, string array[], int size)
{
    if (words.length() == 0)
    {
        cout << "string is empty" << endl;  // if string is empty returns o
    }
    string sub_string; 
    int z = 0;
    int index = 0;
    int length = words.length();
    for (int i = 0; i < length; i++)
    {
        if (words[i] == seperate)  // if there is a seperator, shows the the end of the word and beginning of the next word
        {
            sub_string = words.substr(z,(i-z));  // creates substring to add into array
            z = i+1; // new z will be where index next to seperator
            array[index] = sub_string; // substring added to array
            index++;
        }
    }
    
    array[index] = words.substr(z, words.length()); // gets the last word after the last seperator
}

int main(int argc, char* argv[])
{
    ifstream file;
    string line;
    file.open(argv[1]);
    string arr[4];
    MovieTree Tree;
    while(getline(file,line))
    {
        Split(line, ',', arr, 4);   
        Tree.addMovieNode(stoi(arr[0]), arr[1], stoi(arr[2]), stoi(arr[3]));  
    }
    string input = "";
    string title = "";
    while(input != "4")
    {
        cout << "======Main Menu======" << endl;
        cout << "1. Find a movie" << endl;
        cout << "2. Rent a movie" << endl;
        cout << "3. Print the inventory" << endl;
        cout << "4. Quit" << endl;
        cout << "Press 1 to find a movie, 2) to rent a movie, 3) to print the inventory or 4) to quit." << endl;
        getline(cin,input);
        if(input == "1")
        {
            cout << "Enter Title" << endl;
            getline(cin,title);
            Tree.findMovie(title);
        }
        else if(input == "2")
        {
            cout << "Enter title:" << endl;
            getline(cin,title);
            Tree.rentMovie(title);
        }
        else if(input == "3")
        {
            Tree.printMovieInventory();
        }
        else
        {
            cout << "Goodbye!" << endl;
        }
    }
    return 0;
    
}