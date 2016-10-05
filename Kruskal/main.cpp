#include <iostream>  
#include <algorithm>
#include "Graph.h"  
     
const int max = 1000;

int cicles[ max ];

bool lequal(const data_t t1, const data_t t2)
{
	double d1 = t1.second;
	double d2 = t2.second;
	return d1 < d2;
}

std::vector<data_t> Kruskal( Graph G )
{
	int i, number;
	std::vector<data_t> mst;
	mst.clear();

	std::vector<data_t> edges = G.sorted_edges();

	for( i=0; i < G.V(); i++) cicles[ i ] = i;

	while( (int) mst.size() < ( G.V() - 1) && edges.size() )
	{
		data_t dt = edges[ 0 ];
		std::pair<int,int> p = dt.first;
		int vi = p.first;
		int vj = p.second;

		if( cicles[ vi ] != cicles[vj] )
		{
			number = cicles[ vj ];
			for( i=0; i < G.V(); i++ ) 
			{
				if( cicles[ i ] == number )
				{
					cicles[ i ] = cicles[ vi ];
				}
			}

			mst.push_back( dt );
		}

		edges.erase( edges.begin(), edges.begin() + 1 );
    }

	return mst;
}


int main()  
{  
    Graph G( 11, true );  
    
	G.insert( 0, 1, 1.0 );  
	G.insert( 0, 2, 0.6);  
	G.insert( 0, 3, 1.0 ); 
	G.insert( 0, 4, 1.0 );  
	G.insert( 0, 5, 1.1 ); 
	G.insert( 1, 4, 1.8 ); 
	G.insert( 1, 10, 1.9 ); 
	G.insert( 2, 3, 2.1 ); 
	G.insert( 2, 5, 2.3); 
	G.insert( 2, 6, 1.7 ); 
	G.insert( 3, 4, 1.7 );
	G.insert( 5, 6, 0.5 );
	G.insert( 5, 7, 0.7 );
	G.insert( 5, 8, 0.9 );
	G.insert( 5, 9, 0.9 );
	G.insert( 5, 10, 1.0 );   
	G.insert( 6, 7, 1.9 );
	G.insert( 7, 8, 1.7 );
	G.insert( 8, 9, 1.6 );
	G.insert( 9, 10, 2.2 );
      
    G.show();     

	std::cout << std::endl;

	std::vector<data_t> vec = Kruskal( G );
	std::vector<data_t>::iterator vec_it = vec.begin();

	for ( ; vec_it != vec.end(); vec_it++ )
	{
		std::pair<int,int> p = (*vec_it).first;
		double weight = (*vec_it).second;

		std::cout << p.first << " " << p.second << " " << weight << std::endl;
	}

          
    return 0;    
}  