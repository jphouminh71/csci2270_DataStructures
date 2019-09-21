#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

struct Students{
private:
  string userName;
  float gpa;
  int age;
public:
  Students(){

  }
  Students(string givenName, float givenGpa, int givenAge){
    userName = givenName;
    gpa = givenGpa;
    age = givenAge;
  }
  void setUsername(string);
  void setGpa(float);
  void setAge(int);
  string getUsername();
  float getGpa();
  int getAge();

};
void Students::setUsername(string given_name){
  userName = given_name;
}
void Students::setGpa(float given_gpa){
  gpa = given_gpa;
}
void Students::setAge(int given_age){
  age = given_age;
}
string Students::getUsername(){
  return userName;
}
float Students::getGpa(){
  return gpa;
}
int Students::getAge(){
  return age;
}
vector<Students> addUser(string name, float gpa, int age, vector<Students> myVector){
  Students newStudent = Students(name,gpa,age);
  myVector.push_back(newStudent);
  return myVector;

}
void printList(const vector<Students> myVector){
  for (int i = 0; i < myVector.size(); i++){
    cout << myVector[i].getUsername() << "[" << myVector[i].getGpa() << "]age:" << myVector[i].getAge()
    << endl;
  }
}
int main(int argc, char* argv[]){
  vector<Students> students;

  ifstream infile;
  infile.open(argv[1]);
  if (!infile.is_open()){
    cout << "File has failed to open" << endl;
  }

  else if (infile.is_open()){
    cout << "File opened successfully." << endl;
    string line;
    string item;
    string name;
    float gpa;
    int age;
    while(getline(infile,line)){
      stringstream ss;
      ss << line;
      getline(ss,item,',');
      //cout << item << "<< NAME" << endl;
      name = item;
      getline(ss,item,',');
      //cout << stof(item) << "<< GPA" << endl;
      gpa = stof(item);
      getline(ss,item,',');
      //cout << stoi(item) << "<<AGE" << endl;
      age = stoi(item);
      students = addUser(name,gpa,age,students);
      // Students newStudent = Students(name,gpa,age);
      // students.push_back(newStudent);

    }
    //cout << "VECTOR SIZE: " << students.size() << endl;
    printList(students);
  } // dont code pass this

}

// void readData(string filename){
//   ifstream infile;
//   infile.open(filename);
//   if (!infile.is_open()){
//     cout << "File has failed to open" << endl;
//   }
//
//   else if (infile.is_open()){
//     cout << "File opened successfully." << endl;
//     string line;
//     string item;
//     string name;
//     float gpa;
//     int age;
//     while(getline(infile,line)){
//       stringstream ss;
//       ss << line;
//       getline(ss,item,',');
//       //cout << item << "<< NAME" << endl;
//       name = item;
//       getline(ss,item,',');
//       //cout << stof(item) << "<< GPA" << endl;
//       gpa = stof(item);
//       getline(ss,item,',');
//       //cout << stoi(item) << "<<AGE" << endl;
//       age = stoi(item);
//     }
//   }
//
// }
