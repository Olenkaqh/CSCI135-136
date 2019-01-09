

#include <iostream>
using namespace std;

int main()
{
//asks the user for input
	cout<<"Enter year: "<< endl;
//assigns a variable for user input
	int year;
	cin>> year;
//determines if input is a common or a leap year	
	if( year % 4 != 0)
	{
		cout<<"It is a common year"<<endl;
		
	}
	else if(year% 100 != 0)
	{
		cout<<"It is a leap year"<< endl;
	}
	else if(year%400 != 0)
	{
		cout<<"It is a common year"<<endl;
	}
	else
	{
		cout<<"It is a leap year"<<endl;
	}
	return 0;
}
