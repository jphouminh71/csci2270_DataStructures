#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
node* AddNode(node *head, int num)
{
  if (head == NULL){
    node* newNode = new node;
    newNode->key = num;
    head = newNode;
    return head;
  }
  else if (head != NULL){
    node* currentNode = head;
    while (currentNode->next != NULL){
      currentNode = currentNode->next;
    }
    node* newNode = new node;
    newNode->key = num;
    currentNode->next = newNode;
    return head;
  }

}
int LinkedListFindMinimum(node *head)
{
  node* currentNode = head;
  int smallestValue = 1000000;
  while (currentNode->next != head)
  {
    if (currentNode->key < smallestValue)
    {
      smallestValue = currentNode->key;
    }
    currentNode = currentNode->next;
  }
  return smallestValue;
}

int main(int argc, char* argv[])
{
  cout << "here" << endl;
}
