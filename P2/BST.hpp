/**
 * Author: Lora Tam
 * Date: Aug 11
 * FileName: BST.hpp
 * Class: cse100
 * Id: A09844493
 */

#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <utility> // for std::pair
#include "countint.hpp"


template<typename Data>
class BST {

protected:

  /** Pointer to the root of this BST, or nullptr if the BST is empty */
  BSTNode<Data>* root;

  /** Number of Data items stored in this BST. */
  unsigned int isize;

private:
  /** Destroy Function to eliminate Nodes in BST */
  void destroyFcn(BSTNode<Data>* &node) {
    if(node != NULL) {
      destroyFcn(node->left); // eliminate
      destroyFcn(node->right); // eliminate
      delete node;
    }
    return;
  }

public:

  /** iterator is an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
   */
  BST() : root(nullptr), isize(0)  {
  }


  /** Default destructor.
   *  It is virtual, to allow appropriate destruction of subclass objects.
   *  Delete every node in this BST.
   */ // TODO
  virtual ~BST() {
    // destroy function
    destroyFcn(root);
    root = NULL;
    isize = 0;

  }


  /** Insert a Data item in the BST.
  * Return a pair, with the pair's first member set to an
  * iterator pointing to either the newly inserted element
  * or to the equivalent element already in the set.
  * The pair's second element is set to true
  * if a new element was inserted or false if an
  * equivalent element already existed.
  */ // TODO
  virtual std::pair<iterator,bool> insert(const Data& item) {
    if(nullptr == root) { // empty tree, create new root
      root = new BSTNode<Data>(item);
      isize++;
      return std::pair<iterator,bool>(BSTIterator<Data>(root),true);
    } 
    else {
      BSTNode<Data> *curr = root;
      while(1) {
        if(item < curr->data) {
          if(nullptr == curr->left) {
            curr->left = new BSTNode<Data>(item);
            curr->left->parent = curr;
            isize++;
            return std::pair<iterator,bool>(BSTIterator<Data>(curr->left),
                   true);
          } 
          else {
            curr = curr->left;
          }
        } 
        else if(curr->data < item) {
          if(nullptr == curr->right) {
            curr->right = new BSTNode<Data>(item);
            curr->right->parent = curr;
            isize++;
       return std::pair<iterator,bool>(BSTIterator<Data>(curr->right),true);              }
          else {
              curr = curr->right;
          }
        } 
        else { // item == curr->data, already there
          return std::pair<iterator,bool>(BSTIterator<Data>(curr),false);
        }
      }
    }
  }
  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or the end
   *  iterator if the item is not in the BST.
   */ // TODO
  iterator find(const Data& item) const {
    BSTNode<Data>* currNode = root; // dummy node
    if(currNode == NULL) {
      return end();
    }
    while(true) {
      if(currNode->data < item) { // check if item is greater than currNode
        if(currNode->right != NULL) { // check if right is not null
          currNode = currNode->right; // right becomes currNode  
        }
        else {
          return end(); // else its the end
        }
      }
      else if(item < currNode->data) { 
      // check if item is less than currNode
        if(currNode->left != NULL) { // check if left is not null
          currNode = currNode->left; // left becomes currNode
        }
        else {
          return end(); // else its the end
        }
      }
      else { // check if currNode is == to item
        return typename BST<Data>::iterator(currNode); // return currNode
      }
    }
    return end(); // NULL
  }

  
  /** Return the number of items currently in the BST.
   */ // TODO
  unsigned int size() const {
    return isize; // size
  }

  /** Remove all elements from this BST, and destroy them,
   *  leaving this BST with a size of 0.
   */ // TODO
  void clear() {
    // destroy function
    destroyFcn(root);
    root = NULL;
    isize = 0;
  }

  /** Return true if the BST is empty, else false.
   */ // TODO
  bool empty() const {
    if(isize == 0) { // if size is zero
      return true; // return true
    }
    else {
      return false; // return false
    }
  }

  /** Return an iterator pointing to the first item in the BST.
   */ // TODO
  iterator begin() const {
      BSTNode<Data>* currNode = root; // dummy node
      if(currNode != NULL) { // check that currNode is not null
        while(currNode->left != NULL) { // while left is not null
          currNode = currNode->left; // left becomes currNode
        }
      }
    return iterator(currNode); // return iterator 
  }

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const {
    return typename BST<Data>::iterator(nullptr);
  }

  

 };


#endif //BST_HPP
