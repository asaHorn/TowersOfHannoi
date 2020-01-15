#include<stdio.h>
#include<iostream>
#include<math.h>
#include <stack.h>
#include "disc.h"
using namespace std;

Stack::Stack()
{

}
/*
Stack::~Stack()
{
	// delete data;
}
*/

void Stack::push(void* inData)
{
	// your code
}
void* Stack::pop()
{
	// your code
}

void* Stack::top()
{
	// your code
}

bool Stack::empty()
{
	// your code
}

void Stack::display()
{
	//cout<<endl;
	Node *p1;
	p1 = pTop;
	while (p1 != NULL)
	{
		cout<< ((Disc*)(p1->data))->toString()<<"\t";
		p1 = p1->pNext;
	}
	cout<<endl;
}

