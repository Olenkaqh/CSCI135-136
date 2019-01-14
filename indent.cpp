/*
Author: Olenka Quispe 
Course: CSCI-136

This program reads input line by line, keeps track of the number of
open and close curly brackets inorder to indent each line properly

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
int countChar(string line, char c) //  counts the num of times char c is found in string 
{
	int countC = 0;
	
	for(int i = 0; i < line.length();i++)
	{
		if(line[i] == c)
		{
			countC++;
		}
	}
	return countC;
}
int main()
{
	string textLine;	
	int indentNum = 0;
	int left = 0;
	int right = 0;
	int indent = 0;
	
	while(getline(cin,textLine)) //gets each line from file 
	{	
		//find how much to indent
		if (removeLeadingSpaces(textLine)[0]=='}')  //checks if first char is } 
		{ 
			indent = indentNum - 1;			
		}
		else{
			indent = indentNum;
		}	
		
		//print indented line 
		for (int j=0; j<indent; j++){ //adds indent times the tab
			cout << "\t";
		}
		cout << removeLeadingSpaces(textLine)<<endl;  // prints the line properly indented
		
		left += countChar(textLine, '{'); //gets the num of { in the line from previous line
		right += countChar(textLine, '}'); //gets the num of } int the line from previous line
		indentNum = left - right;		//finds the num of total indents by substracting left and right			
	}

	return 0;
}
