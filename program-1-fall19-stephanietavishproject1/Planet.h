#ifndef PLANET_H
#define PLANET_H

class Planet{
private:
	char type;
    unsigned int pos;
    unsigned int distance;
    unsigned long id;
public:
    Planet(unsigned int);
    unsigned int orbit();
    //is &this valid???
    unsigned long getID() {return id;};
    unsigned int getDistance() {return this->distance;};
    unsigned int getPos() {return this->pos;};
	char getType() {return this->type;};
    void printPlanetInfo();
};

#endif
