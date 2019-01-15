/*
Author: Olenka Quispe
Course: CSCI-136


This program creates poems and stores them in dynamically allocated memory 

*/
#include <iostream>
using namespace std;

string * createAPoemDynamically() {
    string *p = new string;
    *p = "Roses are red, violets are blue";
    return p;
}

int main() {
    while(true) {
        string *p;
        p = createAPoemDynamically();

        // assume that the poem p is not needed at this point
		delete p;
    }
}
