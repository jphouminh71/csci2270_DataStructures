 f// Pon Senphannarat <ponsenphannarat@gmail.com>
// To:
// jphouminh71@yahoo.com
//
// Oct 1 at 2:04 PM

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

// DO NOT MODIFY THIS STRUCT
struct city{
  string name; // name of the city
  city *next; // pointer to the next city
  int numberMessages; // how many messages passed through this city
  string message; // message we are sending accross
};

/* Function prototypes */
city* addCity(city *head, city *previous, string cityName );
city* deleteCity(city *head, string cityName);
city* deleteEntireNetwork(city *head);
city* searchNetwork(city *head, string cityName);
city* loadDefaultSetup(city *head);
void transmitMsg(city *head, string receiver, string message);
void printPath(city *head);
void displayMenu();
city* handleUserInput(city *head);

/* Do NOT modify main function */
int main(int argc, char* argv[]){
  // pointer to the head of our network of cities
  city *head = NULL;

  head = handleUserInput(head);
  printPath(head);
  head = deleteEntireNetwork(head);
  if (head == NULL)
  cout << "Path cleaned" << endl;
  else
  printPath(head);
  cout << "Goodbye!" << endl;
  return 0;
}

/*
* Purpose: handle the interaction with the user
* @param head: the start of the linked list
* @return: the start of the linked list
*
* DO NOT MODIFY THIS FUNCTION
*/
city* handleUserInput(city *head){
  bool quit = false;
  string s_input;
  int input;
  // loop until the user quits
  while (!quit)
  {
    displayMenu();
    // read in input, assuming a number comes in
    getline(cin, s_input);
    input = stoi(s_input);
    switch (input)
    {
      // print all nodes
      case 1: //rebuild network
        head = loadDefaultSetup(head);
        printPath(head);
        break;

      case 2: // print path
        printPath(head);
        break;

      case 3: //message is read in from file
        {
          string cityReceiver;

          cout << "Enter name of the city to receive the message: "
          << endl;
          getline(cin, cityReceiver);
          cout << "Enter the message to send: " << endl;
          string message;
          getline(cin, message);

          transmitMsg(head, cityReceiver, message);
        }
        break;

      case 4:
        {
          string newCityName;
          string prevCityName;
          cout << "Enter a new city name: " << endl;
          getline(cin, newCityName);
          cout << "Enter the previous city name (or First): " << endl;
          getline(cin, prevCityName);
          // find the node containing prevCity
          city *tmp = NULL;
          if(prevCityName !="First")
          tmp = searchNetwork(head, prevCityName);
          // add the new node
          head = addCity(head, tmp, newCityName);
          printPath(head);
        }
        break;

      case 5: // delete city
        {
          string city;
          cout << "Enter a city name: " << endl;
          getline(cin, city);
          head = deleteCity(head, city);
          printPath(head);

        }
        break;

      case 6: // delete network
        head = deleteEntireNetwork(head);
        break;

      case 7: // quit
        quit = true;
        cout << "Quitting... cleaning up path: " << endl;
        break;

      default: // invalid input
        cout << "Invalid Input" << endl;
        break;
    }
  }
  return head;
}

/*
* Purpose: Add a new city to the network
* between the city *previous and the city that follows it in the network.
* Prints: `prev: <city name> new: <city name>` when a city is added,
* prints _nothing_ if the city is being added to the _first_ position in
* the list.
* @param head: pointer to start of the list
* @param previous: name of the city that comes before the new city, or null if
*    the city is being added to the first position
* @param cityName: name of the new city
* @return: pointer to first node in list
*/
city* addCity(city *head, city *previous, string cityName ){

    if (head == NULL)
    {
        head = new city;
        head->name = cityName;
        return head;
    }

    city *newNode = new city;
    newNode->name = cityName;

    if (previous == NULL)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    newNode->next = previous->next;
    previous->next = newNode;
    // Only print this if previous is not NULL
    cout << "prev: " << previous->name << " new: " << cityName << endl;

    return head;
}

/*
* Purpose: Search the network for the specified city and return a pointer
* to that node
* @param head: head of the list
* @param cityName: name of the city to look for in network
* @return: pointer to node of cityName, or NULL if not found
* @see addCity, deleteCity
*/
city *searchNetwork(city *ptr, string cityName){
    bool found = false;
    while(!found && ptr != NULL){
        if(ptr->name == cityName){
            found = true;
        }
        else{
            ptr = ptr->next;
        }
    }
    return ptr;
}

/*
* Purpose: deletes all cities in the network starting at the head city.
* @param head: head of list
* @return: NULL as the list is empty
*/
city* deleteEntireNetwork(city *ptr){
    int count = 0;
    while(ptr){
        city *tmp = ptr->next;
        cout << "deleting: " << ptr->name << endl;
        delete ptr;
        ptr = tmp;
        count++;
    }
    if(ptr==NULL&&count>1){
        cout << "Deleted network" << endl;
    }

  // Return head, which should be NULL
  return ptr;
}

/*
* Purpose: transmit a message from city to city
* @param head: pointer to head of the list
* @param receiver: the name of the City to receive the message
* @param message: the message to transmit*/
void transmitMsg(city *head, string receiver, string message){
    if(head == NULL){
        cout << "Empty list" << endl;
        return;
    }
    city *sender = head;
    while(sender && sender->name != receiver){
        sender->message = message;
        sender->numberMessages++;
        cout << sender->name << " [# messages passed: " << sender->numberMessages << "] received: " << sender->message << endl;
        sender = sender->next;
    }
    sender-> message = message;
    sender->numberMessages++;
    cout << sender->name << " [# messages passed: " << sender->numberMessages << "] received: " << sender->message << endl;
}

/*
* Purpose: delete the city in the network with the specified name.
* @param head: first node in list
* @param cityName: name of the city to delete in the network
* @return: head node of list
*/
city* deleteCity(city *head, string cityName){
    city *current = head;
  while(current->next != NULL){
    if(current->name == cityName){
      break;
    }
    else{
      current = current->next;
    }
  }
  if(current == head){
    head = head->next;
    delete current;
    return head;
  }
  else{
    city *prev = head;
    while(prev->next != NULL){
      if(prev->next != NULL){
        prev->next = current-> next;
        delete current;
        return head;
      }
      prev = prev->next;
    }
  }
}



/*
* Purpose: prints the current list nicely
* @param head: head of list
*/
void printPath(city *head)
{
  cout << "== CURRENT PATH ==" << endl;
  if (head == NULL) {
    cout << "nothing in path" << endl;
  }

  // Add code here to print the network path.
  while(head!=NULL){
    cout << head->name<<" -> ";
    head = head->next;
  }

  cout << " NULL\n===" << endl;
}

/*
* Purpose: populates the network with the predetermined cities
* @param head: start of list
* @return: head of list
*/
city* loadDefaultSetup(city *head){
  head = deleteEntireNetwork(head);
    head = addCity(head,NULL,"Los Angeles");
  // Add code here to populate the LinkedList with the default values

    city *PHX = new city;
    city *DEN = new city;
    city *DAL = new city;
    city *ATL = new city;
    city *NY = new city;

    PHX->name = "Phoenix";
    DEN->name = "Denver";
    DAL->name = "Dallas";
    ATL->name = "Atlanta";
    NY->name = "New York";

    head->next = PHX;
    PHX->next=DEN;
    DEN->next=DAL;
    DAL->next=ATL;
    ATL->next=NY;
    cout<<"prev: Los Angeles  new: "<<PHX->name<<endl;
    cout<<"prev: "<<PHX->name<<"  new: "<<DEN->name<<endl;
    cout<<"prev: "<<DEN->name<<"  new: "<<DAL->name<<endl;
    cout<<"prev: "<<DAL->name<<"  new: "<<ATL->name<<endl;
    cout<<"prev: "<<ATL->name<<"  new: "<<NY->name<<endl;

  return head;
}

/* Purpose: displays a menu with options
* DO NOT MODIFY THIS FUNCTION
*/
void displayMenu(){
  cout << "Select a numerical option:" << endl;
  cout << "======Main Menu=====" << endl;
  cout << "1. Build Network" << endl;
  cout << "2. Print Network Path" << endl;
  cout << "3. Transmit Message" << endl;
  cout << "4. Add City" << endl;
  cout << "5. Delete City" << endl;
  cout << "6. Clear Network" << endl;
  cout << "7. Quit" << endl;
}







// /*=====================================================*
//  * Homework 3 Linked List                              *
//  * Description:                                        *
//  * Author: Jonathan Phouminh                           *
//  * Date:                                               *
//  *=====================================================*/
// #include <iostream>
// #include <fstream>
// #include <cstdlib>
// #include <string>
//
// using namespace std;
//
// struct city
// {
//     string  name;            // name of the city
//     city *  next;            // pointer to the next city
//     int     numberMessages;  // how many messages passed through this city
//     string  message;         // message we are sending accross
//
//     city(){
//
//     }
//     city(string givenName, city* givenAddress, int givenAmountMessages, string givenMessage)
//     {
//       name = givenName;
//       next = givenAddress;
//       numberMessages = givenAmountMessages;
//       message = givenMessage;
//     }
// };
//
// class CityNetwork {
//     private:
//         // pointer to head of linked list of cities
//         city* head;
//     public:
//         CityNetwork();
//         bool isEmpty();
//         /* NOTE: you will complete all the methods marked
//              'TODO'. Definitions are below. Careful with the
//               print statements, moodle expects the output to
//               match exactly. */
//         void addCity(city* previous, string cityName); // TODO
//         void deleteCity(string cityName);              // TODO
//         void loadDefaultSetup();                       // TODO
//         city* searchNetwork(string cityName);          // TODO
//         void deleteEntireNetwork();                    // TODO
//         void transmitMsg(string receiver, string msg); // TODO
//         void printPath();                              // TODO
// };
//
// // declarations for UI/menu helper-functions
// void displayMenu();
// void handleUserInput(CityNetwork& cityNet);
//
// /* Do NOT modify main function */
// int main(int argc, char* argv[])
// {
//     // Object representing our network of cities.
//     // (Linked list representation is in CityNetwork)
//     CityNetwork cityNet;
//
//     // this will loop until user selects quit option
//     handleUserInput(cityNet);
//
//     // quit: clean up.
//     cityNet.printPath();
//     cityNet.deleteEntireNetwork();
//     if (cityNet.isEmpty())
//     {
//         cout << "Path cleaned" << endl;
//     }
//     else
//     {
//         cout << "Error: Path NOT cleaned!" << endl;
//         cityNet.printPath();
//     }
//
//     cout << "Goodbye!" << endl;
//     return 0;
// }
//
//
// /***************************************************************/
// /* CityNetwork Methods                                         */
// /***************************************************************/
// /* TODO: Implement the unfinished methods for CityNetwork.     */
// /*   This class (defined above) uses a linked list of city     */
// /*   structs to store city routes and message counts.          */
// /***************************************************************/
//
// /*
//  * Purpose: Constructer for empty linked list
//  * @param none
//  * @return none
//  * Do not modify.
//  */
// CityNetwork::CityNetwork() {
//     /* finished! do not modify this function. */
//     head = NULL;
// }
//
//  /*
//   * Purpose: populates the network with the predetermined cities
//   * @param none
//   * @return none
//   */
//  void CityNetwork::loadDefaultSetup() {
//      deleteEntireNetwork();
//      // TODO: implement this function: Add default network cities
//      city * LA = new city("Los Angeles",NULL,0,"");
//      city* PHE = new city("Pheonix", NULL, 0, "");
//      city* DEN = new city("Denver", NULL, 0, "");
//      city* DAL = new city("Dallas",NULL,0,"");
//      city* ATL = new city("Atlanta",NULL,0,"");
//      city* NY = new city("New York",NULL,0,"");
//
//      LA->next = PHE;     // assigning the default addresses for the cities
//      PHE->next = DEN;
//      DEN->next = DAL;
//      DAL->next = ATL;
//      ATL->next = NY;
//
//      head = LA;
//  }
//  /*
//   * Purpose: Check if list is empty
//   * @return true if empty; else false
//   * Do not modify.
//   */
// bool CityNetwork::isEmpty() {
//     /* finished! do not modify this function. */
//     return (head == NULL);
// }
//
// /*
//  * Purpose: Add a new city to the network
//  *   between the city *previous and the city that follows it in the network.
//  * @param previous name of the city that comes before the new city
//  * @param cityName name of the new city
//  * @return none
//  */
// void CityNetwork::addCity(city* previous, string cityName) {
//     // TODO: implement this function
//
//     // required print statements:
//         // print the city name we're adding and city name we're following, e.g.
//         //cout << "adding: " << cityName << " (prev: " << previous->name << ")" << endl;
//
//         // if adding to front of list, instead print:
//         //cout << "adding: " << cityName << " (HEAD)" << endl;
//
//
//
// }
//
// /*
//  * Purpose: delete the city in the network with the specified name.
//  * @param cityName name of the city to delete in the network
//  * @return none
//  */
// void CityNetwork::deleteCity(string cityName) {
//     // TODO: implement this function.
//
//     // if the city dosn't exist, nothing we can do.
//     //         use this output statement
//         cout << "City does not exist." << endl;
//
// }
//
// /*
//  * Purpose: Search the network for the specified city and return a pointer to that node
//  * @param cityName name of the city to look for in network
//  * @return pointer to node of cityName, or NULL if not found
//  * @see addCity, deleteCity
//  */
// city* CityNetwork::searchNetwork(string cityName) {
//     // TODO: implement this function.
//
//     // TODO: fix this return statement: should return
//     //   a pointer to the city if found.
//     return NULL;
// }
//
// /*
//  * Purpose: deletes all cities in the network starting at the head city.
//  * @param none
//  * @return none
//  */
// void CityNetwork::deleteEntireNetwork() {
//     // TODO: implement this function.
//
//         // required print statement:
//         //   print the city name as it's deleted, e.g.,
//         //cout << "deleting: " << ptr->name << endl;
//
//
//
//     cout << "Deleted network" << endl;
// }
//
// /*
//  * Purpose: Transmit a message across the network to the
//  *   receiver and increment count in each city it passes through
//  * @param receiver name of the city to receive the message
//  * @param message the message to send to the receiver
//  * @return none
//  */
// void CityNetwork::transmitMsg(string receiver, string message) {
//     // TODO: implement this function.
//     city* initialHead = head;
//     city* currentCity = head;
//     bool found = false;
//     while(found == false)
//     {
//       //cout << "here" << endl;
//       if (currentCity->name == receiver)
//       {
//         found = true;
//         (currentCity->numberMessages)++;
//         cout << currentCity->name << ' ' << "[# messages passed: " << currentCity->numberMessages << ']' << " received: " << message << endl;
//         head = initialHead;
//         break;
//       }
//       else if (found == false)
//       {
//         (currentCity->numberMessages)++;
//         cout << currentCity->name << ' ' << "[# messages passed: " << currentCity->numberMessages << ']' << " received: " << message << endl;
//         currentCity = currentCity->next;
//       }
//     }
//     // if list is empty, print and return
//     if(head == NULL)
//     {
//         cout << "Empty list" << endl;
//         return;
//     }
//
//
//     // required print statement:
//     //   print the city, count of msgs, and message:
//     //   e.g., Denver [# messages passed: 2] received: hi
//         //cout << sender->name << " [# messages passed: " << sender->numberMessages << "] received: " << sender->message << endl;
//
//
// }
//
// /*
//  * Purpose: prints the current list nicely
//  * @param ptr head of list
//  */
// void CityNetwork::printPath() {
//     cout << "== CURRENT PATH ==" << endl;
//
//     // TODO: traverse linked list and print path.
//     city* initialHead = head;
//     city* currentCity = head;
//     while (currentCity != NULL)
//     {
//       cout << currentCity->name << " -> ";
//       currentCity = (currentCity->next);
//     }
//     cout << "NULL\n";
//     currentCity = initialHead;
//     if (currentCity == NULL)
//     {
//         cout << "nothing in path" << endl;
//     }
//
//
//     cout << "===" << endl;
// }
//
//
// /***************************************************************/
// /* User Interface Functionality                                */
// /***************************************************************/
// /* These functions implement the menu display and handle the   */
// /*   user's menu selection by calling the appropriate          */
// /*   CityNetwork methods.                                      */
// /* These functions are complete, DO NOT MODIFY BELOW!          */
// /***************************************************************/
//
// /*
//  * Purpose: handle the interaction with the user
//  * @param CityNetwork to modify through menu actions
//  * @return None
//  * Do NOT modify
//  */
// void handleUserInput(CityNetwork& cityNet)
// {
//     bool quit = false;
//     string s_input;
//     int input;
//
//     // loop until the user quits
//     while (!quit)
//     {
//         displayMenu();
//
//         // read in input, assuming a number comes in
//         getline(cin, s_input);
//         try
//         {
//             input = stoi(s_input);
//         }
//         catch (exception& e)
//         {
//             // non-numeric input. trigger the default switch case.
//             input = 10;
//         }
//
//         switch (input)
//         {
//             case 1:        // rebuild network
//                 cityNet.loadDefaultSetup();
//                 cityNet.printPath();
//                 break;
//
//             case 2:        // print path
//                 cityNet.printPath();
//                 break;
//
//             case 3: // message is read in from stdin
//                     // note: 'standard in' is the console by default
//               {
//                 string cityReceiver;
//                 cout << "Enter name of the city to receive the message: " << endl;
//                 getline(cin, cityReceiver);
//
//                 cout << "Enter the message to send: " << endl;
//                 string message;
//                 getline(cin, message);
//
//                 cityNet.transmitMsg(cityReceiver, message);
//               }
//                 break;
//
//             case 4:       // add city
//               {
//                 string newCityName;
//                 string prevCityName;
//                 cout << "Enter a new city name: " << endl;
//                 getline(cin, newCityName);
//
//                 cout << "Enter the previous city name (or First): " << endl;
//                 getline(cin, prevCityName);
//
//                 // find the node containing prevCity
//                 city *tmp = NULL;
//                 if(prevCityName !="First")
//                 {
//                     tmp = cityNet.searchNetwork(prevCityName);
//                 }
//                 cityNet.addCity(tmp, newCityName);
//                 cityNet.printPath();
//               }
//                 break;
//
//             case 5:     // delete city
//               {
//                 string city;
//                 cout << "Enter a city name: " << endl;
//                 getline(cin, city);
//                 cityNet.deleteCity(city);
//                 cityNet.printPath();
//               }
//                 break;
//
//             case 6:     // delete network
//                 cityNet.deleteEntireNetwork();
//                 break;
//
//             case 7:     // quit
//                 quit = true;
//                 cout << "Quitting... cleaning up path: " << endl;
//                 break;
//
//             default:     // invalid input
//                 cout << "Invalid Input" << endl;
//                 break;
//         }
//     }
// }
//
// /*
//  * Purpose: displays a menu with options
//  * Do not modify.
//  */
// void displayMenu()
// {
//     cout << endl;
//     cout << "Select a numerical option:" << endl;
//     cout << "+=====Main Menu=========+" << endl;
//     cout << " 1. Build Network " << endl;
//     cout << " 2. Print Network Path " << endl;
//     cout << " 3. Transmit Message " << endl;
//     cout << " 4. Add City " << endl;
//     cout << " 5. Delete City " << endl;
//     cout << " 6. Clear Network " << endl;
//     cout << " 7. Quit " << endl;
//     cout << "+-----------------------+" << endl;
//     cout << "#> ";
// }
