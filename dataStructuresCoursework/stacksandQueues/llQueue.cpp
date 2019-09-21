// Queue- Linked List Implementation
#include <iostream>
using namespace std;

struct node{
  int data;
  node* next;
};
class llQueue{
private:
  node* head;
  node* tail;
  node* prev;
  node* temp;
  bool isEmpty()
  {
    if (head == nullptr)
    {
      return true;
    }
    return false;
  }
public:
  llQueue()
  {
    head = nullptr;
    tail = nullptr;   // i guess we dont have to say that the prev and next are equal to null
  }
  // enqueuing element x
  void enqueue(int x)
  {
    temp = new node;
    temp->data = x;
    temp->next = NULL;
    if (isEmpty() == true)
    {
      head = temp;
      tail = temp;  // enqueuing the very first element in the
    }
    else{
      prev = tail;
      tail->next = temp;
      tail = temp;
    }
  }
  void dequeue()
  {
    temp = head;
    head = head->next;  // moving the head to the next element
    delete temp;
  }
  void find(int x)    // extra function for when you are looking a value in the linked list
  {
    int i;
    for (i = 1, temp = head; temp->next != NULL && temp->data != x; temp = temp->next, i++);
    if (temp->data == x){
      cout << "Found at position " << i << endl;
    }
    else if (temp->next == NULL)
    {
      cout << "Error: Number not found... " << endl;
    }
  }
  void display() // function to display all the elements in the linked list
  {
    if (isEmpty() == false)
    {
      for (temp = head; temp != NULL; temp = temp->next)
      {
        cout << temp->data << ' ' << endl;
      }
      cout << endl;
    }
    else{
      cout << "Queue is empty!" << endl;
    }
  }
};

int main(int argc, char* argv[])
{
  llQueue q;
  q.display();
  q.enqueue(15);
  q.display();
  q.enqueue(20);
  q.enqueue(21);
  q.display();
  q.dequeue();
  q.display();
}
