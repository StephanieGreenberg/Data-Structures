#include "Planet.h"
#ifndef LIST_H
#define LIST_H


class List {
	private:
		class Node {
		public:
			Planet * planet;
			Node * next;
			Node * prev;		 
			Node(Planet * p);
			~Node();
		
		};
	
		Node * head;
		Node * tail;
		Node * current;
		unsigned int list_size;
	public:
		List();
		~List();
		void insert(unsigned int index, Planet *p);
		Planet* read(unsigned int index);
		bool remove(unsigned int index);
		unsigned int size();
	
};
#endif
