/*
Author: Olenka Quispe
Course: CSCI-136


This program declares a new calss particle which stores position a
and velocity of a particle
*/
#include <iostream>
#include <cmath>
using namespace std;

class Particle
{
	public:
	double x;
	double y;
	double z;
	double vx;
	double vy;
	double vz; 	
};
class Coord3D //creates a class 
{
	public: // allows the class to be used outside this scope
	double x;
	double y;
	double z;	
};
// dynamically allocate memory for a particle and initialize it
Particle* createParticle(double x, double y, double z, double vx, double vy, double vz)
{
	Particle* p = new Particle; //allocates memory for particle
	p->x = x;  
	p->y = y;
	p->z = z;
	p->vx = vx;
	p->vy = vy;
	p->vz = vz;
	return p;
	
}
// set its velocity to (vx, vy, vz)
void setVelocity(Particle *p, double vx, double vy, double vz)
{
	p->vx = vx;
	p->vy = vy;
	p->vz = vz;
	
}
// get its current position
Coord3D getPosition(Particle *p)
{
	Coord3D pos;  //object created to access the variables in class Coord3D
	pos.x = p->x;
	pos.y = p->y;
	pos.z = p->z;
	
	return pos;
		
}
// update particle's position after elapsed time dt
void move(Particle *p, double dt)
{
	p->x = p->x + (p->vx * dt); 
	p->y = p->y + (p->vy * dt);
	p->z = p->z + (p->vz * dt);
}
// delete all memory allocated for the particle passed by pointer
void deleteParticle(Particle *p)
{
	delete p;
}
int main()
{	
 // make new particle
    Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
    double time = 0.0;
    double dt = 0.1;
    while(time < 3.0) {
        // update its velocity
        setVelocity(p, 10.0 * time, 0.3, 0.1);

        // move the particle
        move(p, dt);
        time += dt;

        // reporting its coordinates
        cout << "Time: " << time << " \t";
        cout << "Position: "
             << getPosition(p).x << ", "
             << getPosition(p).y << ", "
             << getPosition(p).z << endl;
    }
    // remove the particle, deallocating its memory
    deleteParticle(p);
}
