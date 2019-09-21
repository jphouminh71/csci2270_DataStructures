
#include "YTbst.cpp"
int main(int argc, char* argv[])
{
  BST tree;
  // tree.addLeaf(99);
  // tree.addLeaf(3);
  // tree.addLeaf(4);
  // tree.addLeaf(2);
  // tree.addLeaf(1);
  // tree.addLeaf(7);
  // tree.addLeaf(8);
  for (int i = 0; i < 10; i++)
  {
    tree.addLeaf(i);
  }
  for (int i = 54; i < 88; i++)
  {
    tree.addLeaf(i);
  }

  // //cout << tree.returnRootKey() << endl;
  tree.printChildren(tree.returnRootKey());
  tree.printChildren(4);
  cout << "SMALLEST: " << endl;
  int smallest = tree.findSmallest();
  cout << smallest << endl;

  cout << endl;
   cout << "PRINTING IN ORDER TRAVERSAL:" << endl;
   tree.printInOrderTraversal();
  return 0;
}
