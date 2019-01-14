/*
Author: Olenka Quispe 
Course: CSCI-136


This program reads input from cin and prints out each input line
with leading spaces removed

*/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string removeLeadingSpaces(string line) //function removes leading spaces
{
	string newLine = "";
	int countSpace = 0;
	int i = 0;
	while(isspace(line[i])) //adds all the spaces before the first char
		{
			i++;
		}
	
	for(int j = i ; j <line.length(); j++) 
	{
		newLine += line[j]; // adds all the char after the leading spaces
	}
	return newLine;
}
int main()
{
	string textLine;
	while(getline(cin,textLine)) //gets each line from file 
	{
		cout << removeLeadingSpaces(textLine) <<endl; // prints line without leading spaces
	}
	return 0;
}
