/*                        SINGLY LINKED LIST STACK IMPLEMENTATION
  will consist of the same functions but will use a singly linked list
    loadStackToCapacity(), will initiate counter for amou
    isEmpty()
      will return a boolean value if head of linked list is nullptr or not
    push()
      create a new node and link it
    pop()
      remove the last node
    peek()
      print out the key of the top of the stack
    print()
      traverse the link list while printing the keys.

                        Where you left off. . . .
                        this code is finished but there is still an issue when you enter 3 in the menu screen and it still jumps to the default switch case.
*/
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct node{
    string letter;
    node* next;
};

class stackey{
public:
  void loadStackToCapacity();
  bool isEmpty();                   // done
  void push(string);
  void pop();
  void peek();                    // done
  void print();                 //done
private:
  node* stackhead;    // NOT THE HEAD OF THE STACK, its the head of the linked list.
  node* stackTop;   // the tail of a llstack is also the top of the stack.
};
void stackey::loadStackToCapacity(){
  push("a");
  push("b");
  push("c");

}
bool stackey::isEmpty(){
  if (stackhead == nullptr)
  {
    return true;
  }
  return false;
}
/*
  Edge cases to handle.
  if its the first node in the list make it the head node and keep track of it.
    set the head address of the linked list to this one and the stack top
  if its not the head
    add the node
    make sure to keep track of the top of the stack with the tail pointer.
*/
void stackey::push(string i_letter){
  node* newNode = new node;
  newNode->letter = i_letter;
  newNode->next = nullptr;

  // edge case
  if (stackhead == nullptr){
    stackhead = newNode;
    stackTop = newNode;
  }
  else if ( stackhead != nullptr ){
    stackTop->next = newNode;
    stackTop = newNode;
  }
}
/* need to find the previous node to make the new stacktop before or after removing the top node
  edge case to handle is only if you are popping the head node. */
void stackey::pop(){
  node* tempptr = stackhead;
  node* previousNode = nullptr;
  if (stackhead == nullptr){
    cout << "NOTHING TO POP!" << endl;
  }
  else if (stackhead == stackTop){      // only one item in the linked list
    cout << "(HEAD) POPPING: " << stackhead->letter << endl;
    delete stackhead;
    stackhead = nullptr;
    stackTop = nullptr;
  }
  else if (stackhead != stackTop){
    while(tempptr->next->next != nullptr){    // this should find the previous node
      tempptr = tempptr->next ;
    }
    previousNode = tempptr;
    previousNode->next = nullptr;
    cout << "POPPING: " << stackTop->letter << endl;
    delete stackTop;   // pops the last node
    stackTop = previousNode; // repoints the stackTop;
  }
}
/*
  print out the contents of the tail pointer
*/
void stackey::peek(){
  cout << "STACK TOP: " << stackTop->letter << endl;
}
/*
  this function is just traversing and printing the linked list.
*/
void stackey::print(){
  node* tempptr = stackhead;
  if (tempptr == nullptr){
    cout << "NOTHING TO PRINT" << endl;
  }
  else{
    while(tempptr != nullptr){
      cout << tempptr->letter;
      if (tempptr->next != nullptr){
        cout << "-->";
      }
      tempptr = tempptr->next;
    }
  }
}
//   Everything below is just handle user input
void displayMenu(){
  cout << endl;
  cout << "MENU: " << endl;
  cout << "1: PRINT STACK" << endl;
  cout << "2: PEEK STACK" << endl;
  cout << "3: PUSH VALUE ONTO STACK" << endl;
  cout << "4: POP STACK" << endl;
  cout << "5: QUIT" << endl;
  cout << ">>";
}
void handleUserInput(stackey& obj)
{
  string i_letter;
  bool quit = false;
  string s_value;
  int input;
  while(!quit){
    displayMenu();
    getline(cin,s_value);
    try {
      input = stoi(s_value);
    }
    catch(exception& e){
      input = 6;         // trigger the default case
    }
    switch(input){
      case 1:
        obj.print();
        break;
      case 2:
        obj.peek();
        break;
      case 3:
        cout << "Input letter: " << endl;
        cin >> i_letter;
        obj.push(i_letter);
        break;
      case 4:
        obj.pop();
        break;
      case 5:
        cout << "goodbye" << endl;
        quit = true;
        break;
      default:
        cout << "invalid input" << endl;
        break;
    }
  }
}
int main(int argc,char* argv[]){
  stackey ll;
  ll.loadStackToCapacity();
  handleUserInput(ll);
  return 0;
}
