#include <iostream>
using namespace std;

struct Student
{
  string firstName, lastName, aNumber;
  double GPA;
};

int main()
{
  Student* student1 = new Student;
  cout << student1->firstname << endl;    // access using an arrow because it's a pointer not the dot operator

}
