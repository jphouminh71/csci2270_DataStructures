#include <iostream>
using namespace std;

// binary search tree node has data, pointer to left child, and a pointer to right children

struct Node
{
  int data;
  struct Node* left, *right;
  Node(int data)
  {
    this->data = data;
    left = right = nullptr;
  }
};

/* given a binary tree, print its nodes according to the "bottom - up" postorder traversal */
// left -> right -> root
void printPostOrder(struct Node* node)
{
  if (node == nullptr) // root is empty
  {
    return;
  }
  // first recu on the left subtree
  printPostOrder(node->left);

  // then recurr on the right subtree
  printPostOrder(node->right);

  // now deal with the node
  cout << node->data << " ";
}

// given a binary tree, print its nodes in intorder
// left -> root -> right
void printInOrder(struct Node* node)
{
  if (node == nullptr)
  {
    return;
  }
  // first recurr on the left child
  printInOrder(node->left);

  // now deal with the node
  cout << node->data << " ";

  // then recurr on the right subtree
  printInOrder(node->right);

}

// root -> left -> right
void printPreOrder(struct Node* node)
{
  if (node == nullptr)
  {
    return;
  }
  // first print the data of node , which is the root
  cout << node->data << " ";

  // first recurr on the left child
  printPreOrder(node->left);

  // then recurr on the right subtree
  printPreOrder(node->right);
}

int main(int argc, char* argv[])
{
  struct Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  cout << endl << "Preorder traversal of binary tree is " << endl;
  printPreOrder(root);
  cout << endl << "Inordrer traversal of binary tree is " << endl;
  printInOrder(root);
  cout << endl << "PostOrder traversal of binary tree is " << endl;
  printPostOrder(root);
  return 0;
}
