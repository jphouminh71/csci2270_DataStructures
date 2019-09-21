#ifndef BST_HPP
#define BST_HPP

using namespace std;

struct Node{
    int key;
    Node* left = NULL;
    Node* right = NULL;
};

class BST{
    private:
        Node* createNode(int data);
        Node* root;

        /** since root is a private member we need helper functions
         to access root for insertion, searching and printing **/

        Node* addNodeHelper(Node*, int);
        int getSizeHelper(Node*);
        int getMinValueHelper(Node*);
        int getMaxDepthHelper(Node*);

        void printTreeHelper(Node*);

        /**Destructor will call this function to recursively delete all node**/

        void destroyNode(Node *root);

    public:

        void addNode(int);              // function to insert a node in the tree.
        int getSize();                  // function to get number of nodes in the tree
        int getMinValue();              // function to get minimum value in the tree
        int getMaxDepth();              // function to get depth of the tree
        // bool searchKey(int);            // function to search a data in the tree
        void printTree();               //function to print the tree

        BST();                          // default constructor
        BST(int data);                  // parameterized constructor
        ~BST();                         // destructor
        // void deleteNode(int);



};
#endif
