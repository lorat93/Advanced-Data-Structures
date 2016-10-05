/**
 * Author: Lora Tam
 * Date: Aug 14
 * FileName: RST.hpp
 * Class: cse100
 * Id: A09844493
 */
#ifndef RST_HPP
#define RST_HPP
#include "BST.hpp"
#include "countint.hpp"
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <stdlib.h>
#include <time.h>
#include <utility>
#include <stdio.h>

template <typename Data>
class RST : public BST<Data> {

public:

 virtual std::pair<typename BST<Data>::iterator,bool> insert(const Data&
         item) { // TODO: implement this function!
   // call bst insert
   std::pair<typename BST<Data>::iterator, bool> pr = 
            BST<Data>::insert(item);  
   // get the pointer
   BSTNode<Data>* myNode = pr.first.curr;
   //srand(time(NULL));
   // rand for info
   myNode->info = rand();

   // if false then return pair
   if(!(pr.second)) {
     return pr;
   }
   // if 
   else if(this->size() == 1) {
     return pr;
   }
   // call bubble up and then return pair
   else {
     BubbleUp(myNode);
     return pr;
   }     
 }
  // bubble up method to rotate priority to correct position
  void BubbleUp(BSTNode<Data>* newNode) {
    // variable
    int CASE;
    // while the parent's priority is less than the curr node priority
    while(newNode->parent != NULL &&
          newNode->parent->info < newNode->info ) {
      // variables
      BSTNode<Data>* p = newNode->parent;
      BSTNode<Data>* grandp = newNode->parent->parent;
      // if grandp is null
      if(grandp == NULL) {
        CASE = 1;
      }
      // if grandp's left node is parent
      else if(grandp->left == p) {
        CASE = 2;
      }
      // else grandp's right node is parent
      else {
        CASE = 3;
      }
      // is currNode is the left node
      if(newNode->parent->left == newNode) {
        p = rotateWithLeftC(p);
      }
      // if currNode is the right Node
      else {
        p = rotateWithRightC(p);
      }
      // fix for case 1
      if(CASE == 1) {
        BST<Data>::root = p;
        p->parent = NULL;
      }
      // fix for case 2
      if(CASE ==2) {
        grandp->left = p;
        p->parent = grandp;
      }
      // fix for case 3
      if(CASE == 3) {
        grandp->right = p;
        p->parent = grandp;
      }
    }
    
  }
  // rotate with left children method/ rotate right method
  // rotates the priority up if the left childrens priority is greater
  // than the parents
  BSTNode<Data>* rotateWithLeftC(BSTNode<Data>* pnode){
    BSTNode<Data>* newNode = pnode->left;
    pnode->left = newNode->right;
    // if right node not null
    if(newNode->right != NULL) {
      newNode->right->parent = pnode;
    }    
    newNode->right = pnode;
    pnode->parent = newNode;
    return newNode;
  }
  // rotates with right children method/ rotate left method
  // rotates the priority up if the right children priority is greater
  // than the parents
  BSTNode<Data>* rotateWithRightC(BSTNode<Data>* pnode) {
    BSTNode<Data>* newNode = pnode->right;
    pnode->right = newNode->left;
    // if left node not null
    if(newNode->left != NULL) {
      newNode->left->parent = pnode;
    }

    newNode->left = pnode;
    pnode->parent = newNode;
    return newNode;
  }

};
#endif // RST_HPP
