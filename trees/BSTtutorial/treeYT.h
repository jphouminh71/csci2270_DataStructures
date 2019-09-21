/*
    This binary search tree implementation follows pauls programming demonstration on youtube
    https://www.youtube.com/watch?v=sf_9w653xdE&list=PLTxllHdfUq4d-DE16EDkpeb8Z68DU7Z_Q

    The reason why we have a public and private function for each function is so that we can pass the root pointer and not have to worry about losing the address of the pointer when
    recursively traversing.
*/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

  // nodes will just consist of an integer key value, and is able to point to a left and right child pointer
struct node{
  int key;
  node* leftChild;
  node* rightChild;
};
class BST{
private:
  node* root;   // pointer to the top of the tree.
  void addleafprivate(int key, node* ptr);    // done
  void inOrderTraversalPrivate(node* ptr);    // done
  void preOrderTraversalPrivate(node* ptr);   // done
  void postOrderTraversalPrivate(node* ptr);  // done
  node* returnNodePrivate(node* ptr, int key);  // done
  int findSmallestPrivate(node* ptr);           // done
  void removeNodePrivate(node* parent, int key);// done
  void RemoveRootMatch();                       // done
  void RemoveMatch(node* parent, node* match, bool left);   // done
  void removeSubtree(node* ptr);    // going to be used for our deconstructor
public:
  BST(){        // constructor
    root = nullptr;   // initiates an empty tree, root pointer is pointing to nothing
  }
  ~BST(){       // deconstructor , called when
    removeSubtree(root); 
  }
  node* createLeaf(int key);      // done
  void addleaf(int key);          // done
  void inOrderTraversal();        // done
  void preOrderTraversal();       // done
  void postOrderTraversal();      // done
  node* returnNode(int key);      // done
  int returnRootKey();            // done
  void printChildren(int key);    // done
  int findSmallest();             // done
  void RemoveNode(int key);       // done

};
