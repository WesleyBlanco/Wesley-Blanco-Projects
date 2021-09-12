//Name : Blanco Wesley
//Program: Program 3, BlancoWprgm3, 22/10/17
//Description : To find Cincinnati schools under 1000 dollars
//To find the average tuition of Ohio schools and compare the average to BGSU's tuition
//To find the three most expensive schools in Ohio
//Input data required is that of the Schools, the Schools locations, the total enrollment and the tuition
//Calculations for the average tuition is adding all tuitions for 1000 + enrolled students
//If a school is has that many enrolled then it is added to the total and the counter is increased
//At the end the total is divided by the counter.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main ()
{
	//Declare variables
	ifstream infile;
	string schoolName;
	string schoolLocation;
	double price;
	double averageCost = 0;
	double falconAverage;
	double studentsEnrolled;
	double firstHighest = 0;
	double secondHighest = 0;
	double thirdHighest = 0;
	double averageCounter = 0;
	string firstHighestName = "A";
	string secondHighestName = "B";
	string thirdHighestName = "C";

	//Open file first time
	infile.open("OH-in.dat");

	//Pull first set of data
	infile >> schoolName;
	infile >> schoolLocation;
	infile >> studentsEnrolled;
	infile >> price;

	cout << "Cincinnati Schools under $20000" << endl;
	//Answering problem one for Cincinnati Schools.
	while (schoolName != "***")
	{
		//Begin solving for Cincinnati schools
		if (schoolLocation == "Cincinnati" && price < 20000)
		{
			cout << schoolName << endl;
		}

		infile >> schoolName;
		infile >> schoolLocation;
		infile >> studentsEnrolled;
		infile >> price;
	}

	//Closing file to reset.
	infile.close();

	//Opening back up
	infile.open("OH-in.dat");

	//Pulling first data set again
	infile >> schoolName;
	infile >> schoolLocation;
	infile >> studentsEnrolled;
	infile >> price;
	
	//Adding endl to make it look neater
	cout << endl;

	//Answering Q2, Average Tuition and BGSU
	while (schoolName != "***")
	{
		if (schoolName == "BowlingGreenStateUniversity")
		{
			cout << "BGSU has a tuition of $" << price << endl;
			falconAverage = price;
		}
		if (studentsEnrolled >= 10000)
		{
			averageCost = price + averageCost;
			averageCounter = averageCounter++;
		}

		infile >> schoolName;
		infile >> schoolLocation;
		infile >> studentsEnrolled;
		infile >> price;
	}
	averageCost = averageCost / averageCounter;
	cout << "The average tuition is $" << averageCost << endl;
	
	if (falconAverage > averageCost)
		cout << "BGSU\'s tuition is higher than average." << endl;
	else
		cout << "BGSU\'s tuition is lower than average." << endl;

	//Closing file again for third task.
	infile.close();

	//Reopening
	infile.open("OH-in.dat");

	//Pulling data for the third time
	infile >> schoolName;
	infile >> schoolLocation;
	infile >> studentsEnrolled;
	infile >> price;

	//Addeding this endl to make it look neater
	cout << endl;

	//Begin answering Question three, what are the most expensive schools.
	while (schoolName != "***")
	{
		if (price > thirdHighest)
		{
			if (price > secondHighest)
			{
				if (price > firstHighest)
				{
					//Names of schools first highest
					thirdHighestName = secondHighestName;
					secondHighestName = firstHighestName;
					firstHighestName = schoolName;
					
					//Prices of schools firsth highest
					thirdHighest = secondHighest;
					secondHighest = firstHighest;
					firstHighest = price;
				}
				else
				{
					//Names for first highest
					thirdHighestName = secondHighestName;
					secondHighestName = schoolName;

					//Prices for second highest
					thirdHighest = secondHighest;
					secondHighest = price;
				}
			}
			else
			{
				//Names for Third Highest
				thirdHighestName = schoolName;

				//Prices for Third highest
				thirdHighest = price;
			}
		}

		infile >> schoolName;
		infile >> schoolLocation;
		infile >> studentsEnrolled;
		infile >> price;
	}

	//Cout the answers for the last question
	cout << "The most Expensive school is :" << firstHighestName << endl;
	cout << "At the tuition of $" << firstHighest << endl;

	//Endl for formating
	cout << endl;

	cout << "The second most Expensive school is :" << secondHighestName << endl;
	cout << "At the tuition of $" << secondHighest << endl;

	//Endl for formating
	cout << endl;

	cout << "The third most Expensive school is :" << thirdHighestName << endl;
	cout << "At the tuition of $" << thirdHighest << endl;

	//Close the file one last time 
	infile.close();

	system("pause");
	return 0;
}