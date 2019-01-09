/*
Author: Olenka Quispe
Course: CSCI-136

This program asks the user to input two dates. The program checks each day 
and prints the dates and the values of the west elevation in reverse order.
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
	cout << "Enter earlier date: ";
	cin >> initial_date;
	cout << endl <<"Enter later date: ";
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
	

	string actual_date[400];	
	double west_actual_capacity[400];
	
	int i = 0;
	

	while (fin >> date >> eastSt >> eastEl >> westSt >> westEl ) // iterates from input date 1 to input date 2
	{
		fin.ignore(INT_MAX,'\n'); //ignores the rest of the columns
		
		if (date == initial_date )  //checks if date is the same as the input 
		{
			starting_date = true;
		}
		if (starting_date == true) 
		{
			actual_date[i] = date; //saves the date in the array
			west_actual_capacity[i] = westEl; // saves the elevation in the other array
			i++; //increments index by one for each iteration
		
		}
		if (date == final_date)  // stops iteration when date reaches the final date
		{
			starting_date = false;
		}
	}
	for( int j = i ; j >= 0; j--)  // prints the values in reverse
	{
		
		cout << actual_date[j] << " " << west_actual_capacity[j] << endl;
		
	}
		
	fin.close(); // closes file
	return 0;	
}
