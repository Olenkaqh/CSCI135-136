/*
Author: Olenka Quispe
Course: CSCI-136


This program is an improved versionof the previus program. The class
Network has a new member function that allows keep the frienship relation 
between the users.
*/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

struct Post {
    string username, message;
};

class Profile {
private:
	
    string username;
    string displayname;

public:
// Profile constructor for a user (initializing 
// private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn) {
        username = usrn;
        displayname = dspn;
    }
 // Default Profile constructor (username="", displayname="")
    Profile() {
        username = "";
        displayname = "";
    }
  // Return username
    string getUsername() {
        return username;
    }
  // Return name in the format: "displayname (@username)"
    string getFullName() {
        return displayname + " (@" + username + ")";
    }
 // Change display name
    void setDisplayName(string dspn) {
        displayname = dspn;
    }
};

class Network {
private:
    static const int MAX_USERS = 20; // max number of user profiles
    static const int MAX_POSTS = 100;
    int numUsers = 0;  // number of registered users
    Post posts[MAX_POSTS];
    int numPosts = 0;
    Profile profiles[MAX_USERS]; // user profiles array:
    bool following[MAX_USERS][MAX_USERS]; // friendship matrix:
	// following[id1][id2] == true when id1 is following id2
	
 // mapping integer ID -> Profile

  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
    int findID(string usrn) {
        for (int i = 0; i < numUsers; i++) {
            if (profiles[i].getUsername() == usrn) {
                return i;
            }
        }

        return -1;
    }

public:
    Network() {
                for (int i=0; i< MAX_USERS; i++) {
                        for (int j=0; j< MAX_USERS; j++) {
                                following[i][j] = false;
                    }
                }
                numPosts = 0;
        }

        bool addUser(string usrn, string dspn) {
            Profile newUser(usrn, dspn);

            if (numUsers < MAX_USERS) {
                profiles[numUsers++] = newUser;
                return true;
            }

            return false;
        }

        bool follow(string usrn1, string usrn2) {
            int usrnID1 = findID(usrn1);
            int usrnID2 = findID(usrn2);

            if (usrnID1 != -1 && usrnID2 != -1) {
                following[usrnID1][usrnID2] = true;
                return true;
            }

            return false;
        }

        void printDot() {
            cout << "digraph {" << "\n";

                for (int i=0; i<numUsers; i++) {
                        cout << " \"@" << profiles[i].getUsername() << "\"\n";
                }

                for (int i=0; i<numUsers; i++) {
                        for (int j=0; j<numUsers; j++) {
                                if(following[i][j]) {
                                    cout << " \"@" << profiles[i].getUsername() << "\" -> \"@"
                                    << profiles[j].getUsername() << "\"\n";
                                }
                        }
                }

                cout << "}" << "\n";
        }
};

int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}
