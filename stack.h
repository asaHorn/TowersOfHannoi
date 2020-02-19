#ifndef _Stack_H_
#define _Stack_H_

#include "slist.h"

class Stack
{
	struct Node
	{
		void* data;
		Node *pNext;
	};

  private:
  	slist tower;

	public:
		Stack();					// Construct stack
		~Stack();
		void push(void* inData);	// Add element to top of stack
		void* pop();				// Return element at top of stack and remove from top
		void* top();				// Return element at top of stack
		bool empty();
		void display();
		bool isDone();
		int size();
};

#endif 		//_Stack_H_
