#include "heaps.cpp"

int main(int argc, char* argv[]){
  ifstream infile;
  infile.open("informationfile.txt");
  if (infile.is_open()){
    cout << "File opened successfully." << endl;
  }
  else if (!infile.is_open()){
    cout << "File failed to open." << endl;
    return -1;
  }


  return 0;
}
