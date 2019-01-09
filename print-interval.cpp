/*
Author: Olenka Quispe
Course: CSCI-136


This program asks the user to input two integers and prints out
all integers in the range separated by spaces.
*/
 #include <iostream>
 using namespace std;
 
 int main(){
//aks the user for integer 1
 	cout<<"Please enter L: "<< endl ;
 	int num_l;
 	cin>> num_l;
//asks the user for input 2	
 	cout <<"Please enter U: "<<endl;
 	int num_u;
 	cin>> num_u;
//starts with a counter variable and keeps iterating until i is less than num_u
 	for (int i = num_l ; i < num_u; i++)
	 {
//prints all the values of i starting from num_l 
	 	cout<< i << " ";
	 } 		
 	return 0;
 	
 }
 
