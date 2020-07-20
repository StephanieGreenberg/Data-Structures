#ifndef PARSER_H
#define PARSER_H

#include "Planet.h"
#include <vector>

class Parser {
	private:
		std::vector<Planet> planets;
	public:
		Parser(std::string filename);
		std::vector<Planet> getPlanets(){return this->planets;};
};

#endif
