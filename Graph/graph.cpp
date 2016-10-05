#include "graph.hpp"
#include <queue>
#include <limits>

  void Graph::displayGraph()
  {
    for(int i=0 ; i < vList.size() ; i++)
      {
	      cout << "Vertex " << vList[i]->getName() << " has the following edges: " << endl;
        vList[i]->displayList();	
      }
  }

  //Will make sure that we dont have any vertices marked as visited at the beginning. 
  void Graph::clearVisited() 
  {
    for(int i = 0; i < vList.size() && !foundCycle ; i++)
    {
      vList[i]->setStatus(false);
  	}
  }

  //This will push the new vertex to the list of verticies << hmmm is this enough??? 
  void Graph::addNewVertex(Vertex *nVertex) 
	{
		vList.push_back(nVertex);
	}

  //Might need to change this as we start to use other algorithms hmm
  Vertex* Graph::findVertexByName(string name)
  {
    for(int i = 0 ; i < vList.size() ; i++)
      {
        if(vList[i]->getName() == name)
        {
          return vList[i];
        }
      }
    return NULL;
  }
  
  int Graph::dijkstraAlg()
  {
	  int transT = 0;
	  this->clearVisited();
	  Vertex *vert = vList[0];
	  Vertex *tempV;
	  tempV->setStatus(false); 
	  tempV->dist = numeric_limits<int>::max(); //this should set the dist to INFINITY
	  vert->dist = 0;
	  vert->setPrev(NULL);

	vector<Edge> eLst = vert->getAdjVertexList();
    priority_queue<Edge, vector<Edge>, EdgeTimeCmp> pqT;
    
    for(int i = 0; i < eLst.size(); i++ )
    {
      //cout << "Adding edge to pq with cost " << eList[i].getCost() << endl;
      pqT.push(eLst[i]);  
    }
	  while(!pqT.empty())
	  {
		  Edge e = pqT.top();
		  pqT.pop();
		  if (vert->getStatus() == false)
		  {
			  vert->setStatus(true);
			  transT += e.getTime();
			  break;
		  }
		  else
		  {
			   for(int i = 0; i < eLst.size(); i++ )
				{
					vert->dist += eLst[i].getTime();

				}
		  }
	  }

	  return transT;
  }

  //int Graph::TTT()
  //{
	 // int transTime =0;
  //  return transTime;
  //}
  Graph* Graph::MST()
  {
    //Set all vertices to unvisited
    this->clearVisited();

    Vertex* sVert = vList[0];
    
    //cout << "Initial vertex is " << sVert->getName() << endl;

    sVert->setPrev(NULL);
    sVert->setStatus(true);
    vector<Edge> eList = sVert->getAdjVertexList();
    priority_queue<Edge, vector<Edge>, EdgeCostCmp> pq;
    
    for(int i = 0; i < eList.size(); i++ )
    {
      //cout << "Adding edge to pq with cost " << eList[i].getCost() << endl;
      pq.push(eList[i]);  
    }

    Graph* newGraph = new Graph();

    while(!pq.empty())
    {
      //Remove from pq the edge with the lowest cost
      Edge edg = pq.top();
      //cout << "Top of the pq is " << edg.getCost() << endl;
      pq.pop();

      Vertex* endVert = edg.getendV();
      Vertex* startVert = edg.getstartV();

      //Only do stuff if destination vertex has not been visited
      if( endVert->getStatus() != true )
      {
        //Set start as prev vertex for end, mark end visited
        //cout << endVert->getName() << " has been visited!" << endl;
        //cout << "The previous node is now " << startVert->getName() << endl;
        endVert->setStatus(true);
        endVert->setPrev(startVert);
        vector<Edge> destList = endVert->getAdjVertexList();

        Vertex* newVert = new Vertex(startVert->getName());
        Vertex* newVert2 = new Vertex(endVert->getName());
      
        //Put this information into a new graph
        if (newGraph->findVertexByName(newVert->getName()) == NULL)		
        {
          //If the vertex is not already on the graph, a new one should be added
          newGraph->addNewVertex(newVert);
          //cout << "We just added vertex with name " << newVert->getName() << endl ;
        }
        else
        {
          //Otherwise we need to set our pointer to the existing vertex
          newVert = newGraph->findVertexByName(newVert->getName());
        }

        if (newGraph->findVertexByName(newVert2->getName()) == NULL)   
        {
          //Need to make a new vertex if second doesn't exist already
          newGraph->addNewVertex(newVert2);
          //cout << "We just added vertex with name " << newVert2->getName() << endl ;
        }
        else
        {
          //Otherwise we need to set our pointer to the existing vertex
          newVert2 = newGraph->findVertexByName(newVert2->getName());
        }

        newVert->addAdjVertex(newVert2, edg.getCost(), edg.getTime());
        newVert2->addAdjVertex(newVert, edg.getCost(), edg.getTime());

        //cout << "Created edge between " << newVert->getName() << " and " << newVert2->getName() << endl;

        //cout << "The cost is: " << edg.getCost() <<endl;
        //cout << "The time is: " << edg.getTime() <<endl;
        
        //Iterate through adjacency list of new current vertex
        for(int j = 0; j < destList.size(); j++)
        {
          //cout << "Adding edge to pq with cost " << destList[j].getCost() << endl;
          pq.push(destList[j]);  
        }
      }
    }

    return newGraph;
  }

  int Graph::dijkstra()
  {


  }

  //Returns the total cost of the graph
  int Graph::totalCost()
  {
    int total = 0;
    vector<Edge> bigEdgeList;
   
    for(int i=0 ; i < vList.size() ; i++)
      {
        //Get the list of edges for this particular vertex
        vector<Edge> edgeList = vList[i]->getAdjVertexList();
        
        for(int j=0 ; j < edgeList.size() ; j++)
        {
          Edge edg = edgeList[j];

          if( vList[i]->getStatus() == edg.getendV()->getStatus() )
          {
            //If destination vertex hasn't been visited, save this edge
            bigEdgeList.push_back(edg);
          }
        }

        //This vertex was visited
        vList[i]->setStatus(true);
      }

    //Loop through vector of unique edges and sum the costs
    for(int k =0; k < bigEdgeList.size(); k++)
    {
      total += bigEdgeList[k].getCost();
    }

    return total;
  }