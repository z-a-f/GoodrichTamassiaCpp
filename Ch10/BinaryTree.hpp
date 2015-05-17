

/** Binary tree
 *
 */

#import <list>
#import <exception>

template <typename E>
class BinaryTree {
protected:
  struct Node {
	E elt;						// Element value
	Node* par;					// parent
	Node* left;					// left
	Node* right;				// right child
	Node() : elt(), par(NULL), left(NULL), right(NULL) {}
  };
public:
  class Position {
  private:
	Node* v;
  public:
	Position(Node* _v = NULL) : v(_v) { } // Constructor
	E& operator*() { return v->elt; }	  // Get element
	Position left() const { return Position(v->left); } // Get left child
	Position right() const { return Position(v->right); } // Get right child
	Position parent() const { return Position(v->par); }  // Get parent
	bool isRoot() const			// an external node?
	{ return v->par == NULL && v->right == NULL; }
	bool isExternal() const		// an external node?
	{ return v->left == NULL && v->right == NULL; }
	friend class BinaryTree;	// get tree access
  };
  typedef std::list<Position> PositionList; // list of positions

public:
  BinaryTree();					// constructor
  int size() const;				// number of nodes
  bool empty() const;			// is tree empty?
  Position root() const;		// get the root
  PositionList positions() const; // list of nodes
  void addRoot();				  // add root to empty tree
  void expandExternal(const Position& p); // expand external node
  Position removeAboveExternal(const Position& p); // remove p and parent
  // housekeeping functions
protected:
  void preorder(Node* v, PositionList& pl) const; // preorder utility
private:
  Node* _root;					// Pointer to the root
  int n;						// number of nodes
};


BinaryTree::BinaryTree() : _root(NULL), n(0) {}
int BinaryTree::size() const { return n; }
bool BinaryTree::empty() const { return size() == 0; }
BinaryTree::Position BinaryTree::root() const { return Position(_root); }
void BinaryTree::addRott() { _root = new Node; n = 1; }

void BinaryTree::expandExternal(const Position& p) {
  Node* v = p.v;
  v->left = new Node;
  v->left->par = v;
  v->right = new Node;
  v->right->par = v;
  n += 2;
}

BinaryTree::Position BinaryTree::removeAboveExternal(const Position& p) {

}
