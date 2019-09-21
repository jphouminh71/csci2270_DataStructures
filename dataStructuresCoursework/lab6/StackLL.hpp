#ifndef STACKLL_HPP
#define STACKLL_HPP

class StackLL
{
  private:
    struct Node
    {
        int key;
        Node *next;
    };

    // pointer to item to be popped next
    Node* stackHead;

  public:
    StackLL();
    ~StackLL();
    bool isEmpty();
    void push(int key);
    void pop();
    int peek();
};

#endif
