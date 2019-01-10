/* 
author: Olenka Quispe
course: CSCI-136


This program asks the user to input the length, and prints 
the bottpm-left half of a square.
*/

#include <iostream>
using namespace std;

int main()
{
	int length;
	cout << "Input side length: "; // asks user for input
	cin >> length;
	cout<< "\n" << "Shape: " << endl;
	
	for (int row = 0; row <= length; row++)	// loop iterates until row is equal to length
	{
		for (int col = 0; col < row; col++)
		{
			cout << "*"; // prints the asterisk
		}
	 	cout << "\n" << "\n";
	}
	return 0;
}
