
#include <iostream>
#include "BST.hpp"
using namespace std;

int main (int argc, char* argv[]){
  BST tree(5);


  tree.addNode(3); //left child to 5
  tree.addNode(9); //right child to 5


  tree.addNode(1); //left child to 3
  tree.addNode(4); //right child to 3


  tree.addNode(6); //left child to 9


  tree.addNode(2); //left child to 4
  // insert(tmp,4);


  tree.printTree();
  cout << endl << "There are " << tree.getSize() << " nodes in the tree" << endl;
  cout << "The minimum value node is:  " << tree.getMinValue() << endl;
  cout << "There max depth is: " << tree.getMaxDepth() << endl;


  tree.deleteNode(2);
  std::cout << "Remaining Tree :" << endl;
  tree.printTree();

  tree.deleteNode(9);
  std::cout << "Remaining Tree :" << endl;
  tree.printTree();

  tree.deleteNode(2);
  std::cout << "Remaining Tree :" << endl;
  tree.printTree();

  tree.deleteNode(5);
  std::cout << "Remaining Tree :" << endl;
  tree.printTree();

  tree.deleteNode(1);
  std::cout << "Remaining Tree :" << endl;
  tree.printTree();

  tree.deleteNode(3);
  std::cout << "Remaining Tree :" << endl;
  tree.printTree();

  tree.deleteNode(6);
  std::cout << "Remaining Tree :" << endl;
  tree.printTree();

  tree.deleteNode(4);
  std::cout << "Remaining Tree :" << endl;
  tree.printTree();
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
        if(currNode->title.compare(title) > 0 && currNode->leftChild != nullptr) // left sub tree
        {
            currNode->leftChild = deleteMovieHelper(currNode->leftChild, title);
        }
        if(currNode->title.compare(title) < 0 && currNode->rightChild != nullptr)
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
            MovieNode* nodeToDelete = new MovieNode;
            string smallestChild = findSmallestHelper(currNode->leftChild);
            currNode = searchHelper(currNode, smallestChild);
            currNode->title = smallestChild;
            currNode->ranking = nodeToDelete->ranking;
            currNode->year = nodeToDelete->year;
            currNode->quantity = nodeToDelete->quantity;
            currNode->leftChild = deleteMovieHelper(currNode->leftChild, smallestChild);
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

  MovieNode* tempptr = new MovieNode;
  tempptr = searchHelper(root, title);
  else if(tempptr->title == title)
  {
      root = deleteMovieHelper(root, title);
  }
  // else{
  //    cout << "Movie not found." << endl;
  // }
  //delete tempptr;
}
