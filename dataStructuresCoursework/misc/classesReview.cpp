#include <iostream>
#include <cmath>
using namespace std;

class Date{
private:
  int month;
  int day;
  int year;
public:
  Date()      //
  {

  }
  Date(int m, int d, int y){
    month = m;
    day = d;
    year = y;
  }
  void printDate(){
    cout << month << ' ' <<  day << ' ' <<  year << endl;
  }
  void setMonth(int m){
    if (m > 0 && m < 13)
    {
      month = m;
    }
    else
    {
      cout << "Month out of range. " << endl;
    }
  void setDay(int d)
  {
    if (d > 0 &&)
  }

  }
};

int main(int argc, char* argv[])
{
  
  Date currentDay(12,41,2018);
  currentDay.printDate();
  currentDay.setMonth(31);
  currentDay.printDate();

}
