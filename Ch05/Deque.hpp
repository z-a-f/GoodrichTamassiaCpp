#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "exceptions.hpp"
#include "DLinkedList.hpp"


/***********************************************
 * Double ended queue  data structures
 * 
 ***********************************************/

/*************
 * Prototypes
 *************/
template <typename E> class LinkedDeque;
template <typename E> std::ostream& operator<<(std::ostream&, const LinkedDeque<E>);

/********************************
 * Doubly Linked List based deque
 *******************************/
template <typename E>
class LinkedDeque {
public:
  LinkedDeque();
  ~LinkedDeque() {};
  unsigned int size() const;
  bool empty() const;
  const E& front() const throw (DequeEmpty);
  const E& back() const throw (DequeEmpty);
  void insertFront(const E& e);
  void insertBack(const E& e);
  void removeFront() throw (DequeEmpty);
  void removeBack() throw (DequeEmpty);
public:
  friend std::ostream& operator<< <E> (std::ostream& os, const LinkedDeque<E> LD);
private:
  DLinkedList <E> D;
  int n;
};

template <typename E>
LinkedDeque<E>::LinkedDeque() : D(DLinkedList<E>()), n(0) {};

template <typename E>
unsigned int LinkedDeque<E>::size() const { return n; }

template <typename E>
bool LinkedDeque<E>::empty() const { return n==0; }

template <typename E>
const E& LinkedDeque<E>::front() const throw (DequeEmpty) {
  if (empty()) 
    throw DequeEmpty("Front of empty deque!");
  return D.front();
}

template <typename E>
const E& LinkedDeque<E>::back() const throw (DequeEmpty) {
  if (empty()) 
    throw DequeEmpty("Back of empty deque!");
  return D.back();
}

template <typename E>
void LinkedDeque<E>::insertFront(const E& e) {
  D.addFront(e);
  n++;
}

template <typename E>
void LinkedDeque<E>::insertBack(const E& e) {
  D.addBack(e);
  n++;
}

template <typename E>
void LinkedDeque<E>::removeFront() throw (DequeEmpty) {
  if (empty())
    throw DequeEmpty("Remove from front of empty deque!");
  D.removeFront();
  n--;
}

template <typename E>
void LinkedDeque<E>::removeBack() throw (DequeEmpty) {
  if (empty())
    throw DequeEmpty("Remove from back of empty deque!");
  D.removeBack();
  n--;
}

template <typename E>
std::ostream& operator<<(std::ostream& os, const LinkedDeque<E> LD) {
  if (LD.empty()) {
    os << "[EMPTY]";
  } else {
    os << LD.D;
  }
  return os;
}

#endif
