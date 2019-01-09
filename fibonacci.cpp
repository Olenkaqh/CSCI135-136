/*
Author: Olenka Quispe
Course: CSCI-136


This program uses an array of integers to compute and print 
all Fibonacci numbers from F(0) to F(59).
*/

#include <iostream>
using namespace std;

int main()
{
// creates array
	int fib[60];
	fib[0] = 0;
	fib[1] = 1;
//prints the first two numbers of the sequence
	cout << fib[0] << endl;
	cout << fib[1] << endl;
//calculates the value of the next 57 number
	for (int i =2; i < 60; i++ )
	{
		fib[i] = fib[i - 1] + fib[i - 2];
		cout << fib[i] << endl;
	}
	return 0;	
}
