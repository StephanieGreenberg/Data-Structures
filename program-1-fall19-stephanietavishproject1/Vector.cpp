#include "Vector.h"
#include <cstdlib>

using namespace std;

Vector::Vector() {
	this->planets = NULL;
	this->vec_size = 0;
}

Vector::~Vector() {
	for (unsigned int i = 0; i < vec_size; i++) {
		delete this->planets[i];
		this->planets[i] = NULL;
	}
	delete[] this->planets;
	this->planets = NULL;
}

void Vector::insert(unsigned int index, Planet *p) {
	if (index < 0) {
		return;
	}
	else if (index < vec_size) {
		Planet ** temp = new Planet*[this->vec_size + 1];
		for (unsigned int i = 0; i < index; i++) {
			temp[i] = planets[i];
		}
		temp[index] = p;
		for (unsigned int i = index + 1; i < this->vec_size + 1; i++) {
			temp[i] = planets[i-1];
		}	
		this->vec_size+=1;
		delete[] this->planets;
		this->planets = temp;	
		temp = NULL;
	}
	else {
		Planet ** temp = new Planet*[index+1];
		for (unsigned int i = 0; i < this->vec_size; i++) {
			temp[i] = planets[i];
		}
		for (unsigned int i = this->vec_size; i < index; i++) {
			temp[i] = NULL;
		}
		temp[index] = p;
		this->vec_size = index+1;
		delete[] this->planets;
		this->planets = temp;
		temp = NULL;
	}
}

Planet* Vector::read(unsigned int index) {
	if (index < 0 || index > this->vec_size - 1 || this->planets[index] == NULL) {
		return NULL;
	}
	else {
		return this->planets[index];
	}
}

bool Vector::remove(unsigned int index) {
	if (index < 0 || index > this->vec_size - 1) {
		return false;
	}
	else {
		//vec_size-=1;
		Planet ** temp = new Planet*[this->vec_size-1];
		for (unsigned int i = 0; i < index; i++) {
			temp[i] = this->planets[i];
		}
		for (unsigned int i = index+1; i < this->vec_size; i++) {
			temp[i-1] = this->planets[i];
		}
		delete this->planets[index];
		delete[] this->planets;
		this->planets = temp;
		temp = NULL;
		this->vec_size-=1;
		return true;
	}
}

unsigned int Vector::size() {
	return this->vec_size;
}
