// C++ program to print DFS traversal from a given vertex of a given graph
// this graph is just a basic representation of numbers
#include <iostream>
#include <list> // library for implementing linked list from cstdlib
using namespace std;

// // Graph class represents a directed graph using an adjaceny list representation
class Graph
{
  int V; // number of vertices
  // pointer to an array containing adjacency  lists
  list<int> *adj;

  // a recurisve functiion that will be used by DepthFirstSearch (DFS)
  void DFSUtil(int v, bool visited[]);

public:
  Graph(int V); // constructor

  // function to add an edge to graph
  void addEdge(int v, int w);

  // DFS traversal of the vertices reachable from v. Searching the alley of vertex v.
  void DFS(int v);

};

Graph::Graph(int V)
{
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
  adj[v].push_back(w);  // connecting v's to w, this is directed because its only a one way street
}

void Graph::DFSUtil(int v, bool visited[])
{
  // mark the current node as visited then print it
  visited[v] = true;
  cout << v << " ";

  // Recur for all the vertices adjacent to this vertex
  list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i)
    if (!visited[*i])
      DFSUtil(*i, visited);
}

void Graph::DFS(int v)
{
  // Mark all the vertices as not visited and create a new link list of booleans
  bool* visited = new bool[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

  // call the recurisve helper function to print DFS traversal
  DFSUtil(v, visited);
}
int main(int argc, char* argv[])
{
  // Create a graph given in the above diagram
  Graph g(4);
  g.addEdge(0,1);
  g.addEdge(0,2);
  g.addEdge(1,2);
  g.addEdge(2,0);
  g.addEdge(2,3);
  g.addEdge(2,3);

  cout << "Following is the Depth First Traversal (starting from vertex 2) \n";
  g.DFS(2);
  cout << endl;
  return 0;
}
