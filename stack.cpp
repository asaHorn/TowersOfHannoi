#include<stdio.h>
#include<iostream>
#include<math.h>
#include "stack.h"
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
	tower.add(inData)
}
void* Stack::pop()
{
  temp = tower.get(0);
  tower.remove(0);
  return temp;

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
}

void* Stack::top()
{
	// your code
	return tower.get(tower.size());
}

bool Stack::empty()
{
	// your code
	delete tower;
	tower = new slist;
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

