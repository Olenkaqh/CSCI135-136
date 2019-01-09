/*
Author: Olenka Quispe
Course: CSCI-136


This program continuously asks the user to input an integer
until the user enters an integer in the range of 0 to 100.
*/
#include <iostream>
using  namespace std;

int main(){
	cout << "Please enter an integer: "<<endl;
	int num;
	cin >> num;
	while (num <0 || num >100)
	{
		cout << "Please re-enter: "<< endl;
		cin >> num;	
	}
	cout << "Number squared is "<< num*num <<endl;
	
	return 0;
}
	
