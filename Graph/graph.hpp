/**
 * A Huffman tree compression implementation for CSE 100
 * P4 CSE 100 2012
 * Authors: Dan Neumann: daneuman and Narine Cholakyan:
 */

#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include "vertex.hpp"
using namespace::std;

class EdgeCostCmp
{
  public:
    bool operator()(Edge edg1, Edge edg2)
    {
      return edg1.getCost() > edg2.getCost();
    }
};

  class EdgeTimeCmp
{
public:
	 bool operator()(Edge e1, Edge e2)
    {
      return e1.getTime() > e2.getTime();
    }

};

class Graph
{
  private:
  //Create a list of vertices
  vector<Vertex*> vList;
  
  //True if a cycle is found, false otherwise
  bool foundCycle;

  public:

  //Setting no cycles found at the beginning
  Graph()
  {
    foundCycle = false;
  }

  Graph* MST(); //minimum spanning tree
  //bool allVisited();
  int dijkstraAlg();
 // int TTT();
  int dijkstra();
  
  //will make sure that we dont' have any vertices marked as visited at the beginning. 
  //This should be useful :) 
  void clearVisited() ;

  //This will add the new vertex to the list of vertices
  //Hmmm is this enough??? 
  void addNewVertex(Vertex *newV); 

  //Might need to change this as we start to use other algorithms hmm
  Vertex* findVertexByName(string name); 

  //Free mem allocated to verticies
  ~Graph()
  {
    for(int i=0 ; i < vList.size() ; i++)
      delete vList[i];
    vList.clear();
  }

  //May not need this but still 
  void displayGraph();

  int totalCost();

};
#endif