/*
Author: Olenka Quispe
Course: CSCI-136


This program checks if two movies overlap

*/
#include <iostream>
using namespace std;

class Time {
public:
	int h; //hours
	int m; //minutes
};

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Movie { 
public: 
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

int minutesSinceMidnight(Time time)  //gets the time in minutes
{
	int total;
	int hMinutes = 60 * time.h;	//converts the hours into minutes
	total = hMinutes + time.m; //adds the converted minutes and the minutes 
	return total;
}
int minutesUntil(Time earlier, Time later) //finds the time between the two inputs
{
	int result;
	int t1 = minutesSinceMidnight(earlier);
	int t2 = minutesSinceMidnight(later);
	result = t2 - t1; 
	return result;	
}
Time addMinutes(Time time0, int min) //adds the input to the original time
{
	time0.m = time0.m + min;
	while(time0.m >= 60)
	{
		time0.h = time0.h + 1; 	
		time0.m = time0.m - 60;
	}
	return time0;
}

void printTimeSlot(TimeSlot ts)//prints the timeshow for a movies
{
	string g;
	int m_duration = ts.movie.duration; //duration of movie
    Time m_endingTime = ts.startTime;  //starting time
    Time ending = addMinutes(m_endingTime ,m_duration ); //ending time 
	switch(ts.movie.genre)
	{
		case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
  	cout << ts.movie.title << " " << g << " (" << ts.movie.duration << " min)"<<" [starts at "<< ts.startTime.h <<" : " << ts.startTime.m << ", ends by " << ending.h << " : "<< ending.m << "]" << endl;
}
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)  //determines what time the next movie starts
{
	TimeSlot next_ts;
	Time nextTime = addMinutes(ts.startTime,ts.movie.duration); 

	next_ts.startTime.h = nextTime.h;  //saves the new value in the new timeslot
	next_ts.startTime.m = nextTime.m;
	next_ts.movie = nextMovie;
	return next_ts;
}
bool timeOverlap(TimeSlot ts1, TimeSlot ts2) // checks if timeslots overlap
{
	Time final_ts1;
	Time final_ts2;
	int starting_ts1, starting_ts2;
	int ending_ts1, ending_ts2;
	
	final_ts1 = addMinutes(ts1.startTime, ts1.movie.duration); //gets ending time of movie
	final_ts2 = addMinutes(ts2.startTime, ts2.movie.duration);
	
	starting_ts1 = minutesSinceMidnight(ts1.startTime); //converts the time to minutes
	ending_ts1 = minutesSinceMidnight(final_ts1);
	starting_ts2 = minutesSinceMidnight(ts2.startTime);
	ending_ts2 = minutesSinceMidnight(final_ts2);
	
	if(starting_ts1>= starting_ts2 && starting_ts1 < ending_ts2 ) //compares the starting time of the sfirst movie 
	{
		return true;
	}
	else if (ending_ts1 >= starting_ts2 && ending_ts1 <= ending_ts2 ) //compares the ending time of the first movie 
	{
		return true;
	}
	else if(starting_ts2 >= starting_ts1 && starting_ts2 < ending_ts1 ) //compares the starting time of the second movie 
	{
		return true;
	}
	else if (ending_ts2 >= starting_ts1 && ending_ts2 <= ending_ts1 ) //compares the ending time of the second movie 
	{
		return true;
	}	
	else {
		return false;
	}

}
int main()
{
	Movie movie1 = {"Back to the Future", COMEDY, 180};
	Movie movie2 = {"Black Panther", ACTION, 63 };
	TimeSlot morning = {movie1, {10, 30}}; 
	TimeSlot daytime = {movie2, {8, 30}}; 
	if(timeOverlap(morning, daytime)) 
	{
		cout<< "Movies overlap"<<endl;
	}
	else if(timeOverlap(morning, daytime) == false )
	{
		cout << "No overlapping occurs"<< endl;
	}
}
