/* 
author: Olenka Quispe
course: CSCI-136


This program asks the user to input the length, and prints 
the top-right half of a square.
*/

#include <iostream>
using namespace std;

int main()
{
	int length;
	cout << "Input side length: "; // asks user for input
	cin >> length;
	cout<< "\n" << "Shape: " << endl;
	
	for (int row = length; row > 0; row--)	// loop iterates until lenght is 0
	{
		for (int space = 0; space < length - row; space++) 
		{
			cout<<" ";     //prints the spaces 
		}
		for (int col = 0; col < row; col++)
		{
			cout << "*";			//prints asterisks
		}
		
	
	 	cout << endl;
	}
	return 0;
}
