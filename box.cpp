/*
Author: Olenka Quispe
Course: CSCI-136


This program asks the user to input width and height and prints 
rectangular box of the requested size using asterisks.
*/
#include <iostream>
using namespace std;

int main()
{
	int width;
	int height;
	cout << "On input: ";	//asks user for width and height of the box
	cin >> width >> height;
	cout << endl;
	for (int  row= 0; row < height; row++)	// loop iterates until row reaches height
	{
		for(int col = 0; col < width; col++)	//inner loop iterates until col reaches width
		{
			cout << "*";			//prints an asterisks for every iteration
		}
		cout<<endl;
	}
	return 0;
	
}
