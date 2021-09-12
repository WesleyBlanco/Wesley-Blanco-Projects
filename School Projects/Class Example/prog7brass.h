//Program		7
//Description	A program that reads a file filled with data about musical instruments and sets them
//				into their appopriate class from a base class
//Programmer	Wesley Blanco
//Class			CS 2020 Spring 2018

#ifndef PROG7BRASS_H
#define PROG7BRASS_H

#include <iostream>
#include <string>
#include "prog7instrument.h"

using namespace std;

class BrassInstrument : public MusicalInstrument
{
private:
	string soundMaking;
	string material;

public:
	BrassInstrument();
	BrassInstrument(string, double, string, string);

	//Mutators
	void setSound(string realSound) { soundMaking = realSound; };
	void setMaterial(string realMaterial) { material = realMaterial; };

	//Display
	virtual void displayInstrument() const;

};


#endif