#ifndef GALAXY_H
#define GALAXY_H
#include <vector>
#include "Planet.h"

class Galaxy {
	private:
		std::vector<Planet*> planets;
	public:
		Galaxy(std::string filename);
		~Galaxy();
		unsigned int size(){return this->planets.size();};
		void printPlanets();
		Planet* findByName(std::string planetName);
		std::vector<Planet *> shortestPath(Planet * start, Planet * dest);
		int smallestDist(Planet * p );
		double pathDistance(Planet * start, Planet * dest);
};

#endif
