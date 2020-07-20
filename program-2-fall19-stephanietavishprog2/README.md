# Program 2: Program takes in and parses a file containing planet data. Uses a scanner to refine probability of life on each planet, which gets us closer to finding out if there is life on that planet. Scanner uses a priority queue implemented with a templated heap to store planets.

Part A: Setting Up the Search

Welcome to the mission to find life outside our solar system. Unfortunately, we cannot search for intelligent life since we don't know what that looks like (i.e. there's no point of reference here on earth). For this assignment, you are going to scan for life by putting all planets into a max-heap prioritized by their 'probability of life'. We will write code to scan each planet our probe found and refine our probability to either 100 or 0. Since the scanning process takes time, we will first simulate the scanning so we don't have to spend the next 4 billion years testing your program.

Your probe from the previous lab has finally returned to earth with all the necessary information in a formatted text file. Unfortunately, in order for us to use the data, we will need to parse the file into objects.

Planet Class
The Planet class should have the following public interface:
Planet(string id, double probability)
sets the planet's Standard IAU name and probability of life
string getName()
returns the planet's Standard IAU name
double getProbabilty()
returns the Planet's chance of having life
double refine(double r)
adds the value of r to the current probability of life
probability should never be less than 0 or exceed 100.
returns the updated probability of life
You must overload the following operators to compare planets by probability of life
>, <, >=, <=, ==, !=

Parser
Parser(std::string filename)
Opens the filename passed as a parameter and reads the data.
Parses the data into a vector of Planets
You can assume the data is well-formed.
It will follow this format: <planet name> <probability of life>
One planet per line, terminating with a blank line
vector<Planet> getPlanets()
returns a copy of the internally stored vector

Part B: Searching Your Planets
For Part A you read in a text document containing planet data. Once we can parse the file, our next job is to develop a scanner to scan each planet for life. The scanner is going to use a priority queue for internal storage, so it is always working with the highest probability planet. You must create a templated Heap class prioritized by the planet’s current possibility of life. Your heap must be an array based heap and may not use the STL for the heap itself; however, you can use a vector (or other STL container) for the internal array. Because heaps require comparison, we needed to overload several operators for the planet class.

Heap<T>
The following is the required public interface:
Heap(){}
default constructor must be implemented since we have implemented a value constructor
Heap(std::vector<T>)
value constructor takes a vector as a parameter and heapifies the vector
void addElement(T element)
adds an element to the heap and ensures the heap is maintained after insert
T getPriority()
removes the priority value and ensures the heap is maintained after remove
calling on an empty heap is undefined behavior
bool empty()
returns true if the heap is empty, otherwise false
unsigned long size()
returns the number of elements in the heap
vector<T> getArray()
returns a copy of the internal array as an STL vector

You will need additional private methods depending on your implementation.
Scanner

Unfortunately, our scanner is still in the testing phase and cannot tell us if a planet currently has life. Instead, it can only refine the chances. Each scan improves the accuracy of our probability of life by up to +/-1%, rather than giving a definitive 'yes' or 'no'.

We are going to scan a planet, refine its probability of life, then return it to our heap. We should always be scanning the planet with the highest probability of life.

Scanner(vector<Planet>)
Uses your heap template to heapify the vector
std::vector<Planet> scan(unsigned int num_planets)
Removes and scans the top num_planets to refine their probability
The scanner only refines the Planet's current probability by -1.0 or 1.0.
You should randomly refine by -1 or 1
if num_planets is greater than the size of the heap, it should be set to the size of the heap
You should not alter a probability at either 0 or 100.
Returns a vector of the scanned planets
void addPlanet(Planet p)
adds a planet into the internal heap
Heap<Planet> getHeap()
returns a copy of the internal Heap
