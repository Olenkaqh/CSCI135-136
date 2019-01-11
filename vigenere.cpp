/* 
Author: Olenka Quispe
Course: CSCI-136


This program asks the user for input and shift. Using a function,
the program encrypts the input.

*/
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

string encryptVigenere(string plaintext, string keyword)  //function shift char by position of char in keyword
{
	string result = "";
	char textChar;
	int keyIndex = 0;
	int charShift;
	for(int i = 0; i < plaintext.length(); i++)
	{	
		textChar = plaintext[i];   //variable holds a char of plaintext at i index
		
		if(textChar >= 'A'&& textChar <= 'Z') //checks if char is between A and Z
		{
			if (keyIndex >= keyword.length()) //checks if index is greater or equal to the length of the keyword
			{
				keyIndex = 0;					// if index is greater, index is set to 0
			}
			charShift = keyword[keyIndex] -'a'; //calculates the shift of plaintext char
			textChar = 'A'+ (textChar -'A'+ charShift) % 26;	 //shift the char by keyword char
			keyIndex++;
		}
		if(textChar >= 'a'&& textChar <= 'z') //checks if char is between a and z
		{
			if (keyIndex >= keyword.length()) 
			{
				keyIndex = 0;				
			}
			charShift = keyword[keyIndex] -'a';
			textChar = 'a'+ (textChar -'a'+ charShift) % 26;
			keyIndex++;
		
		}	
		result += textChar; //adds new chars to an empty string
	}
	return result;	
}
int main()
{
	string textToShift, shiftWord;
	cout << "Enter plaintext: "; //asks user for input
	getline(cin, textToShift);	//stores input in the variable textToShift
	
	cout << "Enter Keyword: ";
	cin >> shiftWord;
	string encryptedWord = encryptVigenere(textToShift, shiftWord);  //calls function
	cout << "Ciphertext: " << encryptedWord;
	
}
