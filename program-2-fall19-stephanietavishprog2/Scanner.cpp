
#include "Heap.h"
#include "Parser.h"
#include "Planet.h"
#include "Scanner.h"
#include <cstdlib>
#include <vector>

using namespace std;

Scanner::Scanner(vector<Planet> vector){
	this->planets = Heap<Planet>(vector);
}

void Scanner::addPlanet(Planet p){
	this->planets.addElement(p);
}

Heap<Planet> Scanner::getHeap(){
	return this->planets.getArray();
}
Planet Scanner::getval(int i){
	return this->planets.getArray().at(i);
}

vector<Planet> Scanner::scan(unsigned int n){
	vector<Planet> vect;
	if(n>planets.size()){
		n = planets.size();
	}
	for(unsigned int i = 0;i<n;i++){
		Planet p = planets.getPriority();
		if(p.getProbability()==0||p.getProbability()==100){
			vect.push_back(p);
			break;
		}
		int rand_num = rand()%2;
		if(rand_num==0){p.refine(-1.0);}
		if(rand_num==1){p.refine(1.0);}
		vect.push_back(p);
	}
	return vect;
}

