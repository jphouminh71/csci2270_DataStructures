#include "MovieTree.cpp"
int main(int argc, char* argv[])
{
  MovieTree redbox;

  ifstream infile;
  infile.open(argv[1]);
  if (infile.fail())
  {
    cout << "FILE FAILED TO OPEN" << endl;
    return -1;
  }
  else{
    string line;

    string ranking1;
    string title;
    string year1;
    string quantity1;

    while( getline(infile, line))   // read in the file and load in movies and build tree;
    {
      stringstream ss;
      ss << line;
      getline(ss,ranking1,',');
      int ranking = stoi(ranking1);
      getline(ss,title,',');
      getline(ss,year1,',');
      int year = stoi(year1);
      getline(ss,quantity1,',');
      int quantity = stoi(quantity1);
      // cout << "Ranking: " << ranking << endl;
      // cout << "Title: " << title << endl;
      // cout << "Year: " << year << endl;
      // cout << "Quantity: " << quantity << endl;
      redbox.addMovieNode(ranking,title,year,quantity);
    }

   string input = "";
   //string title = "";
   while(input != "1" || input != "2" ||input != "3" || input != "4" || input != "5")
   {
       cout << "======Main Menu======" << endl;
       cout << "1. Find a movie" << endl;
       cout << "2. Rent a movie" << endl;
       cout << "3. Print the inventory" << endl;
       cout << "4. Count movies" << endl;
       cout << "5. Delete movie" << endl;
       cout << "6. Quit" << endl;
       cout << "Press 1 to find a movie, 2) to rent a movie, 3) to print the inventory or 4) to quit." << endl;
       getline(cin,input);
       if(input == "1")
       {
           cout << "Enter Title" << endl;
           getline(cin,title);
           redbox.findMovie(title);
       }
       else if(input == "2")
       {
           cout << "Enter title:" << endl;
           getline(cin,title);
           redbox.rentMovie(title);
       }
       else if(input == "3")
       {
           redbox.printMovieInventory();
       }
       else if (input == "4")
       {
         redbox.countMovies();
       }
       else if (input == "5")
       {
         cout << "Enter Title:" << endl;
         getline(cin,title);
         redbox.deleteMovie(title);
       }
       else
       {
           cout << "Goodbye!" << endl;
           break;
       }
   }
   return 0;
  }
}
