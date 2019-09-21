/*      notes
    going to implement basic binary search tree with just nodes consisting of integers.
    This is not a self balancing tree.

        alright fuck this, this code is too messy, going to start a fresh one. 
*/
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
struct node{
  int key;
  node* leftChild = nullptr;
  node* rightChild = nullptr;
};

class BST{
private:
    node* root = nullptr;
public:
  // helper functions
  bool isEmpty();
  bool findKey(node*, int);           // this will help us when trying to delete nodes.
  node* findSmallest(node*);
  node* findGreatest(node*);
      // practice implementing the print methods, these are recursive functions
  void preordertraversal(node*);
  void postordertraversal(node*);         // done
  void inordertraversal(node*);
    // insertion and deletion functions
  void insertKey(node*, node*);
  void deleteKey(int f_key);

    // driver that allows us to interact with the tree.
  void driver();
};

/* return a boolean that checks if the root pointer to the tree and checks if its a nullptr */
bool BST::isEmpty(){
  if (root == nullptr){
    return true;
  }
  return false;
}
/*
  function will a boolean if the key we are looking for is found.
    since this is a binary search tree, we will traverse down the tree and compare around looking for the right key.
*/
bool  BST::findKey(node* root, int key){
  bool empty = isEmpty();
  if (empty == true){
    cout << "Cannot perform operation(FIND KEY), tree is empty." << endl;
  }
  else if(empty == false){
    if (root->key == key){     // base case if we find the node
      cout << "KEY FOUND!" << endl;
      return true;
    }
    else if (key > root->key){
      cout << "GOING TO THE RIGHT CHILD!" << endl;
      findKey(root->rightChild, key);
    }
    else if (key < root->key){
      cout << "GOING TO THE LEFT CHILD!" << endl;
      findKey(root->leftChild, key);
    }
    else{                                 // should only hit if we didnt find the key.
      cout << "KEY NOT FOUND!" << endl;
      return false;
    }
  }
  return false;   // if we have a problem look here first.
}
/*
  function will return the smallest key in the tree.

  Essentially the process of this will involve traversing down the furthest level of the left side of the tree and returning that node.
  We know we have hit the bottom of the tree if (root->leftChild == nullptr) , root being the node that has been passed down recursively.
*/
node* BST::findSmallest(node* root){
  bool empty = isEmpty();
  if (empty == true){
    cout << "Cannot perform operation(FIND SMALLEST), tree is empty"  << endl;
    return nullptr;
  }
  else{
    // base case to check if the current root is the smallest node
    if (root->leftChild == nullptr){
      cout << "FOUND THE SMALLEST VALUE, "  << root->key << "." << endl;
      return root;
    }
    // keep passing the left child of the root til we hit the last level
    findSmallest(root->leftChild);
  }
  return nullptr;
}
/*
  function will return the node with the greatest value in the tree.
  functions the same way as findSmallest() but just traverse through the right child.
*/
node* BST::findGreatest(node* root){
  bool empty = isEmpty();
  if (empty == true){
    cout << "Cannot perform operation(FIND SMALLEST), tree is empty"  << endl;
    return nullptr;
  }
  else{
    // base case to check if the current root is the smallest node
    if (root->rightChild == nullptr){
      cout << "FOUND THE GREATEST VALUE, "  << root->key << "." << endl;
      return root;
    }
    // keep passing the left child of the root til we hit the last level
    findGreatest(root->rightChild);
  }
  return nullptr;
}
    //                                    From now on we will assume that the trees are not empty for simplicity
/*        PREORDER Traversal
    Print recursively in the order
      root --> left --> right

    Example Diagram,

    0             3         <- root
                /   \
    1          1       4        <- nodes
            /   \    /  \
    2      0     2  5    6        <- leaf nodes

              3, 1, 0, 2, 4, 5, 6
*/
void BST::preordertraversal(node* root){
  if (root == nullptr){
    return;
  }
  cout << root->key << endl;
  preordertraversal(root->leftChild);
  preordertraversal(root->rightChild);
}

/*      POSTORDER TRAVERSAL         , this function doesnt look right
    left -> right -> root

    Example Diagram,

    0             3         <- root
                /   \
    1          1       4        <- nodes
            /   \    /  \
    2      0     2  5    6        <- leaf nodes

            0, 2, 1, 5, 6, 4, 3
*/
void BST::postordertraversal(node* root){
  if (root == nullptr){
    return;
  }
  postordertraversal(root->leftChild);
  postordertraversal(root->rightChild);
  cout << root->key << endl;
}

/*      INORDER TRAVERSAL
    left -> root -> right

    Example Diagram,

    0             3         <- root
                /   \
    1          1       4        <- nodes
            /   \    /  \
    2      0     2  5    6        <- leaf nodes

            0, 1, 3, 3, 5, 4, 6
*/
void BST::inordertraversal(node* root){
  if (root == nullptr){
    return;
  }
  postordertraversal(root->leftChild);
  cout << root->key << endl;
  postordertraversal(root->rightChild);
}

/*    3 edge cases to handle for node insertion of binary search tree.
    1. empty tree.
    2. checking to see if the value is smaller than the current node
    3. checking to see if the value is greater than the current node

    function is passed address for root node and will hold the new node until it is placed into the tree.
*/
void BST::insertKey(node* root, node* newNode){
  // base case and kind of first edge case
  if ( root == nullptr ){
    root = newNode;
    cout << root->key << endl;
  }
  // traverse the right side of the tree
  else if ( newNode->key > root->key){
    cout << "BIGGER" << endl;
    insertKey(root->rightChild, newNode);
  }
  // traverse the left side of the tree
  else if (newNode->key < root->key){
    cout << "SMALLER" << endl;
    insertKey(root->leftChild, newNode);
  }
}
// worry about this at the need
void BST::deleteKey(int f_key){

}
void BST::driver(){
  // since this is not a self balancing tree we need to add the nodes into this order, 3 1 4 0 2 5 6 so we can make sure that our traversals match out output
  node* three = new node;
  three->key = 3;
  node* one = new node;
  one->key = 1;
  node*  four = new node;
  four->key = 4;
  node* zero = new node;
  zero->key = 0;
  node*  two = new node;
  two->key = 2;
  node*  five = new node;
  five->key = 5;
  node*  six = new node;
  six->key = 6;

  insertKey(root, three);
  insertKey(root, four);
  insertKey(root, two);

  inordertraversal(root);


}

int main(int argc, char* argv[]){
  // since this is not a self balancing tree we need to add the nodes into this order, 3 1 4 0 2 5 6 so we can make sure that our traversals match out output
  node* three = new node;
  three->key = 3;
  node* one = new node;
  one->key = 1;
  node*  four = new node;
  four->key = 4;
  node* zero = new node;
  zero->key = 0;
  node*  two = new node;
  two->key = 2;
  node*  five = new node;
  five->key = 5;
  node*  six = new node;
  six->key = 6;

  BST root = nullptr;



  return 0;
}
