#include "YTbst.hpp"

BST::BST()  // constructor
{
  root = nullptr;
}
BST::node* BST::CreateLeaf(int key)  // creates a new leaf node
{
  node* newLeaf = new node;
  newLeaf->key = key;
  newLeaf->leftChild = nullptr;
  newLeaf->rightChild = nullptr;
  return newLeaf;   // returning this so then you can work with it after it is created.
}
void BST::addLeaf(int key)
{
  addLeafPrivate(key, root);
}
void BST::addLeafPrivate(int key, node* ptr)
{
  if (root == nullptr)    // base case
  {
    root = CreateLeaf(key);
  }
  else if (key < ptr->key)  // going into the left subtree
  {
    if (ptr->leftChild != nullptr)
    {
      addLeafPrivate(key, ptr->leftChild);
    }
    else{
      ptr->leftChild = CreateLeaf(key);
    }
  }
  else if (key > ptr->key)  // going into the right subtree
  {
    if (ptr->rightChild != nullptr)
    {
      addLeafPrivate(key, ptr->rightChild);
    }
    else{
      ptr->rightChild = CreateLeaf(key);
    }
  }
  else
  {
    cout << "The key: " << key << " has already been added to the tree. " << endl;
  }
}
void BST::printInOrderTraversal()
{
  printInOrderTraversalPrivate(root);
}
void BST::printInOrderTraversalPrivate(node* ptr)
{
  if (root != nullptr)
  {
    if (ptr->leftChild != nullptr)
    {
      printInOrderTraversalPrivate(ptr->leftChild);
      //cout << ptr->leftChild->key << ' ';
    }
    cout << ptr->key << ' ';
    if (ptr->rightChild != nullptr)
    {
      printInOrderTraversalPrivate(ptr->rightChild);
      //cout << ptr->rightChild->key << ' '
    }
  }
  else
  {
    cout << "The tree is empty." << endl;
  }
}
BST::node* BST::returnNodePrivate(int key, node* ptr)
{
  if (ptr != nullptr)
  {
    if (ptr->key == key)
    {
      return ptr;
    }
    else{
      if (key < ptr->key)
      {
        return returnNodePrivate(key, ptr->leftChild);  // recursively going down into left subtrees
      }
      else{
        return returnNodePrivate(key, ptr->rightChild);
      }
    }
  }
  else
  {
    return nullptr;
  }
}
BST::node* BST::returnNode(int key)
{
  return returnNodePrivate(key, root);
}

int BST::returnRootKey()
{
  if (root != nullptr)
  {
    return root->key;
  }
  else
  {
    return -1000;
  }
}
void BST::printChildren(int key)
{
  node* tempptr = returnNode(key);
  if (tempptr != nullptr)
  {
    cout << "Parent node = " << tempptr->key << endl;

    tempptr->leftChild == nullptr ?
    cout << "Left child = nullptr\n":                       // this is if left pointer is not pointing to anything, otherwise case 2
    cout << "LeftChild = " << tempptr->leftChild->key << endl;

    tempptr->rightChild == nullptr ?
    cout << "rightchild = nullptr\n":                       // this is if left pointer is not pointing to anything, otherwise case 2
    cout << "rightchild = " << tempptr->rightChild->key << endl;
  }
  else{
    cout << "The key " << key << " is not in the tree." << endl;
  }
}
int BST::findSmallestPrivate(node* ptr)
{
  if (root == nullptr)
  {
    cout << "The tree is empty\n";
    return -1000;
  }
  else{
    if (ptr->leftChild != nullptr)
    {
      return findSmallestPrivate(ptr->leftChild);
    }
    else
    {
      return ptr->key;
    }
  }

}
int BST::findSmallest()
{
  return findSmallestPrivate(root);
}
int BST::removeNodePrivate(int key, node* parent)
{
  if (root == nullptr)
  {
    cout << "Tree is empty, nothing to delete." << endl;
  }
  else{
    if (root->key == key)
    {
      RemoveRootMatch();
      //return 0;
    }
    else{
      if (key < parent->key && parent->leftChild != nullptr)
      {
        parent->leftChild->key == key ?
        RemoveMatch(parent,parent->leftChild,true) :
        removeNodePrivate(key, parent->leftChild);
      }
      else if (key > parent->key && parent->rightChild != nullptr)
      {
        parent->rightChild->key == key ?
        RemoveMatch(parent,parent->rightChild,false) :
        removeNodePrivate(key, parent->rightChild);
      }
      else{
        cout << "The key " << key << " was not found in the tree\n";
      }
    }
  }
}
void BST::removeNode(int key)
{
  removeNodePrivate(key, root);
}
void BST::RemoveRootMatch()
{
  if (root == nullptr)
  {
    cout << "Tree is empty, nothing to delete." << endl;
  }
  else{
    node* delptr;
    int rootKey = root->key;
    int smallestInRightSubTree;
    // case 0; root has 0 children
    if (root->leftChild == nullptr and root->rightChild == nullptr)
    {
      root = nullptr;
      delete delptr;
    }
    // case 1: root node has 1 child
    else if (root->leftChild == nullptr and root->rightChild != nullptr)
    {
      root = root->rightChild;
      delptr->rightChild = nullptr;
      delete delptr;
      cout << "The root node with key " << rootKey << " was deleted\n";
      cout << "The new root contains key " << root->key << endl;
    }
    else if (root->rightChild == nullptr and root->leftChild != nullptr)
    {
      root = root->rightChild;
      delptr->leftChild = nullptr;
      delete delptr;
      cout << "The root node with key " << rootKey << " was deleted\n";
      cout << "The new root contains key " << root->key << endl;
    }
    // case 2: root node has 2 children
    else{
      smallestInRightSubTree = findSmallestPrivate(root->rightChild);
      removeNodePrivate(smallestInRightSubTree,root);
      root->key = smallestInRightSubTree;
      cout << "The root key containing key " << root->key << " was overwritten with " << smallestInRightSubTree << endl;
    }
  }
}
void BST::RemoveMatch(node* parent, node* match, bool left)
{
  if (root == nullptr)
  {
    cout << "Cannot remove match. The tree is empty." << endl;
  }
  else{
    node* delptr;
    int matchKey = match->key;
    int smallestInRightSubTree;
    // case 0, no children
    if (match->rightChild == nullptr and match->leftChild == nullptr)
    {
      delptr = match;
      match->leftChild == true ? leftChild == nullptr: rightChild == nullptr;
      delete delptr;
      cout << "The node containing key " << matchKey << " was removed." << endl;
    }
    // case 1 matching node has 1 child
    else if (match->leftChild == nullptr and match->rightChild != nullptr)
    {
      match->leftChild == true ? parent->leftChild = match->rightChild: parent->rightChild = match->rightChild ;
      delptr = match;
      delete delptr;
      cout << "The node containing key " << matchKey << " was removed." << endl;
    }
    else if (match->leftChild != nullptr and match->rightChild == nullptr)
    {
      match->leftChild == true ? parent->leftChild = match->leftChild: parent->rightChild = match->leftChild ;

      delptr = match;
      delete delptr;
      cout << "The node containing key " << matchKey << " was removed." << endl;
    }
    // last case, where the matching node has 2 children
    else
    {
      smallestInRightSubTree = findSmallestPrivate(match->rightChild);
      removeNodePrivate(smallestInRightSubTree, match);
      match->key = smallestInRightSubTree;
    }
  }
}
