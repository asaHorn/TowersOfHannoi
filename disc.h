#ifndef DISC_H
#define DISC_H
#include<stdio.h>
#include<string.h>
#include<iostream>

class Disc
{
	int size;
	
public:
	Disc();
	Disc(int);
	~Disc();
	int getSize();
	bool setSize(int);
	std::string toString();

};

#endif // DISC_H
