#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
void openFile(string filename)
{
  ifstream infile;
  infile.open(filename);
  if (infile.is_open())
  {
    cout << "File opened" << endl;
  }
  string line;
  while (getline(infile,line))
  {
    //cout << line << endl;
    stringstream ss(line);
    string name;
    string age;

    ss >> name;
    ss >> age;

    int ageConverter = stoi(age) + 1;
    cout << "name: " << name << endl << "age: " << age << endl << "Conversion: " << ageConverter << endl;
  }

}
// int main()
// {
//   string filename = "datafile.txt";
//   openFile(filename);
//   return 0;
// }
//
int main(int argc, char* argv[])
{
  //string filename = "datafile.txt";
  openFile(argv[1]);
  return 0;
}
