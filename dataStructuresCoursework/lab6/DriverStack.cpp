#include <iostream>
#include "StackLL.hpp"
// #include "StackLL.cpp"
using namespace std;

int main()
{
    // test stacks
    StackLL stack;

    // TC1: stack empty after created?
    cout << "(1) ";
    cout << "Stack empty? ";
    cout << (stack.isEmpty() ? "yes." : "no.");
    if(!stack.isEmpty()) cout << "  -- FAIL";
    cout << endl;

    // TC2: Push items
    cout << "(2) ";
    cout << "Pushing 1, 2, 3" << endl;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    // TC3: Stack not empty after pushing items
    cout << "(3) ";
    cout << "Stack empty? ";
    cout << (stack.isEmpty() ? "yes." : "no.");
    if(stack.isEmpty()) cout << "  -- FAIL";
    cout << endl;

    // TC4: peek
    cout << "(4) ";
    int topKey = stack.peek();
    cout << "Peeked key: " << topKey;
    if(topKey != 3) {
        cout << "  -- FAIL";
    }
    cout << endl;

    // TC5: pop items
    cout << "(5) Popping everything" << endl;
    int testint = 0;
    int testvals[] = {3, 2, 1};
    while(!stack.isEmpty()) {
        topKey = stack.peek();
        stack.pop();
        cout << "  - pop: " << topKey;
        if(topKey != testvals[testint++]) {
            cout << "  -- FAIL";
        }
        cout << endl;
    }

    return 0;
}