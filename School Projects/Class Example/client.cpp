//Program		7
//Description	A program that reads a file filled with data about musical instruments and sets them
//				into their appopriate class from a base class
//Programmer	Wesley Blanco
//Class			CS 2020 Spring 2018

#include <iostream>
#include <string>
#include "prog7brass.h"
#include "prog7instrument.h"
#include "prog7string.h"
#include <fstream>

using namespace std;

bool retreiveData(MusicalInstrument*[], int, int&);

int main()
{
	const int ARRAYSIZE = 15;
	MusicalInstrument* instArray[ARRAYSIZE]{ nullptr };
	bool check;
	int trueSize = 0;
	check = retreiveData(instArray, ARRAYSIZE, trueSize);

	if (check)
	{
		for (int i = 0; i < trueSize - 1; i++)
		{
			instArray[i]->displayInstrument();
		}
	}

	return 0;
}

//Function		:RetreiveData
//Description	:Function that pulls data from a file and sets it to the pointer in an array of pointers
//Programmer	:Wesley Blanco
//Class			:CS 2020 Spring 2018
//Parameters	:Musical Instrument array of pointers, int of array size, and int of how many variables actually come through the file
//Returns		:A boolean that states if the file opened
bool retreiveData(MusicalInstrument* instArray[], int size, int &trueSize)
{
	ifstream infile;
	infile.open("prog7.txt");
	char stringOrBrass;
	int i = 0;
	BrassInstrument* BrassHold = new BrassInstrument;
	StringInstrument* StringHold = new StringInstrument;
	MusicalInstrument* MusicHold = new MusicalInstrument;
	bool success = true;
	int holdingBows;
	string nameHold;
	double costHold;
	string SoundHold;
	string materialHold;
	int stringsOn;

	if (infile)
	{
		while (!infile.eof() && i < size)
		{
			infile >> stringOrBrass;
			infile.ignore();
			getline(infile, nameHold);
			infile >> costHold;

			if (stringOrBrass == 'B')
			{
				infile >> SoundHold;
				infile >> materialHold;

				BrassHold->setborS(stringOrBrass);
				BrassHold->setName(nameHold);
				BrassHold->setCost(costHold);
				BrassHold->setSound(SoundHold);
				BrassHold->setMaterial(materialHold);

				instArray[i] = BrassHold;
				BrassHold = new BrassInstrument;

			}
			else if (stringOrBrass == 'S')
			{
				StringHold->setborS(stringOrBrass);
				StringHold->setName(nameHold);
				StringHold->setCost(costHold);
				infile >> holdingBows;

				if (holdingBows == 1)
				{
					StringHold->setBow(true);
				}

				infile >> stringsOn;
				StringHold->setStrings(stringsOn);
				instArray[i] = StringHold;
				StringHold = new StringInstrument;
			}
			else
			{
				MusicHold->setborS(stringOrBrass);
				MusicHold->setName(nameHold);
				MusicHold->setCost(costHold);
				instArray[i] = MusicHold;
				MusicHold = new MusicalInstrument;
			}
			i++;
		}
	}
	else
	{
		cout << "Infile Not Found" << endl;
		success = false;
	}
	trueSize = i;

	infile.close();

	return success;
}