#include "Planet.h"
#include <string>

Planet::Planet(std::string id, double probability) {
	//this->distance = rand() % 3001;
	this->id = id;
	this->probability = probability;
	/*int rand_type = rand() % 3;
	if (rand_type == 0) {
		this->type = 'h';
	}
	else if (rand_type == 1) {
		this->type = 'r';
	}
	else {
		this->type = 'g';
	}*/
}

double Planet::refine(double r) {
	if (probability + r < 0) {
		probability = 0;
	}
	else if (probability + r > 100) {
		probability = 100;
	} 
	else {
		probability += r;
	}
	return probability;
}

bool Planet::operator >(Planet p) {
	return probability > p.probability;
}

bool Planet::operator <(Planet p) {
	return probability < p.probability;
}

bool Planet::operator >=(Planet p) {
	return probability >= p.probability;
}

bool Planet::operator <=(Planet p) {
	return probability <= p.probability;
}

bool Planet::operator ==(Planet p) {
	return probability == p.probability;
}

bool Planet::operator !=(Planet p) {
	return probability != p.probability;
}
