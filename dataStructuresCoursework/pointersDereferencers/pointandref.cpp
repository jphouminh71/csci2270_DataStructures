#include <iostream>
#include <string>
#include <vector>
using namespace std;

void passbyValue(int a)
{
  a++;
}
void passByPointer(int* ptr)        // this is like the longer version of passing by reference
{
  cout << "address stored in ptr; " << ptr << endl;
  cout << "value stored in ptr; " << *ptr << endl;    // displaying the value in the ptr that was passed
  (*ptr)++; // incrementing the acutal value
  //*ptr = *ptr + 1;
  //(*ptr)++; // esentially the same thing as the same line above.
}
void passByReference(int& ref)    // when you do this, you actually are passing the value and you can make changes here too
{
  cout << ref << endl;
  ref++;
}
void passbyArray              // dynamic memory allocation
int main(int argc,char* argv[])
{
  int a = 5;
  int* b = &a;

  int* y = new int[10];   // new is allocating memory for the array
  double* x = new double[20]; // pointer array of array of 20 doubles

  delete[] y; // frees the memory allocated to y;
  delete[] x; // frees the memory allocated to x;

  int* x2 = new int;
  *x2 = 5;
  y = x2; // y now points to the same address as x2
  cout << y << endl;
  // x = x2; // does this work? , not
  // program slows down
  int* x3 = new int[100]; // x3 points to array of 100 points, pointer is allocating memory for this array, it hasn't neccessarily been declared
  x3[0] = 100;
  x3[10] = 200;
  //x3 = x2;  // here you switched the pointer of x3 to point at whatever x2, and now you have the original value of 100 int just taking up space
  // how do i get data out of x3?
  // you cant get back because x3 now points to the same address as x2
  // array of 100 ints in memory that cant be accessed
  // memory leak

  //passByReference(a);
  //cout << "NEW A: " << a << endl;
  //passByPointer(b);
  //cout << "NEW VALUE: " << a << endl; // you DYNAMICALLY changed the value of a by passing it by reference!





  // Reference vs Pointer
  // int a = 5;
  // int& ref = a;      // this throws you the value of whatever address it's currently pointing too.
  // int* pointer = &a;  // again this is just pointing to the address
  // // cout << ref << "<< Reference" << endl;
  // // cout << pointer << "<< Pointer" << endl;
  // int size = 10;
  // int myArray[size];
  // for (int i = 0; i < size; i++){
  //   myArray[i] = i;
  // }
  //
  // vector<int> myVector;
  // for (int i = 0; i < 10; i++)
  // {
  //   myVector.push_back(i);
  // }
  // for (int i = 0; i < myVector.size(); i++)
  // {
  //   cout << &myVector[i] << endl;
  // }
  // cout << " ----- " << endl;
  // for (int i = 0; i < myVector.size(); i++)
  // {
  //   cout << *&myVector[i] << endl;
  // }
  // for (int i = 0; i < size; i++){
  //   int& refb = myArray[i];
  //   int* point = &myArray[i];   // have to use to, &, to tell the computer you are throwing a address at it
  //   cout << refb << "<< REFERENCE VALUE" << endl;
  //   cout << point << "<< POINTER VALUE" << endl;
  // }




  // Array of Pointers;
  // int a1 = 5 , a2 = 6, a3 = 7;
  // int* p1 = &a1,
  //      *p2 = &a2,
  //      *p3 = &a3;
  //
  // int* pa[] = {p1,p2,p3};
  // for (int i = 0; i < 3; i++)
  // {
  //   cout << pa[i] << endl;      // for looping through the array of pointers and getting the address
  // }
  // for (int i = 0; i < 3; i++)
  // {
  //   cout << *pa[i] << endl;   // now you are asking for the value of the address at that point.
  // }



  // POINTERS WITH ARRAYS
  // int a[] = { 1,2,3 };
  // int* p1 = &a[0]; // initiallizing pointer with the value of address of position 0 of array 1
  // cout << *p1 << endl;
  // cout << p1[0] << endl;
  // cout << p1[1] << endl;
  // cout << p1[2] << endl;
  // cout << ' ' << endl;
  // cout << a << endl;
  //
  // int b = 777;
  // int* p2 = &b;
  // cout << p2[0] << endl;    // same thing as using *p2 , asking for the value at the address its pointing too
  // cout << p2 << endl; // this pointer is pointing at the address of b.





  // int a = 5;
  //
  // // Pointers
  // int* p1;    // pointer instance
  // p1 = &a;    // setting the value of the pointer variable as address of value, a
  // int* p2 = p1;   // same thing again, you could also have put &a
  // cout << &a << endl;
  // cout << p1 << endl;
  // cout << p2 << endl;
  // cout << *&a << endl;
  // cout << *p1 << endl;  // gives you ,the value of the address, it is pointing to





  // dereferencer
  //cout << *&a << endl;  // this is saying, get me the address, and at that address, get me the value, same as saying cout << a.



  // reference and dereferencer
  // int& my_ref = a;  // essentially saying, give me the value at address a.
  // cout << &a << endl;   // gives you address of variable
  // cout << my_ref << endl;
  // cout << &a << endl;
  // cout << &my_ref << endl;

  // string b = "Ham Sandwich";
  // cout << &b << endl;

  //string y;
  //getline(cin,y);
  return 0;
}
