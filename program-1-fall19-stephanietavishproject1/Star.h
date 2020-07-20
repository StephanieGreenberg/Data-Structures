#include "Planet.h"
#include "List.h"
#include "Vector.h"
#ifndef STAR_H
#define STAR_H

class Starlist{
public:
	Starlist();
	~Starlist();
	unsigned long addPlanet();
	bool removePlanet(unsigned long);
	Planet * getPlanet(unsigned long);
	void orbit();
	void printStarInfo();
	unsigned int getCurrentNumPlanets();

private: List *list;
};


class Starvector{
public:
    Starvector();
    ~Starvector();
    unsigned long addPlanet();
    bool removePlanet(unsigned long);
    Planet * getPlanet(unsigned long);
    void orbit();
    void printStarInfo();
    unsigned int getCurrentNumPlanets();
private:
	Vector * vect;
};

#endif
