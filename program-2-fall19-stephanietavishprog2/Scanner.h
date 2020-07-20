#ifndef SCANNER_H
#define SCANNER_H
#include "Heap.h"
#include "Parser.h"
#include "Planet.h"
#include <vector>

class Scanner{
	private:
		Heap<Planet> planets;
	public:
		Scanner(std::vector<Planet>);
		std::vector<Planet> scan(unsigned int num_planets);
		void addPlanet(Planet p);
		Heap<Planet> getHeap();
		Planet getval(int i);
};
#endif
