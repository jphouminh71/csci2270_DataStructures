#ifndef HW4_TODO_QUEUELINKEDLIST
#define HW4_TODO_QUEUELINKEDLIST

#include <string>

struct TodoItem
{
	std::string todo;
	TodoItem *next;
};

class TodoQueueLinkedList
{
  public:
	TodoQueueLinkedList();
	// {
	// 	queueFront = nullptr;
	// 	queueEnd = nullptr;
	// }
	~TodoQueueLinkedList();
	// {
	// 	while (!isEmpty())
	// 	{
	// 		dequeue();
	// 	}
	// }
	bool isEmpty();
	// {
	// 	if (queueFront == nullptr && queueEnd == nullptr)
	// 	{
	// 		return true;
	// 	}
	// 	return false;
	// }
	void enqueue(std::string todoItem);
	// {
	// 	TodoItem* newItem = new TodoItem;
	// 	newItem->todo = todoItem;
	// 	newItem->next = nullptr;
	// 	if (isEmpty())		// if theres nothing in the queue, keep the next pointer
	// 	{
	// 		newItem->next = nullptr;
	// 		queueFront = newItem;
	// 		queueEnd = newItem;
	// 	}
	// 	else{
	// 		queueEnd->next = newItem;
	// 		queueEnd = newItem;
	// 	}
	// }
	void dequeue();
	// {
	// 	if (isEmpty())
	// 	{
	// 		return;
	// 	}
	// 	else if(!isEmpty())
	// 	{
	// 		if (queueFront == queueEnd)
	// 		{
	// 			delete queueFront;
	// 			queueFront = nullptr;
	// 			queueEnd = nullptr;
	// 		}
	// 		else{
	// 			TodoItem* tempptr = queueFront;
	// 			queueFront = queueFront->next;
	// 			delete tempptr;
	// 		}
	// 	}
	// }
	TodoItem* peek();
	// {
	// 	if (!isEmpty())
	// 	{
	// 		return queueFront;
	// 	}
	// 	return nullptr;
	// }
	TodoItem* getQueueFront();
	// {
	// 	return queueFront;
	// }
	TodoItem* getQueueEnd();
	// {
	// 	return queueEnd;
	// }

  private:
	TodoItem* queueFront; // the item in the list that will be dequeued next
	TodoItem* queueEnd;   // the item in the list that was most recently enqueued
};



#endif
