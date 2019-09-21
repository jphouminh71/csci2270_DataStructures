#include <iostream>
using namespace std;

// functions for binary search Trees

struct BstNode
{
  int data;
  BstNode* left;
  BstNode* right;
};
// function to create a new node
BstNode* GetNewNode(int data)
{
  BstNode* newNode = new BstNode();
  newNode->data = data;
  newNode->left = newNode->right = nullptr;
  return newNode;
}
BstNode* Insert(BstNode* root, int data)
{
  if (root == nullptr)  // empty trees
  {
    root = GetNewNode(data);    // calls a function that creates a new node
  }
  // if data to be inserted is lesser, insert in the left subtree
  else if (data <= root->data)
  {
    root->left = Insert(root->left,data);
  }
  // otherwise we know that the value is bigger than our root
  else{
    root->right = Insert(root->right,data);
  }
  return root;  // this return the ACTUAL ROOT of the tree
}
/*
  deleter() to be implemented..
  can you traverse it?
*/
// to serach an elemenet in BST, returns true if element is found
bool Search(BstNode* root, int data)
{
  if (root == nullptr)   // base case 1, we did not find the data
  {
    return false;
  }
  else if (root->data == data)    // base case 2, we found the value
  {
    return true;
  }
  else if (data <= root->data)  // search through the left subtrees because we know its going to be less than
  {
    return Search(root->left,data);
  }
  else
  {
    return Search(root->right,data);
  }
}

void printPreOrder(BstNode* root)
{
  if (root == nullptr)
  {
    return;
  }
  //cout << "Print Pre order: " << endl;
  cout << root->data << " ";

  printPreOrder(root->left);
  printPreOrder(root->right);
}


int main(int argc, char* argv[])
{
  BstNode* root = nullptr; // creating an empty tree
  // code to test the logic
  root = Insert(root,15);
  root = Insert(root,10);
  root = Insert(root,20);
  root = Insert(root,25);
  root = Insert(root,8);
  root = Insert(root,12);
  printPreOrder(root);
  return 0;
}
