/*
Author: Olenka Quispe
Course: CSCI-136


this programs prints all the numbers in the given range, separated by spaces. it also adds numbers in the range 
, return the total sum and checks if input is only words and digits.
*/
#include <iostream>
#include <cctype>
using namespace std;

void printRange(int left, int right);
int sumRange(int left, int right);
int sumArray(int *arr, int size);
bool isAlphanumeric(string s);
bool nestedParens(string s);

int main() {

  cout << nestedParens("((()))") << endl;      // true (1)
  cout << nestedParens("()") << endl;          // true (1)
  cout << nestedParens("") << endl;            // true (1)

  cout << nestedParens("(((") << endl;         // false (0)
  cout << nestedParens("(()") << endl;         // false (0)
  cout << nestedParens(")(") << endl;          // false (0)
  cout << nestedParens("a(b)c") << endl; 
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
bool isAlphanumeric(string s)
{
	if(s.length() == 0)
    {
        return true;
    }
    else
    {
        char ch = s[0];
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        {
            return isAlphanumeric(s.substr(1));
        }
        else
        {
            return false;
        }
    }
}
bool nestedParens(string s)
{
	if(s.length() == 0)
	{
	  return true;
	}
    else if(s.length() < 2)
    {
        return false;
    }
    else
    {
        if(s[0] == '(' && s[s.size()-1] == ')')
        {
            return nestedParens(s.substr(1, s.size()-2));
        }
        else
        {
        	return false;
        }
    }
}
