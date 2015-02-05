#ifndef HEAP_TREE_HPP
#define HEAP_TREE_HPP

#include <vector>

// Vector based complete binary tree
template <typename E>
class VectorCompleteTree {
private:
  std::vector<E> V;		// Tree constents
public:
  typedef typename std::vector<E>::iterator Position; // Position in the tree
protected:
  Position pos(int i) {		// map index to a position
    return V.begin() + i;
  }
  int idx(xonst Position& p) const { // map a position to index
    return p - V.begin();
  }
public:
  VectorCompleteTree() : V(1) {} // constructor
  int size() const { return V.size() - 1; } // Size of the tree
  Position left (const Position& p) { return pos(2*idx(p)); } // left position
  Position right (const Position& p) { return pos(2*idx(p)) + 1; } // right position
  Position parent (const Position& p) { return pos(idx(p) >> 1); } // parent position
  bool hasLeft ( const Position& p) const { return 2*idx(p) <= size(); } // Is there left?
  bool hasRight ( const Position& p) const { return 2*idx(p) + 1 <= size(); } // Is there right?
  bool isRoot ( const Position& p) const { return idx(p) == 1; } // Is root?
  Position root() { return pos(1); }				 // Get the root
  Position last() { return pos(size()); }			 // Get the last element
  void addLast(const E& e) { V.push_back(e); }			 // Add element to the end
  void removeLast() { V.pop_back(); }				 // Remove last element
  void swap(const Position& p, const Position& q) {		 // Swap two elementscV
    E e = *q;
    *q = *p;
    *p = e;
  }
};


#endif
