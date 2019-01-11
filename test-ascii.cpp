/* 
Author: Olenka Quispe
Course: CSCI-136


This program reports all characters from the input line together
with their ASCII codes.

*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string characters;  
	cout << "Input: "; //asks user for input
	getline (cin, characters);  //gets all the input in the variable character
	
	for( int i = 0; i < characters.length(); i++) // loops through all the characters of the variable 
	{
		cout << characters[i] <<" " << (int)characters[i] << endl; // prints the ACSII of each
	}
	return 0;
}
