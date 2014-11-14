#ifndef LINKED_TREE_HPP
#define LINKED_TREE_HPP

// Declare a node
template <typename T>
struct Node {
  T elt;			// element value
  Node<T>* par;			// Parent
  Node<T>* left;		// Left child
  Node<T>* right;		// Right child
  Node() : elt(), par(NULL), left(NULL), right(NULL) {} // Constructor
};


template <typename T>
class Position {
private:
  Node<T>* v;			// pointer to the node
public:
  Position(Node<T>* _v = NULL) : v(_v) {}
  Elem& operator*() { return v->elt; }
}

#endif
