#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

int mergeSort(int*, int, int);
int merge(int*, int, int, int);

using namespace std;

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
	outfile.open("MergeOutput.txt", fstream::app);

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
		comparisons = mergeSort(p2a, 0, totalElements);
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

int mergeSort(int* p2a, int p, int r)
{
	int comps = 0;
	if (p < r)
	{
		int q = (p + r) / 2;
		comps += mergeSort(p2a, p, q);
		comps += mergeSort(p2a, q + 1, r);
		comps += merge(p2a, p, q, r);
	}
	return comps;
}

int merge(int* p2a, int p, int q, int r)
{
	int comparisons = 0;
	int n = q - p + 1;
	int m = r - q;
	int holder;
	int* Left = new int[n + 1];
	int* Right = new int[m + 1];
	for (int i = 0; i < n; i++)
	{
		Left[i] = p2a[p + i - 1];
	}
	for (int i = 0; i < m; i++)
	{
		Right[i] = p2a[q + i];
	}
	Right[m + 1] = INT_MAX;
	Left[n + 1] = INT_MAX;
	int i = 0;
	int j = 0;
	for (int k = p; k < r; k++)
	{
		if (Left[i] <= Right[j])
		{
			comparisons++;
			holder = p2a[i];
			p2a[k] = Left[i];
			Left[i] = holder;
			i = i + 1;
		}
		else if (p2a[k] = Right[j])
		{
			j = j + 1;
		}
	}
	return comparisons;
}