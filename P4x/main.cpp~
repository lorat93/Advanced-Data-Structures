#include <iostream>  
#include <algorithm>
#include <fstream>
#include "Graph.h"  
#include <stdlib.h>  
#include <sstream>

int floyds(Graph g) 
{
  vector<data_t> edges = g.sorted_edges_time();
  map<pair<string,string>, pair<int,int>> mymap;
  map<pair<string,string>, pair<int,int>> refmap;
  refmap = g.getMap();
  vector<string> vertices = g.vertice(); 
  for(std::vector<string>::iterator k = vertices.begin(); k != vertices.end(); ++k)
  {
	  for(std::vector<string>::iterator i = vertices.begin(); i != vertices.end(); ++i)
	  {
		  if(*k != *i)
			mymap[make_pair(*k,*i)] = make_pair(999999, 999999); 
		  else 
			mymap[make_pair(*k,*i)] = make_pair(0,0); 
	  }
  }
  for(std::map<pair<string,string>, pair<int,int>>::iterator iter = refmap.begin(); iter != refmap.end(); ++iter)
  {
	  mymap[make_pair((*iter).first.first, (*iter).first.second)] = (*iter).second;
  }


  for(std::vector<string>::iterator k = vertices.begin(); k != vertices.end(); ++k)
  {
	  for(std::vector<string>::iterator i = vertices.begin(); i != vertices.end(); ++i)
	  {
		  for(std::vector<string>::iterator j = vertices.begin(); j != vertices.end(); ++j)
		  {
			  if(mymap[make_pair(*i, *k)].second + mymap[make_pair(*k, *j)].second < mymap[make_pair(*i,*j)].second)
				  mymap[make_pair(*i, *j)].second = mymap[make_pair(*i, *k)].second + mymap[make_pair(*k,*j)].second;
		  }
	  }

  }

  int totalTime = 0;
  for(std::map<pair<string,string>, pair<int,int>>::iterator iter = mymap.begin(); iter != mymap.end(); ++iter)
  {
	totalTime += (*iter).second.second;
  }

  return totalTime;

  /*
  for(std::map<pair<string,string>, pair<int,int>>::iterator iter = mymap.begin(); iter != mymap.end(); ++iter)
  {
	  pair<string,string> p = (*iter).first;  
        cout << p.first  << " " <<  
                p.second << " " <<   
                (*iter).second.second << std::endl;
  }
  */
}

vector<data_t> Kruskal( Graph G )
{
	vector<data_t> mst;
	mst.clear();

	vector<data_t> edges = G.sorted_edges_cost();
	vector<string> vertices = G.vertice();

	map<string,string> cicles; 
	for(std::vector<string>::iterator it = vertices.begin(); it != vertices.end(); ++it) 
	{
		cicles[*it] = (*it);
	}

	string number; 
	while( (int) mst.size() < ( G.V() - 1) && edges.size() )
	{
		data_t dt = edges.front();
		std::pair<string,string> p = dt.first;
		string vi = p.first;
		string vj = p.second;


		if( cicles[vi] != cicles[vj] )
		{
			number = cicles[vj];
			for(std::map<string,string>::iterator it = cicles.begin(); it != cicles.end(); ++it) 
			{
				if(it->second == number)
				{
					cicles[it->first] = cicles[vi];
				}
			}
			mst.push_back( dt );
		}
		edges.erase( edges.begin(), edges.begin() + 1);
    }

	return mst;
}

int main(int argc, char* argv[])  
{  
	if(argc != 2)
	{
		cout << "Incorrect number of command line arguments" << endl;
		return 1; 
	}
	Graph g;
	string buffer;
	ifstream input; 
	input.open(argv[1]);

	while (getline(input, buffer))        
  	{
		istringstream iss(buffer);
		string a, b;
		int cost, time;
		if(!(iss >> a >> b >> cost >> time))
		break;
		g.insert(a,b,cost,time);
  	}
	input.close();
	/* 	
	g.insert("ibm.com", "yahoo.com", 20, 33);
	g.insert("yahoo.com", "ucsd.edu", 19, 40);
	g.insert("ucsd.edu", "ibm.com", 10, 17);
	g.insert("yahoo.com", "fsf.org", 5, 10);
	*/
	int totalCost = 0;
	map<pair<string,string>, pair<int,int>> mymap;
	mymap = g.getMap();
	for(clm_it it = mymap.begin(); it != mymap.end(); ++it)
	{
		totalCost += (*it).second.first;
	} 
	totalCost = totalCost/2;
	cout << totalCost << endl;
	/*
	g.insert("A", "B", 3);
	g.insert("A", "D", 5);
	g.insert("A", "C", 2);
	g.insert("B", "D", 2);
	g.insert("D", "C", 2);
	g.insert("B", "F", 13);
	g.insert("D", "F", 6);
	g.insert("D", "G", 3);
	g.insert("D", "E", 4);
	g.insert("C", "E", 5);
	g.insert("E", "G", 6);
	g.insert("F", "G", 2);
	g.insert("F", "H", 3);
	g.insert("H", "G", 6);
	*/
	//g.show();

	//cout << "# of edges: " << g.E() << endl;
	//cout << "# of vertices: " << g.V() << endl;
	

	std::vector<data_t> vec = Kruskal( g );
	std::vector<data_t>::iterator vec_it = vec.begin();
	/*
	for ( ; vec_it != vec.end(); vec_it++ )
	{
		std::pair<string,string> p = (*vec_it).first;
		double cost = (*vec_it).second.first;
		double time = (*vec_it).second.second;

		std::cout << p.first << " " << p.second << " " << cost <<  " " << time << std::endl;
	}
	*/
	int mstCost = 0;
	for ( vec_it = vec.begin(); vec_it != vec.end(); vec_it++ )
	{
		mstCost += (*vec_it).second.first;
	}
	cout << mstCost << endl;
	cout << totalCost-mstCost << endl;

	int totalTime = floyds(g);
	cout << totalTime << endl;
	Graph mst;
	for ( vec_it = vec.begin(); vec_it != vec.end(); vec_it++ )
	{
		mst.insert((*vec_it).first.first,(*vec_it).first.second, (*vec_it).second.first, (*vec_it).second.second);
	}
	int mstTotalTime = floyds(mst);
	cout << mstTotalTime << endl;
	cout << mstTotalTime-totalTime;
	cin.get();
          
    return 0;    
}  
