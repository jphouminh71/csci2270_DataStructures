#ifndef HW4_TODO_STACKLINKEDLIST
#define HW4_TODO_STACKLINKEDLIST

#include <string>

struct TodoItem
{
	std::string todo;
	TodoItem *next;
};

class TodoStackLinkedList
{
  public:
	TodoStackLinkedList();
	~TodoStackLinkedList();
	bool isEmpty();
	void push(std::string todoItem);
	void pop();
	TodoItem* peek();
	TodoItem* getStackHead()	 { return stackHead; }

  private:
	TodoItem* stackHead; // pointer to the TodoItem that will be popped next
};

#endif
