For the first program you and partner are going to build both a dynamic array (vector) and a linked list. Each data structure will be tested to ensure the validity of its operations. Once that is complete and you know your data structures are working, we are going to use them as internal data structures for our Star class. Both versions of the Star class will be evaluated to see which provides better performance.

You will reuse your Planet class from lab 2 with minimal changes.

For all Data Structures, you may (and probably should) add additional functions, methods, and attributes, but what follows is the required minimum interface

You may not use the STL for this program.

You will need to make a small change to your planet class constructor.
Planet
Planet(unsigned int distance)
You do not need to pass an ID. The ID will now be the address of the object.
unsigned long getID()
The return type of the getID() method will need to be changed to a long unsigned to hold the address (8 bytes)

You will need to update your Star class method addPlanet accordingly.

Part A
Vector
You must break up your code into Vector.h and Vector.cpp according to the conventions we have discussed in class. Create a dynamic array data class, Vector. You must create your internal array on the heap (using new). Your Vector class should have, at minimum, the following public interface:
Vector()
initializes an empty vector
~Vector()
A destructor to clean up memory
void insert(unsigned int index, Planet * p)
inserts an element at index, increasing the Vector size by 1
if the insert index is out of bounds, you should increase the capacity to the size of the index + 1
Planet* read(unsigned int index)
returns a pointer to the Planet object at index
if the index is out of bounds or unused, return NULL
bool remove(unsigned int index)
remove the Planet object at index, decreasing the size of the Vector by 1
if the index is out of bounds, return false.
unsigned int size()
returns the current size of the Vector (this may not be the same as the number of elements)
Part B
Linked Lists
You must break up your code into List.h and List.cpp according to the conventions we discussed in class. Create a doubly linked list using a List and Node classes. 

Your List and Node classes can go in the same file. 

Your linked list should have the following public interface:
List()
A pointer to a head and tail node, both initialized to NULL
~List()
A destructor to clean up memory
void insert(unsigned int index, Planet * p)
inserts an element at index, increasing the List size by 1
if the insert index is out of bounds, you should append to the end of the list
Planet* read(unsigned int index)
returns a pointer to the Planet object at index
if index is out of bounds, return NULL
bool remove(unsigned int index)
remove the Planet object at index, decreasing the size of the Vector by 1.
return true on successful deletion or false if index is out of bounds
unsigned int size()
returns the current size of the List

Part C
Full of Stars
Although you should have most of the code written from previous labs. You will need to make slight alterations to your Star class to work with the changes to the Planet class and to work with one of the Data Structures (Vector, List) you have created. You must break up your code into Star.h and Star.cpp according to the conventions we discussed in class.

You will have two Star classes, Starlist and Starvector. You will be using your List and Vector, respectively, as the internal data structure to hold Planets.
Starlist
Your Starlist must have the following public interface:

Starlist()
Initialize memory
~Starlist()
deallocate all memory when the Starlist object is deleted.
unsigned long addPlanet()
return the ID of the newly created Planet object
bool removePlanet(unsigned long)
Takes a Planet’s ID as a parameter, and removes the Planet from the Starlist.
You must return true upon successful deletion and false on failure if the ID isn't found.
Planet * getPlanet(unsigned long)
Takes a Planet’s ID and returns a pointer to the Planet. If the Planet is not found, it returns NULL.
void orbit()
Iterate through your planets and alter their orbit position by +1
void printStarInfo()
Prints the Starlist information.
unsigned int getCurrentNumPlanets()
returns the current number of planets stored
Starvector
Your Starvector must have the following:
Starvector()
Initialize memory
~Starvector()
deallocate all memory when the Starvector object is deleted.
unsigned long addPlanet()
return the ID of the newly created Planet object
bool removePlanet(unsigned long)
Takes a Planet’s ID as a parameter, and removes the Planet from the Star.
You must return true upon successful deletion and false on failure if the ID isn't found.
Planet * getPlanet(unsigned long)
Takes a Planet’s ID and returns a pointer to the Planet. If the Planet is not found, it returns NULL.
void orbit()
Iterate through your planets and alter their orbit position by +1
void printStarInfo()
Prints the Star information.
unsigned int getCurrentNumPlanets()
returns the current number of planets stored (the size of the vector)
