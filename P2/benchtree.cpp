/**
 * Author: Lora Tam
 * Date: Aug 14
 * FileName: benchtree.cpp
 * Class: cse100
 * Id: A09844493
 */

#include "BST.hpp"
#include "RST.hpp"
#include "countint.hpp"
#include <cmath>
#include <iostream>
#include <stdio.h>
#include<string.h>
#include <algorithm>
#include <vector>
#include <set>
#include <sstream>
#include <string>

using namespace std;

// get size function
vector<int> getSize(int isize) {
  std::vector<int> sizes;
  std::vector<int>::iterator it;
  it = sizes.begin();
  int i = 1;
  int j = 0;

  while (i < isize) {
    sizes.insert(sizes.end(),i);
    j++;
    i = (int(pow(2.0,(j+1)))) - 1;
  }   
  return sizes;
}

// convert string to int function
int str2int (const string &str) {
  stringstream strstr(str);
  int num;
  strstr >> num;
  return num;
}


int main(int argc, char* argv[]) {
  int sorted, shuffled = 0;
  // if string input is sorted	
  if(strcmp(argv[2],"sorted") == 0) {
    sorted = 1;
  }
  // if string input is shuffled
  if(strcmp(argv[2],"shuffled") == 0) {
    shuffled = 1;
  }
  int size = str2int(argv[3]);
  int runs = str2int(argv[4]);

  // print out statements
  cout << "# Benchmarking average number of comparisons"
          " for successful find" << endl;
  if(strcmp(argv[1],"bst") == 0) {
    cout << "# Data structure: bst" << endl;
  }
  if(strcmp(argv[1],"rst") == 0) {
    cout << "# Data structure: rst" << endl;
  }
  if(strcmp(argv[1],"set") == 0) {
    cout << "# Data structure: set" << endl;
  }
  if(sorted == 1) {
    cout << "# Data: sorted" << endl;
  }
  if (shuffled == 1) {
  cout << "# Data: shuffled" << endl;
  }
  cout << "# N is powers of 2, minus 1, from 1 to " << size << endl;
  cout << "# Averaging over  " << runs << " runs for each N" << endl;
  cout << "#\n#\tN\tavgcomps\tstdev" << endl;

  vector<int> sizes = getSize(size);
  // if string input is bst
  if(strcmp(argv[1],"bst") == 0) {
    //loop through the trees 
    for(int i = 0; i < sizes.size(); i++) {
      double avgcomps = 0.0;
      double avgsq = 0.0;
      double std_dev = 0.0;
      //loop through the runs 
      for(int x = 0; x < runs; x ++) {

        //create vector with distinct keys
        std::vector<countint> v;
        v.clear();
      for(int j = 0; j < sizes[i]; ++j) {
        v.push_back(j);
      }
      if(shuffled) {
        std::random_shuffle(v.begin(),v.end());
      }

      //insert keys in the vector
      std::vector<countint>::iterator vit = v.begin();
      std::vector<countint>::iterator ven = v.end();

      BST<countint> bst = BST<countint>();
      for(vit = v.begin(); vit != ven; ++vit) {
        bst.insert(*vit);
      }

      //find out the avg comparisons to find key 
      countint::clearcount();
      for(vit = v.begin(); vit != ven; ++vit) {
        bst.find(*vit);
      }
      avgcomps += countint::getcount()/(double)sizes[i];
      avgsq += pow(countint::getcount()/(double)sizes[i],2.0);
      countint::clearcount();
      }
      avgcomps = avgcomps/(double)runs;
      avgsq = avgsq/(double)runs;
      std_dev = sqrt(avgsq - pow(avgcomps,2));		
      cout << "\t" << sizes[i] << "\t" << avgcomps << "\t\t" << std_dev 
      << endl;
    }
  }
  // if string input is rst
  if(strcmp(argv[1],"rst") == 0) {
    for(int i = 0; i < sizes.size(); i++) {
      double avgcomps = 0.0;
      double avgsq = 0.0;
      double std_dev = 0.0;
      for(int x = 0; x < runs; x++) {

	//create vector with distinct keys
	std::vector<countint> v;
	v.clear();
	for(int j = 0; j < sizes[i]; ++j) {
	  v.push_back(j);
	}

	if(shuffled==1) {
	  std::random_shuffle(v.begin(),v.end());
	}
	//insert keys in the vector 
        std::vector<countint>::iterator vit = v.begin();
	std::vector<countint>::iterator ven = v.end();

        RST<countint> rst = RST<countint>();
	for(vit = v.begin(); vit != ven; ++vit) {
	  rst.insert(*vit);
	}

	//find out the avg comparisons to find key
	countint::clearcount();
	for(vit = v.begin(); vit != ven; ++vit) {
	  rst.find(*vit);
	}
	avgcomps += countint::getcount()/(double)sizes[i];
	avgsq += pow((countint::getcount()/(double)sizes[i]),2.0);
      }
      avgcomps = avgcomps/(double)runs;
      avgsq = avgsq/(double)runs;
      std_dev = sqrt(abs(avgsq - pow(avgcomps,2.0)));
      cout << "\t" << sizes[i] << "\t" << avgcomps << "\t\t" << float(std_dev)
      << endl;
    } 
  }
  // if string input is set
  if(strcmp(argv[1],"set") == 0) {
    for(int i = 0; i < sizes.size(); i++) {
      double avgcomps = 0.0;
      double avgsq = 0.0;
      double std_dev = 0.0;
      for(int x = 0; x < runs; x++) {

        //create vector with distinct keys
	std::vector<countint> v;
	v.clear();
	for (int j = 0; j < sizes[i]; ++j) {
	  v.push_back(j);
	}
	if (shuffled) {
	  std::random_shuffle(v.begin(),v.end());
	}

 	//insert keys in the vector 
	std::vector<countint>::iterator vit = v.begin();
	std::vector<countint>::iterator ven = v.end();

	set<countint> set;
	for (vit = v.begin(); vit != ven; ++vit) {
	  set.insert(*vit);
	}

	//find out the avg comparisons to find key
	countint::clearcount();
	for(vit = v.begin(); vit != ven; ++vit) {
	  set.find(*vit);
	}
	avgcomps += countint::getcount()/(double)sizes[i];
	avgsq += pow((countint::getcount()/(double)sizes[i]),2.0);
      }
      avgcomps = avgcomps/(double)runs;
      avgsq = avgsq/(double)runs;
      std_dev = sqrt(abs(avgsq - pow(avgcomps,2.0)));
      cout << "\t" << sizes[i] << "\t" << avgcomps << "\t\t" << std_dev 
      << endl;
    }     
  }
  return 0;
}


