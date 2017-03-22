#include "Taxi.h"

Taxi::Taxi(){
	orientation = 0;
	x = y = 0;
}

void Taxi::moveTaxi(bool right, short distance){
	if(right)
		orientation = (orientation + 1) % 4;
	else
		orientation = (orientation + 3) % 4;

	switch(orientation){
		case 0:
			y += distance;
			break;
		case 1:
			x += distance;
			break;
		case 2:
			y -= distance;
			break;
		case 3:
			x -= distance;
			break;
	}
}

void Taxi::printResults(){
	short a, b;

	if (x < 0)
		a = x * -1;
	else
		a = x;
	if (y < 0)
		b = y * -1;
	else
		b = y;

	cout << "Total distance is " << a + b << " blocks.\n";
}
