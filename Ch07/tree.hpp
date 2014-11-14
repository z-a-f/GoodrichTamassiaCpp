#ifndef LINKED_TREE_HPP
#define LINKED_TREE_HPP

#include <list>
#include "exceptions.hpp"

template <typename T>
class LinkedBinaryTree {
protected:
  struct Node {
    T elt;
    Node* par;			// Parent
    Node* left;			// Left child
    Node* right;		// Right child
    Node() : elt(), par(NULL), left(NULL), right(NULL) {} // Constructor
  }
public:
  class Position {
  private:
    Node* v;			// Pointer to the node of the current position
  public:
    Position(Node* _v = NULL) : v(_v) {} // Constructor
    T& operator*() {return v->elt; }	 // Get element
    Position left() const { return Position(v->left); } // Get left child
    Position right() const { return Position(v->right); } // Get right child
    Position parent() const { return Position(v->parent); } // Get parent
    bool isRoot() const { return v->par == NULL; }	    // Root?
    bool isExternal() const 
    { return v->left == NULL && v->right == NULL; } // External?
  };
  typedef std::list<Position> PositionList;
public:
  LinkedBinaryTree();		// Constructor
  int size() const;		// number of nodes
  bool empty() const;		// empty?
  Position root() const;	// get the root
  PositionList positions() const; // list of all the nodes
  void addRoot() throw TreeNotEmptyException; // add root to an empty tree
  void expandExternal(const Position& p); // expand external node
  Position removeAboveExternal(const Position& p); // remove p and parent
public:				// Housekeeping functions
  ~LinkedBinaryTree();		// Destructor
  LinkedBinaryTree(LinkedBinaryTree<T> lbt);	  // Copy constructor
  LinkedBinaryTree& operator=(const LinkedBinaryOperator& rhs); // Assignment operator
protected:					  // local utilities
  void preorder(Node* v, PositionList& pl) const; // preorder utility
private:
  Node* _root;			// Pointer to the root
  std::size_t n;			// number of nodes
};


#endif
