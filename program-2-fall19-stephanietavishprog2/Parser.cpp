#include "Parser.h"
#include <iostream>
#include <fstream>

using namespace std;

Parser::Parser(string filename) {
	ifstream planetFile;
	planetFile.open(filename);
	string id;
	double probability;
	if (planetFile) {
		while (planetFile>>id>>probability) {
			Planet p(id, probability);
			this->planets.push_back(p);
		}
		planetFile.close();
	}
}