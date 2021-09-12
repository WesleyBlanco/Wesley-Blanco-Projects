//Program		7
//Description	A program that reads a file filled with data about musical instruments and sets them
//				into their appopriate class from a base class
//Programmer	Wesley Blanco
//Class			CS 2020 Spring 2018

#include <iostream>
#include <string>
#include <iomanip>
#include "prog7brass.h"

using namespace std;

//Function		:BrassInstrument constructor
//Description	:A constructor to the Brass Instrument Class
//Programmer	:Wesley Blanco
//Class			:CS 2020 Spring 2018
//Parameters	:None
//Returns		:None
BrassInstrument::BrassInstrument()
{
	BrassInstrument: MusicalInstrument();
	soundMaking = "";
	material = "";
}

//Function		:Brass Instrument Overloaded Constructor
//Description	:An overloaded constructor to the Brass Instrument Class
//Programmer	:Wesley Blanco
//Class			:CS 2020 Spring 2018
//Parameters	:String, Double, String, String holding name, cost, sound made, and material used to make the instrument 
//Returns		:None
BrassInstrument::BrassInstrument(string realName, double realCost, string soundMade, string materialUsed)
{
	BrassInstrument : MusicalInstrument(realName, realCost);
	soundMaking = soundMade;
	material = materialUsed;
}

//Function		:BrassInstrument's override of Display Instrument
//Description	:A function that displays the stored information of Brass instruments
//Programmer	:Wesley Blanco
//Class			:CS 2020 Spring 2018
//Parameters	:None
//Returns		:None
void BrassInstrument::displayInstrument() const
{
	cout << "Type:" << setw(23) << "Brass Instrument" << endl;
	cout << "Name:" << setw(25) << this->instrumentName << endl;
	cout << "Cost:" << setw(18) << "$" << setprecision(2) << fixed << this->cost << endl;
	cout << "Method:" << setw(18) << this->soundMaking << endl;
	cout << "Material:" << setw(18) << this->material << endl;
	cout << endl;
}
