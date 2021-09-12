//Program		7
//Description	A program that reads a file filled with data about musical instruments and sets them
//				into their appopriate class from a base class
//Programmer	Wesley Blanco
//Class			CS 2020 Spring 2018

#ifndef PROG7_INSTRUMENT
#define PROG7_INSTRUMENT

#include <iostream>
#include <string>

using namespace std;

class MusicalInstrument
{
protected:
	char borS;
	string instrumentName;
	double cost;

public:
	MusicalInstrument();
	MusicalInstrument(string, double);

	//Accessor
	char getborS() const { return borS; };
	string getInstrumentName() const { return instrumentName; };
	double getCost() const { return cost; };

	//Mutator
	void setborS(char realBorS) { borS = realBorS; };
	void setName(string realName) { instrumentName = realName; };
	void setCost(double realCost) { cost = realCost; };

	//Display 
	virtual void displayInstrument() const;
};


#endif
