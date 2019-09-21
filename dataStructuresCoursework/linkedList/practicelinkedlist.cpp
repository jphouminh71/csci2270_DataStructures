#include <iostream>
#include <string>

using namespace std;

struct node{
  int data;
  struct node* next;
};

node* start = NULL;
node* createNode(){
  node *temp;
  temp = new node;
  return temp;
}

void insertNode()
{
  node *temp, *traverse;    // created 2 pointers
  int n;
  cout << "Enter -1 to end" << endl;
    cout << "Enter the value to be etnered in the list" << endl;// when -1 entered we will end the list
  while (n!=-1)
  {
    temp = createNode();    //
    temp->data = n;     // this is the way of access the variable in struct node, ->
    temp->next = NULL;
    if(start == NULL)
    {
      start = temp;
    }
    else
    {
      traverse = start;
      while (traverse->next!=NULL)
      {
        traverse = traverse->next;
      }
      traverse->next = temp;
    }
    cout << "Enter the value to be added to the list " << endl;
    cin >> n;
  }
}

void printList()
{
  node *traverse = start;
  while (traverse != NULL)
  {
    cout << traverse->data << " ";
    traverse = traverse->next;
  }
}

int main(int argc, char* argv[])
{
  int option;
  do{
    cout << "\n\n*********** MAIN MENU ****************" << endl;
    cout << "1. Create list" << endl;
    cout << "2. Print List" << endl;
    cout << "3. Exit" << endl;
    cin >> option;

    switch (option)
    {
      case 1: insertNode();
            break;
      case 2: printList();
            break;
    }
  }while(option!=3);
    return 0;
}
