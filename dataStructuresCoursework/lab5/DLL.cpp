#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Node{
  int key;
  Node* previous;
  Node* next;
};
class DoubleLinkedList
{
private:
  Node* head;
  Node* tail;
public:
  DoubleLinkedList(){ // defining constructor
    head = NULL;
    tail = NULL;
  }
  void append(int key){   // goal is to take the key and add it to the end of the list
  // 1. create the new node
  Node* newNode = new Node;     // initialized the new node
  newNode->key = key;
  newNode->previous = NULL;
  newNode->next = NULL;
  // 2. add to list at the end

  // cases:
    // case 1; emptyLiist
  if (head == NULL){
    head = newNode;
    tail = newNode;
  }
    // case 2; not an empty list
  else{
    tail->next = newNode;
    newNode->previous = tail;
    tail = newNode;
  }

  // details
    // new node prev to tail
    // tail point to new node
    // new node next = NULL



  }
  void insertAt(int index, int key)
  {
    Node* newNode = new Node;     // initialized the new node
    newNode->key = key;
    newNode->previous = NULL;
    newNode->next = NULL;
    // case 0; (index out of bounds)
      //impli details: update class to count list length
      // opt1: just add to end of array, iMPLEMENTING THIS ONE
      // opt2: return an error (false)
    // case 1: (index is at the beginning)
    // case 2: (index is at the end of the list, tail)
    // case 3: (list is empty)

    // CASE 4; if index is at the beginning
    if (head == NULL)
    {
      head = newNode;   // have to update both head and tail!
      tail = newNode;
    }
    // CASE 1: if the index is 0
    else if (index == 0)
    {
      newNode->next = head;
      head->previous = newNode;
      head = newNode;
    }
    // CASE 2, 3, 0
    // end, middle, invalid index
    else{
      Node* prevPtr = head;
      int i = 0;
      for (int i = 0; i < index - 1 && (prevPtr->next != NULL); i++){
        prevPtr = prevPtr->next;
      }
      if (i != index - 1)
      {
        cout << "Error" << endl;
        prevPtr = tail;
      }
      // right spot , place Node
      newNode->previous = prevPtr;
      newNode->next = prevPtr->next;
      prevPtr->next = newNode;
      if (newNode->next != NULL){
        newNode->next->previous = newNode;
      }
      else{
        tail = newNode;
      }
    }


  }
  void print(){
    Node* currentNode = head;
    while(currentNode != NULL){
      cout << currentNode->key << ' ';
      currentNode = currentNode->next;
    }
    cout << endl;
  }
  void printReverse(){
    Node* currentNode = tail;
    while(currentNode != NULL){
      cout << currentNode->key << ' ';
      currentNode = currentNode->previous;
    }
    cout << endl;
  }


};
int main(int argc, char* argv[]){
  DoubleLinkedList list;
  cout << "Appendint 2, 4, 6" << endl;
  list.append(2);
  list.append(4);
  list.append(6);
  // list.insertAt(0,1);
  // list.insertAt(2,3);
  list.print();
  list.printReverse();

  return 0;
}
// class DLL{
//
// };
// class DLL{
// private:
//   Node* head; // keeping track of the first element in the linked list
//   Node* tail; // keeping track of the last element in the linked list
// public:
//   void printPath(Node*);   // gonna take in the head
//   void createNewNode(int,Node*,Node*); // gonna take in the key, previous address node, and then another address pointing to another node or null
//
// };
// void DLL::printPath(Node* head){
//   cout << "here" << endl;
// }
// void DLL::createNewNode(int value, Node* previousNode, Node* nextNode)
// {
//   Node* newNode = new Node;
//   newNode->key = value;
//   newNode->previous = previousNode;
//   newNode->next = nextNode;
//   if (head == NULL){
//     head = newNode;
//   }
//   else{
//     Node* currentNode = head;
//     while (currentNode->next != NULL)     // traversing to find the last index
//     {
//       currentNode = currentNode->next;
//     }
//     currentNode->next = newNode;    // setting the last index to point at the newNode
//   }
// }
//
// int main(int argc, char* argv[])
// {
//   DLL link1;
//   cout << "here" << endl;
// }
//


/*
DLL, the same idea for singly linked list but now you keep track of head and tail
- lets you move in either direction
- having a tail can make code more efficient
[val]prev]nex]
*/
