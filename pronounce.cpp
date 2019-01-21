/*
Author: Olenka Quispe
Course: CSCI-135

Assignment: Project 2 

This program will ask user to enter some input and the program will print 
the pronunciation of the input, words with same pronunciation, words with similar
pronunciation, words with an extra phoneme and words with one less phoneme.

*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
using namespace std;

void splitOnSpace(string s, string & before, string & after);
string allcaps(string input);
string getpronunciation(string word);
string getidentical(string word );
int countPhon( string w);
string getPhoneme( string x, int position);
bool checkifValid(string w);
string replacePhoneme(string pronunciation);
string addPhoneme( string pronunciation);
string removePhoneme( string pronunciation);

int main()
{
	ifstream file("cmudict.0.7a.txt"); // opens file	
	if(file.fail())  
	{
		cerr <<"File cannot be opened for reading." << endl;
		exit(1);	//exit if file file fails to open
	}
	
	string input, word;  	
	cout << "Enter word: ";
	cin >> input;
	word = allcaps(input);
	
	string found_pronunciation = getpronunciation(word);
	string found_identical = getidentical(word) ;
	string found_replace = replacePhoneme(found_pronunciation);
	string found_addPhon = addPhoneme(found_pronunciation);
	string found_removePhon = removePhoneme(found_pronunciation);
	
	cout << "Pronunciation   : " << found_pronunciation << endl;	
	cout << "Identical       : " << found_identical << endl;
	cout << "Replace phoneme : " << found_replace << endl;
	cout << "Add Phoneme     : " << found_addPhon << endl;
	cout << "Remove Phoneme  : " << found_removePhon << endl;

	return 0;
}
void splitOnSpace(string s, string & before, string & after) //separates str in file by words
{
    // reset strings
    before = ""; 
    after = "";
    // accumulate before space
    int i = 0;
    while (i < s.size() && not isspace(s[i]))  //loop iterates until string character is a space
	{ 
		before += s[i];		 //adds all the character that are not a space
		i++;
	}
      // skip the space
    i++;
    // accumulate after space
    while (i < s.size()) 
	{ 
		after += s[i]; i++; 
	}
 } 
string allcaps(string input)
{
	for(int i = 0; i < input.length(); i++) // converts the word to all caps
	{
		input[i] = toupper(input[i]);
	}
	return input;
}
string getpronunciation(string word) //function gets pronunciation
{
	string str, current_word, current_pronunciation;
	ifstream file("cmudict.0.7a.txt"); 	// opens file
		
	while(getline(file,str)) 	//reads file line by line
	{
		splitOnSpace(str, current_word, current_pronunciation); //splits the line into separate words	
		if(current_word == word) 	//checks if the first word splitted from the string is equal to the input
		{
			return current_pronunciation;	//returns the rest of the string
		}
	}
	file.close(); 	//close file 
	
	cout << "not found"; 	// prints not found when the function doesn't find the word
	exit(1);	//exits the program
}
string getidentical(string word ) // function gets words that have the same pronunciation as the input
{
	string str, current_word, current_pronunciation;
	string actual_pronunciation = getpronunciation(word); 	//gets the pronunciation of the word
	string identical_words =  "" ; 

	ifstream file("cmudict.0.7a.txt"); 	// opens file
	
	while(getline(file,str))	 //reads file line by line
	{
		splitOnSpace(str, current_word, current_pronunciation); 	//splits the line and separates them into word and pronunciation
		if(current_pronunciation == actual_pronunciation && current_word != word)	 // checks if the word splitted from the string is equal to the input and has the same pronunciation
		{
			identical_words = identical_words + current_word + " "  ; 	// saves all the identical words in one string 
		}		
	}
	return identical_words;
	
	file.close();
}
int countPhon( string w)  // counts the number of phonemes in w
{
	int count = 1;
	for(int i = 0; i < w.length(); i++) //loops through every char
	{
		if( isspace(w[i]))  //checks if char is a space 
		{
			count++;
		}
	}
	return count;
}
string getPhoneme( string x, int position) //gets the phoneme from the word at a particular position
{
	string phon1, remainderWord;
	string wantedPhon;
	int size = countPhon(x); //counts the number of phonemes
	for(int i = 0; i < size; i++ ) // loops throuch the word
	{
		splitOnSpace(x,phon1, remainderWord); // splits the word 
		if( i == position) // checks if i is the req position
		{
			wantedPhon = phon1; 
		}
		else if( i != position)
		{
			x = remainderWord;
		}		
	}
	return wantedPhon;
}
bool checkifValid(string w) //function checks if result is valid
{
	bool valid = true;	
	for(int i = 0; i < w.length(); i++) 
	{
		if(w[i] == '(')
		{
			valid = false;
		}
	}
	return valid;
}

string replacePhoneme(string pronunciation) //function finds word with similar pronunciation to the input
{
	ifstream file("cmudict.0.7a.txt");
	string str, current_word, current_pronunciation;
	string result = "";
	int actualPhon_count = countPhon(pronunciation);  //counts number of phonemes in the input's pronunciation
	int currentPhon_count;
	
	
	while(getline(file, str)) //goes though each line in the file 
	{
		splitOnSpace(str, current_word, current_pronunciation); //splits line into word and pronunciation
		currentPhon_count = countPhon(current_pronunciation); //counts the num of phonemes in the pronunciation
		int incorrect = 0;
		
		if(currentPhon_count == actualPhon_count)  //checks if line pronunciation has the same num of phonemes as the input
		{
			for(int i = 0; i < actualPhon_count ; i++)  //loops through each phoneme 
			{
				if(getPhoneme( current_pronunciation, i)!= getPhoneme( pronunciation, i)) //compares each phoneme to the input's phoneme 
				{
					incorrect++;
				}
			}
		}
		if (incorrect == 1 && checkifValid(current_word) ) //checks if word is valid and there is only one phon diff in the pronunciation
		{
			result = result + current_word + " "; //adds the word to the result
		}	
	}	
	return result;		
}
string addPhoneme( string pronunciation) // finds words with an extra phoneme in the pronunciation
{
	ifstream file("cmudict.0.7a.txt");
	string str, current_word, current_pronunciation;
	string result = "";
	int actualPhon_count = countPhon(pronunciation);  //counts number of phonemes in the input's pronunciation
	int currentPhon_count;
	
	while(getline(file, str)) //goes though each line in the file 
	{
		splitOnSpace(str, current_word, current_pronunciation); //splits line into word and pronunciation
		currentPhon_count = countPhon(current_pronunciation); //counts the num of phonemes in the pronunciation
		int count = 0;
		
		if(currentPhon_count == actualPhon_count + 1)  //checks if current pronunciation has an extra phoneme
		{
			for(int i = 0; i < actualPhon_count; i++)  //loops through each phoneme 
			{
				int endPhon = i + 1;
				if(getPhoneme( current_pronunciation, i) == getPhoneme( pronunciation, i)) //compares each phoneme to the input's phoneme 
				{
					count++; //variable counts how many phonemes are the same 
				}
				if(getPhoneme(current_pronunciation, endPhon) == getPhoneme(pronunciation, i)) //compares each phoneme to the final phoneme of the current word
				{
					count++; //variable counts how many phonemes are the same 
				}
			}
			if (count == actualPhon_count && checkifValid(current_word) ) //checks if word is valid
			{
				result = result + current_word + " "; //adds the word to the result		
			}	
		}
	
	}	
	return result;	
}
string removePhoneme( string pronunciation)
{
	ifstream file("cmudict.0.7a.txt");
	string str, current_word, current_pronunciation;
	string result = "";
	int actualPhon_count = countPhon(pronunciation);  //counts number of phonemes in the input's pronunciation
	int currentPhon_count;
	
	while(getline(file, str)) //goes though each line in the file 
	{
		splitOnSpace(str, current_word, current_pronunciation); //splits line into word and pronunciation
		currentPhon_count = countPhon(current_pronunciation); //counts the num of phonemes in the pronunciation
		int count = 0;
		
		if(currentPhon_count == actualPhon_count - 1) 
		{
			for(int i = 0; i < currentPhon_count ; i++)  //loops through each phoneme 
			{
				int endPhon = i + 1;
				if(getPhoneme( current_pronunciation, i) == getPhoneme( pronunciation, i)) //compares each phoneme to the input's phoneme 
				{
					count++; //variable counts how many phonemes are the same 
				}
				if(getPhoneme(current_pronunciation, i) == getPhoneme(pronunciation, endPhon)) //compares each phoneme to the final phoneme of the actual pronunciation
				{
					count++; //variable counts how many phonemes are the same 
				}
			}
			if (count == currentPhon_count  && checkifValid(current_word) ) //checks if word is valid
			{
				result = result + current_word + " "; //adds the word to the result		
			}	
		}
	
	}	
	return result;	
}
