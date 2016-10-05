/**
 * A Huffman tree compression implementation for CSE 100
 * P4 CSE 100 2012
 * Authors: Dan Neumann: daneuman and Narine Cholakyan:
 */

#ifndef EDGE_HPP
#define EDGE_HPP
#include <iostream>
#include <vector>
using namespace::std;

//Forward Declaration of Vertex
class Vertex; 

class Edge
{
private:

  //the start Vertex
  Vertex *startV;
  
  //the end vertex
  Vertex *endV;
  

  //cost of the edge
  int cost;

  int time;

public:
  Edge(Vertex *stV, Vertex *toV, int eCost, int eTime)
  {
    startV = stV;
    endV = toV;
    cost = eCost;
    time = eTime;
  }

  Vertex* getendV()
  {
    return endV;
  }

  Vertex* getstartV()
  {
    return startV;
  }

  int getCost()
  {
    return cost;
  }

  int getTime()
  {
    return time;
  }

};
#endif