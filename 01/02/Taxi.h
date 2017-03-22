using namespace std;
#include <iostream>

#ifndef TAXI_H
#define TAXI_H
class Taxi{
	private:
		short orientation;
		short x, y;
	public:
		Taxi();
		void moveTaxi(bool right, short distance);
		void printResults();
};
#endif
