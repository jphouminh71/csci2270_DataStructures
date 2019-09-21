//                                                   LINKED LIST PRACTICE
#include <iostream>
#include <string>

using namespace std;

struct node{
  int key;
  node *next;
  node(int k, node *n){   // whenever you are creating a node you can pass in the key and the value of the pointer
    key = k;
    next = n;
  }
};

// THIS MAIN FUNCTION HAS TO DEAL WITH Deletion
int main(int argc, char* argv[])
{
  int i = 1;
  node *head = new node(i, NULL);
  node *p = head; // copying the head, safe programming
  i++;
  while (i <= 10)
  {
    node *n = new node(i , NULL); // n->next = NULL, n -> key  = i
    p->next = n; // set p's next node to point to n
    p = n; // same as p = p->next
    i++;
  }
  // go back to beginning of the LIST
  p = head;
  while(p->next != NULL)  // for deletion we check in advance
  {
    // modify to only print if 4 if found
    if ((p->next)->key == 4)
    {
      cout << "Found it!" << (p->next)->key << endl; // print the value of the key

      // What is wrong here?  MEMORY LEAK, you need to make sure you are using the , delete, keyword. your wasting memory
      delete p->next; // fixing the memory leak
      p->next = (p->next)->next; // overwriting the next value with the node after the node to be deleted
    }
    p = p->next;
  }
  while(head!=NULL) // bad practice because you are using the head to traverse, should be using the p pointer
  {
    cout << head->key << endl;
    head = head->next;
  }
}

THIS MAIN FUNCTION HAS TO DEAL WITH CREATING A LINK LIST FROM SCRATCH, and then insertion methods.
int main(int argc, char* argv[])
{
  int i = 1;
  node *head = new node(i, NULL);
  node *p = head; // head and p point to the same memory, this is the pointer copy of the head link
  i++;
  while(i < 10){
    node *n = new node(i, NULL); // n->next = NULL, n -> key = i {
    p->next = n; // set p's next node to point to n
    p = n; // // same as p = p->next
    i++;
    }
  while (head != NULL){   // now you are traversing through the link list.
    cout << head->key << endl;
    head = head->next;
  }
}
// THIS MAIN FUNCTION WAS TO DEMONSTRATE HOW TO LINK AND SET LINKS
int main(int argc, char* argv[])
{
  node *x = new node(5,NULL); // using the constructor to create a node, this is the head pointer, 5 is the value of the key,
  node *x2 = new node(6, NULL); // creating another node
  x->next = x2;  // YOU JUST LINKED THE 2 NODES TOGETHTER, using the arrow operator because you referenced a pointer to a pointer

  cout << x->next << endl;    // printing out the address of wherever address the second node is at
  cout << x2 << endl;   // this will output the same address

  x2->key = 10; // reassigning the value of x2 as 10;
  node *p = x; // pointing to the same memory address of x, so it is pointing to whatever x is pointing to which is x2, which is pointing at NULL
  while (p != NULL)
  {
    cout << p->key << endl;
    p = p->next;    // going to the next pointer of the pointee
  }

}
