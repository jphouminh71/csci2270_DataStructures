#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

class BST
{
private:
  struct node
  {
    int key;
    node* leftChild;
    node* rightChild;
  };

  node* root;
  void addLeafPrivate(int key, node* ptr);
  void printInOrderTraversalPrivate(node* ptr);
  node* returnNodePrivate(int key,node* ptr);
  int findSmallestPrivate(node* ptr);
  int removeNodePrivate(int key, node* parent);
  void RemoveRootMatch();
  void RemoveMatch(node* parent, node* match, bool left); // if the bool variable is true then the matching child is the left child of the parent node. 
public:
  BST();  // constructor
  //~BST(); // destructor
  node* CreateLeaf(int key);
  void addLeaf(int key);
  void printInOrderTraversal();
  node* returnNode(int key);
  int returnRootKey();
  void printChildren(int key);
  int findSmallest();
  void removeNode(int key);
};

// int numValues = 0;
// int value =0;
// array[10]
// for (int i = 0 ;i < size; i++)
// {
//   if (array[i] >= 0 )
//   {
//     value = value + array[i];
//     numValues;
//   }
// }
//
// int mean = value / numValues;
// ofstream outfile;
// outfile.open("text.txt");
// outfile << mean;
//
// return numValues;
