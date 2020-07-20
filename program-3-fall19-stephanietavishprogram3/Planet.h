#ifndef PLANET_H
#define PLANET_H

#include <string>
#include <list>
#include <vector>

class Planet {
	private:
		std::string name;
		long x;
		long y;
		long z;
	public:
		std::list<Planet*> adjacencyList;
		Planet(std::string planetName, long xCoor, long yCoor, long zCoor);
		std::string getName(){return name;};
		long getXCoor(){return x;};
		long getYCoor(){return y;};
		long getZCoor(){return z;};
		double getDistance(Planet*);
		int index;
		std::list<Planet*> getAdjacent(){return adjacencyList;};
		std::vector<Planet *> opt_prev;
		bool found;
		std::vector<unsigned long> distance_vect;
};

#endif
