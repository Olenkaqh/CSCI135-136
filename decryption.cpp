/* 
Author: Olenka Quispe
Course: CSCI-136

This program asks the user for input and uses functions 
to demostrate encryption and decryption for both ciphers.

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
		actualShift = (c-'a' + rshift) % 26; // parenthesis checks shift from the a and modulus 26 returns the shift back to the range a-z
		c = actualShift + 'a'; // getting the asked value of c
	}
	if( c >= 'A' && c <='Z') //when char is uppercase
	{
		actualShift = (c-'A' + rshift) % 26; // parenthesis checks shift from the A and modulus 26 returns the shift back to the range A-Z
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
char backToOriginal( char c, int rshift)
{
	if(c >= 'a'&& c<='z')
	{
		c = c - rshift;  // goes back to original position
		if(c < 97) //checks if original pos is out of range 
		{	
			c = c+ 26;	 // if it is, it adds 26 to get to original pos 
		}
		
	}
	if(c >= 'A'&& c <= 'Z')
	{
		c = c - rshift;
		if(c < 65)
		{	
			c = c+ 26;	
		}
	}
	return c;
}
string decryptCaesar(string ciphertext, int rshift)
{
	string result= "";
	
	for( int i = 0; i < ciphertext.length(); i++) //loops through every char in the string 
	{
		result += backToOriginal( ciphertext[i], rshift);	 //adds the newchar to an empty string 
	}
	return result;
	
}
string decryptVigenere(string ciphertext, string keyword)
{
	string result = "";
	char textChar;
	int keyIndex = 0;
	int originalshift;
	for(int i = 0; i < ciphertext.length(); i++) //loops through every char in the string
	{	
		textChar = ciphertext[i];   //variable holds a char of plaintext at i index
		
		if(textChar >= 'A'&& textChar <= 'Z')  //checsk if is within the range A-Z
		{
			if (keyIndex >= keyword.length())  // checks if keyword index is within range 0-3
			{
				keyIndex = 0;					// sets index to 0 when is out of range
			}
			originalshift = keyword[keyIndex] -'a'; // finds the shift of the char
			textChar = textChar - originalshift; // finds the original pos of char
			if(textChar < 65)  // if orginal pos is out of range
			{
				textChar = textChar + 26; // it adds 26 to get to original pos
			}
			keyIndex++; //updates the index of keyword
		}
		if(textChar >= 'a'&& textChar <= 'z') 
		{
			if (keyIndex >= keyword.length()) 
			{
				keyIndex = 0;				
			}
			originalshift = keyword[keyIndex] -'a';
			textChar = textChar - originalshift;
			if(textChar < 97) 
			{
				textChar = textChar +26;
			}
			keyIndex++;
		
		}	
		result += textChar;  // adds the original char to an empty string
	}
	return result;
}
int main()
{
	string plaintext, caesar, keyword,vigenere, decryptVi;
	int shift;
	cout << "Enter plaintext	: ";  // asks user for input
	getline(cin, plaintext);
	cout << endl;
	cout << "= Caesar =" <<endl;  
	cout << "Enter shift	: "; //asks user for shift
	cin >> shift;
	caesar = encryptCaesar(plaintext, shift); 
	cout << "ciphertext : " << caesar << endl;  //prints the encrypted word
	cout << "Decrypted	: " << decryptCaesar(caesar, shift) << endl; // prints the decrypted word

	
	cout << "= Vigenere =" << endl;
	cout << "Enter keyword	: ";	//asks user for shift
	cin >> keyword;
	vigenere = encryptVigenere(plaintext, keyword); //calls the function 
	cout << "ciphertext	:"<< vigenere << endl;  //prints the encrypted word
	decryptVi = decryptVigenere(vigenere, keyword) ;
	cout << "Decrypted	: " <<decryptVi << endl;		// prints the decrypted word
}
