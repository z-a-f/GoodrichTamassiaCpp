#ifndef STACK_HPP
#define STACK_HPP

#include "exceptions.hpp"
#include "SLinkedList.hpp"

/***********************************************
 * Stack data structures
 * 
 ***********************************************/
// template <typename T>
// class Stack {
// public:
//   int size() const;		// Number of items
//   bool empty() const;		// Empty?
//   const T& top() const
//     throw (StackEmpty);		// Top element
//   void push (const T& e);	// push e into stack
//   void pop ()
//     throw (StackEmpty);		// remove the top
// };

/***************
 * Prototypes:
 ***************/
template <typename T> class ArrayStack;
template <typename T> std::ostream&operator<<(std::ostream&, const ArrayStack<T>&);

/*********************
 * Array based stack
 ********************/
// Array Stack:
template <typename E>
class ArrayStack {
  enum { DEF_CAPACITY = 100 };	// default capacity
public:
  ArrayStack(int cap = DEF_CAPACITY); // Constructor
  int size() const;		      // Number of items
  bool empty() const;		      // Empty?
  const E& top() const		      // The top element
    throw (StackEmpty);		      // Error if empty
  void push(const E& e)		      // push a new element
    throw (StackFull);		      // Error if full
  void pop()			      // Remove the top
    throw(StackEmpty);		      // Error if empty
public:
  friend std::ostream& operator<< <> (std::ostream&, const ArrayStack<E>&);
private:
  E* S;				// Array of stack elements
  unsigned int capacity;	// stack capacity
  int t;		// index of the top
};

template <typename E>
ArrayStack<E>::ArrayStack(int cap)
  : S(new E[cap]), capacity (cap), t(-1) {}

template <typename E>
int ArrayStack<E>::size() const {
  return t+1;
}

template <typename E>
bool ArrayStack<E>::empty() const {
  return t < 0;
}

template <typename E>
const E& ArrayStack<E>::top() const throw(StackEmpty) {
  if (empty())
    throw StackEmpty("Top of empty stack");
  return S[t];
}

template <typename E>
void ArrayStack<E>::push(const E& e) throw(StackFull) {
  if (size() == capacity)
    throw StackFull("Push to full stack");
  S[++t] = e;
}

template <typename E>
void ArrayStack<E>::pop() throw(StackEmpty) {
  if (empty())
    throw StackEmpty("Pop from empty stack");
  --t;
}

template <typename E>
std::ostream& operator<<(std::ostream& os, const ArrayStack<E>& ar) {
  int t = ar.t;
  os << "{ ";
  while (t >= 0) {
    os << ar.S[t] << ' ';
    t--;
  }
  os << '}';
  return os;
}


/*************************
 * Linked List based Stack
 *************************/
template <typename T>
class LinkedStack {
public:
  LinkedStack();
  int size() const;
  bool empty() const;
  const Elem& top() const throw(StackEmpty); // the top element
  void push(const Elem& e);
  void pop() throw(StackEmpty); 
private:
  SLinkedList<Elem> S; 
  int n;
};


#endif
