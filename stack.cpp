#include<stdio.h>
#include<iostream>
#include<math.h>
#include <stack.h>
#include "disc.h"
using namespace std;

<<<<<<< HEAD
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
=======
// internal linked list

Stack::Stack()
{
	private:
		slist tower;
}

Stack::~Stack()
{
	// delete data;
	delete tower;
}


void Stack::push(void* inData)
{
	tower.add(inData);
}
void* Stack::pop()
{
	void* out = tower.get(tower.size());
	tower.remove(tower.size())
	return out;
>>>>>>> dev
}

void* Stack::top()
{
<<<<<<< HEAD
	// your code
=======
	return tower.get(tower.size());
>>>>>>> dev
}

bool Stack::empty()
{
<<<<<<< HEAD
	// your code
=======
	delete tower;
	tower = new slist;
>>>>>>> dev
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

