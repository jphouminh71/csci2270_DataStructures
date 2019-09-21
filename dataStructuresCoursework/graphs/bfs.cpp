/* Program to print BFS traversal from a given source vertex. BFS (int s) traverses vertices reachable from s */
// remember BFS is exploring alleys one at a time.
// think of a graph as a bunch of linked list
#include <iostream>
#include <list>
using namespace std;

// this class represents a directed graph using an adjacency list representation
class Graph{
  int V;  // number of vertices

  // pointer to an array containing adjacency lists
  list<int> *adj;

public:
  Graph(int V);   // constructor
  void addEdge (int v, int w);  // add edges to the DIRECTED graph
  void BFS(int s); // prints BFS traversal from a given source s.
}

Graph::Graph(int V)   // constructor for the graph
{
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) // creating a street between two nodes, v and w
{
  adj[v].push_back(w);  // add w to v's list
}
void Graph::BFS(int s)
{
  // mark all the vertices as not visisted
  bool* visited = new bool[V];
  for (int i = 0; i < V; i++)
  {
    visited[i] = false;
  }

  // 'i' will be used to get all adjacent vertices of a vertex
  list<int>::iterator i;
  while(!queue.empty())
  {
    // dequeue a vertex from queue and print it
    s = queue.front();
    cout << s << " ";
    queue.pop_front();
    /* get all adjacent vertices of the dequeed vertex s. If a adjacent has not been visted,
    then mark it visited and enqueue it */
    for (i = adj[s].begin(); i != adj[s].end(); ++i)
    {
      if (!visited[*i])
      {
        visited[*i] = true;
        queue.push_back(*i);
      }
    }
  }
}

int main()
{
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  cout << "Following is Breadth First Traversal (starting from vertex 2\n");
  g.BFS(2);
  cout << endl;
  return 0; 
}
