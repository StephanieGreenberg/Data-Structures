#include "Star.h"
#include <stdlib.h>
#include <iostream>

Starlist::Starlist(){
	this->list = new List();
}

Starlist::~Starlist(){	
	delete this->list;
}

unsigned long Starlist::addPlanet(){
	Planet * temp = new Planet(rand()%3001);
	list->insert(this->list->size(),temp);
	return temp->getID();
}

bool Starlist::removePlanet(unsigned long x){
	bool removed = false;
	for(unsigned int i = 0;i< this->list->size(); i++){
		if(this->list->read(i)->getID() == x){
			list->remove(i);
			removed = true;
			}
		}

	return removed;
}


Planet* Starlist::getPlanet(unsigned long y){
	int id = 0;
	for(unsigned int i = 0;i< this->list->size(); i++){
		if(this->list->read(i)->getID() == y){
			id = i;
			return list->read(id);
			}
		}
	return NULL;
}

void Starlist::orbit(){
	for(unsigned int i = 0;i< this->list->size(); i++){
		this->list->read(i)->orbit();
	}
}

void Starlist::printStarInfo(){
	std::cout<<"StarList size: "<<list->size()<<std::endl;
	std::cout<<"Planets: "<<std::endl;
	for(unsigned int i= 0; i<list->size();i++){
		std::cout<<"Id: "<<list->read(i)->getID()<<" ";
		std::cout<<"Type: "<<list->read(i)->getType()<< " ";
		std::cout<<"Distance: "<<list->read(i)->getDistance()<<" ";
		std::cout<<"Position: "<<list->read(i)->getPos()<< " ";
		std::cout<<"Type: "<<list->read(i)->getType()<<std::endl;
		}	
		
	}

unsigned int Starlist::getCurrentNumPlanets(){
	return this->list->size();
}

Starvector::Starvector() {
	this->vect = new Vector();
}

Starvector::~Starvector() {
	delete vect;
}

unsigned long Starvector::addPlanet() {
	Planet * temp_p = new Planet(rand() % 3001);
	vect->insert(vect->size(), temp_p);
	return temp_p->getID();	
}

bool Starvector::removePlanet(unsigned long id) {
	bool found = false;
	for (unsigned int i = 0; i < vect->size(); i++) {
		if (vect->read(i) == NULL) {
			return found;
		}
		if (vect->read(i)->getID() == id) {
			found = vect->remove(i);
			return found;
		}
	}
	return found;
}

Planet* Starvector::getPlanet(unsigned long id) {
	for (unsigned int i = 0; i < vect->size(); i++) {
		if((vect->read(i))->getID() == id) {
			return vect->read(i);
		}
	}
	return NULL;
}

void Starvector::orbit(){
	for(unsigned int i = 0;i< this->vect->size(); i++){
		this->vect->read(i)->orbit();
	}
}

void Starvector::printStarInfo(){
	std::cout<<"Starvector size: "<<vect->size()<<std::endl;
	std::cout<<"Planets: "<<std::endl;
	for(unsigned int i= 0; i<vect->size();i++){
		std::cout<<"Id: "<<vect->read(i)->getID()<<" ";
		std::cout<<"Type: "<<vect->read(i)->getType()<<" ";
		std::cout<<"Distance: "<<vect->read(i)->getDistance()<<" ";
		std::cout<<"Position: "<<vect->read(i)->getPos()<<" ";
		std::cout<<"Type: "<<vect->read(i)->getType()<<std::endl;
		}	
		
	}

unsigned int Starvector::getCurrentNumPlanets(){
	return this->vect->size();
}
