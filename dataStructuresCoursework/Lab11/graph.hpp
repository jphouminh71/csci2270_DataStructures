#ifndef GRAPH_HPP
#define GRAPH_HPP
#include<list>
// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;    // No. of vertices

    // Pointer to an array containing adjacency
    // lists
    std::list<int> *adj;    // this is an adjaceny list
public:
    Graph(int V);  // Constructor , gonna take the number of vertices that are going to be in the list

    // function to add an edge to graph
    void addEdge(int v, int w);

    void print(); // prints the adjaceny list

    // prints BFS traversal from a given source s
    void BFS_visit(int s, bool visited[]);    // going to explore graph from a specific vertex
    void DFS_visit(int s, bool visited[]);
    void BFS();   // going to explore the entire graph by calling BFS visit a lot
    void DFS();
};
#endif
