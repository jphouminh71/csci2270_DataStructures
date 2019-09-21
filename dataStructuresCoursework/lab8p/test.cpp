#include <iostream>
using namespace std;

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
