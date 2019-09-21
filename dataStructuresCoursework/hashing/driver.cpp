#include "hash.cpp"

int main(int argc, char* argv[])
{
  HASH hashtable;

  hashtable.addItem("Jon","Soju");
  hashtable.addItem("rick","vodka");
  hashtable.addItem("morty","water");
  hashtable.addItem("shrek","swamp");
  hashtable.addItem("fiona","wine");
  hashtable.addItem("paul","orange juice");
  hashtable.addItem("paula","strawberry juice");
  hashtable.addItem("jane","watermelon juice");
  hashtable.addItem("jonah","coconut rum");
  hashtable.addItem("jason","beer");
  hashtable.addItem("nick","whiskey");
  hashtable.addItem("John","Crown Royal");
  hashtable.printTable();
  //hashtable.findDrink("rick");
  hashtable.removeItem("Jon");
  hashtable.printTable();
  return 0;
}
