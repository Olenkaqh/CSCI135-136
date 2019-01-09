/*
Author: Olenka Quispe
Course: CSCI-136


This program asks the user to input a string representing the date (in MM/DD/YYYY format),
 and prints out the East basin storage on that day.
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <climits>
using namespace std;

int main(){
	string dt;	
//Asks the user for input
	cout << "Enter date: ";  
	cin >> dt;
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
	string date;
	double eastSt, eastE1, westSt, westE1 ;
	
	while (fin >> date >> eastSt >> eastE1 >> westSt >> westE1 )
	{
		if(date == dt)
		{
// prints the east basin storage on the day entered by user
		cout << "East basin storage: " << eastSt <</* " billion gallons" << */endl;
  		}
	}
	cout << "Read file\n";
	fin.close();  //close stream
	return 0;	
}
