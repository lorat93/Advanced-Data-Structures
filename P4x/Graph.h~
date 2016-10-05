#include <map> 
#include <vector>
#include <string>

using namespace std;

typedef pair< pair<string,string>, pair<int, int>> data_t;
typedef map< pair<string,string>, pair<int, int>>::const_iterator clm_it;  
      
class Graph  
{  
      
private:  
    int nVertices;  
    int nEdges;  
      
    map< pair<string,string>, pair<int, int>> link_map;
    vector<string> vertices;       

public:  
    Graph();  
    ~Graph();  
      
    int V() const;  
    int E() const;  
    void insert( const string& s, const string& t, const int& weight, const int& time );   
    void remove( const string& s, const string& t );  
    bool edge( const string& s, const string& t);  
    vector<data_t> sorted_edges_cost();
    vector<data_t> sorted_edges_time();
    vector<string> vertice();
    map<pair<string,string>,pair<int,int>> getMap();
      
    clm_it getEdge( const string& s, const string& t);      
    void show() const;      
};  
