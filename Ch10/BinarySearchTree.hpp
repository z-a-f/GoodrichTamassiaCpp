#ifndef __BINARY_SEARCH_TREE_HPP__
#define __BINARY_SEARCH_TREE_HPP__

// #include <exception>

#include "Exceptions.hpp"
#include "BinaryTree.hpp"

/** Node element. The tree will be templated to this element. */
template <typename K, typename V> // Key and Value types
class Entry {
public:							// Just to keep everything standard
  typedef K Key;
  typedef V Value;
public:
  /** Default constructor */
  Entry (const K& k = K(), const V& v = V())
	: _key(k), _value(v) {}
  const K& key() { return _key; } /**< Key getter @returns K(key) */
  const V& value() { return _value; } /**< Value getter @returns V(value) */
  void key(const K& k) { _key = k; } /**< Key setter \param[in] K(key) */
  void value(const V& v) { _value = v; } /**< Value setter \param[in] V(value)*/
};

/** Binary Search tree 
 *
 * @warning The module is not tested
 * @todo{Not all functions are defined - need to finish up. Refer to page 435 of the book}
 *
 * @todo Commenting is missing - When polishing up remember to check all the comments
 */
template <typename E>
class BinarySearchTree {
public: // Avoiding tons of template params, just use the ones declared in Entry
  typedef typename E::Key K;
  typedef typename E::Value V;
  class Iterator;
public:
  BinarySearchTree();			// Constructor
  int size() const;				// Size much?
  bool empty() const;			// Have much???
  Iterator find (const K& k);	// Find by key
  void insert(const K& k, const V& v); // Insert a key-value pair
  void erase (const K& k) throw (NonexistentElement); // Remove by key
  void erase (const Iterator& p);					  // Remove by position
  Iterator begin();									  // First entry
  Iterator end();									  // Last entry
protected:
  typedef BinaryTree<E> BinaryTree; // Linked binary tree
  typedef typename BinaryTree::Position TPos; // position in the tree
  TPos root() const;						  // get !virtual! root utility
  TPos finder(const K& k, const TPos& tp);	  // find utility
  TPos inserter (const K& k, const V& v);	  // inserter utility
  TPos eraser (TPos& v);					  // erase utility
  TPos restructure(const TPos& tp)			  // restructure the tree
	throw (BoundaryViolation);
private:
  BinaryTree T;					// The tree of values
  int n; 						// numbe rof elements
public:
  /** Iterator class */
  class Iterator {
  private:
	TPos tp;					// which entry?
  public:
	Iterator(const TPos& tpp) : p(tpp) {}
	const E& operator*() const { return *v; } // Dereference (read only)
	E& operator*() { return *v; }			  // Dereference (read/write)
	bool operator==(const Iterator& p) const  // Comparison
	{ return tp == p.tp; }
	Iterator& operator++();		// inorder successor
	friend class BinarySearchTree; // need access
  };
};

/** 
 * @brief Binary Search Tree increment position
 * 
 * If the node tp has a right child, the next successor will
 * be leftmost entry of the right subtree. Otherwise, tp must
 * be the largest element in the left subtree of some node w.
 * To find w, we walk up the tree as long as we are the right 
 * child of the current parent. Once it is no longer true, the
 * parent is the desired value. If the current value is the 
 * rightmost node of the tree, the iterator will go all the
 * way to the root, but it has to return "end". In order to
 * fix that, we create a "super root" in the initial tree,
 * and "virtual root" as the left child of the super. Super
 * root will serve as an "end" sentinel.
 *
 * @returns Iterator
 */
template <typename E>
BinarySearchTree<E>::Iterator& BinarySearchTree<E>::Iterator::operator++() {
  TPos w = tp.right();
  if (w.isInternal()) {
	do { tp = wp; w = w.left(); }
	while (w.isInternal());
  } else {
	w = tp.parent();
	while (tp == w.right()) { tp = w; w = wp.parent(); }
	tp = w;
  }
  return *this;	
}

/**
 * @brief Binary Search Tree constructor
 *
 * The default constructor creates a super root using the
 * Binary tree, and uses it's left subtree as virtual
 * tree root.*/
template <typename E>
BinarySearchTree<E>::BinarySearchTree() : T(), n(0) {
  T.addRoot();
  T.expandExternal(T.root());
}

/**
 * @brief Root function utility
 */
template <typename E>
BinarySearchTree<E>::TPos root() const {
  return T.root().left();
}

/** 
 * @brief begin function 
 * @returns Iterator
 */
template <typename E>
BinarySearchTree<E>::Iterator begin() {
  TPos v = root();				// Start at virtual root
  while (v.isInternal()) v = v.left(); // Find leftmost node
  return Iterator(v.parent());
}

/** 
 * @brief end function 
 * @returns Iterator
 */
template <typename E>
BinarySearchTree<E>::Iterator end() { return Iterator(T.root()); }

#endif
