#include "Galaxy.h"
#include "Planet.h"
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <float.h>

using namespace std;

Galaxy::Galaxy(string filename) {
	ifstream planetFile;
	//open file with planet info
	planetFile.open(filename);
	string name;
	long x;
	long y;
	long z;
	//read in all planet info and add to planets vector
	if (planetFile) {
		while (planetFile>>name>>x>>y>>z) {
			Planet* planet = new Planet(name, x, y, z);
			this->planets.push_back(planet);
		}
		planetFile.close();
	}


	for (unsigned int i = 0; i < planets.size(); i++) {
		vector<Planet*> planets_temp;
		for (unsigned int j = 0; j < planets.size(); j++) {
			if (i!=j) {
				planets_temp.push_back(planets[j]);
			}
		}
		
		sort(planets_temp.begin(), planets_temp.end(), [&](Planet* c, Planet* d) {return planets[i]->getDistance(c) < planets[i]->getDistance(d);});
		for (int k = 0; k < 4; k++) {
			//Planet *p = planets_temp.getPriority();
			planets[i]->adjacencyList.push_back(planets_temp[k]);
			//planets[i]->adjacencyList.push_back(p);
			//cout << planets_temp[k]->getName() << endl;
			
		}
	}
}

Galaxy::~Galaxy() {
  for (unsigned int i = 0; i < this->planets.size(); i++) {
    delete this->planets[i];
  }
}

void Galaxy::printPlanets() {
	for (auto p : planets) {
		cout<< "Name: " << p->getName() << endl;
		cout<< "X-Coordinate: " << p->getXCoor() << endl;
		cout<< "Y-Coordinate: " << p->getYCoor() << endl;
		cout<< "Z-Coordinate: " << p->getZCoor() << endl;
    cout<< "Adjacent Planets: ";

    for (auto q : p->adjacencyList) {
      cout << q->getName() << "    ";
    }
    cout << "\n\n" << endl;
	}
}

Planet* Galaxy::findByName(std::string planetName){
	for(auto p : planets){
	    if(p->getName() == planetName) {
	    	return p;
	    }
	}
	return nullptr;
}
//done
vector<Planet *> Galaxy::shortestPath(Planet * start, Planet * dest){
	// Init all values to -1 if not start 
	vector<Planet*> retval;
  	for(unsigned int i=0;i<this->planets.size();i++){
		this->planets[i]->index=i;
    		this->planets[i]->found=false;

    		start->opt_prev.push_back(NULL);
    		if (this->planets[i]==start){start->distance_vect.push_back(0);}
    		else {start->distance_vect.push_back(-1);}
	}
	//double ret;
	//Planet * ret_2;
	//double ret_2;
	//from here on out its the dijkstra algorithm
  	for (unsigned int i = 0; i < this->planets.size(); i++){
		//iterate first to find the planet with the least distance to the start
    		Planet* temp = this->planets[smallestDist(start)];
    		for (unsigned int j=0;j<this->planets.size(); j++){
      			for(Planet* planet:temp->adjacencyList){
		// retval = planet  try this, for some reason this gets rid of the inf loop
				 //Now we that we know which planet is close, we must check if the path distance from the start to current(temp)+from temp to planet is smaller than the path distance from start to current)(temp)
// keep this if statement, it should work.... if the distance from the current planet to the next/adj planet is lower through another path it should update the distance for that adj planet and update the opt_prev
        		if (planet == this->planets[j] && (pathDistance(start,temp) +temp->getDistance(planet)) < start->distance_vect[j]){
          		start->distance_vect[j] = pathDistance(start,temp)+temp->getDistance(planet);
          		start->opt_prev[j] =temp;
        		}
     		}
	// this should be done inside the loop where we should update the opt prev if the path is the smallest one for debugging i just put it here
			//start->distance_vect[j] = ret;
			//start->opt_prev[j] = retval;
    	}
	// found is the visted planets in the algorithm
    	temp->found = true;
  	}

  	Planet* curr = dest;
	// we need to return a path here:
  	while(curr != start){
    		if (curr == NULL){
      		retval.clear();
      		break;
    		}
    		retval.insert(retval.begin(), curr);
    		curr = start->opt_prev[curr->index];
  	}
 	if (curr != NULL) {
		retval.insert(retval.begin(), curr);
		}
  	return retval;
}

		

//done
int Galaxy::smallestDist(Planet*start){
  	int retval= 0;
	// reach the first unvisted planet closest to p 
  	for (unsigned int i = 0;i<start->distance_vect.size();i++){
  		if(this->planets[i]->found == false){
      		retval = i;
      		break;
    		}
  	}	
	//check the distance according to the algorithm and return the closest planet that isnt visted. 
  	for (unsigned int i = 0; i < start->distance_vect.size(); i++){
    		if (this->planets[i]->found == false && start->distance_vect[i] <= start->distance_vect[retval]){
      			retval = i;
  	}
  		}
  	return retval;
}

double Galaxy::pathDistance(Planet * start, Planet * dest){
	//if start does not have any opt prev, clear the vector and reinit
 	if (start->opt_prev.size() == 0){
  		for (unsigned int i = 0; i < this->planets.size(); i++){
  			this->planets[i]->found = false;
  			this->planets[i]->index = i;
      			start->opt_prev.push_back(NULL);
      			if (this->planets[i] == start){start->distance_vect.push_back(0);}
      			else {start->distance_vect.push_back(-1);}
    		}
		// heres where we actually find the path distance using the same set up as shortest path
  	for (unsigned int i = 0; i < this->planets.size(); i++){
      		Planet* current = this->planets[smallestDist(start)];
      		for (unsigned int j = 0; j < this->planets.size(); j++){
        		for(Planet* planet : current->adjacencyList){
        			if (planet == this->planets[j] && (pathDistance(start, current) + current->getDistance(planet)) < start->distance_vect[j]){
            			start->distance_vect[j] = pathDistance(start, current) + current->getDistance(planet);
            			start->opt_prev[j] = current;
          	}
        	}
      		}
     		current->found = true;
    	}
  	}


  	double retVal = 0;
  	Planet * current = dest;
  	while (current!=start){
  		if (start->opt_prev.size() == 0){return LDBL_MAX;}
    		if (start->opt_prev[current->index] == NULL){return LDBL_MAX;}
    		retVal+= current->getDistance(start->opt_prev[current->index]);
    		current = start->opt_prev[current->index];
  	}
  	return retVal;
}

