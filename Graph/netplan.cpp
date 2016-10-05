/**
 * A Huffman tree compression implementation for CSE 100
 * P4 CSE 100 2012
 * Authors: Dan Neumann: daneuman and Narine Cholakyan:
 */

#include <fstream>
#include <string>
#include "graph.hpp"
using namespace std;

int main(int argc, char *argv[])
{

  // Handle Incorrect Inputs---------------------------------------------------
  if( argc != 2 )
  {
    cout << "./netplan called with incorrect arguments." << endl;
    cout << "Usage: ./netplan infile" << endl;
    return 1;
  }

  // Step One: Create Initial Empty Graph--------------------------------------
  cout << "Creating initiallity empty graph." << endl;
  Graph* graphInst = new Graph(); 
  string comp1,comp2 = "";
  int cost, time = 0;
  
  // Step Two: Open Input File For Reading-------------------------------------
  cout << "Opening input file for reading." << endl;

  ifstream infile;
  infile.open(argv[1]);
 
  // Step Three: Read Input File And Generate Graph----------------------------
  cout << "Reading lines from input file." << endl;
  
  while (!infile.eof())
  {
    infile >> comp1 >> comp2 >> cost >> time;
    
    if(infile.eof()) break;
    
    //cout << "Comp1 is: " << comp1 << endl;
    Vertex *newVert = new Vertex(comp1);  
    
    if (graphInst->findVertexByName(comp1) == NULL)		
    {
      //If the vertex is not already on the graph, a new one should be added
      graphInst->addNewVertex(newVert);
      //cout << "We just added vertex with name " << comp1 << endl ;
    }
    else
    {
      //Otherwise we need to set our pointer to the existing vertex
      newVert = graphInst->findVertexByName(comp1);
    }

    //cout << "Comp2 is: " << comp2 <<endl;
    Vertex *newVert2 = new Vertex(comp2);

    //if (comp1 != comp2)
    //{
    if (graphInst->findVertexByName(comp2) == NULL)   
    {
      //Need to make a new vertex if second doesn't exist already
      graphInst->addNewVertex(newVert2);
      //cout << "We just added vertex with name " << comp2 << endl ;
    }
    else
    {
      //Otherwise we need to set our pointer to the existing vertex
      newVert2 = graphInst->findVertexByName(comp2);
    }

    //Use addAdjVertex to create edges between two vertices.
    newVert->addAdjVertex(newVert2, cost, time);
    //This is undirected so both vertexes need to know about the edge
    newVert2->addAdjVertex(newVert, cost, time);

    //cout << "Created edge between " << comp1 << " and " << comp2 << endl;

    //cout << "The cost is: " << cost <<endl;
    //cout << "The time is: " << time <<endl;

    //}
    /*
    else
    {
      cout << "Can't create edges between the same vertex!" << endl;
    }
    */
    //cout << "----------------------------------" << endl;
  }

  // Step Four: Close Input File-----------------------------------------------
  infile.close();
  cout << "Closing input file, done with reading." << endl;

  //cout << "Printing the current graph." << endl;
  //graphInst.displayGraph();
  
  // Step Five: Output Total Cost of Edges-------------------------------------
  cout << "Displaying the total cost of graph." << endl;
 
  int graphCost = graphInst->totalCost();
  cout << graphCost << endl;
  
  // Step Six: Find Minimum Cost Spanning Tree---------------------------------
  cout << "Creating a minimum cost spanning tree." << endl;

  Graph* graphInst2 = new Graph();
  graphInst2 = graphInst->MST();

  cout << "Displaying the total cost of the MST." << endl;
  
  int graphCost2 = graphInst2->totalCost();
  cout << graphCost2 << endl;

  cout << "Displaying the difference in costs between the two paths." << endl;
  cout << (graphCost - graphCost2) << endl;

  // Step Seven: Find Minimum Time Path----------------------------------------
  cout << "Displaying the total transit time." << endl;
  
 
  int Ttime = graphInst->dijkstraAlg();
  cout << Ttime << endl;

  //Call destructor on two graphs
  delete graphInst;
  delete graphInst2;
}