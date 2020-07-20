#include "List.h"
#include <cstdlib>

using namespace std;

List::Node::Node(Planet * p) {
	this->planet = p;
	this->next = NULL;
	this->prev = NULL;
}

List::Node::~Node() {
	delete this->planet;

}
List::List() {
	this->head = NULL;
	this->tail = NULL;
	this->current = NULL;
	this->list_size = 0;
}

List::~List() {
	current = head;
	while (current != NULL) {
		Node * temp_next = current->next;
		delete current;
		current = temp_next;
	}
}

void List::insert(unsigned int index, Planet *p) {
	if (index < 0) {
		return;
	}
	Node * temp = new Node(p);
	if (head == NULL ) {
		head = temp;
		tail = head;
	}
	else {
		if (index == 0) {
			temp->next = head;
			temp->prev = NULL;
			head->prev = temp;
			head = temp;
		}
		else if (index > list_size-1) {
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
		else {
			current = head;
			for (unsigned int i = 0; i < index; i++) {
				current = current->next;
			}
			temp->prev = current->prev;
			current->prev->next = temp;
			current->prev = temp;
			temp->next = current;
		}
	}
	temp = NULL;
	list_size++;
}

Planet* List::read(unsigned int index) {
	if (index < 0 || index > list_size-1) {
		return NULL;
	}
	else {
		current = head;
		unsigned int ctr = 0;
		while (current != NULL) {
			if (ctr == index) {
				return current->planet;
			}
			else {
				ctr++;
				current = current->next;
			}
		}
	}
	return NULL;
}

bool List::remove(unsigned int index) {
	if (index < 0 || index > list_size-1 || head == NULL) {
		return false;
	}
	else {
		current = head;
		for (unsigned int i = 0; i < index; i++) {
			current = current->next;
			if (current == NULL) {
				return false;
			}
		}
		if (current->prev != NULL) {
			current->prev->next = current->next;
		}
		if (current->next != NULL) {
			current->next->prev = current->prev;
		}
		if (head == current) {
			head = current->next;
		}
		if (tail == current) {
			tail = current->prev;
		}
	}
	list_size-=1;
	delete current;
	current = NULL;
	return true;
}

unsigned int List::size() {
	return list_size;
}
