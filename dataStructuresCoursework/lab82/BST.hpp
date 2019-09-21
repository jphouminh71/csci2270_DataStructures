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
        int getMaxValueHelper(Node*);
        int getMaxDepthHelper(Node*);
        Node *deleteNodeHelper(Node* , int );
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
        void deleteNode(int key);
        BST();                          // default constructor
        BST(int data);                  // parameterized constructor
        ~BST();                         // destructor
        // void deleteNode(int);



};
#endif












































MovieNode* searchHelper(MovieNode *currentNode, string title)
{
    if(currentNode->title.compare(title) > 0 && currentNode->leftChild != nullptr) // search through the left subtree
    {
        return searchHelper(currentNode->leftChild, title);
    }
    if(currentNode->title.compare(title) < 0 && currentNode->rightChild != nullptr) // search through the right subtree
    {
        return searchHelper(currentNode->rightChild, title);
    }
    return currentNode;

}

string findSmallestHelper(MovieNode * pointer)
{
    if(pointer == nullptr)
    {
        return "";
    }
    if(pointer -> leftChild!= nullptr)
    {
        return findSmallestHelper(pointer -> leftChild);
    }
    return pointer -> title;

}


MovieNode * deleteMovieHelper(MovieNode * currNode, string title)
{
    if(currNode == nullptr)
    {
        return nullptr;
    }
    if(currNode->title != title)
    {
        if(currNode ->title.compare(title) > 0 && currNode->leftChild != NULL) // left sub tree
        {
            currNode->leftChild = deleteMovieHelper(currNode->leftChild, title);
        }
        if(currNode->title.compare(title) < 0 && currNode->rightChild != NULL)
        {
            currNode->rightChild = deleteMovieHelper(currNode->rightChild, title);
        }
    }
    else// found the movie
    {
        if(currNode->rightChild == nullptr && currNode->leftChild == nullptr)// no children
        {
            delete currNode;
            currNode = nullptr;
        }
        else if(currNode->rightChild == nullptr) // has a left child
        {
            MovieNode * temp = currNode->leftChild;
            delete currNode;
            currNode = temp;
        }
        else if(currNode->leftChild == nullptr) // has a right child
        {
            MovieNode * temp = currNode->rightChild;
            delete currNode;
            currNode = temp;
        }
        else
        {
            MovieNode * delNode = new MovieNode;
            string smallestChild = findSmallestHelper(currNode -> leftChild);
            delNode = searchHelper(currNode, smallestChild);
            currNode->title = smallestChild;
            currNode->ranking = delNode->ranking;
            currNode->year = delNode->year;
            currNode->quantity = delNode->quantity;
            currNode->leftChild = deleteMovieHelper(currNode->leftChild, smallestChild);
        }
    }
    return currNode;

}


void MovieTree::deleteMovie(string title)
{
    MovieNode * CheckNode = new MovieNode;
    CheckNode = searchHelper(root, title);
    if(CheckNode -> title == title)
    {
        root = deleteMovieHelper(root, title);
    }
    else
    {
        cout << "Movie not found." << endl;
    }
    //delete CheckNode;
}
