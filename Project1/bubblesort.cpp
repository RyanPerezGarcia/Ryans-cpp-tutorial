#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int main()
{
    srand(time(0));
    double list[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "enter a bumber\n";
        cin>> list[i];
    }
    cout << "Here is the unsorted list: \n";
    for (int i = 0; i < 10; i++)
    {
        cout << list[i] << ", ";
    }
    bool haveSwapped;
    do
    {
        haveSwapped = false;
        for (int i = 0; i < 9; i++)
        {
            double *a = &list[i];
            double *b = &list[i + 1];
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
    for (int i = 0; i < 10; i++)
    {
        cout << list[i] << ", ";
    }
}
