#include "homework1pt3.h"
#include <vector>
int main(int argc, char* argv[]){
  vector<Movies> movies;
  Movies defaultMovie = Movies();
  Movies customMovie1 = Movies("insidious",2009,8.8);
  Movies customMovie2 = Movies("insidious2",2011,8.2);
  movies.push_back(defaultMovie);
  movies.push_back(customMovie1);
  movies.push_back(customMovie2);
  for (int i = 0; i < movies.size(); i++){
    cout << movies[i].getTitle() << endl;
    cout << movies[i].getYear() << endl;
    cout << movies[i].getRating() << endl;
    cout << "------------------" << endl;
  }
}
