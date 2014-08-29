#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "exceptions.hpp"

/***********************************************
 * Queue data structures
 * 
 ***********************************************/

// template <typename T>
// class Queue {
// public:
//   int size() const;		// number of items in Queue
//   bool empty() const;		// empty?
//   const E& front() const throw (QueueEmpty); // front element
//   void enqueue (const T& e);		     // enque to the back
//   void dequeue () throw (QueueEmpty); // dequeue from front
// };

/***************
 * Prototypes:
 ***************/
template <typename T> class ArrayQueue;
template <typename T> class LinkedQueue;
template <typename T> std::ostream&operator<<(std::ostream&, const ArrayQueue<T>&);
template <typename T> std::ostream&operator<<(std::ostream&, const LinkedQueue<T>&);

/*********************
 * Array based stack
 ********************/
template <typename E>
class ArrayQueue {
  enum { DEF_CAPACITY = 100 };	// default capacity
public:
  ArrayQueue(int cap = DEF_CAPACITY); // Constructor
  unsigned int size() const;	      // Number of items
  bool empty() const;		      // Empty?
  const E& front() const	      // The front element
    throw (QueueEmpty);		      // Error if empty
  void enqueue(const E& e)	      // push a new element
    throw (QueueFull);		      // Error if full
  void dequeue()		      // Remove the top
    throw(QueueEmpty);		      // Error if empty
public:
  friend std::ostream& operator<< <> (std::ostream&, const ArrayQueue<E>&);
private:
  E* Q;				// Array of stack elements
  unsigned int capacity;	// stack capacity
  unsigned int f;		// front of the queue
  unsigned int r;		// rear of the queue
  unsigned int n;			// NUmber of elements
};

template <typename E>
ArrayQueue<E>::ArrayQueue(int cap)
  : S(new E[cap]), capacity (cap), n(0), f(0), r(0) {}

template <typename E>
int ArrayQueue<E>::size() const {
  return n;
}

template <typename E>
bool ArrayQueue<E>::empty() const {
  return n == 0;
}

template <typename E>
const E& ArrayQueue<E>::front() const throw(QueueEmpty) {
  if (empty())
    throw QueueEmpty("Front of empty Queue");
  return Q[f];
}

template <typename E>
void ArrayQueue<E>::enqueue(const E& e) throw(QueueFull) {
  if (size() == capacity)
    throw QueueFull("Enqueue to full Queue");
  Q[r] = e;
  r = (r + 1) % capacity;
  n++;
}

template <typename E>
void ArrayQueue<E>::dequeue() throw(QueueEmpty) {
  if (empty())
    throw QueueEmpty("Dequeue from empty Queue");
  f = (f+1) % capacity;
  n--;
}

template <typename E>
std::ostream& operator<<(std::ostream& os, const ArrayQueue<E>& ar) {
  if (ar.empty()) {
    os << "EMPTY";
  } else {
    
  }
}


/*************************
 * Linked List based Queue
 *************************/


#endif
