#include <iostream>  
#include <algorithm>  
#include "Graph.h"  


struct less_cost
{
   inline bool operator()(const data_t& lhs, const data_t& rhs)
   {
      return lhs.second.first < rhs.second.first;
   }
};
struct less_time
{
   inline bool operator()(const data_t& lhs, const data_t& rhs)
   {
      return lhs.second.second < rhs.second.second;
   }
};

Graph::Graph()  
{  
    nVertices = 0;  
    nEdges = 0;  
}  
      
Graph::~Graph()  
{}  
      
clm_it Graph::getEdge( const string& s, const string& t )  
{  
    pair<string,string> p( s, t );  
    clm_it mit = link_map.find( p );  
      
    return mit;  
}  
      
// Check if link exists between end nodes  
bool Graph::edge( const string& s, const string& t)  
{  
    return getEdge( s, t ) != link_map.end();  
}  
      
// Add a link: map node pair with weight  
void Graph::insert( const string& s, const string& t, const int& weight, const int& time)  
{  
	
    pair<string,string> p1( s, t );  
    pair<string,string> p2( t, s );  
    
	if(link_map.find(p1) == link_map.end() && link_map.find(p2) == link_map.end())
	{
		link_map[p1] = make_pair(weight, time);  
		link_map[p2] = make_pair(weight, time);  
		nEdges++;

		if(find(vertices.begin(), vertices.end(), s) == vertices.end())
		{
			vertices.push_back(s);
			//nVertices++;
		}
		if(find(vertices.begin(), vertices.end(), t) == vertices.end())
		{
			vertices.push_back(t);
			//nVertices++;
		}
	}

   
}  
      
// Remove selected link - remove both directions  
// if graph is not directed  
void Graph::remove( const string& s, const string& t )  
{  
    pair<string,string> p1( s, t );  
    map< pair<string,string>, pair<int,int>>::iterator mit = link_map.find( p1 );  
    link_map.erase( mit );  
    
    pair<string,string> p2( t, s );  
    mit = link_map.find( p2 );  
    link_map.erase( mit );  
      
    nEdges--;  
}  
      
// Print the network topology  
void Graph::show() const  
{  
    clm_it mit = link_map.begin();  
      
    for ( ; mit != link_map.end(); ++ mit )  
    {  
        pair<string,string> p = (*mit).first;  
        cout << p.first  << " " <<  
                p.second << " " <<   
                (*mit).second.first << std::endl;  
    }  
}  
      
// Return number of network nodes  
int Graph::V() const  
{  
    //return nVertices;  
	return vertices.size();
}  
      
// Return number of edges  
int Graph::E() const  
{  
    return nEdges;  
}  

std::vector<string> Graph::vertice()
{
	return vertices; 
}
// Sort the weighted edges
std::vector<data_t> Graph::sorted_edges_cost()
{
	std::vector< data_t > vec(link_map.begin(), link_map.end());
	
	std::sort(vec.begin(), vec.end(), less_cost());
	
	return vec;
}
std::vector<data_t> Graph::sorted_edges_time()
{
	std::vector< data_t > vec(link_map.begin(), link_map.end());
	
	std::sort(vec.begin(), vec.end(), less_time());
	
	return vec;
}
map<pair<string,string>,pair<int,int>> Graph::getMap()
{
	return link_map;
}
