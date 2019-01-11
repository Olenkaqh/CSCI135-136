/* 
Author: Olenka Quispe
Course: CSCI-136


This program asks the user to input a plaintext sentence, 
then asks user to enter the right shift, and it
reports the ciphertext computed using the encryption function.

*/

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

char shiftChar( char c, int rshift) //a helper function to shift one character by rshift
{
	int actualShift; 
	if(c >= 'a'&& c <= 'z') //when char is lowercase
	{
		actualShift = (c-'a' + rshift) % 26; // parenthesis checks shift from a and modulus 26 returns the shift back to the range a-z
		c = actualShift + 'a'; // getting the asked value of c
	}
	if( c >= 'A' && c <='Z') //when char is uppercase
	{
		actualShift = (c-'A' + rshift) % 26; // parenthesis checks shift from A and modulus 26 returns the shift back to the range A-Z
		c = actualShift + 'A'; // getting the asked value of c
	}
	return c; 
}
//caesar cipher encryption
string encryptCaesar(string plaintext, int rshift) // function shift each character in the string by rshift
{
	string result= "";
	
	for( int i = 0; i < plaintext.length(); i++) //loops through every char in the string 
	{
		result += shiftChar( plaintext[i], rshift);	 //adds the newchar to an empty string 
	}
	return result;
}
int main()
{
	string textToShift, newWord;
	int shift;
	cout << "Enter plain text: ";	//asks user for input
	getline(cin, textToShift); 	//extracts all the characters and stores them in the variable textToShift
	
	cout << "Enter Shift: ";	//asks user for shift
	cin >> shift; 
	
	newWord = encryptCaesar(textToShift, shift); //calls function to get the new word
	cout << "ciphertext: " << newWord;			// prints the result
	
	return 0;
}
