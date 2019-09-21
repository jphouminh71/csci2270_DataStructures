#include "zombiecity.cpp"
#include <sstream>
#include <fstream>
using namespace std;


/*
  the file that is too be read in is information that is represented by a 15x15 adjacency matrix
  every city should be read in as a vertex and placed in the vector

*/

int main(int argc, char* argv[])
{
  Graph zombieCity;

  ifstream infile;
  infile.open(argv[1]);
  string line;
  int initialCount = 0;
  int lineCount = 0;
  while(getline(infile,line))
  {
    initialCount++;
    if (lineCount != 1)     // skip the first line because its unneccessary information to read in
    {
      stringstream ss;
      ss << line;
      while(getline(ss,line,','))
      {
        if (lineCount == 16)
          lineCount = 0;

        lineCount++;
        if (lineCount == 1)   // for finding the cities, should push_back the city name int
        {
          cout << "CURRENT CITY: " << line << endl;
          zombieCity.addVertex(line);
        }
        else    // for getting the the values associated with the cities
        {
          cout << "VALUE: " << line << endl;
        }
      }

    }
  }
  return 0;
}
