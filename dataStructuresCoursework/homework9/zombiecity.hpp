#ifndef GRAPH_HPP
#define GRAPH_HPP

#include<vector>
#include<iostream>

struct vertex;

/*This is the struct for the adjacent vertices for each
 vertex in the graph. */
struct adjVertex
{
      	vertex *v;
      	int distance;
};

/*this is the struct for each vertex in the graph.  */
struct vertex
{
        int ID;
        std::string name;
        int district;
        bool visited;
        std::vector<adjVertex> adj; //stores edges to adjacent vertices
};

class Graph
{
        public:
        /*
        class constructor
        Purpose: perform all operations necessary to instantiate a class 	object
        Parameters: none
        */
        Graph();

        /*
        class destructor
        Purpose: free all resources that the object has aquired
        Parameters: none
        */
        ~Graph();

        /*
        Method Name: addEdge
        Purpose: Creates an edge between two vertices (using an adjVertex
        	struct)
        Param: v1 - vertex at one end of edge
        Param: v2 - vertex at opposite end of edge
        */
        void addEdge(std::string v1, std::string v2, int distance);

        /*
        Method Name: addVertex
        Purpose: Creates a vertex
        Param: name - name of the vertex (city name)
        */
        void addVertex(std::string name);

        /*
        Method Name: displayEdges
        Purpose: print all edges in graph (see writeup for format)
        Parameters: none
        */
        void displayEdges();

        /*
        Method Name: assignDistricts
        Purpose: Iterate through the vertices, perform BFT to find connected
        	components, and assign to district
        Parameters: none
        */
        void assignDistricts();

        private:
        std::vector<vertex> vertices; //stores vertices

        /*
        Method Name: findVertex
        Purpose: Find and return the vertex of the specified city
        Param: name - name of the city vertex to be returned
        returns pointer to a vertex
        */
        vertex * findVertex(std::string name);

        /*
        Method Name: BFTraversalLabel
        Purpose: Call BFTraversalLabel from within assignDistricts to label
        	the districts. This method should implement a breadth first
        	traversal from the startingCity and assign all cities
        	encountered the distID value
        Param: name - name of starting city for breadth first traversal
        */
        void BFTraversalLabel(std::string startingCity, int distID);
};

#endif // GRAPH_HPP
