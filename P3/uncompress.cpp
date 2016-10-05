/*
 * Bo Hong Carson Chan A09354706 bhc002@ucsd.edu
 * Lora Tam A09844493	ltam@ucsd.edu
 * cse 100 s2 2013
 * 8/21/13
 * uncompress.cpp
 */
#include <fstream>
#include <iomanip>  // setprecision
#include "HCTree.hpp" 

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		cout << "Incorrect number of command line arguments" << endl;
		return 1; 
	}

	vector<int> frequency(256);
	long begin, end, outputSize; 
	ifstream input;
	input.open(argv[1], ios::binary);
	int n;
	char ch;
	bool empty = true;
	int sum=0;

	// reading the frequency header
	// --------------------------------------------------------------------
	if(input.good())
	{
		for(int i = 0; i < frequency.size(); i++)
		{
			input >> n;
                        //cout << n << " ";
                        sum=n+sum;
			frequency[i] = n;
			if(n != 0)
				empty = false;
		}
	}
        //cout <<"sum "<< sum << endl;
	
	// build a huffman tree
	// --------------------------------------------------------------------
	HCTree hct;
	if(!empty)
		hct.build(frequency);
	

	// decoding
	//--------------------------------------------------------------------
	BitInputStream binput = BitInputStream(input);
	ofstream output;
	output.open(argv[2]);
	
	if(!empty)
	{
		for(int i = 0; i < sum; i++)
		{
			ch = hct.decode(binput);
			
			output << ch;
		}
	}

	input.close();
	output.close();
	
	// calculate output file size
	ifstream input2;
	input2.open(argv[2]);
	begin = input2.tellg();
	input2.seekg (0, ios::end);
	end = input2.tellg();
	outputSize = end - begin;
	
	cout << "The uncompressed file has a size of " << outputSize 
             << " bytes" << endl;

	return 0;
}
