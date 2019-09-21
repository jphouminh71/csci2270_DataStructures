#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <iomanip>
using namespace std;
struct user{
  string name; // name of the user
  user* next; // pointer to the next user
  user* previous;
  float balance; // amount of money the person will owe
  string statement; // billing statement
};

class dualLinkedList{
public:
  void addUser(string name, float balance, string statement);  // done
  user* deleteEntireSystem(user* head);  // done
  void deleteUser(string name);       // done
  user* searchSystem(user* head, string username);  // done
  void loadDefaultSetup();          // done
  void printEverything();         // done
  void printBackwards();   // done
  void displayMenu();     // done
  void getUserInformation(); // done
private:
  user* head = nullptr;
  user* tail = nullptr;
};
/*
    This is the menu function that the user will use to interact with the dual link system, the one bug about this is the handling invalid inputs when they are not numeric values. small fix
*/
void dualLinkedList::displayMenu(){
  int n;
  user* foundPerson;
  string name;
  do{
    cout << "1: Load Default Setup\n 2: Add User\n 3: Delete User\n 4: See total\n 5: Search System\n 6: Print Everything\n 7: Print Everything Backwards\n";
    cin >> n;
    switch(n)
    {
      case 0:
        cout << "goodbye" << endl;
        head = deleteEntireSystem(head);
        if (head == nullptr){
          cout << "SYSTEM CLEARED." << endl;
        }
        break;
      case 1:
        cout << "Loading Default Setup\n" << endl;
        loadDefaultSetup();
        break;
      case 2:
        cout << "Add User\n" << endl;
        getUserInformation();
        break;
      case 3:
        cout << "Delete User, Enter name:\n" << endl;
        cin.ignore();
        cin >> name;
        deleteUser(name);
        break;
      case 4:
        cout << "See total" << endl;
        break;
      case 5:
        cout << "Search System and print statement\n" << endl;
        cout << "Enter name: \n" << endl;
        cin.ignore();
        getline(cin,name);
        foundPerson = searchSystem(head,name);
        if (foundPerson == nullptr)
        {
          cout << "User not found." << endl;
        }
        else if (foundPerson != nullptr)
        {
          cout << name << ":" << foundPerson->statement << endl;
        }
        break;
      case 6:
        printEverything();
        break;
      case 7:
        printBackwards();
        break;
      default:
        cout << n << " is not and option." << endl;
        break;
    }
  }while(n!=0);
}
/*
    This function opens and reads from file in folder and creates a dually linked  list with the elements
*/
void dualLinkedList::loadDefaultSetup()
{
  ifstream infile;
  infile.open("default.txt");
  if (infile.is_open())
  {
    cout << "file opened successfully" << endl;
  }
  // parse the line
  string line;
  while(getline(infile,line)){
    stringstream ss;
    ss << line;
    string item;
    string name;
    float balance;
    string statement;
    getline(ss,item,',');
    name = item;
    getline(ss,item,',');
    balance = stoi(item);
    getline(ss,item);
    statement = item;

    addUser(name, balance, statement);
  }
  infile.close();
}
/*
    Create a new user object and tie to to the linked list
    if its the first thing in the list (if head == nullptr)
        set its stuff to nullptr
    if its no the first thing
      get the tail and update that nodes next pointer to the new node and then update the new nodes previous to the existing tail node
*/
void dualLinkedList::addUser(string name, float balance, string statement){
  user* newUser = new user;
  newUser->name = name;
  newUser->balance = balance;
  newUser->statement = statement;
  newUser->next = nullptr;
  newUser->previous = nullptr;

  if (head == nullptr)  // first thing to add
  {
    head = newUser;
    tail = newUser;
  }
  else{
    newUser->previous = tail;
    tail->next = newUser;
    tail = newUser;
  }
}
/*
    deletes a specific node in the list specified by given string.
      edge cases
        only one node in the list
        head node is to be removed
        tail node is to be removed
        node is inbetween two other nodes
*/
void dualLinkedList::deleteUser(string name){
  user* currentptr = searchSystem(head, name);
  if (currentptr == nullptr){       // empty linked list
    cout << "nothing to delete" << endl;
  }
  else if(currentptr != nullptr)   // found the user in the dualLinkedList
  {
    if (currentptr == head && currentptr == tail)
    {
      head = nullptr;
      tail = nullptr;
      delete currentptr;
    }
    else if (currentptr == head){   // the head node needs to be removed.
      head = currentptr->next;
      head->previous = nullptr;
      delete currentptr;
      cout << "CURRENT NODE:" << currentptr->name;
      cout << "  NEXT NODE: " << currentptr->next->name;

      cout << endl;
    }
    else if (currentptr == tail)  // the tail of the list needs to be removed.
    {
      tail = currentptr->previous;
      tail->next = nullptr;
      delete currentptr;
    }
    else{   // the node is inbetween two other nodes.
      user* tempptr = currentptr->previous;
      tempptr->next = currentptr->next;
      currentptr->next->previous = tempptr;
      delete currentptr;
    }
  }
}
/*
    given a string , the function will search through the list and return address of node, otherwise returns nullptr.
*/
user* dualLinkedList::searchSystem(user*head, string name){
  user* tempptr = head;
  while(tempptr)
  {
    if (tempptr->name == name)
    {
      return tempptr;
    }
    tempptr = tempptr->next;
  }
  return nullptr;
}
/* helper function that is used for addUser. Makes debugging easier. */
void dualLinkedList::getUserInformation(){
  string name, statement;
  int balance;

  cin.ignore();
  cout << "Input Name: " << endl;
  getline(cin,name);
  cout << "Input Balance: " << endl;
  cin.ignore();
  cin >> balance;
  cout << "Input Statement: " << endl;
  cin.ignore();
  getline(cin,statement);
  addUser(name, balance, statement);
}
/*
  traverses throught the list while at the smae time writing out all current nodes to output file and freeing the memory.
*/
user* dualLinkedList::deleteEntireSystem(user* head) // return should return nullptr if system was cleared successfully
{
  user* currentptr = head;
  user* tempptr = nullptr;
  ofstream outfile;
  outfile.open("default.txt");
  while(currentptr)
  {
    tempptr = currentptr->next;
    outfile << currentptr->name << "," << currentptr->balance << "," << currentptr->statement << endl;
    delete currentptr;
    currentptr = tempptr;
  }
  head = currentptr;
  outfile.close();
  return head; // should be null
}
void dualLinkedList::printEverything(){
  user* tempptr = head;
  while (tempptr != nullptr)
  {
    cout << tempptr->name;
    if (tempptr->next != nullptr)
    {
      cout << "-->";
    }
    tempptr = tempptr->next;
  }
  cout << endl;
}
void dualLinkedList::printBackwards(){
  user* tempptr = tail;
  while (tempptr != nullptr){
    cout << tempptr->name ;
    if (tempptr->previous != nullptr)
    {
      cout << "-->";
    }
    tempptr = tempptr->previous;
  }
  cout << endl;
}
/*    Notes:
  default setup should always be loaded first idk why coded it this way.
  but just finish the delete function then move onto stacks and queues!
*/
