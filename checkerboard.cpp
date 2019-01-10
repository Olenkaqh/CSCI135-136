/*
Author: Olenka Quispe
Course: CSCI-136


This program asks the user to input width and height and prints 
rectangular checkerboard of the requested size using asterisks.
*/
#include <iostream>
using namespace std;

int main()
{
	int width;
	int height;
	cout << "Input width: "; 	// asks the user to input width
	cin >> width;	
	
	cout << "Input height: "; 	//asks the user to input height
	cin >> height;
	
	cout << endl;
	cout << "shape: "<<"\n";
	
	for (int row = 0; row < height; row++) //outer loop that iterates until it reaches the height
	{
		for (int col = 0; col < width; col++) //loop that iterates until it reaches the width
		{
			if (row % 2 == 0)  // if row is even, it will print the asterisks first
			{
				if ( col % 2 == 0) 
				{
					cout << "*";
				}
				else 
				{
					cout << " ";
				}
			}
			else   			//if row is not even, it will print the space first
			{
				if ( col % 2 == 0)
				{
					cout << " ";
				}
				else 
				{
					cout << "*";
				}
			}
		}
		cout << endl;
	}
	return 0;
}

