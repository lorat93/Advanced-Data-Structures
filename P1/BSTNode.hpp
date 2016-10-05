/**
 * Author: Lora Tam
 * Date: Aug 11
 * FileName: BSTNode.hpp
 * Class: cse100
 * Id: A09844493
 */

#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>


/** This class template defines a node type for the BST container.
 *  Note that all members are public. So, the BST implementation should
 *  take care not to expose any BSTNode objects.
 */
template<typename Data>
class BSTNode {

public:

  /** Member variables. */
  BSTNode<Data>* parent;
  BSTNode<Data>* left;
  BSTNode<Data>* right;
  const Data data;  // the const Data in this node
  int info;  // variable used in advanced algorithms 

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d): data(d) {
    left = right = parent = nullptr;
  }


  /** Return the inorder successor of this BSTNode in a BST,
   *  or nullptr if none.
   *  PRECONDITION: this BSTNode is a node in a BST.
   *  POSTCONDITION:  the BST is unchanged.
   *  RETURNS: the BSTNode that is the inorder successor of this BSTNode,
   *  or nullptr if there is none.
   */ // TODO
  BSTNode<Data>* successor() {
    BSTNode<Data>* currNode = this; // dummy node
    if(right != NULL) { // if right is not null
      currNode = right; // right is currNode
      while(currNode->left != NULL) { // while left is not null
        currNode = currNode->left; // left is currNode
      }
      return currNode; // return currNode
    }
    else {
      if(currNode->parent != NULL && currNode == currNode->parent->left) { 
        // this is left child
        return currNode->parent; // return parent
      }
      else {
        while(currNode->parent != NULL &&
              currNode == currNode->parent->right) { // this is right
          currNode = currNode->parent; // parent is currNode
        }
        if(currNode->parent != NULL) { // parent is not null
          currNode = currNode->parent; // parent is currNode
          return currNode; // return currNode
        }
        else {
          return NULL; // return null
        }
      }
    }
  }

}; 

/** Overload operator<< to insert a BSTNode's fields in an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; i:" << std::setw(10) << n.info;   // its info field
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}

#endif // BSTNODE_HPP
