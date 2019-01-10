/*
Author: Olenka Quispe
Course: CSCI-136


This program asks the user to input the shape size, and 
prints a diagonal cross of that dimension
*/
#include <iostream>
using namespace std;

int main()
{
	int size;
	int pos1;
	int pos2;
	cout << "Input size: "; 	// asks the user for input
	cin >> size;
	cout << endl;
	cout << "shape: "<<"\n";
	
	for (int row = 0; row < size; row++)
	{
		pos1 = row;
		pos2 = size - row - 1;
    	for (int col = 0; col < size; col++) 
		{
				if (col == pos1 || col == pos2){
					cout << "*";
				}
				else{
					cout << " ";
				}
    	}
    	cout << endl;
    }

	
	return 0;
}
