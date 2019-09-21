#include <iostream>
#include <string>
using namespace std;

struct Node
{
  int key;
  Node* left;
  Node* right;
};

// A utility function to create a new BST node
struct Node* newNode(int item)
{
  Node* temp = (Node*)malloc(sizeof(Node));
  temp->key = item;
  temp->left = temp->right = nullptr;
  return temp;
};

class BSTclass
{
private:

public:
  BSTclass()
  {
    cout << "BST class constructor called" << endl;
  }
  void inorder(Node*);
  Node* insert(Node*, int);
  Node* minValueNode(Node*);
  Node* deleteNode(Node*, int);
};
//
// traversing through the binary tree INORDER, left root right
void BSTclass::inorder(Node *root)
{
  if (root != NULL)
  {
    inorder(root->left);
    cout << root->key;
    cout << " ";
    inorder(root->right);
  }
}

// Utility function to insert a new Node with given key in BST
Node* BSTclass::insert(Node* node, int key)
{
  // if the tree is empty, return a new nodes
  if (node == NULL)
  {
    return newNode(key);
  }
  // otherwise , recur down the trees
  if (key < node->key)
  {
    node->left = insert(node->left, key);
  }
  else
  {
    node->right = insert(node->right, key);
  }
  return node;
}
Node* BSTclass::minValueNode(Node* node)
{
  Node* current = node;
  // loop down to find leftmost leaf
  while (current->left != NULL)
  {
    current = current->left;
  }
  return node;
}

// given a binary search tree and a key, this function deletes the key and returns the new ROOT
Node* BSTclass::deleteNode(Node* root, int k)
{
  // base case
  if (root == NULL)
  {
    return root;
  }
  // recursive calls for ancestors of
  // Node to be deleted
  if (root->key > k)
  {
    root->left = deleteNode(root->left, k);
    return root;
  }
  else if (root->key < k)
  {
    root->right = deleteNode(root->right, k);
    return root;
  }

  // we reach here when root is the node to be deleted
  // if one of the children is empty
  if (root->left == NULL)
  {
    Node* temp = root->right;
    delete root;
    return temp;
  }
  else if (root->right == NULL)
  {
    Node* temp = root->left;
    delete root;
    return temp;
  }
  // if both children exits
  else
  {
    Node* succParent = root->right;
    // find successor
    Node* succ = root->right;
    while (succ->left != NULL)
    {
      succParent = succ;
      succ = succ->left;
    }

    // delete successor, since successor is always left child of its parent we can make successors right child as left of its parent
    succParent->left = succ->right;
    // copy successor data to root
    root->key = succ->key;
    // delete sucessor and return root
    delete succ;
    return root;
  }


}
int main(int argc, char* argv[])
{
  /*
    creating
    50
  30  70
20  40  60 80
  */
  BSTclass bst;
  Node* root = NULL;
  root = bst.insert(root,50);
  root = bst.insert(root,30);
  root = bst.insert(root,20);
  root = bst.insert(root,40);
  root = bst.insert(root,70);
  root = bst.insert(root,60);
  root = bst.insert(root,80);

  cout << "Inorder traversal of the given tree \n";
  bst.inorder(root);

  cout << "\nDelete20\n";
  root = bst.deleteNode(root,20);
  cout << "Inorder traversal of the modified tree " << endl;
  bst.inorder(root);

  cout << "\nDelete 30\n";
  root = bst.deleteNode(root,30);
  cout << "Inorder traversal of the modified tree \n";
  bst.inorder(root);
  cout << "\nDelete 50\n";
  root = bst.deleteNode(root,50);
  cout << "Inorder traversal of the modified tree \n";
  bst.inorder(root);

  cout << endl;

  return 0;
}
