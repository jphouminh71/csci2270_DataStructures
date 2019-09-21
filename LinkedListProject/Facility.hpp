#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
#include <sstream>

using namespace std;

struct room
{
  string name = "EMPTY";
  int level = -1;
  room* next = nullptr;
  room* prev = nullptr;
};

class Facility{
private:
  room *head = nullptr;  // head pointer;
  room *tail = nullptr;


  string BuildingName;
  int currentFloorCount = 0;  // should always be 0;
  const int MAX_FLOOR_COUNT = 10;

public:
  Facility(){

  }
  Facility(string name){
    BuildingName = name;
  }
  bool reachedCap();   // checking to see if theres more space to add more room
  void DisplayFloors();
  void removeFloor(string name);
  void addFloor(string name);
  void loadDefaultSetup();
  void changeRoom(string name); // for updating room if you wanted to change it
  room* findRoom(string name);
  void printRoomInformation(room* room);
  void identifyEmptyRooms(vector<int>&);  // look through the linked list currently exists for floors that are empty


};

void Facility::printRoomInformation(room* room){  // done
  cout << "Room Name: " << room->name << endl;
  cout << "Floor ID: " << room->level << endl;
}

room* Facility::findRoom(string givenName){   // will return the address of the room we are trying to find ,done
  if (head == nullptr){
    cout << "No rooms to find." << endl;
    return nullptr;
  }

  room *tempptr = head;
  while(tempptr->next != nullptr){
    if (tempptr->name == givenName)   // looking for the room
    {
      return tempptr;
    }
  }
  cout << "Room not found!" << endl;
  return nullptr; // room wasn't found
}

void Facility::loadDefaultSetup(){    // done
  ifstream infile;
  infile.open("floorNames.txt");
  string line;
  while(getline(infile,line)) // this is for loading the default setUp
  {
    stringstream ss;
    ss << line;
    string item;
    string floorName;
    int floorNumber;
    // get the floorName;
    getline(ss,item,' ');
    floorName = item;
    // // get the floorNumber;
    getline(ss,item,' ');
    floorNumber = stoi(item);

    // now start adding nodes in
    addFloor(floorName);
  }
}

bool Facility::reachedCap(){  // done
  if (currentFloorCount < 10){
    return true;
  }
  return false;
}

void Facility::DisplayFloors(){   // done
  if (head == nullptr){
    cout << "No Registered Floors." << endl;
  }
  else{
    room* tempptr = head;
    while(tempptr->next != nullptr){
      cout << tempptr->name << ":" << tempptr->level << endl;
      tempptr = tempptr->next;
    }
  }
}

void Facility::addFloor(string name)    // done
{
  room* newRoom = new room;
  newRoom->name = name;
  newRoom->level = currentFloorCount;

  if (head == nullptr && tail == nullptr)
  {
    head = newRoom;
    tail = newRoom;
  }
  else{
    tail->next = newRoom; // link the current tails next to the new room node
    newRoom->prev = tail; // set the previous pointer for the new node to the current tail
    tail = newRoom; // make the tail the newRoom
  }
  currentFloorCount++;
}

void Facility::removeFloor(string name) // since you dont really remove floors, this function will just set everything in that room to its null values
{
  room* roomToBeRemoved = findRoom(name);
  roomToBeRemoved->name = "EMPTY";
  // dont need to mess with the floor number
  // keep the pointers the same because you woulnd't shift actual building floors
}
void Facility::identifyEmptyRooms(vector<int>& givenVect)
{
  if (head == nullptr){
    cout << "No Floors to identify." << endl;
  }
  else{
    room* tempptr = head;
    while(tempptr->next != nullptr){
      if(tempptr->name == "EMPTY")
      {
        givenVect.push_back(tempptr->level);
      }
      tempptr = tempptr->next;
    }

    if (givenVect.empty())
    {
      cout << "No empty Floors!" << endl;
    }
    else{
      for (int i = 0 ; i < givenVect.size(); i++)
      {
        cout << givenVect[i] << endl;
      }
    }
  }
}
