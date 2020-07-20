# Program 3: Program to search for shortest path from one planet in the galaxy to another. Uses sort to create adjacency list and Djikstra's Shortest Path algorithm to find shortest path from start planet to destination.

Part A: Plotting the Stars
Finally, we are going to visit the stars (virtually). We have gathered all the data we need, and now we are going to visit each planet that has been found to contain life; however, our craft is very simple and cannot travel too far without refueling, so we will have to plot our course as efficiently as possible. You are going to create a library that reads in a file with a list a planets and their coordinates in space. The driver code will input a starting planet and destination planet, and you will return the shortest path between the two as a vector of planet names along with the path. Then we are going to test the performance of your path finding algorithm, and possibly give you extra credit.

You will read in a text file containing planets and their x, y, and z coordinates in 3 dimensional space. The file format will be as follows:

Kepler-1049b -25 13 8
HAT-P-27b 8 27 23
HD116029b 9 -35 -5

Planet names will not contain whitespace and will be uniquely named. Input files will be well-formed (no need for error checking). You will need to build a directed, weighted graph using the x, y, and z coordinates.

Each planet will have 4 adjacent planets. These should be the 4 closest planets in space. Not all adjacencies will be symmetric. This means the graph is a directed graph. So the algorithm for building the adjacency list will be to find the distance for all planets, but set only the 4 closest as adjacent.

You should use an array or vector to store the planets. To hold edges you will need to implement an adjacency list or adjacency matrix (you may use the STL list or vector class).

To help you visualize the graph, I have created the following: planetsB.dat

Planet Public Interface
Planet(string planetName, long xCoor, long yCoor, long zCoor)
std::string getName()
Returns the planet name
long getXCoor()
Returns the x coordinate
long getYCoor()
Returns the y coordinate
long getZCoor()
Returns the z coordinate
list<Planet*> getAdjacent()
Returns an adjacency list for the planet
Galaxy Public Interface
Galaxy(string filename)
Takes in a filename and build a list of planets with adjacencies
unsigned int size()
The number of planets currently contained in the galaxy
Planet* findByName(std::string planetName)
Returns the planet object with the associated name

Part B: Searching Your Planets
In order to travel between planets, we have to stop at nearby planets to refuel. You will need to implement Dijkstra’s shortest path algorithm to determine the shortest path between two planets. If you want to implement a different shortest path algorithm, you must clear it with me first. You must use only "adjacent" planets when finding the path. In other words, planetA may have 4 adjacencies, but also may not be adjacent to any other planet. That means there is no path to planetA.

You should add the following public method to your Galaxy class:
vector<Planet * > shortestPath(Planet * start, Planet * dest)
The method should return the shortest path between two planets by returning a list of the planets you will need to travel through in order.

You will also need a second method that gives the distance (in light years) between two planets on the graph:
double pathDistance(Planet * start, Planets * dest)
The method should return the total distance (based on the path you must take) between the two planets.
The method should return inf if there is no path.
take a look at LDBL_MAX, which is equal to inf
