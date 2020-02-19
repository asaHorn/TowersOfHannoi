#include<stdio.h>
#include<iostream>
#include<math.h>
#include "stack.h"
#include "disc.h"
using namespace std;

Stack::Stack()
{
	slist tower = *new slist;
}

Stack::~Stack()
{
	// delete data;
	cout << "destroying tower"; //debug
	delete &tower;
	cout << "tower is donezo"; //debug
}

void Stack::push(void* inData)
{
	tower.add(inData);
}

void* Stack::pop()
{
	void* out = tower.get(tower.size()-1);
	tower.remove(tower.size()-1);
	return out;
}

void* Stack::top()
{
	if (tower.size() <= 0){
		return NULL;
	}
	// your code
	return tower.get(tower.size()-1);

}

bool Stack::empty()
{
	// your code
	delete &tower;
	tower = *new slist;
	return true;
}

int Stack::size(){
	return tower.size();
}

// iterate through and see if stack is in order, if stack is in order retruns true
bool Stack::isDone()          //SPACIFIC TO TOH
{
	//WILL BREAK WITH NEGITIVE STARTING VALUES!!!    
	int last = 0; //set to 0 so order goes 0,1,2 ect. 

	if(tower.size() == 1 || tower.size() == 0){  //handle 0 and 1 sized tower edge cases
		return false;
	}
	
	//run through all values, if they are in order exit
	for(int i=0; i<tower.size()-1; i++){
		if (((Disc*) tower.get(i))->getSize() != last+1){ //is this disc != to last disc+1?
			return false;
		}
		last = ((Disc*) tower.get(i))->getSize();
	}

	return true;
}

void Stack::display()
{
	for(int i=0; i < tower.size(); i++)
	{
		cout<< ((Disc*)tower.get(i))->toString() << " ";
	}
}

