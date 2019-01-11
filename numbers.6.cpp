

#include <iostream>
using namespace std;

bool isDivisibleBy(int n, int d) //function compares two integers
{
	if(d == 0 ) //checks if denominator is 0
	{
		return false;
	}
	if (n % d == 0) // condition that checks if integer1 is divisible by integer2
	{
		return true;	
	}
	return false;

}
bool isPrime(int n) //function determines if input is a prime number
{

	if (n >= 2) // if input is greater than 2, it checks if number is prime
	{
		for( int i = 2; i < n ; i++ ) // checks if input is divisible by a number other than itself
		{
			if( isDivisibleBy(n,i) == true) 
			{
				return false;
			}
		}
	}
	else
	{
	return false;	
	}
	return true;
}
int nextPrime(int n)
{
   n = n + 1;
   while(isPrime(n) != true)
   {
   		n ++;
   }
	return n;
}
int countPrimes(int a, int b) //finds the primes between a and b
{
	int nums = 0;
	
	for ( int i = a  ; i <= b   ; i++)
	{
		if(isPrime(i)== true)
		{
			nums++;  // increases everytime a number is prime
		}
	}
	return nums;
}
bool isTwinPrime(int n)  //determines of is a twin prime
{
	if (isPrime(n)== true)
	{
		if (isPrime(n-2) == true || isPrime(n+2) == true ) // if n-2 or n+2 if prime, then n is a twin prime
		{
			return true;	
		}
	}
	return false;
}
int nextTwinPrime(int n) //finds the next twin prime 
{
/* another way to create this function
	for (int i = n+1;;i++)  //checks if number greater than n is a twin prime
	{
		if (isTwinPrime(i) == true)
		{
			return i;
		}
	}
*/
	int next = n+1;
	while(isTwinPrime(next)==false)
	{
		next++;
	}
	return next;
	
}
int main()
{
	int num;
	cout << "Please enter an integer:  "; // asks user for input
	cin >> num;
	cout << nextTwinPrime(num);
	return 0;
}

