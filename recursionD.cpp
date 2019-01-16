/*
Author: Olenka Quispe
Course: CSCI-136


this programs prints all the numbers in the given range, separated by spaces. it also adds numbers in the range 
and return the total sum. checks if input contains only numbers and letters.
*/
#include <iostream>
using namespace std;

void printRange(int left, int right);
int sumRange(int left, int right);
int sumArray(int *arr, int size);
bool isAlphanumeric(string s);

int main() {

	cout << isAlphanumeric("ABCD") << endl;        // true (1)
	cout << isAlphanumeric("Abcd1234xyz") << endl; // true (1)
	cout << isAlphanumeric("KLMN 8-7-6") << endl;  // false (0)
}
void printRange(int left, int right) //prints the range
{
	if ( left <= right ) {
		
		cout << left << " ";		 //prints the number
		printRange(left+1, right);	//make a recursive call, printing from left to right
	}
	
	else {  //base case
		
		return;
	}	
}

int sumRange(int left, int right) //calculates the sum of a range
{
	if(left > right) { // base case or exit case
	
		return 0;
	}
	return sumRange(left+1, right) + left; //makes a recursive call, adding from left to right
}

int sumArray(int *arr, int size) //calculates the sum of an array
{
	if(size <=0) {  // base case
		
		return 0;
	}
	return sumArray(arr, size - 1) + arr[size - 1]; //makes a recursive call,adding the numbers in the array	
}

bool isAlphanumeric(string s) //checks if string contains only numbers and letters
{
	if(s.length() < 0) // empty string 
    {
        return true;
    }
    const char *c = s.c_str();
    
    if(!isalnum(c[0])|| !isspace(c[0]))
    {
      return false; // found a non-alphanum
    }
	return isAlphanumeric(c+1); //makes a recursive call, to check rest of the string
	
}
