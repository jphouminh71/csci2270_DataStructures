#include <iostream>
#include "BST.hpp"
using namespace std;

/**
Create a node with key as data
**/

Node* BST:: createNode(int data)
{
    Node* newNode = new Node;
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BST::BST()
{

}

/**
parameterized constructor. It will create the root and put the data in the root.
**/

BST::BST(int data)
{
    root = createNode(data);
}

/**
Destructor
**/

BST::~BST(){
     destroyNode(root);
}

 /**
 This function will destroy the subtree rooted at currNode.
 Think about in what order should you destroy. POSTORDER. or right-left-root
 **/

void BST:: destroyNode(Node *currNode)  // this is post order traversal
{
     if(currNode!=NULL)
     {
         destroyNode(currNode->left);
         destroyNode(currNode->right);
         delete currNode;
         currNode = NULL;
     }
 }

//--------------------------------------------INSERT NODE IN THE TREE--------------------------------------

/**
This function will add the data in the tree rooted at currNode.
We will call this function from addNode.
NOTE: root is a private member of BST. Hence addNode function can not diretly access it.
      So we need this helper function. Implement your code for inserting a node in this function.
**/

Node* BST:: addNodeHelper(Node* currNode, int data) // folling the definition of BST
{
    if (currNode == nullptr)
    {
      return createNode(data);  // if there is nothing, create a node of that data and return it
    }
    if (currNode->key > data) // we should go to the left subtree
    {
      // left subtree
      currNode->left = addNodeHelper( currNode-> left, data);
    }
    else if (currNode->key < data) // we should be traversing to the right tree
    {
      // right subtree
      currNode->right = addNodeHelper(currNode->right, data);
    }
    return currNode;
}

 /**
 This function will insert the data in the tree. As this function can not access the rooted
 it will call the addNodeHelper function.
 **/

void BST:: addNode( int data)
{
  if (root == nullptr)  // this is just a safety check
  {
    root = createNode(data);
  }
  else{
    addNodeHelper(root, data);
  }
}

//--------------------------------------------GET NUMBER OF NODES-------------------------------------------
// size tree = (size of left trees + size of right tree + 1 (the root))
int BST::getSizeHelper(Node* currNode)
{
    if (currNode == nullptr)
    {
      return 0;
    }

    return getSizeHelper(currNode->left) + getSizeHelper(currNode->right) + 1;
}

int BST::getSize()
{
    return getSizeHelper(root);
}
//-------------------------------------------GET MINIMUM VALUE FROM THE TREE---------------------------------

/**
Find the minimum in the subtree rooted ar currNode
Go to the left most node of this subtree.
**/

int BST::getMinValueHelper(Node* root)
{
    if (root->left == nullptr)
    {
      return root->key;
    }
    return getMinValueHelper(root->left);
}

int BST::getMinValue()
{
  if (root == nullptr)
  {
    cout << " Tree is empty. " << endl;
    return -1;
  }
  return getMinValueHelper(root);
}

//--------------------------------------------GET MAXIMUM DEPTH OF THE TREE----------------------------------

int BST::getMaxDepthHelper(Node* currNode)
{
    if(currNode == nullptr) // no nodes
    {
      return 0;
    }
    if (currNode->left == nullptr && currNode->right == nullptr)  // if its a leaf node
    {
      return 0;
    }
    int left_depth = getMaxDepthHelper(currNode->left);
    int right_depth = getMaxDepthHelper(currNode->right);
    if (left_depth > right_depth)
    {
      return left_depth + 1;  // account for the root
    }
    return right_depth + 1; // acconuting for the root

}

int BST::getMaxDepth()
{
  return getMaxDepthHelper(root);
}

void BST:: printTreeHelper(Node* curNode)
{
    if(curNode)
    {
           printTreeHelper( curNode->left);
           cout << " "<< curNode->key;
           printTreeHelper( curNode->right);
    }
}
void BST:: printTree(){
    printTreeHelper(root);
    cout<<endl;
}
