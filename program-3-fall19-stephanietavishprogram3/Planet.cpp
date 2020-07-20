#include "Planet.h"
#include <string>
#include <math.h>

using namespace std;

Planet::Planet(string planetName, long xCoor, long yCoor, long zCoor) {
	this->name = planetName;
	this->x = xCoor;
	this->y = yCoor;
	this->z = zCoor;
}

double Planet::getDistance(Planet* planet) {
	double distance = 0.0;
	distance = sqrt((pow((this->x - planet->getXCoor()),2)) + (pow((this->y - planet->getYCoor()),2)) + (pow((this->z - planet->getZCoor()),2)));
	return distance;
}
