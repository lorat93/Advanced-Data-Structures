/**
 * A Huffman tree compression implementation for CSE 100
 * P4 CSE 100 2012
 * Authors: Dan Neumann: daneuman and Narine Cholakyan: ncholaky
 */

#ifndef VERTEX_HPP
#define VERTEX_HPP
#include "edge.hpp"

class Vertex
{
  private:
    
    //This is the name of the current vertex (computer name)
    string name;
	 Vertex *prev;
    
    //List of outgoing edges for this vertex
    vector<Edge> adjVertexList;

    //Used in dfs to mark the vertex visited
    bool isVisited;

	public:
	int dist;
		Vertex(string id)
		{
			name = id;
			isVisited = false;
		}

	//do not del the adj vertexs here...they will be deleted by graph destructor
	~Vertex()
	{
		adjVertexList.clear();
	}

	bool getStatus()
	{
		return isVisited;
	}

	void setStatus(bool st)
	{
		isVisited = st;
	}

	string getName()
	{
		return name;
	}

  Vertex* getPrev()
  {
    return prev;
  }

  void setPrev(Vertex *vert)
  {
    prev = vert;
  }

  bool dupEdge(Edge *dup)
  {
    //This seems like a really bad way to check for duplicates
    for(int i = 0; i < adjVertexList.size(); i++)
    {
      Edge edg = adjVertexList[i];
      if( dup->getstartV()->getName() == edg.getstartV()->getName() && dup->getendV()->getName() == edg.getendV()->getName() )
      {
        return true;
      }

    }

    return false;
  }

	void addAdjVertex(Vertex *adj, int cost, int time)
	{
		//create an edge with 'this' as the originating vertex and adj as the destination vertex
    Edge *newEdge = new Edge(this, adj, cost, time);

    if(!dupEdge(newEdge))
    {
		  adjVertexList.push_back(*newEdge);
    }
	}

	vector<Edge>& getAdjVertexList()
	{
		return adjVertexList;
	}

  void displayList()
  {
    for(int i = 0; i < adjVertexList.size(); i++)
    {
      Edge edg = adjVertexList[i];
      cout << name << " -> " << edg.getendV()->getName() << endl; 
    }
  }

};
#endif