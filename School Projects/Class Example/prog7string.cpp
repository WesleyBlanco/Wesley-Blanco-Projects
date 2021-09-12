//Program		7
//Description	A program that reads a file filled with data about musical instruments and sets them
//				into their appopriate class from a base class
//Programmer	Wesley Blanco
//Class			CS 2020 Spring 2018

#include "prog7string.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Function		:Default Constructor
//Description	:A default constructor for class String Instrument
//Programmer	:Wesley Blanco
//Class			:CS 2020 Spring 2018
//Parameters	:None
//Returns		:None
StringInstrument::StringInstrument()
{
	StringInstrument : MusicalInstrument();
	howManyStrings = 0;
	isBowed = false;
}

//Function		:StringInstrument overloaded Constructor
//Description	:Overloaded Constructor for String Instrument
//Programmer	:Wesley Blanco
//Class			:CS 2020 Spring 2018
//Parameters	:String, double, bool, and int, holding name, price, if it uses a bow, and how many strings it has
//Returns		:None
StringInstrument::StringInstrument(string realName, double realPrice, bool realBowed, int realStrings)
{
	StringInstrument : MusicalInstrument(realName, realPrice);
	howManyStrings = realStrings;
	isBowed = realBowed;
}

//Function		:String Instrument's Overrided Display Instrument
//Description	:An overrrided function of DisplayInstrument
//Programmer	:Wesley Blanco
//Class			:CS 2020 Spring 2018
//Parameters	:None
//Returns		:None
void StringInstrument::displayInstrument() const
{
	cout << "Type:" << setw(26) << "Stringed Instrument" << endl;
	cout << "Name:" << setw(25) << this->instrumentName << endl;
	cout << "Cost:" << setw(18) << "$" << setprecision(2) << fixed << this->cost << endl;

	if (isBowed)
		cout << "Bowed:" << setw(18) << "Yes" << endl;
	else
		cout << "Bowed:" << setw(18) << "No" << endl;

	cout << "Strings" << setw(18) << this->howManyStrings << endl;
	cout << endl;
}
