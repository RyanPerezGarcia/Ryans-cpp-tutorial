#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
int main()
{
	srand(time(0)); 
	vector <double> list{ -1, 5, 7, 4, 2, -10, 8, 6, 2, -10 };
	for (int i = 0; i < 90; i++)
	{
		list.push_back(rand()%100-1);
	}
	cout << "Here is the unsorted list: \n";
	for (int i = 0; i <100; i++)
	{
		cout << list[i] << ", ";
	}
	bool haveSwapped;
	do
	{
		haveSwapped = false;
		for (int i = 0; i < 99; i++)
		{
			double* a = &list[i];
			double* b = &list[i + 1];
			double s;
			if (*a > *b)
			{
				s = *a;
				*a = *b;
				*b = s;
				haveSwapped = true;
			}
		}

	} while (haveSwapped);
	cout << "\nHere is the sorted list:\n ";
	for (int i = 0; i < 100; i++)
	{
		cout << list[i] << ", ";
	}

		
}
