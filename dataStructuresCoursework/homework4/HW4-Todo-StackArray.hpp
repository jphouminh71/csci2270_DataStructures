r#ifndef HW4_TODO_STACKARRAY
#define HW4_TODO_STACKARRAY

#include <string>

struct TodoItem
{
	std::string todo;
};

const int MAX_STACK_SIZE = 5;

class TodoStackArray
{
  public:
	TodoStackArray();	// done
	bool isEmpty();	// done
	bool isFull();	// done
	void push(std::string todoItem);	// done, check
	void pop();
	TodoItem* peek();	// done
	int getStackTop()	 // done
	{
		return stackTop;
	}
	TodoItem** getStack()
	{
		return stack;
	}

  private:
	int stackTop;	//the index in stack[] that will be popped next
	TodoItem* stack[MAX_STACK_SIZE];	// this is an array full of item nodes (pointers)
};

#endif
