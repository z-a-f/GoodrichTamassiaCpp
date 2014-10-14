
#ifndef VECTOR_CH06_HPP
#define VECTOR_CH06_HPP

#include <memory>
#include "exceptions.hpp"

/* Chapter 6.1 - GR C++ */
template <typename T> class ArrayVector;
template <typename T> std::ostream& operator<<(std::ostream&, const ArrayVector<T>&);


template <typename T>
class ArrayVector {
public:
  ArrayVector();		// Construct
  ArrayVector(size_t N);
  ArrayVector(const ArrayVector<T>& AV);
  size_t size() const;
  bool empty() const;
  T& operator[](int i);
  T& at(int i) throw (IndexOutOfBounds);
  void reserve(int N);
  void erase(int i);
  void insert(int i, const T& e);
  void insert(const T& e);	// Insert in the end
  void insertFront(const T& e);	// Insert in the front
  // housekeeping
  
public:				// friends
  friend std::ostream& operator<< <T>(std::ostream&, const ArrayVector<T>&);
private:
  size_t capacity;
  size_t n;
  size_t front;
  std::unique_ptr<T[]> A;
};

template <typename T>
ArrayVector<T>::ArrayVector()
  : capacity(0), n(0), front(0) {		// , A(NULL) {}
  A = NULL;
}

template <typename T>
ArrayVector<T>::ArrayVector(size_t N) 
  : capacity(N), n(0), front(0) {
  if (N < 2) N = 2;
  A = std::unique_ptr<T[]>(new T[N]);
}


template <typename T>
ArrayVector<T>::ArrayVector(const ArrayVector<T>& AV) {
  capacity = AV.capacity;
  n = AV.n;
  front = AV.front;
  std::unique_ptr<T[]> B = std::unique_ptr<T[]>(new T[AV.capacity]);
  for (int j = 0; j < AV.n; j++) {
    B[j] = AV.A[j];
  }
  A = std::move(B);
}


template <typename T>
size_t ArrayVector<T>::size() const {
  return n;
}

template <typename T>
bool ArrayVector<T>::empty() const {
  return (size() == 0);
}

template <typename T>
T& ArrayVector<T>::operator[] (int i) {
  return A[i];
}

template <typename T>
T& ArrayVector<T>::at(int i) throw (IndexOutOfBounds) {
  if (i < 0 || i >= size())
    throw IndexOutOfBounds("Illegal index in function at()");
  return A[i];
}

template <typename T>
void ArrayVector<T>::reserve(int N) {
  if (capacity >= N) return;
  std::unique_ptr<T[]> B = std::unique_ptr<T[]>(new  T[N]);
  for (int j = 0; j < n; j++)
    B[j] = A[j];
  A = std::move(B);
  capacity = N;
}

template <typename T>
void ArrayVector<T>::erase(int i) {
  for (int j = i + 1; j < n; j++)
    A[j-1] = A[j];
  n--;
}

template <typename T>
void ArrayVector<T>::insert(int i, const T& e) {
  if (n >= capacity){
    int c = 2*capacity;
    (1 > c) ? reserve(1) : reserve(c);
  }
  for (int j = n - 1; j >= i; j--)
    A[j+1] = A[j];
  A[i] = e;
  n++;
}

template <typename T>
void ArrayVector<T>::insert(const T& e) { // Insert in the end
  insert(n, e);
}

template <typename T>
void ArrayVector<T>::insertFront(const T& e) {
  if (n >= capacity) {
    int c = 2*capacity;
    (1 > c) ? reserve (2) : reserve (c);
  }
  if (front == 0) front = capacity - 1;
  else front--;
  A[front] = e;
  n++;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const ArrayVector<T>& AV) {
  if (AV.capacity == 0) {
    os << "[ Zero Capacity! ]";
    return os;
  }
  size_t end = (AV.front + AV.n) % AV.capacity;
  os << "[ Capacity: " << AV.capacity << "; ";
  os << "Front: " << AV.front << "; ";
  for (size_t i = AV.front; i < end; i = (i + 1) % AV.capacity) {
    os << AV.A[i] << ' ';
  }
  os << ']';
  return os;
}

#endif
