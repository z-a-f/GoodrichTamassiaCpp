typedef int Elem;		// list base element type
class NodeList {		// node-based list
private:
  struct Node;
public:
  class Iterator;
public:
  NodeList();			   // default constructor
  int size() const;		   // list size
  bool empty() const;		   // is the list empty?
  Iterator begin() const;	   // beginning position
  Iterator end() const;		   // (just beyond) last position
  void insertFront(const Elem& e); // insert at front
  void insertBack(const Elem& e);  // insert at rear
  void insert(const Iterator& p, const Elem& e); // insert e before p
  void eraseFront();				 // remove first
  void eraseBack();				 // remove last
  void erase(const Iterator& p);		 // remove p
  // housekeeping functions omitted...
private:			// data members
  int     n;			// number of items
  Node*   header;		// head-of-list sentinel
  Node*   trailer;		// tail-of-list sentinel
};

struct NodeList::Node {		// a node of the list
  Elem elem;			// element value
  Node* prev;			// previous in list
  Node* next;			// next in list
};

class NodeList::Iterator {	// an iterator for the list
public:				// 
  Elem& operator*();		// reference to the element
  bool operator==(const Iterator& p) const; // compare positions
  bool operator!=(const Iterator& p) const; // 
  Iterator& operator++();		    // move to next position
  Iterator& operator--();	// move to previous position
  friend class NodeList;	// give NodeList access
private:			// 
  Node* v;			// pointer to the node
  Iterator(Node* u);		// create from node
};

NodeList::Iterator::Iterator(Node* u)		// constructor from Node*
{ v = u; }

Elem& NodeList::Iterator::operator*()		// reference to the element
{ return v->elem; }
// compare positions
bool NodeList::Iterator::operator==(const Iterator& p) const
{ return v == p.v; }

bool NodeList::Iterator::operator!=(const Iterator& p) const
{ return v != p.v; }
// move to next position
NodeList::Iterator& NodeList::Iterator::operator++()
{ v = v->next; return *this; }
// move to previous position
NodeList::Iterator& NodeList::Iterator::operator--()
{ v = v->prev; return *this; }

NodeList::NodeList() {			// constructor
  n = 0;					// initially empty
  header = new Node;				// create sentinels
  trailer = new Node;
  header->next = trailer;			// have them point to each other
  trailer->prev = header;
}

int NodeList::size() const 			// list size
{ return n; }

bool NodeList::empty() const 			// is the list empty?
{ return (n == 0); }

NodeList::Iterator NodeList::begin() const	// begin position is first item
{ return Iterator(header->next); }

NodeList::Iterator NodeList::end() const	// end position is just beyond last
{ return Iterator(trailer); }

