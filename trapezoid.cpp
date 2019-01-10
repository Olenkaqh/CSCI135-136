/*
Author: Olenka Quispe
Course: CSCI-136


This program asks the user to input the height and width, and prints 
an upside-down trapezoid of given input.
*/
#include <iostream>
using namespace std;

int main()
{
	int width;
	int height;
	int pos1;
	int pos2;
	int spaces = 0;
	
	cout << "Input width: "; 	// asks the user for input
	cin >> width;
	cout << endl << "Input height: "; 	// asks the user for input
	cin >> height;
	
	cout << endl;
	cout << "shape: "<<"\n";
	if (height * 2 - 1 > width)    // checks if shape is possible
	{
		cout << "Impossible shape !" << endl; 
	}
	else 
	{
		for (int row = 0; row < height; row++)
		{
			pos1 = row;
			pos2 = width - row -1;
			
			for (int col = 0; col < width; col++) 
			{
				if( col >= pos1 && col <= pos2 ) // if pos if within the req position it will print the asterisks
				{
					cout << "*";
				}	
				else // if pos is not the required position, it will print a space
				{
					cout << " ";
				}
			}
			cout << endl;
		}
    	
    }
	return 0;
}
