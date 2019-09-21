#include <iostream>
#include <string>
#include <sstream>
#include <fstream>    // allows for filestream
using namespace std;

struct Student{
  // data members
  int student_iD;
  string name;
  string major;
  // constructors
  Student()   // default constructor
  {

  }
  Student(int given_ID, string given_name, string given_major)
  {
    student_iD = given_ID;
    name = given_name;
    major = given_major;
  }

};

int main()
{
  Student newStudent;   // creating a new object for the constructor , Student()
  newStudent.name = "Jon";
  newStudent.major = "Computer Science";
  newStudent.student_iD = 106054641;

  Student anotherStudent(6,"bob","noMajor");

  // initiallizing objects for Struct of students into an array

  Student arrayOfStudents[3];

  arrayOfStudents[0].student_iD = 100;
  arrayOfStudents[0].name = "jon";
  arrayOfStudents[0].major = "computer science";


  // now practing file.io
  ifstream infile;
  infile.open("datafile.txt");
  string line;
  int counter = 0;
  while(getline(myfile, line))
  {
    cout << line << enld;
    // string stream = include sstream;
    stringstream ss;
    //write line string into string sstreamss << line;
    string item;

    getline(ss,item',');
    arrayOfStudents[counter].student_iD = stoi(item); // converting the input of the number into a integer
    getline(ss,item,',');
    arrayOfStudents[counter].name = item;
    getline(ss, item, ',').major = item;
    arrayOfStudents[counter].major = item;
  }

}



/*
Structs, for local uses of creating objects vs Classes, used for BIG programs

*/
