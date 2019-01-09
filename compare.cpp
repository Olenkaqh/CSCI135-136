/*
Author: Olenka Quispe
Course: CSCI-136


This program asks the user to input two dates. The program checks each day 
and prints which basin had the higher elevation on that day.
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <climits>
using namespace std;

int main()
{
	string initial_date, final_date;
	cout << "Enter starting date: ";
	cin >> initial_date;
	cout << endl <<"Enter ending date: ";
	cin >> final_date;
//reads the file 	
	ifstream fin("Current_Reservoir_Levels.tsv"); 
// tests for errors in the file 	
	if (fin.fail())  
	{
		cerr << "File cannot be opened for reading." << endl;
		exit(1);            //exit if failed to open the file
	} 	
	string junk;
	getline(fin, junk);  
	string date ;
	double eastEl, eastSt, westEl, westSt  ;
	
	bool starting_date = false;
	
	while (fin >> date >> eastSt >> eastEl >> westSt >> westEl ) // iterates from input date 1 to input date 2
	{
		fin.ignore(INT_MAX,'\n'); //ignores the rest of the columns
		if (date == initial_date ) 
		{
			starting_date = true;
		}
		if (starting_date == true)
		{
			if (eastEl > westEl)
			{
				cout << date <<	" East" <<endl; 
			}
			else if (eastEl < westEl) 
			{
				cout << date << " West"<< endl;
			}
			else if (eastEl == westEl)
			{
				cout << date << " Equal" << endl;
			}
		}
		if (date == final_date)
		{
			starting_date = false;
		}
		
	}
	
	fin.close();
	return 0;	
}
