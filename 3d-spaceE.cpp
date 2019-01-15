/*
Author: Olenka Quispe
Course: CSCI-136

This program calculates the distance between two points and receives the coordinates
of two points and returns the pointer of the point that is farther away fromt the origen and 
calculates the velocity and contains functions that create, delete and coordiante
objects dynamically.
*/

#include <iostream>
#include <cmath>
using namespace std;


class Coord3D //creates a class 
{
	public: // allows the class to be used outside this scope
	double x;
	double y;
	double z;	
};
//fuction computes the distance from point O to point P
double length(Coord3D *p) 
{
	double distance = sqrt(pow(p->x, 2)+pow(p->y, 2)+pow(p->z, 2)); //calculates distance
	return distance;
}

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2) //checks which function is farther away from point O
{
	double distP = length(p1); 
	double distQ = length(p2);
	if(distP > distQ)
	{
		return p1;
	}
	else 
	{
		return p2;
	}
	
}

void move(Coord3D *ppos, Coord3D *pvel, double dt) //finds the position of the point at a given time
{
	ppos->x = ppos->x + (pvel->x * dt);
	ppos->y = ppos->y + (pvel->y * dt);
	ppos->z = ppos->z + (pvel->z * dt);
	 
} 
// allocate memory and initialize
Coord3D* createCoord3D(double x, double y, double z)
{
	//Coord3D u = {10, 20, 30};
	Coord3D* p = new Coord3D;
	(*p).x = x; // p->x = x;
	(*p).y = y;
	(*p).z = z;
	return p;
}

// free memory
void deleteCoord3D(Coord3D *p)
{
	delete p;	
}
int main()
{
 	double x, y, z;
    cout << "Enter position: ";
    cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z);
    
    cout << "Enter velocity: ";
    cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z);

    move(ppos, pvel, 10.0);

    cout << "Coordinates after 10 seconds: "  << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;

    deleteCoord3D(ppos); // release memory
    deleteCoord3D(pvel);
}

