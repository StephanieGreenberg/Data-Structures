#ifndef HEAP_H
#define HEAP_H

#include <vector>

template <class T> class Heap {
	private:
		std::vector<T> planets;
	public:
		Heap();
		Heap(std::vector<T>);
		void addElement(T element);
		T getPriority();
		bool empty();
		unsigned long size();
		void heapify();
		void siftdown(int);
		void swap(int, int);
		std::vector<T> getArray();
};

template <class T> Heap<T>::Heap() {
	this->planets = {};
}

template <class T> Heap<T>::Heap(std::vector<T> elements) {
	this->planets = elements;
	heapify();
}

template <class T> void Heap<T>::addElement(T element) {
	this->planets.push_back(element);
	heapify();
}

template <class T> T Heap<T>::getPriority() {
	heapify();
	swap(0,this->planets.size()-1);
	T val = this->planets.back();
	this->planets.pop_back();
	heapify();
	return val;
	
}

template <class T> bool Heap<T>::empty() {
	if(this->planets.size()>0){return false;}
	else{
		return true;
	}
}

template <class T> unsigned long Heap<T>::size() {
	return this->planets.size();
}

template <class T> std::vector<T> Heap<T>::getArray() {
	return planets;
}

template <class T> void Heap<T>::swap(int x, int y){
	T x2 = planets.at(x);
	planets.at(x) = planets.at(y);
	planets.at(y) = x2;
}

template <class T> void Heap<T>::heapify() {
	for (int i = (this->planets.size() - 2)/2; i >= 0; i--) {
		siftdown(i);
	}
}

template <class T> void Heap<T>::siftdown(int index) {
	int largest = index;
	unsigned long left = 2*index+1;
	unsigned long right = 2*index+2;

	if (left < this->planets.size() && planets[left] > planets[index]) {
		largest = left;
	}

	if (right < this->planets.size() && planets[right] > planets[largest]) {
		largest = right;
	}

	if (largest != index) {
		swap(largest, index);
		siftdown(largest);
	}
}
#endif
