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
  };
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
  public:
    //~Position() { delete v; };
  };
  typedef std::list<Position> PositionList;
public:
  LinkedBinaryTree();		// Constructor
  std::size_t size() const;		// number of nodes
  bool empty() const;		// empty?
  Position root() const;	// get the root
  PositionList positions() const; // list of all the nodes
  void addRoot() throw (TreeNotEmptyException); // add root to an empty tree
  void expandExternal(const Position& p); // expand external node
  Position removeAboveExternal(const Position& p); // remove p and parent
public:				// Housekeeping functions
  ~LinkedBinaryTree();		// Destructor
  LinkedBinaryTree(const LinkedBinaryTree<T>& lbt); // Copy constructor
  LinkedBinaryTree& operator=(const LinkedBinaryTree<T>& rhs); // Assignment operator
private:
  void destroyTree(Node* p);			  // For destructor
protected:					  // local utilities
  void preorder(Node* v, PositionList& pl) const; // preorder utility
private:
  Node* _root;			// Pointer to the root
  std::size_t n;			// number of nodes
};


/** Main functions **/
template <typename T>
LinkedBinaryTree<T>::LinkedBinaryTree() : _root(NULL), n(0) {}

template <typename T>
std::size_t LinkedBinaryTree<T>::size() const { return n; }

template <typename T>
bool LinkedBinaryTree<T>::empty() const { return size() == 0; }

template <typename T>
typename LinkedBinaryTree<T>::Position LinkedBinaryTree<T>::root() const
{ return Position(_root); }

template <typename T>
void LinkedBinaryTree<T>::addRoot() throw (TreeNotEmptyException) {
  if (!empty()) {
    throw TreeNotEmptyException("Cannot add root - tree not empty!");
  }
  _root = new Node; n = 1;
}


/** Housekeeping functions **/
template <typename T>
LinkedBinaryTree<T>::~LinkedBinaryTree() {
  // destroyTree(_root);
}

template <typename T>
void LinkedBinaryTree<T>::destroyTree(Node* p) {
  
  if (p != NULL) {
    destroyTree(p->left);
    destroyTree(p->right);
    delete p;
  }
  
}

#endif
