#ifndef _Stack_H_
#define _Stack_H_

class Stack
{
	struct Node
	{
		void* data;
		Node *pNext;
	};

	Node* pTop;


	public:
		Stack();					// Construct stack
		void push(void* inData);	// Add element to top of stack
		void* pop();				// Return element at top of stack and remove from top
		void* top();				// Return element at top of stack
		bool empty();
		void display();

};

#endif 		//_Stack_H_
