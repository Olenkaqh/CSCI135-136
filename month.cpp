/*
Author: Olenka Quispe
Course: CSCI-136
Instructor: Subhadarshi Panda
Assignment: Lab1

This program asks the user to input the year and the month 
and prints the number of days in the month
*/

#include <iostream>
using namespace std;

int main()
{
	int year, month;
	cout << "Enter year: ";
	cin >> year;
	cout << "Enter month: ";
	cin >> month;
	
	if (year != 4 || year != 400)
	{
		if(month == 2)
		{
			cout << 28;
		}
		else if(month % 2 == 0)
		{
			cout << 30;
		}
		else
		{
			cout<< 31;
		}
		
	}
	else
	{
			if(month == 2)
		{
			cout << 29;
		}
		else if(month % 2 == 0)
		{
			cout << 30;
		}
		else
		{
			cout<< 31;
		}
	}
	return 0;	
}
