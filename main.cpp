//towers of Hanoi
//Asa Horn
//Lasa CS, starting code provided by James Shockey

#include<stdio.h>
#include<iostream>
#include<math.h>
#include "stack.h"
#include "disc.h"

using namespace std;

//Is legal: returns true if toMove can be placed on recive, false if not
	//toMove the moving piece
	//recove the piece to cover
bool isLegal(int* toMove, int* recive){
	if(recive == NULL){
		return true;
	}
	if(toMove == NULL){
		return false;
	}
	else if(*toMove < *recive){
		return true;
	}
	else{
		return false;
	}
}

void legalMove(Stack* one, Stack* two, int i){
	cout << "making move: " << i << "\n\n";
	if(isLegal((int*)one->top(), (int*)two->top())){ //is it legal to a -> b
		two->push(one->pop()); //move A to B
	}
	else{
		one->push(two->pop()); //move B to A
	}
}

void boardDisplay(Stack* one, Stack* two, Stack* three){
	cout << "one: ";
	one->display();
	cout << endl;

	cout << "two: ";
	two->display();
	cout << endl;

	cout << "three: ";
	three->display();
	cout << endl;

	cout << endl;
}

//if a and b are empty and c is finished return true, else return false
bool finished(Stack* a, Stack* b, Stack* c){
	if( a->size() == 0 && b->size() == 0 && c->isDone() == 0){
		cout << "passed 'finished': " << a->size() << "|" << b->size() << "|" << c->isDone() << "\n";
		cout << "\n TOWER HAS BEEN COMPLETED GET REKED\n";
		return true;
	}
	cout << "failed 'finsihed': " << a->size() << "|" << b->size() << "|" << c->isDone() << "\n";
	return false;
}

void toh(int n)
{
  int i, x;
	Stack* t1 = new Stack();
	Stack* t2 = new Stack();
	Stack* t3 = new Stack();

    for (i = n; i >= 1; i--)
    {
		//d.setSize(i);
		Disc* d = new Disc(i);
		cout << d->toString() << "\n";
    t1->push(d);
    }

	// ****  Your Tower of Hanoi solution!
	//For an even number of disks:
		//make the legal move between pegs A and B (in either direction),
		// make the legal move between pegs A and C (in either direction),
		// make the legal move between pegs B and C (in either direction),
		// repeat until complete.
	// For an odd number of disks:
		// make the legal move between pegs A and C (in either direction),
		// make the legal move between pegs A and B (in either direction),
		// make the legal move between pegs B and C (in either direction),
		// repeat until complete.
	int loopNum =0;

	if(n % 2 == 0){\
		while(!finished(t1, t2, t3)){		
			legalMove(t1, t2, loopNum*3); //make the legal move between pegs A and B 
			boardDisplay(t1, t2, t3);

			if(finished(t1, t2, t3))break; //make sure that move wasn't the last one

			legalMove(t1, t3, loopNum*3+1); // make the legal move between pegs A and C
			boardDisplay(t1, t2, t3);

			if(finished(t1, t2, t3))break; //make sure that move wasn't the last one

			legalMove(t2, t3, loopNum*3+2); // make the legal move between pegs B and C
			boardDisplay(t1, t2, t3);
			
			loopNum++;
		}
	}
	else{
		while(!finished(t1, t2, t3)){		
			legalMove(t1, t3, loopNum*3); // make the legal move between pegs A and C
			boardDisplay(t1, t2, t3);

			if(finished(t1, t2, t3))break; //make sure that move wasn't the last one

			legalMove(t1, t2, loopNum*3+1); // make the legal move between pegs A and B
			boardDisplay(t1, t2, t3);

			if(finished(t1, t2, t3))break; //make sure that move wasn't the last one

			legalMove(t2, t3, loopNum*3+2); // make the legal move between pegs B and C
			boardDisplay(t1, t2, t3);

			loopNum++;
		}
	}
}

int main()
{
    int n;
    cout<<"enter the number of disks\n";
    cin>>n;
    toh(n);
    return 0;
}