/*
Author: Olenka Quispe
Course: CSCI-136

This program implements a new class called network. This class allows us 
to add new users and store their profiles.
*/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Profile {
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn);
    // Default Profile constructor (username="", displayname="")
    Profile();
    // Return username
    string getUsername();
    // Return name in the format: "displayname (@username)"
    string getFullName();
    // Change display name
    void setDisplayName(string dspn);
};
class Network {
private:
  static const int MAX_USERS = 20; // max number of user profiles
  int numUsers;                    // number of registered users
  Profile profiles[MAX_USERS];     // user profiles array:
   // mapping integer ID -> Profile

  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
  int findID (string usrn);
public:
  // Constructor, makes an empty network (numUsers = 0)
  Network();
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool addUser(string usrn, string dspn);
};

int main() {
  Network nw;
  cout << nw.addUser("mario", "Mario") << endl;     // true (1)
  cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

  cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
  cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
  cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

  for(int i = 2; i < 20; i++)
    cout << nw.addUser("mario" + to_string(i), 
            "Mario" + to_string(i)) << endl;   // true (1)

  cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
}

Profile::Profile(string usrn, string dspn) {
	username = usrn;
	displayname = dspn;	
}
Profile::Profile() { //contructor
	username ="";
	displayname = "";
}
string Profile::getUsername() {
	return username;
}
string Profile::getFullName() {
	return displayname+" (@"+username+")";
}
void Profile::setDisplayName(string dspn) {
	displayname = dspn;	
}
Network::Network() : numUsers(0) {} //initializer list

int Network::findID(string usrn) {
	
	for(int i = 0; i < MAX_USERS; i++) {
	
		if(profiles[i].getUsername() == usrn) {
			return i;
		}
	}
	return -1;
}
bool Network::addUser(string usrn, string dspn)
{
	int i = 0;
	bool acceptable;
	while(i < usrn.length()) {
		if(isalnum(usrn[i])) {
			acceptable = true;
			i++;
		}
		else {
			return false;
		}		
	}
	if(acceptable) {
		if(findID (usrn) == -1 && numUsers < MAX_USERS ) {
			Profile newUser(usrn, dspn);
			profiles[numUsers] = newUser;
			numUsers ++;
			return true;
		}
		else {
			return false;
		}
	}
}
 
