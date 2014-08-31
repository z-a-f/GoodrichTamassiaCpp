#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "exceptions.hpp"
#include "DLinkedList.hpp"


/***********************************************
 * Double ended queue  data structures
 * 
 ***********************************************/

/********************************
 * Doubly Linked List based deque
 *******************************/
template <typename T>
class LinkedDeque {
public:
  LinkedDeque();
  unsigned int size() const;
  bool empty() const;
  const E& front() const throw (DequeEmpty);
  const E& back() const throw (DequeEmpty);
  void insertFront(const E& e);
  void insertBack(const E& e);
  void removeFront() throw (DequeEmpty);
  void removeBack() throw (DequeEmpty);
private:
  DLinkedList D;
  int n;
};

#endif
