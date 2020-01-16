#include<stdio.h>
#include<iostream>
#include<math.h>
#include "stack.h"
#include "disc.h"

using namespace std;

void toh(int n)
{
    int i, x;
	Disc* a;
	Disc* b;
	Stack* t1 = new Stack();
	Stack* t2 = new Stack();
	Stack* t3 = new Stack();
	

    for (i = n; i >= 1; i--)
    {
		//d.setSize(i);
		Disc* d = new Disc(i);
		cout << d->toString();
        t1->push(d);
    }

	// ****  Your Tower of Hanoi solution!


}
int main()
{
    int n;
    cout<<"enter the number of disksn";
    cin>>n;
    toh(n);
    return 0;
}