#include <iostream>
using namespace std;

struct Node{
  int id = -1; // update this value when you are creating a node instance
  Node* next = nullptr; // the first instance of node should be pointing to null, you handle the other stuff in outside functions
};

class llstack{
public:
  llstack();    // default constructor
  llstack(int); // constructor            , this is overloading constructor
  ~llstack();   // destructor
  bool push(int);   // push function pushings another node to top of the stack , essentially creating a new node that is now the head, which is the top of the stack , returns bool
  bool pop(int&);     // function will delete whatever was on the top of the stack, passing in a reference to an integer , returns bool
  bool peek(int&);  // peeking to the top of the stack by passing in a reference to to an integer , returns bool

private:
  Node* head = nullptr;     // pointer to the head of the linked list , initally going to be pointing to nothing until it is set equal to something
  Node* createNode(int,Node*);  // this function is going to be the call to the Node contructor with first arg being the key of the node and then a pointer to the next node
  void deleteStack();     // the reasons these are private because these will not be needed for external programmers
  bool isEmpty();
};

llstack::llstack()
{

}
llstack::llstack(int key)
{
  Node* newNode = createNode(key, nullptr);
  head = newNode;
}
Node* llstack::createNode(int key, Node* nextNode)
{
  Node* newNode = new Node;
  newNode->id = key;
  newNode->next = nextNode;
  return newNode;
}
llstack::~llstack()
{
  deleteStack();
}
void llstack::deleteStack()
{
  // for me to write
}
bool llstack::push(int givenValue)
{
  // new nodes for the LLstack go to the head, last in first out
  Node* newNode = createNode(givenValue, head); // creating a new node with the given key and then pointing its next pointer to whatever the head was pointing too
  head = newNode; // the head of the linked list is now the the createNewNode
  return true; // newNode was added successfully
}
bool llstack::pop(int& itemToRemove)    // we are passing by reference here because we are going to need whatever value we just popped as to be stored in that variable so we can use it in print statement
{
  // you always pop from the head, first one in last one out
    // the head
  if (isEmpty() == false)
  {
    itemToRemove = head->id;    // grabbing the value from head;
    Node* tempptr = head;
    head = head->next;
    delete tempptr;
    return true;  // the head , or the top of the stack, has been successfully removed
  }
  else{
    cout << "The stack is empty! nothing to pop." << endl;
    return false; // failed to pop , no value to pop
  }
}
bool llstack::isEmpty()
{
  if (head == nullptr)  // if the head is nothing
  {
    return true;
  }
  else{
    return false;
  }
}
bool llstack::peek(int& value)
{
  return true;
}

int main(int argc, char* argv[])
{
  llstack stackeyOne(15);   // creating a linked list stack with initial head as 15, pointing to nothing
  stackeyOne.push(16);  // creating a new node and putting it to the top of the stack, or the head in this case
  int NodeIdToGet;
  if (stackeyOne.pop(NodeIdToGet) == true)
  {
    cout << "Node with id: " << NodeIdToGet << " just removed from the stack." << endl;
  }
  if (stackeyOne.pop(NodeIdToGet) == true)
  {
    cout << "Node with id: " << NodeIdToGet << " just removed from the stack." << endl;
  }
  if (stackeyOne.pop(NodeIdToGet) == true)
  {
    cout << "Node with id: " << NodeIdToGet << " just removed from the stack" << endl;
  }
  //cout << "Top of the stack: " << stackeyOne.peek() << endl;
  return 0;
}
