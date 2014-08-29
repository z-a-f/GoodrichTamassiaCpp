#ifndef C_LINKED_LIST_HPP
#define C_LINKED_LIST_HPP

// prototypes:
template <typename T> class CLinkedList;
template <typename T> std::ostream& operator<<(std::ostream&, const CLinkedList<T>&);

template <typename T>
class CNode {
private:
  T elem;			// element value
  CNode<T> *next;		// next item in the list

  friend class CLinkedList<T>;	// access to CLinkedList
  friend std::ostream& operator<< <T>(std::ostream&, const CLinkedList<T>&);
};

template <typename T>
class CLinkedList {
public:
  CLinkedList();		// Empty list constructor
  ~CLinkedList();		// Destructor
  bool empty() const;		// is the list empty?
  const T& front() const;	// get the front element
  const T& back() const;	// get the back element
  void advance();		// advance the cursor
  void add(const T& e);		// add at the cursor
  void remove();		// remove node after cursor
private:
  friend std::ostream& operator<< <T>(std::ostream&, const CLinkedList<T>&);
private:
  CNode<T>* cursor;		// Cursor
};

template <typename T>
CLinkedList<T>::CLinkedList() : sursor(NULL) {} // constructor

template <typename T>
CLinkedList<T>::~CLinkedList() { // destructor
  while (!empty())
    remove();
}

template <typename T>
bool CLinkedList<T>::empty() const { // empty?
  return cursor == NULL;
}

template <typename T>
const T& CLinkedList<T>::front() const { // front element
  return cursor->next->elem;		 // will return SegFault
}

template <typename T>
const T& CLinkedList<T>::back() const { // front element
  return cursor->elem;			// will return SegFault
}

template <typename T>
void CLinkedList<T>::advance() {
  cursor = cursor->next;
}
/**/

template <typename T>
void CLinkedList<T>::addFront(const T& e) {
  CNode<T>* v = new CNode<T>;	// New node
  v->elem = e;
  v->next = head;
  head = v;
}

template <typename T>
void CLinkedList<T>::removeFront() {
  CNode<T>* old = head;
  head = old->next;
  delete old;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const CLinkedList<T>& SL) {
  CNode<T> *p = SL.head;
  // os << "HEAD" << "->";
  while (p != NULL) {
    os << p->elem << "->";
    p = p->next;
  }
  // delete p;
  os << "NULL";
  return os;
}



#endif
