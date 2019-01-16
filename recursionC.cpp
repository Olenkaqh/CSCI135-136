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
int sumArray(int *arr, int size);

int main() {

    int size = 10;
    int *arr = new int[size]; // allocate array dynamically
    arr[0] = 12;
    arr[1] = 17;
    arr[2] = -5;
    arr[3] = 3;
    arr[4] = 7;
    arr[5] = -15;
    arr[6] = 27;
    arr[7] = 5;
    arr[8] = 13;
    arr[9] = -21;

    int sum1 = sumArray(arr, size); // Add all elements
    cout << "Sum is " << sum1 << endl;  // Sum is 43
    
    int sum2 = sumArray(arr, 5); // Add up first five elements
    cout << "Sum is " << sum2 << endl;  // Sum is 34

    delete[] arr;         // deallocate it
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
