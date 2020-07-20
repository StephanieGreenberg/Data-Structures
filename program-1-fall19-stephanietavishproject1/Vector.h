#include "Planet.h"
#ifndef VECTOR_H
#define VECTOR_H

class Vector {
	private:
		Planet ** planets;
		unsigned int vec_size;
	public:
		Vector();
		~Vector();
		void insert(unsigned int index, Planet * p);
		Planet* read(unsigned int index);
		bool remove(unsigned int index);
		unsigned int size();	
};
#endif
