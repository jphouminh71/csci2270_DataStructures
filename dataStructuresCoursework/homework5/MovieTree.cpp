#include "MovieTree.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;
MovieTree::MovieTree()
{
  root = nullptr;   // initiate the root of the tree to null, this will change once we start adding in nodes
}
void destructor(MovieNode* temp)
{
  if (temp != nullptr)
  {
    destructor(temp->leftChild);
    destructor(temp->rightChild);
    delete temp;
    temp = nullptr;
  }
}
MovieTree::~MovieTree() // postOrder, right root left
{
  destructor(root);
}
void printHelper(MovieNode * tempRoot)
{
    if(tempRoot)
    {
        printHelper(tempRoot->leftChild);
        cout << "Movie: " << tempRoot->title << " " << tempRoot->quantity << endl;
        printHelper(tempRoot->rightChild);
    }
}
void MovieTree::printMovieInventory()
{
  //MovieNode* tempRoot = root;
  printHelper(root);
}
void addMovieHelper(MovieNode* root, MovieNode* newMovie)
{
  if(root->title.compare(newMovie->title) > 0) // going into the left subtree , compare function same as ==
    {
        if(root->leftChild != nullptr)
        {
            addMovieHelper(root->leftChild, newMovie);
        }
        else
        {
            root->leftChild = newMovie;
        }
    }
    else if(root->title.compare(newMovie->title) < 0) // going into the right subtree
    {
        if(root->rightChild != nullptr)
        {
            addMovieHelper(root->rightChild, newMovie);
        }
        else
        {
            root->rightChild = newMovie;
        }
    }
}
void MovieTree::addMovieNode(int ranking, string title, int releaseYear, int quantity)
{
    MovieNode* newMovie = new MovieNode;
    newMovie->ranking = ranking;
    newMovie->title = title;
    newMovie->year = releaseYear;
    newMovie->quantity = quantity;
    newMovie->rightChild = nullptr;
    newMovie->leftChild = nullptr;

  if (root == nullptr)
  {
    root = newMovie;
  }
  else{
    addMovieHelper(root,newMovie); // make a helper function to make code cleaner. this will execute if a root was already established
  }
}

MovieNode* searchHelper(MovieNode *currentNode, string title)
{
    if(currentNode->title.compare(title) > 0 && currentNode->leftChild != nullptr) // search through the left subtree
    {
        return searchHelper(currentNode->leftChild, title);
    }
    if(currentNode->title.compare(title) < 0 && currentNode->rightChild != nullptr) // search through the right subtree
    {
        return searchHelper(currentNode->rightChild, title);
    }
    return currentNode;

}

void MovieTree::findMovie(string title)
{
   MovieNode * NEWNODE = searchHelper(root, title);
   if(NEWNODE->title == title)
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
   MovieNode * rentMovie = searchHelper(root, title);

   if(rentMovie->title == title && rentMovie->quantity == 0)
   {
       cout <<"Movie not found." << endl;
   }
   else if(rentMovie->title == title)
   {
     rentMovie->quantity = (rentMovie->quantity) -1;    // decrement quantity of movies left
     cout << "Movie has been rented." << endl;
     cout << "Movie " << "'"<< rentMovie->title <<"' Info:"<< endl;
     cout << "================================" << endl;
     cout << "Ranking : " << rentMovie->ranking << endl;
     cout << "Title   : " << rentMovie->title << endl;
     cout << "Year    : " << rentMovie->year << endl;
     cout << "Quantity: " << rentMovie->quantity << endl;
     if (rentMovie->quantity == 0)
     {
         deleteMovie(title);
     }
   }
   else
   {
       cout << "Movie not found." << endl;
   }
}

int countMoviesHelper(MovieNode *tempptr)
{
    if(!tempptr)
    {
        return 0;
    }
    return (1 + countMoviesHelper(tempptr->leftChild) + countMoviesHelper(tempptr->rightChild));

}

void MovieTree::countMovies()
{
    int count = 0;
    count = countMoviesHelper(root);
    cout << "Count = " << count << endl;
}
string findSmallestHelper(MovieNode* tempptr)
{
    if(tempptr == nullptr)
    {
        return "";
    }
    if(tempptr->leftChild!= nullptr)
    {
        return findSmallestHelper(tempptr->leftChild);
    }
    return tempptr->title;

}
MovieNode* deleteMovieHelper(MovieNode* currNode, string title)
{
  if(currNode == nullptr)
    {
        return nullptr;
    }
    if(currNode->title != title)
    {
        if(currNode->title.compare(title) > 0)// && currNode->leftChild != nullptr) // left sub tree
        {
            currNode->leftChild = deleteMovieHelper(currNode->leftChild, title);
        }
        if(currNode->title.compare(title) < 0)// && currNode->rightChild != nullptr)
        {
            currNode->rightChild = deleteMovieHelper(currNode->rightChild, title);
        }
    }
    else// found the movie
    {
        if(currNode->rightChild == nullptr && currNode->leftChild == nullptr)// no children
        {
            delete currNode;
            currNode = nullptr;
        }
        else if(currNode->rightChild == nullptr) // has a left child
        {
            MovieNode* temp = currNode->leftChild;
            delete currNode;
            currNode = temp;
        }
        else if(currNode->leftChild == nullptr) // has a right child
        {
            MovieNode* temp = currNode->rightChild;
            delete currNode;
            currNode = temp;
        }
        else  // take the other child and make it the parent so we dont lose track of nodes
        {
            //MovieNode* nodeToDelete = new MovieNode;
            string smallestChildTitle = findSmallestHelper(currNode->rightChild);
            MovieNode* nodeToDelete = searchHelper(currNode, smallestChildTitle);
          //  nodeToDelete = searchHelper(currNode, smallestChildTitleTitle);
            currNode->title = smallestChildTitle;
            currNode->ranking = nodeToDelete->ranking;
            currNode->year = nodeToDelete->year;
            currNode->quantity = nodeToDelete->quantity;
            currNode->rightChild = deleteMovieHelper(currNode->rightChild, smallestChildTitle);
        }
    }
    return currNode;
}
void MovieTree::deleteMovie(string title)
{
  if (root == nullptr)
  {
    cout << "Movie not found." << endl;
  }
  else{
    //MovieNode* tempptr = new MovieNode;
    MovieNode* tempptr = searchHelper(root, title);
    if (tempptr->title == title)
    {
      root = deleteMovieHelper(root, title);
    }
    else{
      cout << "Movie not found." << endl;
    }
  }
}
