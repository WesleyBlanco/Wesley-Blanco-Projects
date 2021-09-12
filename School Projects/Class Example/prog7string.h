//Program		7
//Description	A program that reads a file filled with data about musical instruments and sets them
//				into their appopriate class from a base class
//Programmer	Wesley Blanco
//Class			CS 2020 Spring 2018

#ifndef PROG7STRING_H
#define PROG7STRING_H

#include <iostream>
#include <string>
#include "prog7instrument.h"

using namespace std;

class StringInstrument : public MusicalInstrument
{
private:
	bool isBowed;
	int howManyStrings;

public:
	StringInstrument();
	StringInstrument(string, double, bool, int);

	void setBow(bool realBow) { isBowed = realBow; };
	void setStrings(int realStrings) { howManyStrings = realStrings; };

	virtual void displayInstrument() const;
};

#endif