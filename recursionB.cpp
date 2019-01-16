/*
Author: Olenka Quispe
Course: CSCI-136


this programs prints all the numbers in the given range, separated by spaces. it also adds numbers in the range 
and return the total sum.
*/
#include <iostream>
using namespace std;

void printRange(int left, int right);
int sumRange(int left, int right);

int main() {
	
    int x = sumRange(1, 3);
    cout << "This is " << x << endl;   // 6
    
    int y = sumRange(-2, 10);
    cout << "That is " << y << endl;   //52
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
	return sumRange(left+1, right) + left; //makes a recursive calll, adding from left to right
}

