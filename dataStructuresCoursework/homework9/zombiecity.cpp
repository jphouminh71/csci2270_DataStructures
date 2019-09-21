#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <list>     // library for easy linked lists
#include <vector>
#include <queue>
#include "zombiecity.hpp"
using namespace std;

Graph::Graph()    // dont know what i should be intiating
{

}

Graph::~Graph()
{
  for (unsigned int i = 0; i < vertices.size(); i++)
  {
    vertices.pop_back();
  }
}

void Graph::addEdge(std::string v1, std::string v2, int distance)
{
    vertex* tempptr = findVertex(v1);
  vertex* tempptr2 = findVertex(v2);
  if (tempptr == nullptr || tempptr2 == nullptr)
  {
    cout << "Cannot link . One or more cities do not exist." << endl;
  }
  else{
    adjVertex newAdjVertex1;    // now we push the two objects into the vectors.
    newAdjVertex1.v = tempptr2;
    newAdjVertex1.distance = distance;
    //
    // adjVertex newAdjVertex2;
    // newAdjVertex2.v = tempptr;
    // newAdjVertex2.distance = distance;

    tempptr->adj.push_back(newAdjVertex1);
  }
}

void Graph::addVertex(string name)
{
  vertex newVertex;
  newVertex.name = name;
  newVertex.ID = -999;
  newVertex.district = -999;
  newVertex.visited = false;

  vertices.push_back(newVertex);

}

void Graph::displayEdges()
{
  for(unsigned int i = 0; i < vertices.size(); i++)
  {
    vertex* tempptr = findVertex(vertices[i].name);
    if(tempptr->adj.size() == 1)
    {
      cout << vertices[i].district << ":" << vertices[i].name << "-->" << tempptr->adj[0].v->name << "(" << tempptr->adj[0].distance << " miles)" << endl;
    }
    else
    {
      cout << vertices[i].district << ":" << vertices[i].name << "-->" << tempptr->adj[0].v->name << "(" << tempptr->adj[0].distance << " miles)";
      for (unsigned int j = 1; j < tempptr->adj.size(); j++)
      {
        cout << "***" << tempptr->adj[j].v->name << " (" << tempptr->adj[j].distance << " miles)";
      }
      cout << endl;
    }
  }
}

void Graph::assignDistricts()
{
  int id = 1;
  for(unsigned int i = 0; i < vertices.size(); i++)
  {
    if(vertices[i].visited == false)
    {
      BFTraversalLabel(vertices[i].name,id);
      id++;
    }
  }
}

vertex* Graph::findVertex(string name)
{
  for (unsigned int i = 0; i < vertices.size(); i++)
  {
    if (vertices[i].name == name)
    {
      return &vertices[i];
    }
  }
  return nullptr;
}

void Graph::BFTraversalLabel(string startingCity, int distID)
{
  queue<vertex*> q;
  vertex* tempptr = findVertex(startingCity);
  q.push(tempptr);
  tempptr->visited = true;
  tempptr->district = distID;

  while(q.empty() == false)
  {
    tempptr = q.front();
    q.pop();

    for(unsigned int i = 0; i < tempptr->adj.size(); i++)
    {
      if (tempptr->adj[i].v->visited == false)  // hasnt been visited
      {
        tempptr->adj[i].v->visited = true;   //
        tempptr->adj[i].v->district = distID;
        q.push(tempptr->adj[i].v);
      }
    }
  }
}
