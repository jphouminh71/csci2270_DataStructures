#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Movies{
private:
  string title;
  int year;
  double rating;
public:
  Movies(){           // default constructor
    title = "unknown";
    year = 2016;
    rating = 0.0;
  }
  Movies(string givenTitle, int givenYear, double givenRating){
    title = givenTitle;
    year = givenYear;
    rating = givenRating;
  }
  void setTitle(string);
  void setYear(int);
  void setRating(double);
  string getTitle();
  int getYear();
  double getRating();
};
void Movies::setTitle(string givenTitle){
  title = givenTitle;
}
void Movies::setYear(int givenYear){
  year = givenYear;
}
void Movies::setRating(double givenRating){
  rating = givenRating;
}
string Movies::getTitle(){
  return title;
}
int Movies::getYear(){
  return year;
}
double Movies::getRating(){
  return rating;
}
