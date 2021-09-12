
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>

int BuildMaxHeap(int*, int);
int Heapify(int*, int, int);
int HeapSort(int*, int);

using namespace std;

//Filename through argv
int main(int argc, char* argv[])
{
	int totalElements = 0;
	string reader;
	//Declaring all Infiles from Data Generation
	ifstream infile;
	infile.open(argv[argc - 1]);
	clock_t timer = 0;
	int comparisons;

	//Declaring the Outfile
	ofstream outfile;
	outfile.open("HeapSortOutput.txt", fstream::app);

	if (infile)
	{
		//Fills the dynamic array with its total elements and
		//Also populates the array by getting line then changing line to an int
		int i;
		while (!infile.eof())
		{
			totalElements++;
			getline(infile, reader);
		}
		infile.close();
		infile.open(argv[argc - 1]);

		totalElements--;
		int n;
		int* p2a = new int[totalElements];
		i = 0;
		while (!infile.eof() && i < totalElements)
		{
			infile >> n;
			p2a[i] = n;
			i++;
		}


		timer = clock();
		comparisons = HeapSort(p2a, totalElements);
		timer = clock() - timer;
		

		//Output to file
		outfile << totalElements << ", ";
		outfile << comparisons << ", ";
		outfile << timer << endl;

		//this was for proving array was correctly sorted
		//for (int j = 0; j < i; j++)
		//{
		//	cout << p2a[j] << endl;
		//}


		infile.close();
		delete[] p2a;
	}
	else
	{
		cout << "Infile failed" << endl;
		outfile << "Infile Failed" << endl;
	}

	outfile.close();
}

int Heapify(int* p2a, int i, int totalElements)
{
	int Left = 2 * i + 1;
	int Right = 2 * i + 2;
	int holder;
	int large;
	int comparisons = 0;
	if (Left < totalElements && p2a[Left] > p2a[i])
	{
		comparisons++;
		large = Left;
	}
	else
	{
		large = i;
	}
	if (Right < totalElements && p2a[Right] > p2a[large])
	{
		comparisons++;
		large = Right;
	}
	if (large != i)
	{
		holder = p2a[i];
		p2a[i] = p2a[large];
		p2a[large] = holder;
		comparisons += Heapify(p2a, large, totalElements);
	}
	return comparisons;
}

int BuildMaxHeap(int* p2a, int totalElements)
{
	int comparisons = 0;
	for (int i = totalElements / 2 - 1; i >= 0; i--)
	{
		comparisons += Heapify(p2a, i, totalElements);
	}
	return comparisons;
}

int HeapSort(int* p2a, int totalElements)
{
	int holder;
	int comparisons = BuildMaxHeap(p2a, totalElements);
	for (int i = totalElements - 1; i >= 0; i--)
	{
		holder = p2a[i];
		p2a[i] = p2a[0];
		p2a[0] = holder;

		comparisons += Heapify(p2a, 0, i);
	}
	return comparisons;
}