#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#include "treeYT.h"

node* BST::createLeaf(int key){
  node* newNode = new node;
  newNode->key = key;
  newNode->leftChild = nullptr;
  newNode->rightChild = nullptr;
  return newNode;
}

/*
  Now, this is the function that will actually allow us to being adding nodes to our tree, this is going to be a recursive function and since we passed the root from the addleaf() function
  we will not have to worry about losing the address of the real root of the tree.
   - initially ptr is a reference to the root pointer.
*/
void BST::addleafprivate(int key, node* ptr){
  // edge case for an empty tree.
  if (root == nullptr){
    root = createLeaf(key);
  }
  // now we worry about where to put the next node if its not an empty tree.
  else if ( key < ptr->key ){   // going down into the left subtree if it exists
    if ( ptr->leftChild != nullptr){        // traversing down all the way
      addleafprivate(key, ptr->leftChild);
    }
    else{           // putting the leaf node into the slot
      ptr->leftChild = createLeaf(key);
    }
  }
  // now we do the same but if the key value is greater than the current value
  else if ( key > ptr->key ){   // going down into the left subtree if it exists
    if ( ptr->rightChild != nullptr){        // traversing down all the way
      addleafprivate(key, ptr->rightChild);
    }
    else{           // putting the leaf node into the slot
      ptr->rightChild = createLeaf(key);
    }
  }

  // edge case if the key has already been added.
  else{
    cout << "The key, " << key << " has already been added to the tree." << endl;
  }

}
/*
  we have this function so that when we want to add a leaf from the main file, we just have to worry about passing it an integer value and not worry about the location.
  all this function will do is call the addleafprivate() which will then handle finding the location of where the leaf should be added.
    everytime its called it will always start searching from the root.
    it also saves us from the losing the root pointer when we are messing with it when we do recursive processes .
*/
void BST::addleaf(int key){
  addleafprivate(key, root);
}
/*
    similarly to the functions above, we have a private function for this because we dont want to lose track of the root pointer since this is a recursive function
    In-order traversal is given as
      left -> root -> right
*/
void BST::inOrderTraversalPrivate(node* ptr){
  if (root != nullptr){       // first catch if the tree is empty
    if (ptr == nullptr)     // actually performing the in order traveral
    {
      return;
    }
    inOrderTraversalPrivate(ptr->leftChild);
    cout << ptr->key << ' ';
    inOrderTraversalPrivate(ptr->rightChild);
  }
  else if ( root == nullptr){
    cout << "Cannot perform operation (PRINT IN ORDER), tree is empty." << endl;
  }
}
void BST::inOrderTraversal()
{
  cout << "INORDER traveral: ";
  inOrderTraversalPrivate(root);
  cout << endl;
}
/*    preorder traversal
        root -> left -> right
*/

void BST::preOrderTraversalPrivate(node* ptr){
  if (root == nullptr){
    cout << "Cannot perform operation(PREORDER TRAVERSAL), tree is empty." << endl;
  }
  else if (root != nullptr){
    if (ptr == nullptr){    // base case
      return;
    }
    cout << ptr->key << ' ';
    preOrderTraversalPrivate(ptr->leftChild);
    preOrderTraversalPrivate(ptr->rightChild);
  }
}
/*
    Function just calls the private function and passes the root pointer.
*/
void BST::preOrderTraversal(){
  cout << "PREORDER traversal: ";
  preOrderTraversalPrivate(root);
  cout << endl;
}
/*  POST order
  left -> right -> root

*/
void BST::postOrderTraversalPrivate(node* ptr){
  if (root == nullptr){
    cout << "Cannot perform operation(POSTOERDER TRAVERSAL), tree is empty." << endl;
  }
  else if (root != nullptr){
    if (ptr == nullptr){
      return;
    }
    postOrderTraversalPrivate(ptr->leftChild);
    postOrderTraversalPrivate(ptr->rightChild);
    cout << ptr->key << ' ';
  }
}

void BST::postOrderTraversal(){
  cout << "POSTORDER traversal: ";
  postOrderTraversalPrivate(root);
  cout << endl;
}
/*
    Function accepts a pointer that will initially be a pointer to the root of the tree and an int key value that will be searched for in the tree
    then the function will then return the adress to the node if found, otherwise returns nullptr.

    Function either returns a nullptr value if found or returns address of the node in the tree.

    This will be helpful in general when we are trying to find nodes to delete or if we need to just see if a node is there in general
*/
node* BST::returnNodePrivate(node* ptr, int key){
  if (ptr != nullptr){
    if ( ptr->key == key){        // only comes here if we found the address
      //cout << "FOUND!" << endl;
      return ptr;
    }
    else{
      if ( key < ptr->key){                                 // traverse down the left side of the tree
        return returnNodePrivate(ptr->leftChild, key);
      }
      else{                                                 // traverse down the right side of the tree
        return returnNodePrivate(ptr->rightChild, key);
      }
    }
  }
  else{
    return nullptr;       // we did not find the key
  }
}
/* function calls private function to return address of node in tree if found */
node* BST::returnNode(int key){
  return returnNodePrivate(root, key);
}

/*
    Function returns the key for all nodes
*/
int BST::returnRootKey(){
  if (root != nullptr){
    return root->key;
  }
  else{
    return -9999;
  }
}
/*
    print children function will take any key and print out childnodes of the key.
    1. Take in the key that we want to be the parent and get that nodes address
    2. Determine if that key exists or not.
*/
void BST::printChildren(int key){
  node* ptr = returnNode(key);

  if ( ptr != nullptr ){            // key exists
    cout << "Parent Node: " << ptr->key << endl;

    // printing out its left children
    ptr->leftChild == nullptr ?
    cout << "Left Child: nullptr" << endl :     // case 1 if it is nullptr
    cout << "Left Child: " << ptr->leftChild->key << endl;  // case 2 if its not a nullptr

    // printing out its right children
    ptr->rightChild == nullptr ?
    cout << "Right Child: nullptr" << endl :
    cout << "Right Child: " << ptr->rightChild->key << endl;
  }
  else if (ptr == nullptr){
    cout << "Key: " << key << " was not in the tree." << endl;
  }
}
/*
    This function will
    function intitially takes in the root pointer and will return the smallest key in the
    This function will help us when we run into the case of removing a node that has two children and we
    will have to replace it with the smallest key in the right
    }
*/
int BST::findSmallestPrivate(node* ptr){
  if (root != nullptr){         // tree is not empty
    if (ptr->leftChild == nullptr){     // we hit the last left child node
      return ptr->key;
    }
    return findSmallestPrivate(ptr->leftChild);     // keep traversing down the trees furthest left child
  }
  else{                         // tree is empty
      cout << "Cannot perform operation(FIND SMALLEST), tree is empty." << endl;
      return -9999;
  }
}
int BST::findSmallest(){
  return findSmallestPrivate(root);
}

/*
    Function takes in pointer to the parent node and key value of node that needs to be deleted

    3 Things to think about when removing nodes in BST.
    1. If there are no children for the node we are looking for just delete the node
    2. If there is one child, we need to have the parent pointer of the node to be deleted point to the child
    then delete the node
    3. If the node has two children, we must replace the node with the smallest node in the right children then delete that
    node you used to replace the node that needed to intially be deleted.

    Note, this note isnt actually deleting any keys, but finding the parent nodes and child nodes
    so we can have another function actually do the delete function
*/
void BST::removeNodePrivate(node* parent, int key){
  if (root != nullptr){   // non empty tree
    // if the root is actually the node we want to delete
    if (root->key == key){
      RemoveRootMatch();      // helper function to remove the root node.
    }
    else{
      // look down the left side of the tree for the node, making the leftChild of the current parent the new parent
      if (parent->leftChild != nullptr && key < parent->key){
        parent->leftChild->key == key?
        RemoveMatch(parent,parent->leftChild, true) :    // passing the parent and its child to another function
        removeNodePrivate(parent->leftChild, key);
      }
      // look down the right side of the tree
      else if (parent->rightChild != nullptr && key > parent->key){
        parent->rightChild->key == key?
        RemoveMatch(parent,parent->rightChild, false) :    // passing the parent and its child to another function
        removeNodePrivate(parent->rightChild, key);
      }
      // did not find the key.
      else{
        cout << "The key: " << key << " was not found in the tree." << endl;
      }
    }
  }
  else if (root == nullptr){      // empty tree
    cout << "Cannot perform operation(REMOVE NODE), tree is empty." << endl;
  }
}
void BST::RemoveNode(int key){
  removeNodePrivate(root, key);
}
/*
    This is the function that actually does the node removal process.
*/

void BST::RemoveRootMatch(){
  if (root != nullptr){
    node* delptr = root;
    int rootKey = root->key;
    // case for when the root has two children
    int smallestRightChildKey;

    // case 0, root has no childen
    if (root->leftChild == nullptr && root->rightChild == nullptr){
      // clear the root pointer
      root = nullptr;
      // delete the actual root pointer
      delete delptr;
    }
    // case 1, has either a right child
    else if (root->leftChild == nullptr && root->rightChild != nullptr){   // has a right child
      root = root->rightChild;
      delptr->rightChild = nullptr;  // completely disconnecting the root and its right child
      delete delptr;
      cout << "The root node with key " << rootKey << " was deleted, the new root contains key, " << root->key << endl;
    }
    // case 1, has either a left child
    else if (root->rightChild == nullptr && root->leftChild != nullptr){   // has a right child
      root = root->leftChild;
      delptr->leftChild = nullptr;  // completely disconnecting the root and its right child
      delete delptr;
      cout << "The root node with key " << rootKey << " was deleted, the new root contains key, " << root->key << endl;
    }
    // case 2, root node has two children so we must replace it with smallest value in right subtree.
    else{
      smallestRightChildKey = findSmallestPrivate(root->rightChild);  // finds the smallest key in right subtree.
      removeNodePrivate(root, smallestRightChildKey);  // should never have more than one child, we cant just recall this function because this function
                                                      // doesnt take in a parameter so we start the iterative process by calling removeNodePrivate function!
      // now we overwrite the root with the new smallestValue , and our tree properties are still intact.
      root->key = smallestRightChildKey;
      cout << "The root node with key " << rootKey << " was deleted, the new root contains key, " << root->key << endl;
    }

  }
  else if (root == nullptr){
    cout << "Cannot perform operation(REMOVE ROOT MATCH), the tree is empty." << endl;
  }
}

void BST::RemoveMatch(node* parent, node* match, bool left){
  if (root != nullptr){
    node* delptr = nullptr;
    int matchKey = match->key;
    int smallestRightChildKey;

    // case 0, no children
    if (match->leftChild == nullptr && match->rightChild == nullptr){
      delptr = match;
      left == true ?
      parent->leftChild = nullptr :
      parent->rightChild = nullptr;
      delete delptr;

      cout << "The node containing the key " << matchKey << " was removed." << endl;
    }

    // case 1, node has one child to delete, has a right child but not a left child
    else if (match->leftChild == nullptr && match->rightChild != nullptr){    // has a right child
      left == true ?
      parent->leftChild = match->rightChild :
      parent->rightChild = match->rightChild;

      match->rightChild = nullptr;
      delptr = match;
      delete delptr;

      cout << "The node containing the key " << matchKey << " was removed." << endl;
    }
    // case 1, node has one child to delete, has a left child but not right child
    else if (match->rightChild == nullptr && match->leftChild != nullptr){    // has a left child
      left == true ?
      parent->leftChild = match->leftChild :
      parent->rightChild = match->leftChild;

      match->leftChild = nullptr;
      delptr = match;
      delete delptr;

      cout << "The node containing the key " << matchKey << " was removed." << endl;
    }

    // case 2, node has 2 children
    else{
      smallestRightChildKey = findSmallestPrivate(match->rightChild);
      removeNodePrivate(match, smallestRightChildKey);
      match->key = smallestRightChildKey;
    }
  }
  else if (root == nullptr){
      cout << "Cannot perform operation(REMOVE MATCH), the tree is empty." << endl;
  }

}

void BST::removeSubtree(node* ptr){
  if (ptr->leftChild != nullptr){   // goes through entire left subtree
    removeSubtree(ptr->leftChild);
  }
  if (ptr->rightChild != nullptr){    // goes through entire right subtree
    removeSubtree(ptr->rightChild);
  }

  cout << "Deleting node: " <<  ptr->key << endl;
  delete ptr;
}

/*      Side Notes

    Confused on why they implemented a different delete function for just the root node.

*/
