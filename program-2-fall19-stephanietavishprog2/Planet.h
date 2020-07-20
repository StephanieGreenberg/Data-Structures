#ifndef PLANET_H
#define PLANET_H

#include <string>

class Planet {
	private:
		std::string id;
		//unsigned int distance;
		double probability;
		//char type;
	public:
		Planet(std::string id, double probability);
		std::string getName(){return this->id;};
		double getProbability(){return this->probability;};
		double refine(double r);
		bool operator >(Planet p);
		bool operator <(Planet p);
		bool operator >=(Planet p);
		bool operator <=(Planet p);
		bool operator ==(Planet p);
		bool operator !=(Planet p);
		//string getID(){return this->id;};
		//unsigned int getDistance(){return this->distance;};
		//char getType(){return this->type;};
};

#endif
