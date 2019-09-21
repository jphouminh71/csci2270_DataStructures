#include <iostream>
#include "MovieTree.hpp"
using namespace std;

MovieTree::MovieTree()
{
    root = nullptr;
}

MovieTree::~MovieTree()
{
    //need to destroy;
}

void MovieTree::AddMovieNodePrivate(MovieNode* CurrNode, MovieNode* newNode)
{

    if(CurrNode->title.compare(newNode -> title) > 0) // go into left subtree
    {
        if(CurrNode -> leftChild != NULL)
        {
            AddMovieNodePrivate(CurrNode -> leftChild, newNode);
        }
        else
        {
            CurrNode -> leftChild = newNode;
        }
    }
    else if(CurrNode->title.compare(newNode -> title) < 0) // right subtree
    {
        if(CurrNode -> rightChild != NULL)
        {
            AddMovieNodePrivate(CurrNode -> rightChild, newNode);
        }
        else
        {
            CurrNode -> rightChild = newNode;
        }
    }

}

void MovieTree::addMovieNode(int ranking, std::string title, int releaseYear, int quantity)
{
    MovieNode * newNode = new MovieNode;
    newNode -> ranking = ranking;
    newNode -> title = title;
    newNode -> year = releaseYear;
    newNode -> quantity = quantity;
    newNode -> rightChild = NULL;
    newNode -> leftChild = NULL;    
    //MovieNode* Temp = root;
    if(root == NULL)
    {
        root = newNode;
    }
    else
    {
        AddMovieNodePrivate(root, newNode);
    }

}

void MovieTree::printMovieInventory()
{
    MovieNode* PTR = root;
    printHelper(PTR);
}

void MovieTree::printHelper(MovieNode * TEMP_ROOT)
{
    if(TEMP_ROOT)
    {
        printHelper(TEMP_ROOT -> leftChild);
        cout << "Movie: " << TEMP_ROOT -> title << " " << TEMP_ROOT -> quantity << endl;
        printHelper(TEMP_ROOT -> rightChild);
    }
}

MovieNode * MovieTree::searchHelper(MovieNode *currNode, string title)
{
    if(currNode ->title.compare(title) > 0 && currNode -> leftChild != NULL) // left sub tree
    {
        return searchHelper(currNode -> leftChild, title);
    }
    if(currNode -> title.compare(title) < 0 && currNode -> rightChild != NULL) // right sub tree
    {
        return searchHelper(currNode -> rightChild, title);
    }
    return currNode;
    
}

void MovieTree::findMovie(string title)
{
    MovieNode * NEWNODE = new MovieNode;
    NEWNODE = searchHelper(root, title);
    if(NEWNODE -> title == title)
    {
        cout << "Movie " << "'"<< NEWNODE->title <<"' Info:"<< endl;
    	cout << "================================" << endl;
    	cout << "Ranking : " << NEWNODE->ranking << endl;
    	cout << "Title   : " << NEWNODE->title << endl;
    	cout << "Year    : " << NEWNODE->year << endl;
    	cout << "Quantity: " << NEWNODE->quantity << endl;
    }
    else
    {
        cout << "Movie not found." << endl;
    }
    
}

void MovieTree::rentMovie(string title)
{
    MovieNode * NEWNODE = new MovieNode;
    NEWNODE = searchHelper(root, title);
    if(NEWNODE -> title == title && NEWNODE -> quantity == 0)
    {
        cout <<"Movie out of stock." << endl;
    }
    else if(NEWNODE -> title == title)
    {
        NEWNODE-> quantity = (NEWNODE -> quantity) -1;
        cout << "Movie has been rented." << endl;
        cout << "Movie " << "'"<< NEWNODE->title <<"' Info:"<< endl;
    	cout << "================================" << endl;
    	cout << "Ranking : " << NEWNODE->ranking << endl;
    	cout << "Title   : " << NEWNODE->title << endl;
    	cout << "Year    : " << NEWNODE->year << endl;
    	cout << "Quantity: " << NEWNODE->quantity << endl;
    }
    else
    {
        cout << "Movie not found." << endl;
    }
    
}