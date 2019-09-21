#include "treeYT.cpp"
int main(int argc,char* argv[])
{
  BST myTree;

  int array[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};

  //myTree.inOrderTraversal();  // we expect this right now to tell us that the tree is currently empty.

  // load the tree.
  for (int i = 0 ; i < 16; i++){
    myTree.addleaf(array[i]);
  }

//        The traversal test cases
  //myTree.inOrderTraversal();
  //myTree.preOrderTraversal();
  //myTree.postOrderTraversal();

//        Testing helper function, returnNode()
  //node* key = myTree.returnNode(14);
  //cout << key->key << "<--" << endl;

//        Testing out the print children function for all nodes
  // int i = 0;
  // for(i = 0; i < 16; i++){
  //   myTree.printChildren(array[i]);
  //   cout << endl;
  // }

//        Testing out the findSmallest function
  // int smallest_value = myTree.findSmallest();
  // smallest_value == -9999 ?
  // cout << "Tree was empty." << endl :
  // cout << "Smallest Value: " << smallest_value << endl;

// testing out removeNode
  // myTree.RemoveNode(50);
  // myTree.inOrderTraversal();
  // myTree.RemoveNode(52);
  // myTree.inOrderTraversal();















  return 0;
}



/*
    changes made to this program include adding
      -preorder traversal()
      -postorder traveral ()
      -top view()
      -find height()
*/
