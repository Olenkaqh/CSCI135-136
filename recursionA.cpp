/*
Author: Olenka Quispe
Course: CSCI-136


this programs prints all the numbers in the given range, separated by spaces
*/
#include <iostream>
using namespace std;

void printRange(int left, int right);

int main() {
    printRange(-2, 10);
}
void printRange(int left, int right)
{
	if ( left <= right ) {
		cout << left << " ";		 //prints the number
		printRange(left+1,right);	//make a recursive call, printing from (left + 1) to right
	}
	
	else {
		return;
	}
	
}

