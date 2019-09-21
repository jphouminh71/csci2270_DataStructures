#include<iostream>
#include<climits>
#include<list>
#include "graph.hpp"
using namespace std;

// DIRECTED GRAPH
Graph::Graph(int V)
{
  this->V = V;    // key word is special keyword that referes to the object from within the object,
  adj = new list<int>[V]; // list is a linked list data structure from the built in library
}
void Graph::BFS_visit(int s, bool visited[])
{
  list<int> queue;
  visited[s] = true;
  queue.push_back(s);
  while (!queue.empty())
  {
    s = queue.front();  // peekq    // should be back 
    cout << s << " ";
    queue.pop_front();  // popping the front value  // pop back

    for(auto v : adj[s])    // syntax for iterator functino for linked list, new syntax
    {
      if (!visited[v])
      {
        queue.push_back(v);
        visited[v] = true;
      }
    }
  }
}
void Graph::DFS_visit(int s, bool visited[])
{

}
void Graph::print()
{
  for(int i = 0; i < V; i++)    // V is the total number of vertices , also we need to use an iterator for this function
  {
    cout << "[" << i << "] --> ";
    list<int>::iterator itr;    // this is the syntax of the iterator function
    for(itr = adj[i].begin(); itr != adj[i].end(); ++itr)
    {
      int s = *itr; // s is now the object
      cout << s << ", ";
    }
    cout << endl;
  }
}
void Graph::addEdge(int v, int w)
{
  adj[v].push_back(w);  // adding w to v's linked list
  //adj[w].push_back(v);    if we were to do this it would be a directed graph
}

void Graph::BFS()   // explore each neighbor of the vertices and then visit each neighbor in the order that you saw them, based on the queue
{
  bool visited[V];  // array to mark whether we visited the node or not;
  for (int i = 0; i < V; i++)
  {
    visited[i] = false;   // we havnt visited anything yet
  }
  for (int s = 0; s < V; s++)
  {
    if (!visited[s])    // if hasnt been visited yet
    {
      BFS_visit(s, visited);
    }
  }
  cout << endl;

}
void Graph::DFS()
{

}
