#include "Facility.hpp"

int main(int argc, char* argv[])
{
  Facility RaptorFitness;

  RaptorFitness.loadDefaultSetup();

  string input = "";
  while (input != "6"){
    cout << "RAPTOR FITNESS\n==============\n";
    cout << "1 : Display Floors\n";
    cout << "2 : Add Floor\n";
    cout << "3 : Remove Floor\n";
    cout << "4 : Find Room\n";
    cout << "5 : Identify Empty Floor\n";
    cout << "6 : Update Floor\n";
    cout << "7 : Quit\n";
    getline(cin,input);
    switch(stoi(input))
    {
      case 1:
      {
        RaptorFitness.DisplayFloors();
      }
      break;
      case 2:
      {
        cout << "case 2" << endl;
      }
      break;
      case 3:
      {
        cout << "case 3" << endl;

      }
      break;
      case 4:
      {
        cout << "Enter a room name!" << endl;

        string input;
        getline(cin,input);

        room* RoomToFind = RaptorFitness.findRoom(input);
        if (!RoomToFind){
          cout << "No room named: " << input << " found!\n";
        }
        else{
          RaptorFitness.printRoomInformation(RoomToFind);
        }
      }
      break;
      case 5:
      {
        vector<int> emptyRooms;

        RaptorFitness.identifyEmptyRooms(emptyRooms);
        for (int i = 0; i < emptyRooms.size(); i++)
        {
          emptyRooms.pop_back();  // clear the vector after done
        }
      }
      break;
      case 6:
      {
        cout << "Goodbye!" << endl;
        // this should write out to save the information
      }
      break;
    }

  }

}
