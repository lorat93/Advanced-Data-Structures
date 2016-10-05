/*
 * Bo Hong Carson Chan A09354706 bhc002@ucsd.edu
 * Lora Tam A09844493	ltam@ucsd.edu
 * cse 100 s2 2013
 * 8/21/13
 *  compress.cpp
 */
#include <fstream>
#include <iomanip> // setprecision
#include "HCTree.hpp"
#include <stdio.h>

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		cout << "Incorrect number of command line arguments" << endl;
		return 1; 
	}
	cout << "Compressing " << argv[1] << " to " << argv[2] << endl; 
	
	vector<int> frequency(256);
	long size; 
	unsigned char ch;
	bool empty = true;

	ifstream input;
	input.open(argv[1], ios::binary);
	
	// counting the frequency of all symbols in the input file
	// -------------------------------------------------------------------	  
	while(1)
	{
		ch = input.get(); 
	 	if(! input.good())	
			break;
		frequency[ch]++;
			}
		for(int i = 0; i < frequency.size(); i++)
		{
			if(frequency.at(i) != 0)	
				empty = false;
		}

	if(!input.eof())
	{
		cerr << "There was a problem" << endl;
		return 1; 
	}
	
	// calculate file size
	input.clear();
	input.seekg (0, ios::end);
	size = input.tellg();

	cout << argv[1] << " has a size of " 
	     << size << " bytes" << endl;
  
	// building the huffman tree
	// ------------------------------------------------------------------
	HCTree hct; 
	if(!empty)	
		hct.build(frequency);
	
	//-------------------------------------------------------------------
	ofstream output;
	output.open(argv[2], ios::binary);
	
	// writing the frequency to output file header
	// ------------------------------------------------------------------
	if(!empty)
	{
		for(int i = 0; i < frequency.size(); i++)
			output << " " << frequency.at(i);
	}
	// returning to the beginning of the input file
	input.clear();
	input.seekg(0, ios::beg);
	
	BitOutputStream os = BitOutputStream(output);
	// encoding to the output file
	if(!empty)
	{	
		while(1)
		{
			ch = input.get();
			
			if(!input.good())
				break;
			hct.encode(ch,os);

			/*
			for(int i = 0; i < frequency.size(); i++)
			{
				if(ch == i)
				{
					if(frequency[i] > 0);
						hct.encode(ch,os);
				}
			}
			*/
		
		}
		os.flush();
	}
	
	input.close();
	output.close();
	//--------------------------------------------------------------
	ifstream input2; 
	input2.open(argv[2]);

	// calculate outputfile size
	input2.seekg (0, ios::end);
	size = input2.tellg();
	
	input2.close();
	
	cout << argv[2] << " has a size of " << size
             << " bytes" << endl;
	
	/*
	for(int i=0;i < frequency.size() ; i++)
		cout << frequency.at(i) <<" "; 
	*/
	return 0;
}
