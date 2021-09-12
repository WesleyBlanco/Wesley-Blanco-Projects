//Program		7
//Description	A program that reads a file filled with data about musical instruments and sets them
//				into their appopriate class from a base class
//Programmer	Wesley Blanco
//Class			CS 2020 Spring 2018
#include <iostream>
#include <string>
#include "prog7instrument.h"
#include <iomanip>

//Function		:Musical Instrument's constructor
//Description	:A constructor for Muscial Instrument
//Programmer	:Wesley Blanco
//Class			:CS 2020 Spring 2018
//Parameters	:None
//Returns		:None
MusicalInstrument::MusicalInstrument()
{
	instrumentName = "";
	cost = 0.0;
}

//Function		:Musical Instrument's overloaded constructor
//Description	:An overloaded constructor for Muscial Instrument Class
//Programmer	:Wesley Blanco
//Class			:CS 2020 Spring 2018
//Parameters	:String and Double for name and cost
//Returns		:None
MusicalInstrument::MusicalInstrument(string realName, double realPrice)
{
	instrumentName = realName;
	cost = realPrice;
}

//Function		:displayInstrument
//Description	:A function that displays stored data from about an instrument
//Programmer	:Wesley Blanco
//Class			:CS 2020 Spring 2018
//Parameters	:None
//Returns		:None
void MusicalInstrument::displayInstrument() const
{
	cout << "Type:" << setw(25) << "Unknown Instrument" << endl;
	cout << "Name:" << setw(25) << this->instrumentName << endl;
	cout << "Cost:" << setw(18) << setprecision(2) << fixed << "$" << this->cost << endl;
	cout << endl;
}
