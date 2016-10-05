#include "BST.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * A simple test driver for the BST class template.
 * P1 CSE 100 2013
 * Author: P. Kube (c) 2013
 * Additional tests by Mariya Shilova
 */
int main() {

  /* Create an STL vector of some ints */
  vector<int> v;
  v.push_back(3);
  v.push_back(4);
  v.push_back(1);
  v.push_back(100);
  v.push_back(-33);

  /* Create an STL vector of some ints */
  vector<int> myVector;
  /* Create an instance of BST holding int */
  BST<int> myTree;
 
// testing for duplicate elements with this vector
  myVector.push_back(100);
  myVector.push_back(-8);
  myVector.push_back(36);
  myVector.push_back(36);
  myVector.push_back(-100);
  myVector.push_back(13);
  myVector.push_back(20);
  myVector.push_back(36);
  myVector.push_back(55);
  myVector.push_back(55);
  myVector.push_back(-10);
  myVector.push_back(-100);
  // vecor of ints: 
 
  // iterators assisting duplicate test
  vector<int>::iterator myVecIt = myVector.begin();
  vector<int>::iterator myVecIt2 = myVector.end();
  bool duplicate = false;
  // testing adding a duplicate element in the tree
  int counter = 0;  // counter for duplicates
  for(;myVecIt != myVecIt2; ++myVecIt)  {

    std::pair<BST<int>::iterator,bool> pr = myTree.insert(*myVecIt);
    if(!pr.second)  {
      duplicate = true;
      cout << "warning:  CANNOT ADD DUPLICATE ELEMENTS TO THE TREE" << endl;
      counter++;
    }
 
  } 
  cout << "" << endl;
  cout<< "TESTING THAT CANNOT ADD DUPLICATE ELEMENTS TO THE TREE" << endl;
  cout << " tried to add duplicates 4 times, counter should be 4" << endl;
  if(counter == 4)
    cout << "correct counter" << endl;
  else {
    cout << " INCORRECT COUNTER !!!!!!!!!!" << endl; 
    cout << "duplicate test failed" << endl;
    return -1;
  }
  // make sure that the duplicate element was not added
  cout << "Added  duplicats into the tree" << endl;
  cout << "so duplicate flag should be true" << endl;
  if(duplicate)
    cout << "the duplicate flag is :  true" << endl;  
  else {
    cout << "the duplicate flag was false, test failed" << endl;
    return -1;
  }
  // check that the size is correct
  cout << "the size of the tree should be 8  " << endl;
  if(myTree.size() == 8)
  cout << "the size is :     " << myTree.size() << endl;
  else  {
    cout << "wrong size, test failed" << endl;
    return -1;
  }
  cout << "FINISHED DUPLICATE TEST" << endl;
  cout << "" << endl;
 
/// TESTING != AND == OPERATORS
  BST<int>::iterator end = myTree.end();
  BST<int>::iterator begin = myTree.begin();
  BST<int>::iterator begin1 = myTree.begin();
 
  cout << "the two iterators are same, so == value should be true " << endl;
  if((begin==begin1))
    cout << "the == value is    true         "  << endl;
  else  {
    cout << "its false!!!!!!!!!!!!" << endl;
    return -1;
  }
  cout << "the two iterators are same, so != value should be false " << endl;
  if(!(begin!=begin1) )
    cout << " the value != is    false      " << endl;
  else  {
    cout <<  " its true !!!!!!!!!!" << endl;
    return -1;
  }
  ++begin; 
  cout << "the two iterators are diff, so == value should be false" << endl;
  if(!(begin==begin1))
    cout << "the == value is    false         "  << endl;
  else  {
    return -1;
  }
  cout << "the two iterators are diff, so != value should be true" << endl;
  if((begin!=begin1))
  cout << "the != value is  true      "  << endl;
  else 
    return -1;
  cout << " Finished operators testing"  << endl;
  cout << "" << endl;

// testing find here

  cout << "TESTING FIND "  << endl;
//test return value in find when element not found
//
  BST<int>::iterator find100= myTree.find(100);
  BST<int>::iterator findNeg8= myTree.find(-8);
  BST<int>::iterator find36= myTree.find(36);
  BST<int>::iterator findNeg100= myTree.find(-100);
  BST<int>::iterator find13 = myTree.find(13);
  BST<int>::iterator find20= myTree.find(20);
  BST<int>::iterator find55 = myTree.find(55);
  BST<int>::iterator findNeg10= myTree.find(-10);
  BST<int>::iterator find200= myTree.find(200);
 
  cout << "should be 100, and the value is     "<< *find100 << endl;
  if(*find100 != 100)
    return -1;
  cout << "should be -8, and the value is     "<< *findNeg8 << endl;
  if(*findNeg8 != -8)
    return -1;
  cout << "should be 36, and the value is     "<< *find36<< endl;
  if(*find36 != 36)
    return -1;
  cout << "should be -100 and the value is     "<< *findNeg100<< endl;
  if(*findNeg100 != -100)
    return -1;
  cout << "should be 13 and the value is     "<< *find13 << endl;
  if(*find13 != 13)
    return -1;
  cout << "should be 20 and the value is     "<< *find20 << endl;
  if(*find20 != 20)
    return -1;
  cout << "should be 55 and the value is     "<< *find55 << endl;
  if(*find55 != 55)
    return -1;
  cout << "should be -10 and the value is     "<< *findNeg10 << endl;
  if(*findNeg10 != -10)
    return -1;

  if(find200 == end)
    cout << " there is no 200 in the tree "<<  endl;
  else
    return -1;
  cout << "finished find testing" << endl;
  cout << "" << endl;


// testing successor here

  cout << "TESTING successor() here  "  << endl;
  BST<int>::iterator su1 =  myTree.begin();
  BST<int>::iterator su2 =  myTree.begin();
  // testing successor values
  cout << "the smallest value in the tree should be -100" << endl;
  cout << "the value is  " << *su1 << endl;
  cout << "the value is  " << *su2 << endl;
  for(unsigned int i = 0; i < myTree.size() -1; i++)  {

   cout << " the successor of " << *su1 << " is " << *++su2 << endl;
   su1++;

  }
  cout << "" << endl;
 


  // Testing successor on a larger BST
  BST<int> largeBst;
  // adding lost of elements
  for(int i = 0; i < 10000; i++)  {
    int k = rand()%10000;
    largeBst.insert(k);
  }
  cout << "the size of the tree is " << largeBst.size()  << endl;
  BST<int>::iterator su =  largeBst.begin();
  BST<int>::iterator su0 =  largeBst.begin();
  // testing successor values
  bool wrongSu = false;
  for(unsigned int i = 0; i < largeBst.size() -1; i++)  {

   //cout << " the successor of " << *su << " is " << *++su0 << endl;
   if(!(*su < *++su0))  {
      cout << "Warning: wrong successor!!!!!!!!!!!!!!!!!!" << endl;
      wrongSu = true;
  }
   su++;
  }
  if(wrongSu)
    cout << "successor did not pass on large data !!!!!!!!!!!" << endl;
  else
    cout << "successor passed on large data ;)  " << endl;
  cout << "" << endl;
 
  cout << "testing CLEAR() here  " << endl;
  if(!largeBst.empty())  
    cout << "empty seems to be working on non-empty tree " << endl;
  else
    cout << " WARNING: something is wrong with the empty() method, does not work on non-empty tree" << endl;
  largeBst.clear();
  if(largeBst.empty())
    cout << "CLEAR and Empty are working: cleared the tree then called empty" << endl;
  else  
    cout << "WARNING --- something is wrong with clear() or isEmpty()  " << endl;

  cout << "" << endl;
  largeBst.insert(100);
  if(!largeBst.empty())  
    cout << "empty is working after adding one element to an empty tree " << endl;
  else
    cout << " WARNING: something is wrong with the empty() method, does not work on non-empty tree" << endl;
 
  largeBst.clear();
  BST<int>:: iterator clearEnd = largeBst.end();
  BST<int>:: iterator clearBeg = largeBst.begin();
  if(clearEnd==clearBeg)
    cout  << " iterator is correct on the empty tree"  << endl;
  else 
    cout << "WARNING: something is wrong with the iterator on the empty tree" << endl;
  if(largeBst.size() == 0)
    cout << "size cleared correctly after calling clear"  << endl;
  else
    cout << "WARNING: size does not clear properly in clear" << endl;
 

  /* Create an instance of BST holding int */
  BST<int> b;

  /* Insert a few data items. */
  vector<int>::iterator vit = v.begin();
  vector<int>::iterator ven = v.end();
  for(; vit != ven; ++vit) {
    // all these inserts are unique, so should return a std::pair
    // with second part true
    std::pair<BST<int>::iterator,bool> pr = b.insert(*vit);
    if(! pr.second ) {
      return -1;
    }
    if(*(pr.first) != *vit) {
      return -1;
    }  
  }

  /* Test size. */
  cout << "Size is: " << b.size() << endl;
  if(b.size() != v.size()) {
    cout << "... which is incorrect." << endl;
    return -1;
  }

  /* Test find return value. */
  vit = v.begin();
  for(; vit != ven; ++vit) {
    if(*(b.find(*vit)) != *vit) {
      cout << "Incorrect return value when finding " << *vit << endl;
      return -1;
    }
  }
 
  /* Sort the vector, to compare with inorder iteration on the BST */
  sort(v.begin(),v.end());

  /* Test BST iterator; should iterate inorder */
  cout << "traversal using iterator:" << endl;
  vit = v.begin();
  BST<int>::iterator en = b.end();
  BST<int>::iterator it = b.begin();
  for(; vit != ven; ++vit) {
    if(! (it != en) ) {
      cout <<  ","<< *it<<  *vit  << ": Early termination of BST iteration." << endl;
      return -1;
    }
    cout << *it << endl;
    if(*it != *vit) {
      cout << *it << "," << *vit << ": Incorrect inorder iteration of BST." << endl;
      return -1;
    }
    ++it;
  }
  cout << "OK." << endl;

}
