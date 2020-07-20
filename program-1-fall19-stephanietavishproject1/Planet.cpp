#include "Star.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

Planet::Planet(unsigned int distance){
	this->distance = distance;
	this->id = (unsigned long)this;
	int rand_type = rand() % 3;
	if (rand_type == 0) {
		this->type = 'h';
	}
	else if (rand_type == 1) {
		this->type = 'r';
	}
	else {
		this->type = 'g';
	}
   	this->pos = rand() % 360;
}

unsigned int Planet::orbit() {
	this->pos = ((this->pos)+1)%360;
	return this->pos;
}
void Planet::printPlanetInfo() {
	cout << "ID: " << this->type << this->getID() << " Distance from Star: " << this->distance << " Position: " << this->pos << endl;
}

